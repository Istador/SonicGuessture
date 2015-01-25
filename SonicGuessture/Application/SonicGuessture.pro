#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T11:09:02
#
#-------------------------------------------------

QT       += core gui widgets multimedia

TARGET   = SonicGuessture
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += gnu++11

QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app

HEADERS  += videowidget.h \
    cvmattoqimage.h \
    mediator.h \
    music.h \
    gui.h \
    camera.h \
    colorpicker.h \
    util.h \
    guessture.h \
    guessturecollection.h \
    guesstures/gvulcansalute.h \
    guesstures/gvictory.h \
    guesstures/gtriforce.h \
    guesstures/gnoise.h \
    guesstures/gclap.h \
    shapes/shape.h \
    shapes/line.h \
    shapes/lineseq.h \
    shapes/complement.h \
    shapes/union.h \
    colorkeyer.h \
    analyser.h

SOURCES  += videowidget.cpp \
    main.cpp \
    mediator.cpp \
    music.cpp \
    gui.cpp \
    camera.cpp \
    colorpicker.cpp \
    guessture.cpp \
    guessturecollection.cpp \
    guesstures/gvulcansalute.cpp \
    guesstures/gvictory.cpp \
    guesstures/gtriforce.cpp \
    guesstures/gnoise.cpp \
    guesstures/gclap.cpp \
    shapes/shape.cpp \
    shapes/line.cpp \
    shapes/lineseq.cpp \
    shapes/complement.cpp \
    shapes/union.cpp \
    colorkeyer.cpp \
    analyser.cpp \
    util.cpp


FORMS    += GUI.ui \
    mainmenu.ui \
    optionsmenu.ui \
    pausemenu.ui \
    colorpickmenu1.ui \
    colorpickmenu2.ui \
    guessturemenu.ui \
    solutionmenu.ui \
    ratingmenu.ui \
    totalratingmenu.ui

include(opencv.pri)
