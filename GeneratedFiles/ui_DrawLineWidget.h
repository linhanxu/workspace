/********************************************************************************
** Form generated from reading UI file 'DrawLineWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWLINEWIDGET_H
#define UI_DRAWLINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawLineWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *DrawLineWidget)
    {
        if (DrawLineWidget->objectName().isEmpty())
            DrawLineWidget->setObjectName(QString::fromUtf8("DrawLineWidget"));
        DrawLineWidget->resize(400, 400);
        horizontalLayout = new QHBoxLayout(DrawLineWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(DrawLineWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 6, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 7, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 8, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(DrawLineWidget);

        QMetaObject::connectSlotsByName(DrawLineWidget);
    } // setupUi

    void retranslateUi(QWidget *DrawLineWidget)
    {
        DrawLineWidget->setWindowTitle(QApplication::translate("DrawLineWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("DrawLineWidget", "Draw line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawLineWidget: public Ui_DrawLineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWLINEWIDGET_H
