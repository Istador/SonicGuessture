#include "analyser.h"
#include "guessturecollection.h"
#include <QDebug>

Analyser* Analyser::_instance = 0;


Analyser* Analyser::Instance(){
    if(_instance == 0){
        _instance = new Analyser;
        _instance->moveToThread(_instance->thread);
        _instance->thread->start();
    }
    return _instance;
}


Analyser::Analyser(){}


void Analyser::analyze(const cv::Mat& image){
    //qDebug() << "Analyser::analyze" << QThread::currentThreadId();

    Guessture* g = GuesstureCollection::Instance()->current();

    //nur wenn das Guessture auch aktiv ist
    if(g != NULL && g->isActive()){
        //wenn die geste korrekt ausgeführt wurde
        if(g->analyze(image)){
            //informiere Mediator
            emit guesstureRecognized();
        }
    }
}

