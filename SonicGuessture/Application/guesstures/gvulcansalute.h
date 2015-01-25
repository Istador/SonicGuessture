#ifndef GVULCANSALUTE_H
#define GVULCANSALUTE_H

#include "guessture.h"
#include "shapes/shape.h"

class GVulcanSalute : public Guessture
{
public:
    bool analyze(const cv::Mat& bitmap);
private:
    ShapePtr s_shape;

//###############################################
//###############################################
//### Singleton
public:
    static GVulcanSalute* Instance();
private:
    GVulcanSalute();
    static GVulcanSalute* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GVULCANSALUTE_H
