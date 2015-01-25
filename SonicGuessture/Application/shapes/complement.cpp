#include "complement.h"

Complement::Complement(ShapePtr shape){
    s_shape = shape;
}

int2 Complement::test(const cv::Mat& image){
    int2 tmp = s_shape->test(image);
    return int2(tmp.second - tmp.first, tmp.second);
}
