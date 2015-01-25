/********************************************************************************
** Form generated from reading UI file 'colorpickmenu2.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORPICKMENU2_H
#define UI_COLORPICKMENU2_H

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

class Ui_WColorPick2
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *butColor2ToMainMenu;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *butColor2No;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *butColor2Yes;

    void setupUi(QWidget *WColorPick2)
    {
        if (WColorPick2->objectName().isEmpty())
            WColorPick2->setObjectName(QStringLiteral("WColorPick2"));
        WColorPick2->resize(400, 300);
        gridLayout = new QGridLayout(WColorPick2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(WColorPick2);
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

        butColor2ToMainMenu = new QPushButton(WColorPick2);
        butColor2ToMainMenu->setObjectName(QStringLiteral("butColor2ToMainMenu"));
        butColor2ToMainMenu->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(butColor2ToMainMenu);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        butColor2No = new QPushButton(WColorPick2);
        butColor2No->setObjectName(QStringLiteral("butColor2No"));

        horizontalLayout_2->addWidget(butColor2No);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        butColor2Yes = new QPushButton(WColorPick2);
        butColor2Yes->setObjectName(QStringLiteral("butColor2Yes"));

        horizontalLayout_2->addWidget(butColor2Yes);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WColorPick2);

        QMetaObject::connectSlotsByName(WColorPick2);
    } // setupUi

    void retranslateUi(QWidget *WColorPick2)
    {
        WColorPick2->setWindowTitle(QApplication::translate("WColorPick2", "Form", 0));
        label->setText(QApplication::translate("WColorPick2", "Ok?", 0));
        butColor2ToMainMenu->setText(QApplication::translate("WColorPick2", "X", 0));
        butColor2No->setText(QApplication::translate("WColorPick2", "No", 0));
        butColor2Yes->setText(QApplication::translate("WColorPick2", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class WColorPick2: public Ui_WColorPick2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORPICKMENU2_H
