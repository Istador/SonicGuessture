#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QThread>
#include <QKeyEvent>
#include <QMouseEvent>
#include <guessture.h>

#include "ui_GUI.h"
#include "ui_mainmenu.h"
#include "ui_optionsmenu.h"
#include "ui_pausemenu.h"
#include "ui_colorpickmenu1.h"
#include "ui_colorpickmenu2.h"
#include "ui_guessturemenu.h"
#include "ui_solutionmenu.h"
#include "ui_ratingmenu.h"
#include "ui_totalratingmenu.h"

#include <opencv2/opencv.hpp>

namespace Ui { class MainWindow; }

class GUI : public QMainWindow {
Q_OBJECT

public:
    ~GUI();
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void showMainMenu();
    void showColorPicker1();
    void showColorPicker2();
    void showGuesstureMenu();
    void showSolutionMenu(Guessture* guessture);
    void showRatingMenu(Guessture* guessture);
    void showTotalRatingMenu();

private:
    Ui::MainWindow ui;
    QHBoxLayout* layout;
    QString imagesDir;

    //Hauptmenü
    Ui::WMainMenu mm;       QLabel lab_mm;
    //Optionsmenü
    Ui::WOptionsMenu om;    QLabel lab_om;
    int mvolume;
    int svolume;
    //Pausenmenü
    Ui::WPauseMenu pm;      QLabel lab_pm;
    //Color Picker
    Ui::WColorPick1 cp1;    QLabel lab_cp1;
    Ui::WColorPick2 cp2;    QLabel lab_cp2;
    //Guessturemenu
    Ui::WGuessture gm;      QLabel lab_gm;
    int hint;
    //Solutionmenu
    Ui::WSolution sm;       QLabel lab_sm;
    //Ratingmenu
    Ui::WRating rm;         QLabel lab_rm;
    Ui::WTotalRating trm;   QLabel lab_trm;

    QWidget* previousWidget;
    QWidget* currentWidget;
    void changeWidget(QWidget* newWidget);
    void setupLabel(QLabel* lab);

signals: //ausgehend
    void guesstureRecognized();
    void keyPress(const int&);
    void mouseClicked();
    void start();
    void quit();
    void nextGuessture();
    void skipGuessture();

public slots: //Eingehend
    void imageResult(const cv::Mat& image);
    void debugImage(const cv::Mat& image);
    void loopMusic(const QString& filename);
    void playSound(const QString& filename);

private slots:
    void on_butMainStart_clicked();
    void on_butMainOptions_clicked();
    void on_butMainExit_clicked();

    void on_butOptionsCancel_clicked();
    void on_butOptionsOk_clicked();
    void on_volumeMusicSlider_valueChanged(int volume);
    void on_volumeSoundSlider_valueChanged(int volume);

    void on_butPauseResume_clicked();
    void on_butPauseToOptions_clicked();
    void on_butPauseSkip_clicked();
    void on_butPauseToMainMenu_clicked();

    void on_butColor1ToMainMenu_clicked();
    void on_butColor2ToMainMenu_clicked();
    void on_butColor2Yes_clicked();
    void on_butColor2No_clicked();

    void on_butGuesstureToPauseMenu_clicked();
    void on_butGuesstureHint_clicked();

    void on_butRatingNext_clicked();
    void on_butRatingToMainMenu_clicked();


//###############################################
//###############################################
//### Singleton
    void on_butSolutionNext_clicked();

    void on_butTotalRatingToMainMenu_clicked();

public:
    static GUI* Instance();
private:
    explicit GUI(QWidget *parent = 0);
    static GUI* _instance;
//### Singleton
//###############################################
//###############################################
};

#endif // GUI_H
