#include "union.h"

Union::Union(){}

Union::Union(Shapes shapes){
    s_shapes = shapes;
}

int2 Union::test(const cv::Mat& image){
    int r = 0; //anzahl korrekter punkte
    int n = 0; //totale anzahl punkte

    //Für alle Linien
    for(ShapePtr s : s_shapes){
        int2 tmp = s->test(image);
        r += tmp.first;
        n += tmp.second;
    }

    return int2(r, n);
}
