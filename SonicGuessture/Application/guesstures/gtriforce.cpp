#include "gtriforce.h"


GTriforce::GTriforce()
 : Guessture("Triforce",
             "overworld.mp3",
             "tri.png",
             "Kōji Kondō - The Legend of Zelda Theme (Overworld Theme)",
             "Yellow Triangle",
             300,
             120)
{}


bool GTriforce::analyze(const cv::Mat& bitmap){
    return false;
    Q_UNUSED(bitmap);
}


GTriforce* GTriforce::_instance = 0;


GTriforce* GTriforce::Instance(){
    if(_instance == 0){
        _instance = new GTriforce;
    }
    return _instance;
}
