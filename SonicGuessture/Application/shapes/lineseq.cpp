#include "lineseq.h"

LineSeq::LineSeq(pts points, bool closed){
    //Alle Punkte als Linien miteinander verbunden abspeichern
    for(uint i = 0; i < points.size()-1; i++){
        pt a = points.at(i);
        pt b = points.at(i+1);
        s_shapes.push_back(std::make_shared<Line>(a,b));
    }
    //ein geschlossener Linienzug verbindet den letzten wieder mit dem ersten Punkt
    if(closed){
        pt a = points.back();
        pt b = points.front();
        s_shapes.push_back(std::make_shared<Line>(a,b));
    }
}
