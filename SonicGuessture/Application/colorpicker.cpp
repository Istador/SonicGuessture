#include "colorpicker.h"
#include <QDebug>
#include <QPoint>
#include <QCursor>
#include "gui.h"
#include "colorkeyer.h"

#define PICKRADIUS 6


ColorPicker* ColorPicker::_instance = 0;


ColorPicker* ColorPicker::Instance(){
    if(_instance == 0){
        _instance = new ColorPicker;
        _instance->moveToThread(_instance->thread);
        _instance->thread->start();
    }
    return _instance;
}


ColorPicker::ColorPicker(){
    selected = NULL;
}

void ColorPicker::shutdown(){
    selected = NULL;
}


/**
 * @brief determines the average color inside a specified circle in the image
 * @param input the image for which the color should be determined
 * @param cx x coordinate for the center of the circle
 * @param cy y coordinate for the center of the circle
 * @param radius radius of the circle
 * @return Color
 */
cv::Scalar ColorPicker::averageColor(const cv::Mat& input, int cx, int cy, int radius){
    // Durchschnittsfarbe berechnen
    int n = 0, a = 0, b = 0, c = 0;
    for(int y = cy-radius; y <= cy+radius; y++) if(0 <= y && y <= input.rows)
        for(int x = cx-radius; x <= cx+radius; x++) if(0 <= x && x <= input.cols){
            //bis hier hin erzeugen die for-Schleifen ein Quadrat
            //jetzt prüfen, ob die Quadratpunkte im Kreisradius liegen
            int dist = (x-cx)*(x-cx) + (y-cy)*(y-cy); // dist²
            if(dist <= radius*radius){ // dist² ≤ radius²
                n++;
                cv::Vec3b p = input.at<cv::Vec3b>(y, x);
                a += p[0];
                b += p[1];
                c += p[2];
            }
        }
    return cv::Scalar(a/n, b/n, c/n);
}

/**
 * @brief if no color was selected yet, show an crosshair, otherwise highlight the selected color
 * @param input the image that will get modified
 */
void ColorPicker::cameraImage(const cv::Mat& rgb){
    //qDebug() << "ColorPicker cameraImage" << QThread::currentThreadId();

    cv::Mat output;

    //wenn noch keine Farbe ausgewählt wurde
    if(selected == NULL){

        //Input zu Ouput kopieren.
        rgb.copyTo(output);

        //RGB zu HSV umwandeln
        cv::Mat hsv;
        cv::cvtColor(rgb, hsv, CV_BGR2HSV);

        //Mausposition berechnen
        QPoint pos = QCursor::pos();
        int w = GUI::Instance()->width();
        int h = GUI::Instance()->height();
        int cx = pos.x() * rgb.cols / w;
        int cy = pos.y() * rgb.rows / h;

        // Durchschnitts HSV-Farbe berechnen
        last = averageColor(hsv, cx, cy, PICKRADIUS);

        //Kreis zeichnen
        cv::circle(output, cv::Point(cx, cy), PICKRADIUS, cv::Scalar(0, 0, 255), 0);

    }
    //wenn eine Farbe ausgewählt wurde
    else {
        //Keying Vorschau
        output = ColorKeyer::Instance()->keying(rgb);
    }

    //modifiziertes Bild weitergeben
    emit modifiedImage(output);
}


/**
 * @brief mouseClick-handler to select a color
 */
void ColorPicker::mouseClicked(){
    qDebug() << "ColorPicker::mouseClicked" << QThread::currentThreadId();
    if(selected == NULL){
        selected = &last;
        emit colorSelected(*selected);
        qDebug() << "ColorPicker select:" << (*selected)[0] << (*selected)[1] << (*selected)[2];
    }
}

/**
 * @brief keyPress-handler to accept or reject a selected color
 * @param key the pressed key
 */
void ColorPicker::keyPress(const int& key){
    qDebug() << "ColorPicker::keyPress" << QThread::currentThreadId();
    if(selected != NULL){
        //Bestätigen
        if(key == Qt::Key_Y){
            qDebug() << "Yes" << QThread::currentThreadId();
            emit colorPicked(*selected);
        }
        //Abbrechen
        else if(key == Qt::Key_N){
            qDebug() << "No" << QThread::currentThreadId();
            emit colorSelected(cv::Scalar(0,0,0));
            selected = NULL;
        }
    }
}
