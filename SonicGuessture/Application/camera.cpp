#include "camera.h"
#include <QDebug>
#include "cvmattoqimage.h"

Camera* Camera::_instance = 0;

Camera::Camera(){
    start();
}

void Camera::run() {
    VideoCapture videoCapture;

    // Kamera öffnen; Device 0
    videoCapture.open(0);

    //Auflösung halbieren
    int w = videoCapture.get(CV_CAP_PROP_FRAME_WIDTH) / 2;
    int h = videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT) / 2;
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, w);
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, h);

    qDebug() << "Camera started. Thread" << QThread::currentThreadId();

    Mat videoFrame;//Read Only. nicht ändern!
    while(true){
        if (false == videoCapture.grab()){
            qDebug() << "grab() failed";
            break;
        }
        if (false == videoCapture.retrieve(videoFrame, 0)){ //Kanalnummer 0
            qDebug() << "retrieve() failed";
            break;
        }

        //Horizontal spiegeln (damit der Bildschirm wie ein Spiegel wirkt)
        flip(videoFrame, videoFrame, 1);

        //Bild an andere Threads weitergeben
        emit cameraImage(videoFrame);

        //msleep(30);
    }
    return;
}
