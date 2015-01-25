/********************************************************************************
** Form generated from reading UI file 'optionsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSMENU_H
#define UI_OPTIONSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WOptionsMenu
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lab_musicvolume;
    QSlider *volumeMusicSlider;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lab_soundvolume;
    QSlider *volumeSoundSlider;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *butOptionsCancel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *butOptionsOk;

    void setupUi(QWidget *WOptionsMenu)
    {
        if (WOptionsMenu->objectName().isEmpty())
            WOptionsMenu->setObjectName(QStringLiteral("WOptionsMenu"));
        WOptionsMenu->resize(400, 300);
        gridLayout = new QGridLayout(WOptionsMenu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        title = new QLabel(WOptionsMenu);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout->addWidget(title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lab_musicvolume = new QLabel(WOptionsMenu);
        lab_musicvolume->setObjectName(QStringLiteral("lab_musicvolume"));
        lab_musicvolume->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_2->addWidget(lab_musicvolume);

        volumeMusicSlider = new QSlider(WOptionsMenu);
        volumeMusicSlider->setObjectName(QStringLiteral("volumeMusicSlider"));
        volumeMusicSlider->setMinimum(1);
        volumeMusicSlider->setMaximum(100);
        volumeMusicSlider->setValue(70);
        volumeMusicSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volumeMusicSlider);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        lab_soundvolume = new QLabel(WOptionsMenu);
        lab_soundvolume->setObjectName(QStringLiteral("lab_soundvolume"));
        lab_soundvolume->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_3->addWidget(lab_soundvolume);

        volumeSoundSlider = new QSlider(WOptionsMenu);
        volumeSoundSlider->setObjectName(QStringLiteral("volumeSoundSlider"));
        volumeSoundSlider->setMinimum(1);
        volumeSoundSlider->setMaximum(100);
        volumeSoundSlider->setValue(90);
        volumeSoundSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeSoundSlider);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        butOptionsCancel = new QPushButton(WOptionsMenu);
        butOptionsCancel->setObjectName(QStringLiteral("butOptionsCancel"));

        horizontalLayout_4->addWidget(butOptionsCancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        butOptionsOk = new QPushButton(WOptionsMenu);
        butOptionsOk->setObjectName(QStringLiteral("butOptionsOk"));

        horizontalLayout_4->addWidget(butOptionsOk);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WOptionsMenu);

        QMetaObject::connectSlotsByName(WOptionsMenu);
    } // setupUi

    void retranslateUi(QWidget *WOptionsMenu)
    {
        WOptionsMenu->setWindowTitle(QApplication::translate("WOptionsMenu", "Form", 0));
        title->setText(QApplication::translate("WOptionsMenu", "Options", 0));
        lab_musicvolume->setText(QApplication::translate("WOptionsMenu", "Music Volume", 0));
        lab_soundvolume->setText(QApplication::translate("WOptionsMenu", "Sound Volume", 0));
        butOptionsCancel->setText(QApplication::translate("WOptionsMenu", "Cancel", 0));
        butOptionsOk->setText(QApplication::translate("WOptionsMenu", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class WOptionsMenu: public Ui_WOptionsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSMENU_H
