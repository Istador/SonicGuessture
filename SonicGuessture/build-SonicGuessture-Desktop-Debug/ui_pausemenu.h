/********************************************************************************
** Form generated from reading UI file 'pausemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEMENU_H
#define UI_PAUSEMENU_H

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

class Ui_WPauseMenu
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *butPauseResume;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *butPauseToOptions;
    QPushButton *butPauseSkip;
    QPushButton *butPauseToMainMenu;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WPauseMenu)
    {
        if (WPauseMenu->objectName().isEmpty())
            WPauseMenu->setObjectName(QStringLiteral("WPauseMenu"));
        WPauseMenu->resize(400, 300);
        gridLayout = new QGridLayout(WPauseMenu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        butPauseResume = new QPushButton(WPauseMenu);
        butPauseResume->setObjectName(QStringLiteral("butPauseResume"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(butPauseResume->sizePolicy().hasHeightForWidth());
        butPauseResume->setSizePolicy(sizePolicy);
        butPauseResume->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(butPauseResume);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        title = new QLabel(WPauseMenu);
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

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        butPauseToOptions = new QPushButton(WPauseMenu);
        butPauseToOptions->setObjectName(QStringLiteral("butPauseToOptions"));
        butPauseToOptions->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(butPauseToOptions);

        butPauseSkip = new QPushButton(WPauseMenu);
        butPauseSkip->setObjectName(QStringLiteral("butPauseSkip"));

        verticalLayout_2->addWidget(butPauseSkip);

        butPauseToMainMenu = new QPushButton(WPauseMenu);
        butPauseToMainMenu->setObjectName(QStringLiteral("butPauseToMainMenu"));
        butPauseToMainMenu->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(butPauseToMainMenu);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WPauseMenu);

        QMetaObject::connectSlotsByName(WPauseMenu);
    } // setupUi

    void retranslateUi(QWidget *WPauseMenu)
    {
        WPauseMenu->setWindowTitle(QApplication::translate("WPauseMenu", "Form", 0));
        butPauseResume->setText(QApplication::translate("WPauseMenu", "X", 0));
        title->setText(QApplication::translate("WPauseMenu", "Pause", 0));
        butPauseToOptions->setText(QApplication::translate("WPauseMenu", "Options", 0));
        butPauseSkip->setText(QApplication::translate("WPauseMenu", "Skip Guessture", 0));
        butPauseToMainMenu->setText(QApplication::translate("WPauseMenu", "Main menu", 0));
    } // retranslateUi

};

namespace Ui {
    class WPauseMenu: public Ui_WPauseMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEMENU_H
