#ifndef COLORKEYER_H
#define COLORKEYER_H

#include <QObject>
#include <QThread>
#include <opencv2/opencv.hpp>

class ColorKeyer : public QObject {
    Q_OBJECT

public:
    cv::Mat keying(const cv::Mat& image);

private:
    QThread* thread = new QThread;
    cv::Scalar min, max;
    cv::Mat hsvRange(const cv::Mat& hsv);
    int imgLimit;

signals: //Ausgehend
    void analyze(const cv::Mat& image);
public slots: //Eingehend
    void colorPicked(const cv::Scalar& keyColor);
    void cameraImage(const cv::Mat& image);

//###############################################
//###############################################
//### Singleton
public:
    static ColorKeyer* Instance();
private:
    ColorKeyer();
    static ColorKeyer* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // COLORKEYER_H
