#include "line.h"
#include <math.h>
#include "util.h"
#include <QDebug>
#include <QThread>

Line::Line(pt a, pt b){
    p_a = a;
    p_b = b;
}

int2 Line::test(const cv::Mat& image){
    //qDebug() << "Line::test (start)" << QThread::currentThreadId();

    //Umwandlung Normierte-Koordinaten zu Bildkoordinaten
    double x1 = p_a.first * image.cols;
    double x2 = p_b.first * image.cols;
    double y1 = p_a.second * image.rows;
    double y2 = p_b.second * image.rows;

    //Variablen für min und max
    double x_min = image.cols;
    double x_max = 0.0;
    double y_min = image.rows;
    double y_max = 0.0;

    //Bestimme minimum und maximum für x und y
    x_min = x1 < x_min ? x1 : x_min;
    x_max = x1 > x_max ? x1 : x_max;
    x_min = x2 < x_min ? x2 : x_min;
    x_max = x2 > x_max ? x2 : x_max;
    y_min = y1 < y_min ? y1 : y_min;
    y_max = y1 > y_max ? y1 : y_max;
    y_min = y2 < y_min ? y2 : y_min;
    y_max = y2 > y_max ? y2 : y_max;

    //qDebug() << "Line::test (min " << x_min << y_min << "max" << x_max << y_max << ")" << QThread::currentThreadId();

    //nicht durch 0 teilen
    if(x_max - x_min == 0) return int2(1,1);

    //Steigung der Linie
    double m = (y_max - y_min) / (x_max - x_min);

    //qDebug() << "Line::test (m "<< m << ")" << QThread::currentThreadId();

    int r = 0; //anzahl korrekter punkte
    int n = 0; //totale anzahl punkte

    for(int x = (int)ceil(x_min); x <= (int)floor(x_max) ; x++){
        n++;

        // Berechne y-Koordinate: f(x) = m * x + b
        int y = (int)round(m * (x - x_min) + y_min);

        y = clamp(y, (int)ceil(y_min), (int)floor(y_max));

        //qDebug() << "Line::test (for:" << x << y << ")" << QThread::currentThreadId();

        //Prüfe ob der Punkt x,y weiß ist.
        uchar val = image.at<uchar>(y,x);
        if(val==255) r++;
    }

    //qDebug() << "Line::test (end)" << QThread::currentThreadId();
    return int2(r, n);
}
