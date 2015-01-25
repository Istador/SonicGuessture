#ifndef CAMERA_H
#define CAMERA_H

#include <QThread>

#include <opencv2/opencv.hpp>
using namespace cv;

class Camera : public QThread {
Q_OBJECT

private:
    void run();

signals: //Ausgehend
    void cameraImage(const cv::Mat& image);

//###############################################
//###############################################
//### Singleton
public:
    static Camera* Instance(){if(_instance==0)_instance=new Camera; return _instance;}
private:
    Camera();
    static Camera* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // CAMERA_H
