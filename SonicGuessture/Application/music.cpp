#include "music.h"
#include "util.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

#define FADETIME 2000



Music* Music::_instance = 0;


Music* Music::Instance(){
    if(_instance == 0){
        _instance = new Music;
    }
    return _instance;
}


Music::Music() : sem(1) {
    mpone = true;
    mvolume = 70;
    svolume = 90;

    musicDir = QApplication::applicationDirPath()+"/../Music/";
    soundDir = QApplication::applicationDirPath()+"/../Sounds/";

    soundPlayer = new QMediaPlayer;
    musicPlayer1 = new QMediaPlayer;
    musicPlayer2 = new QMediaPlayer;
    musicPlaylist1 = new QMediaPlaylist;
    musicPlaylist2 = new QMediaPlaylist;

    musicPlayer1->setVolume(mvolume);
    musicPlayer2->setVolume(0);
    soundPlayer->setVolume(svolume);

    musicPlaylist1->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlaylist2->setPlaybackMode(QMediaPlaylist::Loop);

    musicPlayer1->setPlaylist(musicPlaylist1);
    musicPlayer2->setPlaylist(musicPlaylist2);
}


void Music::playSound(QString filename){
    QUrl url = QUrl::fromLocalFile(soundDir + filename);
    soundPlayer->stop();
    soundPlayer->setMedia(url);
    soundPlayer->play();
}


void Music::stopMusic(){
    //abspielen anhalten
    musicPlayer1->stop();
    musicPlayer2->stop();
    //entferne aktuelle Tracks
    musicPlaylist1->removeMedia(0);
    musicPlaylist2->removeMedia(0);
}


void Music::loopMusic(QString filename){
    QUrl url = QUrl::fromLocalFile(musicDir + filename);

    sem.acquire();

    qDebug() << "Music::loopMusic" << QThread::currentThreadId();

    //Musikstück austauschen und lautlos abspielen

    if(mpone){
        musicPlayer2->stop();
        musicPlaylist2->removeMedia(0);
        if(filename != NULL)
            musicPlaylist2->addMedia(url);
        musicPlayer2->setVolume(0);
        musicPlayer2->play();
    } else {
        musicPlayer1->stop();
        musicPlaylist1->removeMedia(0);
        if(filename != NULL)
            musicPlaylist1->addMedia(url);
        musicPlayer1->setVolume(0);
        musicPlayer1->play();
    }

    mpone = !mpone;

    //führe fade() in einem eigenem Thread aus
    QtConcurrent::run(this, &Music::fade);
}


//Fade Volume
void Music::fade(){

    //soll leiser werden
    QMediaPlayer* from = mpone ? musicPlayer2 : musicPlayer1;

    //soll lauter werden
    QMediaPlayer* to = mpone ? musicPlayer1 : musicPlayer2;

    qDebug() << "Music::fade start" << QThread::currentThreadId();

    int fadeprogress = 0;
    const int sleeptime = FADETIME / mvolume;

    while(fadeprogress < mvolume){
        QThread::msleep(sleeptime);

        from->setVolume(clamp(mvolume - fadeprogress, 0, 100)); //leiser
        to->setVolume(clamp(fadeprogress, 0, 100)); //lauter

        fadeprogress += 1;
    }

    from->stop();

    qDebug() << "Music::fade stop" << QThread::currentThreadId();

    sem.release();
}

void Music::setMVolume(int volume){
    mvolume = volume;
    if(mpone) musicPlayer1->setVolume(mvolume);
    else musicPlayer2->setVolume(mvolume);
}

void Music::setSVolume(int volume){
    svolume = volume;
    soundPlayer->setVolume(svolume);
}
