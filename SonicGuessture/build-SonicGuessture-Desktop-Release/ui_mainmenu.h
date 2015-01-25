/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

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

QT_BEGIN_NAMESPACE

class Ui_WMainMenu
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *title;
    QSpacerItem *verticalSpacer_3;
    QPushButton *butMainStart;
    QPushButton *butMainOptions;
    QPushButton *butMainExit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WMainMenu)
    {
        if (WMainMenu->objectName().isEmpty())
            WMainMenu->setObjectName(QStringLiteral("WMainMenu"));
        WMainMenu->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WMainMenu->sizePolicy().hasHeightForWidth());
        WMainMenu->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WMainMenu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        title = new QLabel(WMainMenu);
        title->setObjectName(QStringLiteral("title"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(204, 204, 204, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        title->setPalette(palette);
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setStyleSheet(QStringLiteral("color: red;"));

        verticalLayout->addWidget(title);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        butMainStart = new QPushButton(WMainMenu);
        butMainStart->setObjectName(QStringLiteral("butMainStart"));
        butMainStart->setMinimumSize(QSize(200, 0));

        verticalLayout->addWidget(butMainStart);

        butMainOptions = new QPushButton(WMainMenu);
        butMainOptions->setObjectName(QStringLiteral("butMainOptions"));
        butMainOptions->setMinimumSize(QSize(200, 0));

        verticalLayout->addWidget(butMainOptions);

        butMainExit = new QPushButton(WMainMenu);
        butMainExit->setObjectName(QStringLiteral("butMainExit"));
        butMainExit->setMinimumSize(QSize(200, 0));

        verticalLayout->addWidget(butMainExit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(WMainMenu);

        QMetaObject::connectSlotsByName(WMainMenu);
    } // setupUi

    void retranslateUi(QWidget *WMainMenu)
    {
        WMainMenu->setWindowTitle(QApplication::translate("WMainMenu", "Form", 0));
        title->setText(QApplication::translate("WMainMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">Sonic Guessture</span></p></body></html>", 0));
        butMainStart->setText(QApplication::translate("WMainMenu", "Start", 0));
        butMainOptions->setText(QApplication::translate("WMainMenu", "Options", 0));
        butMainExit->setText(QApplication::translate("WMainMenu", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class WMainMenu: public Ui_WMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
