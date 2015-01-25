#include "guessture.h"
#include <time.h>
#include "music.h"
#include "mediator.h"

/**
 * @brief Creates a new DefaultGuessture for debugging
 */
Guessture::Guessture()
    : Guessture("Empty", "Portal2-There_She_Is.mp3", "noise.png", "Hint 1 Text", "Hint 2 Text", 180, 30)
{
}

/**
 * @brief Creates a new Guessture
 * @param musicFile filename in ../music/ folder
 * @param imageFile filename in ../images/ folder
 */
Guessture::Guessture(QString name, QString musicFile, QString imageFile, QString hint1, QString hint2, int noobTime, int nerdTime){
    s_name = name;
    s_musicFile = musicFile;
    s_imageFile = imageFile;
    s_hint1 = hint1;
    s_hint2 = hint2;
    i_noobTime = noobTime;
    i_nerdTime = nerdTime;
    i_endTime = -1;
}


/**
 * @brief virtual destructor, otherwise it will not be called by delete on subclass pointers.
 */
Guessture::~Guessture(){}


/**
 * @brief initializes variables, starts the timer and plays music
 */
void Guessture::start(){
    i_startTime = (int) time(NULL); // NOW
    i_endTime = 0;

    i_timeStars = 0;
    i_hintStars = 0;

    b_usedHint1 = false;
    b_usedHint2 = false;

    emit Mediator::Instance()->loopMusic(s_musicFile);
}

/**
 * @brief to use to skip this guessture without giving stars
 */
void Guessture::skip(){
    i_endTime = -1;
    end();
}


/**
 * @brief stops the timer and calculate how many stars the user earned
 * @return amount of stars
 */
int Guessture::end(){
    i_timeStars = 0;
    i_hintStars = 0;

    bool skipped = i_endTime == -1;

    i_endTime = (int) time(NULL); //NOW

    //Abgebrochen
    if(skipped) return 0;

    //Sterne für Zeit
    i_timeStars = 1;
    int time = i_endTime - i_startTime;
    if(time <= i_nerdTime) i_timeStars++;
    if(time <= i_noobTime) i_timeStars++;

    //Sterne für nicht benötigte Hinweise
    i_hintStars = 2;
    if(b_usedHint1) i_hintStars--;
    if(b_usedHint2) i_hintStars--;

    return getStars();
}


/**
 * @brief wheter this guessture was started but not ended yet
 * @return
 */
bool Guessture::isActive(){
    return i_endTime == 0;
}


/**
 * @return a hint for the guessture for the cost of one star
 */
QString Guessture::getHint(){
    if(!b_usedHint1){
        b_usedHint1 = true;
        return s_hint1;
    }
    if(!b_usedHint2){
        b_usedHint2 = true;
        return s_hint2;
    }
    return "";
}

/**
 * @return the name of this guessture
 */
QString Guessture::getName() const {return s_name;}

/**
 * @return filename of the image inside the /Images/ folder
 */
QString Guessture::getImageFile() const {return s_imageFile;}

/**
 * @return amount of stars for finishing in time
 */
int Guessture::getTimeStars() const {return i_timeStars;}

/**
 * @return amount of stars for not taking hints
 */
int Guessture::getHintStars() const {return i_hintStars;}

/**
 * @return total amount of stars
 */
int Guessture::getStars() const {return i_timeStars + i_hintStars;}

/**
 * @brief function to analyse the webcam image, to recognize the guessture
 * @param bitmap color-keyed-bitmap ready to analyze
 * @return true, if the guessture was correctly performed, false otherwise
 */
bool Guessture::analyze(const cv::Mat& bitmap){return false; Q_UNUSED(bitmap)}
