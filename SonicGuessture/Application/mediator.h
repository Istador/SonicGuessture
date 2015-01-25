#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QThread>
#include <QString>
#include <opencv2/opencv.hpp>
#include "guessture.h"
#include "gui.h"
#include "camera.h"
#include "music.h"
#include "guessturecollection.h"
#include "colorpicker.h"
#include "colorkeyer.h"
#include "analyser.h"

class Mediator : public QObject {
Q_OBJECT

private:
    QThread* thread = new QThread;
    GUI* gui;
    Camera* cam;
    GuesstureCollection* gc;
    ColorPicker* cp;
    ColorKeyer* ck;
    Analyser* an;

signals: //Ausgehend
    void displayImage(const QString& filename);
    void shutdown();
    void loopMusic(const QString& filename);
    void playSound(const QString& filename);

public slots: //Eingehend
    void start();
    void colorSelected(const cv::Scalar& keyColor);
    void colorPicked(const cv::Scalar& keyColor);
    void newGuessture();
    void noMoreGuesstures();
    void guesstureRecognized();
    void skipGuessture();
    void quit();

//###############################################
//###############################################
//### Singleton
public:
    static Mediator* Instance();
private:
    Mediator();
    static Mediator* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // MEDIATOR_H
