/********************************************************************************
** Form generated from reading UI file 'guessturemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESSTUREMENU_H
#define UI_GUESSTUREMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <videowidget.h>

QT_BEGIN_NAMESPACE

class Ui_WGuessture
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *butGuesstureToPauseMenu;
    QHBoxLayout *horizontalLayout_3;
    VideoWidget *debugimage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labHint1;
    QLabel *labHint2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *butGuesstureHint;

    void setupUi(QWidget *WGuessture)
    {
        if (WGuessture->objectName().isEmpty())
            WGuessture->setObjectName(QStringLiteral("WGuessture"));
        WGuessture->resize(434, 378);
        gridLayout = new QGridLayout(WGuessture);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        butGuesstureToPauseMenu = new QPushButton(WGuessture);
        butGuesstureToPauseMenu->setObjectName(QStringLiteral("butGuesstureToPauseMenu"));
        butGuesstureToPauseMenu->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(butGuesstureToPauseMenu);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        debugimage = new VideoWidget(WGuessture);
        debugimage->setObjectName(QStringLiteral("debugimage"));
        debugimage->setMinimumSize(QSize(200, 200));
        debugimage->setMaximumSize(QSize(200, 200));
        debugimage->setScaledContents(false);
        debugimage->setAlignment(Qt::AlignCenter);
        debugimage->setAutoFillBackground(false);
        debugimage->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(debugimage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labHint1 = new QLabel(WGuessture);
        labHint1->setObjectName(QStringLiteral("labHint1"));
        labHint1->setStyleSheet(QStringLiteral("color: red;"));

        verticalLayout_2->addWidget(labHint1);

        labHint2 = new QLabel(WGuessture);
        labHint2->setObjectName(QStringLiteral("labHint2"));
        labHint2->setStyleSheet(QStringLiteral("color: red;"));

        verticalLayout_2->addWidget(labHint2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        butGuesstureHint = new QPushButton(WGuessture);
        butGuesstureHint->setObjectName(QStringLiteral("butGuesstureHint"));

        horizontalLayout_2->addWidget(butGuesstureHint);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WGuessture);

        QMetaObject::connectSlotsByName(WGuessture);
    } // setupUi

    void retranslateUi(QWidget *WGuessture)
    {
        WGuessture->setWindowTitle(QApplication::translate("WGuessture", "Form", 0));
        butGuesstureToPauseMenu->setText(QApplication::translate("WGuessture", "X", 0));
        debugimage->setText(QString());
        labHint1->setText(QApplication::translate("WGuessture", "Hint 1: [hidden]", 0));
        labHint2->setText(QApplication::translate("WGuessture", "Hint 2: [hidden]", 0));
        butGuesstureHint->setText(QApplication::translate("WGuessture", "Hint", 0));
    } // retranslateUi

};

namespace Ui {
    class WGuessture: public Ui_WGuessture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESSTUREMENU_H
