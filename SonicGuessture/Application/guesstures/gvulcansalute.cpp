#include "gvulcansalute.h"
#include "shapes/complement.h"
#include "shapes/lineseq.h"
#include "shapes/union.h"
#include <QDebug>
#include <QThread>

GVulcanSalute::GVulcanSalute()
 : Guessture("Vulcan Salute",
             "trek.mp3",
             "vulcan.jpg",
             "Alicander Courage - Where No Man Has Gone Before",
             "Live long and prosper",
             180,
             30)
{
    pts green;
    green.push_back(pt(0.285, 0.560));
    green.push_back(pt(0.410, 0.760));
    green.push_back(pt(0.495, 0.635));
    green.push_back(pt(0.460, 0.245));
    green.push_back(pt(0.510, 0.210));
    green.push_back(pt(0.555, 0.560));
    green.push_back(pt(0.610, 0.580));
    green.push_back(pt(0.670, 0.325));
    green.push_back(pt(0.715, 0.370));
    green.push_back(pt(0.685, 0.640));
    green.push_back(pt(0.475, 0.830));
    ShapePtr ls_green = std::make_shared<LineSeq>(green);

    pts red;
    red.push_back(pt(0.360, 0.870));
    red.push_back(pt(0.185, 0.550));
    red.push_back(pt(0.255, 0.430));
    red.push_back(pt(0.405, 0.595));
    red.push_back(pt(0.400, 0.165));
    red.push_back(pt(0.540, 0.095));
    red.push_back(pt(0.595, 0.390));
    red.push_back(pt(0.655, 0.125));
    red.push_back(pt(0.780, 0.335));
    red.push_back(pt(0.750, 0.720));
    ShapePtr ls_red = std::make_shared<LineSeq>(red);
    ShapePtr c_red = std::make_shared<Complement>(ls_red);

    Shapes shapes;
    shapes.push_back(ls_green);
    shapes.push_back(c_red);

    s_shape = std::make_shared<Union>(shapes);
}


bool GVulcanSalute::analyze(const cv::Mat& bitmap){
    //qDebug() << "GVulcanSalute::analyze (start)" << QThread::currentThreadId();
    int2 tmp = s_shape->test(bitmap);

    //berechne wieviele der überprüften Punkte prozentual korrekt sind
    double percent = ((double)tmp.first) / ((double)tmp.second);

    qDebug() << "GVulcanSalute::analyze ("<< percent <<")" << QThread::currentThreadId();

    //bei über 90% Ähnlichkeit betrachte es als korrekt
    if(percent > 0.90) return true;
    else return false;
}


GVulcanSalute* GVulcanSalute::_instance = 0;


GVulcanSalute* GVulcanSalute::Instance(){
    if(_instance == 0){
        _instance = new GVulcanSalute;
    }
    return _instance;
}
