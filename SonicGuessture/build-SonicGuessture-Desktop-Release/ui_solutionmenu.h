/********************************************************************************
** Form generated from reading UI file 'solutionmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTIONMENU_H
#define UI_SOLUTIONMENU_H

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

class Ui_WSolution
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *imgSolution;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labSolutionName;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *butSolutionNext;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WSolution)
    {
        if (WSolution->objectName().isEmpty())
            WSolution->setObjectName(QStringLiteral("WSolution"));
        WSolution->resize(468, 571);
        gridLayout = new QGridLayout(WSolution);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        imgSolution = new QLabel(WSolution);
        imgSolution->setObjectName(QStringLiteral("imgSolution"));
        imgSolution->setMinimumSize(QSize(400, 400));
        imgSolution->setMaximumSize(QSize(400, 400));

        horizontalLayout_5->addWidget(imgSolution);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        labSolutionName = new QLabel(WSolution);
        labSolutionName->setObjectName(QStringLiteral("labSolutionName"));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        labSolutionName->setFont(font);
        labSolutionName->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_3->addWidget(labSolutionName);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        butSolutionNext = new QPushButton(WSolution);
        butSolutionNext->setObjectName(QStringLiteral("butSolutionNext"));

        horizontalLayout_2->addWidget(butSolutionNext);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);


        retranslateUi(WSolution);

        QMetaObject::connectSlotsByName(WSolution);
    } // setupUi

    void retranslateUi(QWidget *WSolution)
    {
        WSolution->setWindowTitle(QApplication::translate("WSolution", "Form", 0));
        imgSolution->setText(QString());
        labSolutionName->setText(QApplication::translate("WSolution", "Guessture", 0));
        butSolutionNext->setText(QApplication::translate("WSolution", "Yay!", 0));
    } // retranslateUi

};

namespace Ui {
    class WSolution: public Ui_WSolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTIONMENU_H
