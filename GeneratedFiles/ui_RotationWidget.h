/********************************************************************************
** Form generated from reading UI file 'RotationWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATIONWIDGET_H
#define UI_ROTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RotationWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *xAngle;
    QPushButton *rotateButton;
    QDoubleSpinBox *zAngle;
    QDoubleSpinBox *yAngle;

    void setupUi(QWidget *RotationWidget)
    {
        if (RotationWidget->objectName().isEmpty())
            RotationWidget->setObjectName(QString::fromUtf8("RotationWidget"));
        RotationWidget->resize(227, 100);
        gridLayout = new QGridLayout(RotationWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(RotationWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        xAngle = new QDoubleSpinBox(groupBox);
        xAngle->setObjectName(QString::fromUtf8("xAngle"));
        xAngle->setMinimum(-180.000000000000000);
        xAngle->setMaximum(180.000000000000000);
        xAngle->setSingleStep(10.000000000000000);

        gridLayout_2->addWidget(xAngle, 1, 0, 1, 1);

        rotateButton = new QPushButton(groupBox);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));

        gridLayout_2->addWidget(rotateButton, 2, 0, 1, 3);

        zAngle = new QDoubleSpinBox(groupBox);
        zAngle->setObjectName(QString::fromUtf8("zAngle"));
        zAngle->setMinimum(-180.000000000000000);
        zAngle->setMaximum(180.000000000000000);
        zAngle->setSingleStep(10.000000000000000);

        gridLayout_2->addWidget(zAngle, 1, 2, 1, 1);

        yAngle = new QDoubleSpinBox(groupBox);
        yAngle->setObjectName(QString::fromUtf8("yAngle"));
        yAngle->setMinimum(-180.000000000000000);
        yAngle->setMaximum(180.000000000000000);
        yAngle->setSingleStep(10.000000000000000);

        gridLayout_2->addWidget(yAngle, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 2, 1, 1);


        retranslateUi(RotationWidget);

        QMetaObject::connectSlotsByName(RotationWidget);
    } // setupUi

    void retranslateUi(QWidget *RotationWidget)
    {
        RotationWidget->setWindowTitle(QApplication::translate("RotationWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("RotationWidget", "Rotations in degrees", nullptr));
        rotateButton->setText(QApplication::translate("RotationWidget", "Rotate..", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RotationWidget: public Ui_RotationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATIONWIDGET_H
