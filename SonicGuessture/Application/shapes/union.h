#ifndef UNION_H
#define UNION_H

#include "shape.h"

class Union : public Shape {
public:
    Union(Shapes shapes);
    int2 test(const cv::Mat& image);

protected:
    Union();
    Shapes s_shapes;
};

#endif // UNION_H
