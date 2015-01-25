#include "gui.h"
#include <QDebug>
#include "guessturecollection.h"
#include "cvmattoqimage.h"
#include "music.h"

GUI* GUI::_instance = 0;


GUI* GUI::Instance(){
    if(_instance == 0){
        _instance = new GUI;
    }
    return _instance;
}


GUI::GUI(QWidget *parent) :
    QMainWindow(parent)
{
    currentWidget = NULL;
    previousWidget = NULL;
    imagesDir = QApplication::applicationDirPath()+"/../Images/";

    ui.setupUi(this);

    layout = new QHBoxLayout(ui.videoOutput);

    //Hauptmenü
    mm.setupUi(&lab_mm);    setupLabel(&lab_mm);
    //Optionsmenü
    om.setupUi(&lab_om);    setupLabel(&lab_om);
    mvolume = 70;
    svolume = 90;
    //Pausenmenü
    pm.setupUi(&lab_pm);    setupLabel(&lab_pm);
    //Color Picker
    cp1.setupUi(&lab_cp1);  setupLabel(&lab_cp1);
    cp2.setupUi(&lab_cp2);  setupLabel(&lab_cp2);
    //Guessturemenu
    gm.setupUi(&lab_gm);    setupLabel(&lab_gm);
    //Solutionmenu
    sm.setupUi(&lab_sm);    setupLabel(&lab_sm);
    //Solutionmenu
    rm.setupUi(&lab_rm);    setupLabel(&lab_rm);
    trm.setupUi(&lab_trm);  setupLabel(&lab_trm);

    //Für alle hinzugefügten Widgets verbinde sie signals/slots
    QMetaObject::connectSlotsByName(this);

    //Entferne alle Widgets wieder (waren nur für connectSlotsByName hinzugefügt)
    while(layout->count() > 0){
        //Entferne erstes Element
        QLayoutItem* li = layout->takeAt(0);
        //wenn es ein Widget ist
        QWidget* w = li->widget();
        if(w != NULL && w->parent() != NULL){
            //enterne den Pointer auf den Parent (sonst wird weiterhin draw aufgerufen!)
            w->setParent(NULL);
        }
    }

    //Öffne das Hauptmenü
    changeWidget(&lab_mm);

    //Schwarze Hintergrundfarbe
    setStyleSheet("background-color: black;");


    //setCursor(QCursor(Qt::ArrowCursor)); //Mauszeiger einschalten
    //setCursor(QCursor(Qt::BlankCursor)); //Kein Mauszeiger
}


GUI::~GUI(){}


void GUI::changeWidget(QWidget* newWidget){
    if(currentWidget != NULL){
        layout->removeWidget(currentWidget);
        if(currentWidget->parent() != NULL)
            currentWidget->setParent(NULL);
    }
    if(newWidget != NULL){
        layout->addWidget(newWidget);
    }
    previousWidget = currentWidget;
    currentWidget = newWidget;
}


void GUI::setupLabel(QLabel* lab){
    lab->setStyleSheet("background-color: none;");
    lab->setAlignment(Qt::AlignCenter);
    layout->addWidget(lab);
}


void GUI::imageResult(const cv::Mat& input){
    //umwandeln und an Widget übergeben
    ui.videoOutput->setImage(cvMatToQImage(input));
}

void GUI::debugImage(const cv::Mat& input){
    gm.debugimage->setImage(cvMatToQImage(input));
}


void GUI::keyPressEvent(QKeyEvent* e){
    qDebug() << "GUI::keyPress" << QThread::currentThreadId();
    //Wenn Esc gedrückt wurde
    if (e->key()==Qt::Key_Escape){
        //Musik ausfaden
        loopMusic(NULL);
        //Spiel beenden
        this->close();
    } else if(e->key()==Qt::Key_F5){
        //TODO: DEBUG
        emit guesstureRecognized();
    } else {
        emit keyPress(e->key());
    }
}


void GUI::mousePressEvent(QMouseEvent* e){
    emit mouseClicked();
    Q_UNUSED(e);
}

void GUI::loopMusic(const QString& filename){Music::Instance()->loopMusic(filename);}
void GUI::playSound(const QString& filename){Music::Instance()->playSound(filename);}


//Main Menu
void GUI::showMainMenu(){changeWidget(&lab_mm); emit quit();}
void GUI::on_butMainOptions_clicked(){changeWidget(&lab_om);}
void GUI::on_butMainExit_clicked(){loopMusic(NULL); this->close();}
void GUI::on_butMainStart_clicked(){showColorPicker1(); emit start();}

//Optionsmenü
void GUI::on_butOptionsOk_clicked(){
    //Optionen speichern
    mvolume = om.volumeMusicSlider->value();
    svolume = om.volumeSoundSlider->value();
    changeWidget(previousWidget);
}
void GUI::on_butOptionsCancel_clicked(){
    //Optionen rückgängig machen
    om.volumeMusicSlider->setValue(mvolume);
    om.volumeSoundSlider->setValue(svolume);
    changeWidget(previousWidget);
}
void GUI::on_volumeMusicSlider_valueChanged(int volume){
    Music::Instance()->setMVolume(volume);
}
void GUI::on_volumeSoundSlider_valueChanged(int volume){
    Music::Instance()->setSVolume(volume);
}

//Pausenmenü
void GUI::on_butPauseResume_clicked(){changeWidget(&lab_gm);}
void GUI::on_butPauseToMainMenu_clicked(){showMainMenu();}
void GUI::on_butPauseToOptions_clicked(){changeWidget(&lab_om);}
void GUI::on_butPauseSkip_clicked(){
    emit skipGuessture();
}

//Color Picker
void GUI::showColorPicker1(){changeWidget(&lab_cp1);}
void GUI::showColorPicker2(){changeWidget(&lab_cp2);}
void GUI::on_butColor1ToMainMenu_clicked(){showMainMenu();}
void GUI::on_butColor2ToMainMenu_clicked(){showMainMenu();}
void GUI::on_butColor2Yes_clicked(){emit keyPress(Qt::Key_Y);}
void GUI::on_butColor2No_clicked(){emit keyPress(Qt::Key_N);}

//Guessturemenu
void GUI::showGuesstureMenu(){
    gm.labHint1->setText("Hint 1: [hidden]");
    gm.labHint2->setText("Hint 2: [hidden]");
    gm.butGuesstureHint->setVisible(true);
    hint = 0;
    changeWidget(&lab_gm);
}
void GUI::on_butGuesstureHint_clicked(){
    QString h = GuesstureCollection::Instance()->current()->getHint();
    if(hint == 0) gm.labHint1->setText("Hint 1: "+h);
    else if(hint == 1){
        gm.labHint2->setText("Hint 2: "+h);
        gm.butGuesstureHint->setVisible(false);
    }
    hint++;
}
void GUI::on_butGuesstureToPauseMenu_clicked(){changeWidget(&lab_pm);}

//Solution Menu
void GUI::showSolutionMenu(Guessture* guessture){
    //Bild
    QPixmap img(imagesDir+guessture->getImageFile());
    img = img.scaled(400, 400, Qt::KeepAspectRatio);
    sm.imgSolution->setPixmap(img);
    //Name
    sm.labSolutionName->setText(guessture->getName());

    changeWidget(&lab_sm);
}
void GUI::on_butSolutionNext_clicked(){
    showRatingMenu(GuesstureCollection::Instance()->current());
    loopMusic(NULL);
}

//Rating Menu
void GUI::showRatingMenu(Guessture* guessture){
    //Grüner Stern
    QPixmap green(imagesDir+"greenstar.png");
    green = green.scaled(50, 50, Qt::KeepAspectRatio);
    //Roter Stern
    QPixmap red(imagesDir+"redstar.png");
    red = red.scaled(50, 50, Qt::KeepAspectRatio);
    //Sterne für Zeit
    int t = guessture->getTimeStars();
    rm.timeStar1->setPixmap(t >= 1 ? green : red);
    rm.timeStar2->setPixmap(t >= 2 ? green : red);
    rm.timeStar3->setPixmap(t >= 3 ? green : red);

    //Sterne für nicht benötigteTips
    int h = guessture->getHintStars();
    rm.hintStar1->setPixmap(h >= 1 ? green : red);
    rm.hintStar2->setPixmap(h >= 2 ? green : red);

    changeWidget(&lab_rm);
}
void GUI::on_butRatingNext_clicked(){emit nextGuessture();}
void GUI::on_butRatingToMainMenu_clicked(){showMainMenu();}

//Total Rating Menu
void GUI::showTotalRatingMenu(){
    //Grüner Stern
    QPixmap green(imagesDir+"greenstar.png");
    green = green.scaled(50, 50, Qt::KeepAspectRatio);
    //Roter Stern
    QPixmap red(imagesDir+"redstar.png");
    red = red.scaled(50, 50, Qt::KeepAspectRatio);

    int ts = 0;

    //Guesstures
    Guessture* g = GuesstureCollection::Instance()->item(0);
    int s = g->getStars();  ts += s;
    trm.s1_1->setPixmap(s >= 1 ? green : red );
    trm.s1_2->setPixmap(s >= 2 ? green : red );
    trm.s1_3->setPixmap(s >= 3 ? green : red );
    trm.s1_4->setPixmap(s >= 4 ? green : red );
    trm.s1_5->setPixmap(s >= 5 ? green : red );
    g = GuesstureCollection::Instance()->item(1);
    s = g->getStars();  ts += s;
    trm.s2_1->setPixmap(s >= 1 ? green : red );
    trm.s2_2->setPixmap(s >= 2 ? green : red );
    trm.s2_3->setPixmap(s >= 3 ? green : red );
    trm.s2_4->setPixmap(s >= 4 ? green : red );
    trm.s2_5->setPixmap(s >= 5 ? green : red );
    g = GuesstureCollection::Instance()->item(2);
    s = g->getStars();  ts += s;
    trm.s3_1->setPixmap(s >= 1 ? green : red );
    trm.s3_2->setPixmap(s >= 2 ? green : red );
    trm.s3_3->setPixmap(s >= 3 ? green : red );
    trm.s3_4->setPixmap(s >= 4 ? green : red );
    trm.s3_5->setPixmap(s >= 5 ? green : red );
    g = GuesstureCollection::Instance()->item(3);
    s = g->getStars();  ts += s;
    trm.s4_1->setPixmap(s >= 1 ? green : red );
    trm.s4_2->setPixmap(s >= 2 ? green : red );
    trm.s4_3->setPixmap(s >= 3 ? green : red );
    trm.s4_4->setPixmap(s >= 4 ? green : red );
    trm.s4_5->setPixmap(s >= 5 ? green : red );
    /*
    g = GuesstureCollection::Instance()->item(4);
    s = g->getStars();  ts += s;
    trm.s5_1->setPixmap(s >= 1 ? green : red );
    trm.s5_2->setPixmap(s >= 2 ? green : red );
    trm.s5_3->setPixmap(s >= 3 ? green : red );
    trm.s5_4->setPixmap(s >= 4 ? green : red );
    trm.s5_5->setPixmap(s >= 5 ? green : red );
    */
    trm.label_5->setVisible(false);

    trm.labTotalRating->setText(QString::number(ts)+" / 20 Stars");

    changeWidget(&lab_trm);
}
void GUI::on_butTotalRatingToMainMenu_clicked(){showMainMenu();}
