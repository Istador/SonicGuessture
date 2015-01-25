#include "mediator.h"


Mediator* Mediator::_instance = 0;


Mediator* Mediator::Instance(){
    if(_instance == 0){
        _instance = new Mediator;
        _instance->moveToThread(_instance->thread);
        _instance->thread->start();
    }
    return _instance;
}


Mediator::Mediator(){

    //andere Threads erstellen
    gui = GUI::Instance();
    cam = Camera::Instance();
    gc = GuesstureCollection::Instance();
    cp = ColorPicker::Instance();
    ck = ColorKeyer::Instance();
    an = Analyser::Instance();

    //Camera direkt an GUI
    connect(cam, SIGNAL(cameraImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)), Qt::UniqueConnection);

    //GUI darf das spiel starten
    connect(gui, SIGNAL(start()), this, SLOT(start()), Qt::UniqueConnection);

    //Musik
    connect(this, SIGNAL(loopMusic(const QString&)), gui, SLOT(loopMusic(const QString&)), Qt::UniqueConnection);
    connect(this, SIGNAL(playSound(const QString&)), gui, SLOT(playSound(const QString&)), Qt::UniqueConnection);

    //Shutdowns
    connect(this, SIGNAL(shutdown()), cp, SLOT(shutdown()), Qt::UniqueConnection);

    //GUI anzeigen
    gui->showFullScreen();

    //Hauptmenümusik
    Music::Instance()->loopMusic("Portal2-There_She_Is.mp3");

}


//slots (Eingehend)


void Mediator::start(){
    //GUI kann das Spiel nicht mehr starten
    disconnect(gui, SIGNAL(start()), this, SLOT(start()));
    connect(gui, SIGNAL(quit()), this, SLOT(quit()), Qt::UniqueConnection);

    //Camera nicht mehr an GUI
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)));
    connect(cam, SIGNAL(cameraImage(const cv::Mat&)), cp, SLOT(cameraImage(const cv::Mat&)), Qt::UniqueConnection);

    // ColorPicker verbinden
    connect(cp,  SIGNAL(modifiedImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)), Qt::UniqueConnection);
    connect(gui, SIGNAL(mouseClicked()), cp, SLOT(mouseClicked()), Qt::UniqueConnection);
    connect(gui, SIGNAL(keyPress(const int&)), cp, SLOT(keyPress(const int&)), Qt::UniqueConnection);
    connect(cp,  SIGNAL(colorSelected(const cv::Scalar&)), this, SLOT(colorSelected(const cv::Scalar&)), Qt::UniqueConnection);
    connect(cp,  SIGNAL(colorSelected(const cv::Scalar&)), ck, SLOT(colorPicked(const cv::Scalar&)), Qt::UniqueConnection);
    connect(cp,  SIGNAL(colorPicked(const cv::Scalar&)), this, SLOT(colorPicked(const cv::Scalar&)), Qt::UniqueConnection);
    connect(cp,  SIGNAL(colorPicked(const cv::Scalar&)), ck, SLOT(colorPicked(const cv::Scalar&)), Qt::UniqueConnection);
}

void Mediator::colorSelected(const Scalar& keyColor){
    if(keyColor != cv::Scalar(0,0,0)) gui->showColorPicker2();
    else gui->showColorPicker1();
}

void Mediator::colorPicked(const Scalar& keyColor){
    qDebug() << "Mediator::colorPicked" << QThread::currentThreadId();

    //Camera direkt an GUI
    connect(cam, SIGNAL(cameraImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)), Qt::UniqueConnection);
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), cp, SLOT(cameraImage(const cv::Mat&)));

    //ColorPicker trennen
    disconnect(cp, SIGNAL(modifiedImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)));
    disconnect(gui, SIGNAL(mouseClicked()), cp, SLOT(mouseClicked()));
    disconnect(gui, SIGNAL(keyPress(const int&)), cp, SLOT(keyPress(const int&)));
    disconnect(cp,  SIGNAL(colorSelected(const cv::Scalar&)), this, SLOT(colorSelected(const cv::Scalar&)));
    disconnect(cp,  SIGNAL(colorSelected(const cv::Scalar&)), ck, SLOT(colorPicked(const cv::Scalar&)));
    disconnect(cp, SIGNAL(colorPicked(const cv::Scalar&)), this, SLOT(colorPicked(const cv::Scalar&)));

    //Rückmeldungen von GuesstureCollection ob eine neue Geste kommen soll
    connect(gc, SIGNAL(newGuessture()), this, SLOT(newGuessture()), Qt::UniqueConnection);
    connect(gc, SIGNAL(noMoreGuesstures()), this, SLOT(noMoreGuesstures()), Qt::UniqueConnection);

    //resette die GuesstureCollection und sende die erste Guessture
    gc->start();

    Q_UNUSED(keyColor)
}


void Mediator::newGuessture(){
    qDebug() << "Mediator::newGuessture" << QThread::currentThreadId();

    //Rückmeldungen von GuesstureCollection abschalten
    disconnect(gc, SIGNAL(newGuessture()), this, SLOT(newGuessture()));
    disconnect(gc, SIGNAL(noMoreGuesstures()), this, SLOT(noMoreGuesstures()));

    //Überspringen erlauben
    connect(gui, SIGNAL(skipGuessture()), this, SLOT(skipGuessture()), Qt::UniqueConnection);
    //CameraImage an ColorKeyer weiterleiten
    connect(cam, SIGNAL(cameraImage(const cv::Mat&)), ck, SLOT(cameraImage(const cv::Mat&)), Qt::UniqueConnection);
    //ColorKeyedImage von ColorKeyer an Analyser weitergeben
    connect(ck, SIGNAL(analyze(const cv::Mat&)), an, SLOT(analyze(const cv::Mat&)), Qt::UniqueConnection);
    connect(ck, SIGNAL(analyze(const cv::Mat&)), gui, SLOT(debugImage(const cv::Mat&)), Qt::UniqueConnection);
    //Geste korrekt vom Analyzer erkannt
    connect(an, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()), Qt::UniqueConnection);
    //DEBUG: F5 -> Geste korrekt erkannt
    connect(gui, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()), Qt::UniqueConnection);

    //Zeiterfassung und Musik starten
    gc->current()->start();

    //Menü anzeigen
    gui->showGuesstureMenu();
}


void Mediator::noMoreGuesstures(){
    qDebug() << "Mediator::noMoreGuesstures" << QThread::currentThreadId();

    //Rückmeldungen von GuesstureCollection abschalten
    disconnect(gc, SIGNAL(newGuessture()), this, SLOT(newGuessture()));
    disconnect(gc, SIGNAL(noMoreGuesstures()), this, SLOT(noMoreGuesstures()));

    emit playSound("ItemCatch.mp3");

    //Credits-Musik
    emit loopMusic("Portal2-Robots_FTW.mp3");

    //zur Endstatistik
    gui->showTotalRatingMenu();
}


void Mediator::guesstureRecognized(){
    qDebug() << "Mediator::guesstureRecognized" << QThread::currentThreadId();

    //Kein überspringen mehr
    disconnect(gui, SIGNAL(skipGuessture()), this, SLOT(skipGuessture()));
    //CameraImage nicht mehr zum ColorKeyer
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), ck, SLOT(cameraImage(const cv::Mat&)));
    //ColorKeyedImage nicht mehr von ColorKeyer zum Analyser
    disconnect(ck, SIGNAL(analyze(const cv::Mat&)), an, SLOT(analyze(const cv::Mat&)));
    //Gestenerkennung nicht mehr vom Analyzer bekommen
    disconnect(an, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()));
    //nicht mehr DEBUG Gestenerkennung bekommen
    disconnect(gui, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()));

    //Zeit stoppen
    gc->current()->end();

    //Erfolgreicher Sound
    emit playSound("SmallItemCatch.mp3");

    connect(gui, SIGNAL(nextGuessture()), gc, SLOT(nextGuessture()), Qt::UniqueConnection);
    connect(gc, SIGNAL(newGuessture()), this, SLOT(newGuessture()), Qt::UniqueConnection);
    connect(gc, SIGNAL(noMoreGuesstures()), this, SLOT(noMoreGuesstures()), Qt::UniqueConnection);

    //zur Auflösung
    gui->showSolutionMenu(gc->current());
}

void Mediator::skipGuessture(){
    qDebug() << "Mediator::skipGuessture" << QThread::currentThreadId();

    //Kein überspringen mehr
    disconnect(gui, SIGNAL(skipGuessture()), this, SLOT(skipGuessture()));
    //CameraImage nicht mehr zum ColorKeyer
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), ck, SLOT(cameraImage(const cv::Mat&)));
    //ColorKeyedImage nicht mehr von ColorKeyer zum Analyser
    disconnect(ck, SIGNAL(analyze(const cv::Mat&)), an, SLOT(analyze(const cv::Mat&)));
    //Gestenerkennung nicht mehr vom Analyzer bekommen
    disconnect(an, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()));
    //nicht mehr DEBUG Gestenerkennung bekommen
    disconnect(gui, SIGNAL(guesstureRecognized()), this, SLOT(guesstureRecognized()));

    //Zeit stoppen
    gc->current()->skip();

    //Sound des Scheiterns
    emit playSound("GameOver.mp3");

    //Musik aus
    emit loopMusic(NULL);

    connect(gui, SIGNAL(nextGuessture()), gc, SLOT(nextGuessture()), Qt::UniqueConnection);
    connect(gc, SIGNAL(newGuessture()), this, SLOT(newGuessture()), Qt::UniqueConnection);
    connect(gc, SIGNAL(noMoreGuesstures()), this, SLOT(noMoreGuesstures()), Qt::UniqueConnection);

    //zur Auswertung (überspringe Auflösung)
    gui->showRatingMenu(gc->current());
}


void Mediator::quit(){
    disconnect(gui, SIGNAL(quit()), this, SLOT(quit()));
    //disconnect(this, SLOT(noMoreGuesstures()));
    //disconnect(this, SLOT(newGuessture(const Guessture&)));

    //Hauptmenümusik
    emit loopMusic("Portal2-There_She_Is.mp3");

    emit shutdown();

    //Color Picker bekommt keine Signale mehr
    disconnect(gui, SIGNAL(mouseClicked()), cp, SLOT(mouseClicked()));
    disconnect(gui, SIGNAL(keyPress(const int&)), cp, SLOT(keyPress(const int&)));

    //Camera direkt an GUI, und nicht mehr zu anderen
    connect(cam, SIGNAL(cameraImage(const cv::Mat&)), gui, SLOT(imageResult(const cv::Mat&)), Qt::UniqueConnection);
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), cp, SLOT(cameraImage(const cv::Mat&)));
    disconnect(cam, SIGNAL(cameraImage(const cv::Mat&)), ck, SLOT(cameraImage(const cv::Mat&)));

    //GUI darf das spiel starten
    connect(gui, SIGNAL(start()), this, SLOT(start()), Qt::UniqueConnection);
}
