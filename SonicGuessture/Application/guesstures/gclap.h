#ifndef GCLAP_H
#define GCLAP_H

#define MSIZE 20

#include "guessture.h"

class GClap : public Guessture
{
public:
    bool analyze(const cv::Mat& bitmap);
private:
    bool memory[MSIZE];
    void updateMemory(bool neu);
    bool clearMemory();
    bool checkMemory();
//###############################################
//###############################################
//### Singleton
public:
    static GClap* Instance();
private:
    GClap();
    static GClap* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GCLAP_H
