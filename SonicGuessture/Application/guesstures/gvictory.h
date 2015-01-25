#ifndef GVICTORY_H
#define GVICTORY_H

#include "guessture.h"
#include "shapes/shape.h"

class GVictory : public Guessture
{
public:
    bool analyze(const cv::Mat& bitmap);
private:
    ShapePtr s_shape;

//###############################################
//###############################################
//### Singleton
public:
    static GVictory* Instance();
private:
    GVictory();
    static GVictory* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GVICTORY_H
