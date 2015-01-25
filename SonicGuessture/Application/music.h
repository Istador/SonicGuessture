#ifndef MUSIC_H
#define MUSIC_H

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QApplication>
#include <QString>
#include <QSemaphore>

class Music {

private:
    QString musicDir;
    QString soundDir;
    QMediaPlayer* soundPlayer;
    QMediaPlayer* musicPlayer1;
    QMediaPlayer* musicPlayer2;
    QMediaPlaylist* musicPlaylist1;
    QMediaPlaylist* musicPlaylist2;
    bool mpone;
    int mvolume;
    int svolume;

    QSemaphore sem; // binary Semaphore to limit to one fade at a time

    void fade();

//signals: //Ausgehend

public: //Eingehend
    void stopMusic();
    void loopMusic(QString filename);
    void playSound(QString filename);
    void setMVolume(int volume);
    void setSVolume(int volume);

//###############################################
//###############################################
//### Singleton
public:
    static Music* Instance();
private:
    Music();
    static Music* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // MUSIC_H
