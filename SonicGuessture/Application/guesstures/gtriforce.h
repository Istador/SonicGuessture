#ifndef GTRIFORCE_H
#define GTRIFORCE_H

#include "guessture.h"

class GTriforce : public Guessture
{
public:
    bool analyze(const cv::Mat& bitmap);

//###############################################
//###############################################
//### Singleton
public:
    static GTriforce* Instance();
private:
    GTriforce();
    static GTriforce* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GTRIFORCE_H
