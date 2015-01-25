#include "colorkeyer.h"
#include "guessturecollection.h"
#include <QDebug>

#include "util.h"

#define MEDIAN true
#define MEDIANAMM 5

#define MORPHO true

#define HUEDIST 13
#define SATDIST 60
#define VALDIST 110

ColorKeyer* ColorKeyer::_instance = 0;


ColorKeyer* ColorKeyer::Instance(){
    if(_instance == 0){
        _instance = new ColorKeyer;
        _instance->moveToThread(_instance->thread);
        _instance->thread->start();
    }
    return _instance;
}


ColorKeyer::ColorKeyer(){
    imgLimit = 0;
}


void ColorKeyer::colorPicked(const cv::Scalar& keyColor){
    qDebug() << "ColorKeyer::colorPicked" << QThread::currentThreadId();

    //min und max befüllen

    //HUE (cyclic, 0..179)
    min[0] = (int)(keyColor[0] - HUEDIST) % 180; // %' result might be < 0 because of -
    if(min[0] < 0) min[0] += 180;
    max[0] = (int)(keyColor[0] + HUEDIST) % 180; // here it can't be < 0 because of +

    //this clamp should be redundant, just to be sure
    min[0] = clamp(min[0], 0, 179);
    max[0] = clamp(max[0], 0, 179);

    //SAT
    min[1] = clamp(keyColor[1] - SATDIST, 0, 255);
    max[1] = clamp(keyColor[1] + SATDIST, 0, 255);

    //VAL
    min[2] = clamp(keyColor[2] - VALDIST, 0, 255);
    max[2] = clamp(keyColor[2] + VALDIST, 0, 255);

    qDebug() << "ColorKeyer min:" << min[0] << min[1] << min[2];
    qDebug() << "ColorKeyer max:" << max[0] << max[1] << max[2];
}

cv::Mat ColorKeyer::hsvRange(const cv::Mat& hsv){
    cv::Mat bitmap(hsv.rows, hsv.cols, CV_8UC1);

    for(int y = 0; y < bitmap.rows; y++)
        for(int x = 0; x < bitmap.cols; x++){
            cv::Vec3b p = hsv.at<cv::Vec3b>(y,x);

            bool draw =
              //HUE (cyclic, 0..179 = 0..359°)
              (
                ( min[0] <= max[0] && min[0] <= p[0] && p[0] <= max[0] )
                ||
                ( min[0] > max[0] && ( p[0] <= max[0] || min[0] <= p[0] ) )
              )
              //SAT
              && min[1] <= p[1] && p[1] <= max[1]
              //VAL
              && min[2] <= p[2] && p[2] <= max[2]
            ;

            bitmap.at<uchar>(y,x) = draw ? 255 : 0;
        }
    return bitmap;
}

cv::Mat ColorKeyer::keying(const cv::Mat& rgb){
    //RGB zu HSV umwandeln
    cv::Mat hsv;
    cv::cvtColor(rgb, hsv, CV_BGR2HSV);

    //markieren von ähnlichen Punkten
    cv::Mat bitmap = hsvRange(hsv);

    //Medianfilter
    if(MEDIAN) cv::medianBlur(bitmap, bitmap, MEDIANAMM);

    //Morphologischer Filter
    if(MORPHO){
        //vergrößern
        cv::dilate(bitmap, bitmap, cv::MORPH_ELLIPSE);
        cv::dilate(bitmap, bitmap, cv::MORPH_ELLIPSE);
        cv::dilate(bitmap, bitmap, cv::MORPH_ELLIPSE);

        //Closing
        cv::dilate(bitmap, bitmap, cv::MORPH_ELLIPSE);
        cv::dilate(bitmap, bitmap, cv::MORPH_ELLIPSE);
        cv::erode(bitmap, bitmap, cv::MORPH_ELLIPSE);
        cv::erode(bitmap, bitmap, cv::MORPH_ELLIPSE);
    }

    return bitmap;
}

void ColorKeyer::cameraImage(const cv::Mat& rgb){
    //nur für jedes 2. Bild
    imgLimit = (imgLimit + 1) % 2;
    if(imgLimit != 0) return;

    //qDebug() << "ColorKeyer::cameraImage" << QThread::currentThreadId();

    cv::Mat bitmap = keying(rgb);

    emit analyze(bitmap);
}

