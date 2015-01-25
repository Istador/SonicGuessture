#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QObject>
#include <QThread>
#include <opencv2/opencv.hpp>

class ColorPicker : public QObject {
Q_OBJECT

private:
    QThread* thread = new QThread;
    cv::Scalar last;
    cv::Scalar* selected;
    cv::Scalar averageColor(const cv::Mat& img, int cx, int cy, int radius);

signals: //Ausgehend
    void colorSelected(const cv::Scalar& keyColor);
    void colorPicked(const cv::Scalar& keyColor);
    void modifiedImage(const cv::Mat& image);

public slots: //Eingehend
    void cameraImage(const cv::Mat& image);
    void mouseClicked();
    void keyPress(const int&);
    void shutdown();

//###############################################
//###############################################
//### Singleton
public:
    static ColorPicker* Instance();
private:
    ColorPicker();
    static ColorPicker* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // COLORPICKER_H
