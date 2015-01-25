#ifndef GUESSTURECOLLECTION_H
#define GUESSTURECOLLECTION_H

#include <vector>
#include <QObject>
#include <QThread>
#include "guessture.h"

#define LENGTH 4

class GuesstureCollection : public QObject {
Q_OBJECT

public:
    void start();
    Guessture* current();
    Guessture* item(int i);
private:
    QThread* thread = new QThread;
    Guessture* guesstures[LENGTH];
    int index;

signals: //Ausgehend
    void newGuessture();
    void noMoreGuesstures();

public slots: //Eingehend
    void nextGuessture();

//###############################################
//###############################################
//### Singleton
public:
    static GuesstureCollection* Instance();
private:
    GuesstureCollection();
    static GuesstureCollection* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GUESSTURECOLLECTION_H
