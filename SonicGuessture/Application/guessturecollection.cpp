#include "guessturecollection.h"
#include <QDebug>
#include "guesstures/gclap.h"
#include "guesstures/gnoise.h"
#include "guesstures/gtriforce.h"
#include "guesstures/gvictory.h"
#include "guesstures/gvulcansalute.h"
#include "gui.h"


GuesstureCollection* GuesstureCollection::_instance = 0;


GuesstureCollection* GuesstureCollection::Instance(){
    if(_instance == 0){
        _instance = new GuesstureCollection;
        _instance->moveToThread(_instance->thread);
        _instance->thread->start();
    }
    return _instance;
}


GuesstureCollection::GuesstureCollection(){
    //TODO: initiallisiere Datenstruktur
    guesstures[0] = GVulcanSalute::Instance();
    guesstures[1] = GClap::Instance();
    guesstures[2] = GNoise::Instance();
    //guesstures[3] = GTriforce::Instance();
    guesstures[3] = GVictory::Instance();
}

void GuesstureCollection::start(){
    index = 0;
    emit newGuessture();
}

Guessture* GuesstureCollection::current(){
    if(index >= LENGTH) return NULL;
    return guesstures[index];
}

Guessture* GuesstureCollection::item(int i){
    if(i >= LENGTH || i < 0) return NULL;
    return guesstures[i];
}

void GuesstureCollection::nextGuessture(){
    qDebug() << "GuesstureCollection::nextGuessture" << QThread::currentThreadId();

    if(++index >= LENGTH){
        emit noMoreGuesstures();
    } else {
        emit newGuessture();
    }
}
