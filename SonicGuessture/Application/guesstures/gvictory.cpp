#include "gvictory.h"
#include "shapes/complement.h"
#include "shapes/lineseq.h"
#include "shapes/union.h"
#include <QDebug>
#include <QThread>

GVictory::GVictory()
 : Guessture("Victory sign",
             "Beethoven5.mp3",
             "v.png",
             "Ludwig van Beethoven - Symphony No. 5 in C minor, Op. 67",
             "Morse code: •••-",
             240,
             60)
{
    Shapes shapes;

    //green (12 lines)

    //Finger (3 * 3 = 9 lines)
    pts green1;
    green1.push_back(pt(0.375, 0.230));
    green1.push_back(pt(0.440, 0.600));
    green1.push_back(pt(0.525, 0.590));
    green1.push_back(pt(0.615, 0.220));
    ShapePtr ls_green1 = std::make_shared<LineSeq>(green1);
    shapes.push_back(ls_green1);
    shapes.push_back(ls_green1); //count twice
    shapes.push_back(ls_green1); //count tripple

    //Hand unten (3 lines)
    pts green2;
    green2.push_back(pt(0.390, 0.790));
    green2.push_back(pt(0.475, 0.900));
    green2.push_back(pt(0.605, 0.745));
    ShapePtr ls_green2 = std::make_shared<LineSeq>(green2, true);
    shapes.push_back(ls_green2);

    //red (9 lines)

    //zwischen den fingern (3 lines)
    pts redm;
    redm.push_back(pt(0.420, 0.115));
    redm.push_back(pt(0.480, 0.400));
    redm.push_back(pt(0.580, 0.110));
    ShapePtr ls_redm = std::make_shared<LineSeq>(redm);
    ShapePtr c_redm = std::make_shared<Complement>(ls_redm);
    shapes.push_back(c_redm);
    shapes.push_back(c_redm); //count twice

    //links (3 lines)
    pts redl;
    redl.push_back(pt(0.300, 0.815));
    redl.push_back(pt(0.350, 0.575));
    redl.push_back(pt(0.295, 0.150));
    redl.push_back(pt(0.350, 0.575)); //erneut
    ShapePtr ls_redl = std::make_shared<LineSeq>(redl);
    ShapePtr c_redl = std::make_shared<Complement>(ls_redl);
    shapes.push_back(c_redl);

    //rechts (3 lines)
    pts redr;
    redr.push_back(pt(0.705, 0.730));
    redr.push_back(pt(0.615, 0.536));
    redr.push_back(pt(0.700, 0.175));
    redr.push_back(pt(0.615, 0.536)); //erneut
    ShapePtr ls_redr = std::make_shared<LineSeq>(redr);
    ShapePtr c_redr = std::make_shared<Complement>(ls_redr);
    shapes.push_back(c_redr);

    s_shape = std::make_shared<Union>(shapes);
}


bool GVictory::analyze(const cv::Mat& bitmap){
    //qDebug() << "GVictory::analyze (start)" << QThread::currentThreadId();
    int2 tmp = s_shape->test(bitmap);

    //berechne wieviele der überprüften Punkte prozentual korrekt sind
    double percent = ((double)tmp.first) / ((double)tmp.second);

    qDebug() << "GVictory::analyze ("<< percent <<")" << QThread::currentThreadId();

    //bei über 95% Ähnlichkeit betrachte es als korrekt
    if(percent > 0.95) return true;
    else return false;
}


GVictory* GVictory::_instance = 0;


GVictory* GVictory::Instance(){
    if(_instance == 0){
        _instance = new GVictory;
    }
    return _instance;
}
