#include "gclap.h"

#include <QDebug>

GClap::GClap()
 : Guessture("Claping hands",
             "rock.mp3",
             "clap.jpg",
             "Queen - We Will Rock You",
             "If you're happy and you know it ...",
             180,
             60)
{
    clearMemory();
}


bool GClap::analyze(const cv::Mat& bitmap){

    cv::Mat tmp;
    bitmap.copyTo(tmp);

    //Vergrößern
    cv::dilate(tmp, tmp, cv::MORPH_ELLIPSE);
    cv::dilate(tmp, tmp, cv::MORPH_ELLIPSE);

    // 1. Bestimmung der Regionen
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(tmp,contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    int n = (int)contours.size();

    //int iMaxArea = -1;
    int imax1 = -1;
    int imax2 = -1;
    //int maxArea = 0;
    int max1 = 0;
    int max2 = 0;

    for(int i=0; i < n; i++){
        //    2.	Berechnung der Fläche der Region
        int area = cv::contourArea(contours[i]);

        //    3.	Bestimmung der Regionen mit den größten Flächen
        if(imax1 == -1 || area > max1){
            imax2 = imax1;
            max2 = max1;
            imax1 = i;
            max1 = area;
        } else if(imax2 == -1 || area > max2){
            imax2 = i;
            max2 = area;
        }
    }

    bool zusammen = (max1 > 4000 && max2 < 2000 && max1 < 10000);

    if(zusammen) qDebug() << "zusammen" << max1 << max2;
    else qDebug() << "getrennt" << max1 << max2;

    updateMemory(zusammen);

    if(checkMemory()){
        clearMemory();
        return true;
    }

    return false;
}


void GClap::updateMemory(bool neu){
    //von rechts nach links neue einfügen
    for(int i = MSIZE - 1; i >= 0; i--){
        bool tmp = memory[i];
        memory[i] = neu;
        neu = tmp;
    }
}


bool GClap::clearMemory(){
    for(int i = 0; i < MSIZE; i++)
        memory[i] = false;
}


bool GClap::checkMemory(){
    int einsen = 0;
    int fehler = 0;

    //Anzahl true's zählen
    for(int i=0; i<MSIZE; i++){
        if(memory[i]) einsen++;
    }

    //bei weniger als 3 trues abbrechen
    if(einsen <= 2) return false;

    //betrachte 3 speicherstellen nebeneinander
    for(int i=0; i<MSIZE-2; i++){
        //keine lücke zwischen 2 trues
        if(memory[i] && !memory[i+1] && memory[i+2])
            fehler++;
        //keine 3 trues hintereinander
        else if(memory[i] && memory[i+1] && memory[i+2])
            fehler++;
    }

    //auf ein true soll 5 später +-1 auch mindestens ein true folgen
    for(int i=0; i<MSIZE-6; i++) if(memory[i]) {
        if(!memory[i+4] && !memory[i+5] && !memory[i+6])
            fehler++;
    }

    //bei mehr als einem fehler, nicht erfolgreich
    if(fehler > 2) return false;

    return true;
}


GClap* GClap::_instance = 0;


GClap* GClap::Instance(){
    if(_instance == 0){
        _instance = new GClap;
    }
    return _instance;
}
