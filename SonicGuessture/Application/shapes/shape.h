#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <memory>
#include <utility>
#include <opencv2/opencv.hpp>

/**
 * @brief 2D-Points
 */
typedef std::pair<double, double> pt;

/**
 * @brief result type of a test, containing two integers
 */
typedef std::pair<int,int> int2;

class Shape {
public:
    virtual ~Shape(){}
    virtual int2 test(const cv::Mat& image) = 0;
protected:
    Shape();
};

/** @brief shape pointer */
typedef std::shared_ptr<Shape> ShapePtr;

/** @brief several shapes */
typedef std::vector<ShapePtr> Shapes;

#endif // SHAPE_H
