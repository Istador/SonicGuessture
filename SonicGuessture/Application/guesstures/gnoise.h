#ifndef GNOISE_H
#define GNOISE_H

#include "guessture.h"

class GNoise : public Guessture
{
public:
    bool analyze(const cv::Mat& bitmap);

private:
    cv::Mat local;
    int resetter;

//###############################################
//###############################################
//### Singleton
public:
    static GNoise* Instance();
private:
    GNoise();
    static GNoise* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GNOISE_H
