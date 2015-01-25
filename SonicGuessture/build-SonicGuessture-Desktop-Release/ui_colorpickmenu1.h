/********************************************************************************
** Form generated from reading UI file 'colorpickmenu1.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKMENU1_H
#define UI_COLORPICKMENU1_H

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

class Ui_WColorPick1
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *butColor1ToMainMenu;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WColorPick1)
    {
        if (WColorPick1->objectName().isEmpty())
            WColorPick1->setObjectName(QStringLiteral("WColorPick1"));
        WColorPick1->resize(346, 265);
        gridLayout = new QGridLayout(WColorPick1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(WColorPick1);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        butColor1ToMainMenu = new QPushButton(WColorPick1);
        butColor1ToMainMenu->setObjectName(QStringLiteral("butColor1ToMainMenu"));
        butColor1ToMainMenu->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(butColor1ToMainMenu);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WColorPick1);

        QMetaObject::connectSlotsByName(WColorPick1);
    } // setupUi

    void retranslateUi(QWidget *WColorPick1)
    {
        WColorPick1->setWindowTitle(QApplication::translate("WColorPick1", "Form", 0));
        label->setText(QApplication::translate("WColorPick1", "Choose your skin color", 0));
        butColor1ToMainMenu->setText(QApplication::translate("WColorPick1", "X", 0));
    } // retranslateUi

};

namespace Ui {
    class WColorPick1: public Ui_WColorPick1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKMENU1_H
