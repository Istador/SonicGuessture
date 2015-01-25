#ifndef COMPLEMENT_H
#define COMPLEMENT_H

#include "shape.h"

class Complement : public Shape {
public:
    Complement(ShapePtr shape);
    int2 test(const cv::Mat& image);
private:
    ShapePtr s_shape;
};

#endif // COMPLEMENT_H
