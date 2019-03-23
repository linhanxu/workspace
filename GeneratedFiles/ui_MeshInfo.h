/********************************************************************************
** Form generated from reading UI file 'MeshInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHINFO_H
#define UI_MESHINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshInfoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *numVertices;
    QLabel *label;
    QLabel *numFaces;
    QLabel *label_2;

    void setupUi(QWidget *MeshInfoWidget)
    {
        if (MeshInfoWidget->objectName().isEmpty())
            MeshInfoWidget->setObjectName(QString::fromUtf8("MeshInfoWidget"));
        MeshInfoWidget->resize(189, 102);
        verticalLayout = new QVBoxLayout(MeshInfoWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MeshInfoWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        numVertices = new QLabel(groupBox);
        numVertices->setObjectName(QString::fromUtf8("numVertices"));

        gridLayout->addWidget(numVertices, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        numFaces = new QLabel(groupBox);
        numFaces->setObjectName(QString::fromUtf8("numFaces"));

        gridLayout->addWidget(numFaces, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        retranslateUi(MeshInfoWidget);

        QMetaObject::connectSlotsByName(MeshInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *MeshInfoWidget)
    {
        MeshInfoWidget->setWindowTitle(QApplication::translate("MeshInfoWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("MeshInfoWidget", "Mesh Info", nullptr));
        numVertices->setText(QApplication::translate("MeshInfoWidget", "0", nullptr));
        label->setText(QApplication::translate("MeshInfoWidget", "Vertices", nullptr));
        numFaces->setText(QApplication::translate("MeshInfoWidget", "0", nullptr));
        label_2->setText(QApplication::translate("MeshInfoWidget", "Faces", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeshInfoWidget: public Ui_MeshInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHINFO_H
