#ifndef LINE_H
#define LINE_H

#include "shape.h"

/**
 * @brief a line between two points
 */
class Line : public Shape {
public:
    Line(pt a, pt b);
    int2 test(const cv::Mat& image);
private:
    pt p_a;
    pt p_b;
};

#endif // LINE_H
