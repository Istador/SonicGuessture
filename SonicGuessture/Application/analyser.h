#ifndef ANALYSER_H
#define ANALYSER_H

#include <QObject>
#include <QThread>
#include <opencv2/opencv.hpp>

class Analyser : public QObject {
    Q_OBJECT

private:
    QThread* thread = new QThread;

signals: //Ausgehend
    void guesstureRecognized();
public slots: //Eingehend
    void analyze(const cv::Mat& image);

//###############################################
//###############################################
//### Singleton
public:
    static Analyser* Instance();
private:
    Analyser();
    static Analyser* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // ANALYSER_H
