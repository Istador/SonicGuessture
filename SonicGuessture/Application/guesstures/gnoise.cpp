#include "gnoise.h"

#include <QDebug>
#include <QThread>

GNoise::GNoise()
 : Guessture("Cover all pixels",
             "noise.mp3",
             "noise.png",
             "White noise",
             "All frequencies",
             300,
             120)
{
    resetter = 0;
    local = cv::Scalar(0); //speicher leeren
}


bool GNoise::analyze(const cv::Mat& bitmap){
    cv::Mat tmp;
    bitmap.copyTo(tmp);

    //Vergrößern
    cv::dilate(tmp, tmp, cv::MORPH_ELLIPSE);
    cv::dilate(tmp, tmp, cv::MORPH_ELLIPSE);

    //jedes 62. Bild resetten (etwa alle 5 sekunden), oder beim ersten mal
    resetter = (resetter + 1) % 62;
    if(resetter == 0 || local.empty()){
        tmp.copyTo(local);
    }

    //OR-Funktion
    cv::bitwise_or(local, tmp,local);

    //Zähle weiße pixel
    int n = local.rows * local.cols;
    int r = 0;
    for(int y = 0; y < local.rows; y++)
        for(int x = 0; x < local.cols; x++){
            uchar val = local.at<uchar>(y,x);
            if(val != 0) r++;
        }

    //berechne wieviele prozent weiß ist
    double percent = ((double)r) / ((double)n);

    qDebug() << "GNoise::analyze ("<< percent <<")" << QThread::currentThreadId();

    //bei über 90% betrachte es als korrekt
    if(percent > 0.90){
        local = cv::Scalar(0); //speicher leeren
        return true;
    }
    else return false;
}


GNoise* GNoise::_instance = 0;


GNoise* GNoise::Instance(){
    if(_instance == 0){
        _instance = new GNoise;
    }
    return _instance;
}
