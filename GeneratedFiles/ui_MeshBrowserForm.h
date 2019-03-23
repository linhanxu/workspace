/********************************************************************************
** Form generated from reading UI file 'MeshBrowserForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHBROWSERFORM_H
#define UI_MESHBROWSERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshBrowserDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pathButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QWidget *thumbnailWidget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *thumbLayout;
    QScrollBar *scrollBar;
    QLabel *folderLabel;
    QFrame *line;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *MeshBrowserDialog)
    {
        if (MeshBrowserDialog->objectName().isEmpty())
            MeshBrowserDialog->setObjectName(QString::fromUtf8("MeshBrowserDialog"));
        MeshBrowserDialog->resize(542, 554);
        gridLayout = new QGridLayout(MeshBrowserDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pathButton = new QPushButton(MeshBrowserDialog);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));

        horizontalLayout_2->addWidget(pathButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(6);
#endif
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        okButton = new QPushButton(MeshBrowserDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(MeshBrowserDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        thumbnailWidget = new QWidget(MeshBrowserDialog);
        thumbnailWidget->setObjectName(QString::fromUtf8("thumbnailWidget"));
        thumbnailWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(thumbnailWidget);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        thumbLayout = new QGridLayout();
        thumbLayout->setSpacing(1);
        thumbLayout->setObjectName(QString::fromUtf8("thumbLayout"));

        horizontalLayout_3->addLayout(thumbLayout);

        scrollBar = new QScrollBar(thumbnailWidget);
        scrollBar->setObjectName(QString::fromUtf8("scrollBar"));
        scrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(scrollBar);


        gridLayout_2->addWidget(thumbnailWidget, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 2);

        folderLabel = new QLabel(MeshBrowserDialog);
        folderLabel->setObjectName(QString::fromUtf8("folderLabel"));
        folderLabel->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(folderLabel, 0, 0, 1, 1);

        line = new QFrame(MeshBrowserDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(MeshBrowserDialog);
        QObject::connect(okButton, SIGNAL(clicked()), MeshBrowserDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MeshBrowserDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MeshBrowserDialog);
    } // setupUi

    void retranslateUi(QDialog *MeshBrowserDialog)
    {
        MeshBrowserDialog->setWindowTitle(QApplication::translate("MeshBrowserDialog", "Mesh Browser", nullptr));
        pathButton->setText(QApplication::translate("MeshBrowserDialog", "Browse..", nullptr));
        okButton->setText(QApplication::translate("MeshBrowserDialog", "Open", nullptr));
        cancelButton->setText(QApplication::translate("MeshBrowserDialog", "Cancel", nullptr));
        folderLabel->setText(QApplication::translate("MeshBrowserDialog", "C:\\", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeshBrowserDialog: public Ui_MeshBrowserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHBROWSERFORM_H
