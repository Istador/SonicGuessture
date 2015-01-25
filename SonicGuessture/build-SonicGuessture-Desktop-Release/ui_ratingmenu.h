/********************************************************************************
** Form generated from reading UI file 'ratingmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATINGMENU_H
#define UI_RATINGMENU_H

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

class Ui_WRating
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *timeStar1;
    QLabel *timeStar2;
    QLabel *timeStar3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *hintStar1;
    QLabel *hintStar2;
    QLabel *hintStar3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *butRatingToMainMenu;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *butRatingNext;

    void setupUi(QWidget *WRating)
    {
        if (WRating->objectName().isEmpty())
            WRating->setObjectName(QStringLiteral("WRating"));
        WRating->resize(400, 300);
        gridLayout = new QGridLayout(WRating);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        title = new QLabel(WRating);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label = new QLabel(WRating);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        timeStar1 = new QLabel(WRating);
        timeStar1->setObjectName(QStringLiteral("timeStar1"));
        timeStar1->setMinimumSize(QSize(50, 50));
        timeStar1->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(timeStar1);

        timeStar2 = new QLabel(WRating);
        timeStar2->setObjectName(QStringLiteral("timeStar2"));
        timeStar2->setMinimumSize(QSize(50, 50));
        timeStar2->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(timeStar2);

        timeStar3 = new QLabel(WRating);
        timeStar3->setObjectName(QStringLiteral("timeStar3"));
        timeStar3->setMinimumSize(QSize(50, 50));
        timeStar3->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(timeStar3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_2 = new QLabel(WRating);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        hintStar1 = new QLabel(WRating);
        hintStar1->setObjectName(QStringLiteral("hintStar1"));
        hintStar1->setMinimumSize(QSize(50, 50));
        hintStar1->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(hintStar1);

        hintStar2 = new QLabel(WRating);
        hintStar2->setObjectName(QStringLiteral("hintStar2"));
        hintStar2->setMinimumSize(QSize(50, 50));
        hintStar2->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(hintStar2);

        hintStar3 = new QLabel(WRating);
        hintStar3->setObjectName(QStringLiteral("hintStar3"));
        hintStar3->setEnabled(false);
        hintStar3->setMinimumSize(QSize(50, 50));
        hintStar3->setMaximumSize(QSize(50, 50));

        horizontalLayout_4->addWidget(hintStar3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        butRatingToMainMenu = new QPushButton(WRating);
        butRatingToMainMenu->setObjectName(QStringLiteral("butRatingToMainMenu"));

        horizontalLayout_2->addWidget(butRatingToMainMenu);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        butRatingNext = new QPushButton(WRating);
        butRatingNext->setObjectName(QStringLiteral("butRatingNext"));

        horizontalLayout_2->addWidget(butRatingNext);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WRating);

        QMetaObject::connectSlotsByName(WRating);
    } // setupUi

    void retranslateUi(QWidget *WRating)
    {
        WRating->setWindowTitle(QApplication::translate("WRating", "Form", 0));
        title->setText(QApplication::translate("WRating", "Rating", 0));
        label->setText(QApplication::translate("WRating", "Time", 0));
        timeStar1->setText(QString());
        timeStar2->setText(QString());
        timeStar3->setText(QString());
        label_2->setText(QApplication::translate("WRating", "Hints", 0));
        hintStar1->setText(QString());
        hintStar2->setText(QString());
        hintStar3->setText(QString());
        butRatingToMainMenu->setText(QApplication::translate("WRating", "Main menu", 0));
        butRatingNext->setText(QApplication::translate("WRating", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class WRating: public Ui_WRating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATINGMENU_H
