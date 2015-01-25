#include <QApplication>
#include <QDebug>
#include <QThread>

#include <opencv2/opencv.hpp>
#include "mediator.h"
#include "guessture.h"

Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(cv::Scalar)
Q_DECLARE_METATYPE(Guessture)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<cv::Mat>();
    qRegisterMetaType<cv::Scalar>();
    qRegisterMetaType<Guessture>();

    qDebug() << "Main Thread" << QThread::currentThreadId();

    Mediator::Instance();

    return a.exec();
}
