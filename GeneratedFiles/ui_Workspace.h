/********************************************************************************
** Form generated from reading UI file 'Workspace.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSPACE_H
#define UI_WORKSPACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkspaceClass
{
public:
    QAction *actionExit;
    QAction *actionNewScene;
    QAction *actionImportObject;
    QAction *actionExportObject;
    QAction *actionCameraProjection;
    QAction *actionMeshBrowser;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *sceneArea;
    QToolBar *mainToolBar;
    QDockWidget *rightDock;
    QWidget *rightDockWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *WorkspaceClass)
    {
        if (WorkspaceClass->objectName().isEmpty())
            WorkspaceClass->setObjectName(QString::fromUtf8("WorkspaceClass"));
        WorkspaceClass->setWindowModality(Qt::ApplicationModal);
        WorkspaceClass->resize(1015, 671);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Workspace/Resources/icons/AppIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        WorkspaceClass->setWindowIcon(icon);
        WorkspaceClass->setDocumentMode(false);
        actionExit = new QAction(WorkspaceClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNewScene = new QAction(WorkspaceClass);
        actionNewScene->setObjectName(QString::fromUtf8("actionNewScene"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Workspace/Resources/icons/newScene.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewScene->setIcon(icon1);
        actionImportObject = new QAction(WorkspaceClass);
        actionImportObject->setObjectName(QString::fromUtf8("actionImportObject"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Workspace/Resources/icons/insertObject.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImportObject->setIcon(icon2);
        actionExportObject = new QAction(WorkspaceClass);
        actionExportObject->setObjectName(QString::fromUtf8("actionExportObject"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Workspace/Resources/icons/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportObject->setIcon(icon3);
        actionCameraProjection = new QAction(WorkspaceClass);
        actionCameraProjection->setObjectName(QString::fromUtf8("actionCameraProjection"));
        actionMeshBrowser = new QAction(WorkspaceClass);
        actionMeshBrowser->setObjectName(QString::fromUtf8("actionMeshBrowser"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Workspace/Resources/icons/browse.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionMeshBrowser->setIcon(icon4);
        centralWidget = new QWidget(WorkspaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sceneArea = new QMdiArea(centralWidget);
        sceneArea->setObjectName(QString::fromUtf8("sceneArea"));

        verticalLayout->addWidget(sceneArea);

        WorkspaceClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(WorkspaceClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        WorkspaceClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        rightDock = new QDockWidget(WorkspaceClass);
        rightDock->setObjectName(QString::fromUtf8("rightDock"));
        rightDockWidget = new QWidget();
        rightDockWidget->setObjectName(QString::fromUtf8("rightDockWidget"));
        verticalLayout_2 = new QVBoxLayout(rightDockWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rightDock->setWidget(rightDockWidget);
        WorkspaceClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), rightDock);

        mainToolBar->addAction(actionNewScene);
        mainToolBar->addAction(actionMeshBrowser);
        mainToolBar->addAction(actionImportObject);

        retranslateUi(WorkspaceClass);
        QObject::connect(actionExit, SIGNAL(triggered()), WorkspaceClass, SLOT(close()));

        QMetaObject::connectSlotsByName(WorkspaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *WorkspaceClass)
    {
        WorkspaceClass->setWindowTitle(QApplication::translate("WorkspaceClass", "Workspace", nullptr));
        actionExit->setText(QApplication::translate("WorkspaceClass", "Exit", nullptr));
        actionNewScene->setText(QApplication::translate("WorkspaceClass", "New scene", nullptr));
        actionImportObject->setText(QApplication::translate("WorkspaceClass", "Import object", nullptr));
#ifndef QT_NO_TOOLTIP
        actionImportObject->setToolTip(QApplication::translate("WorkspaceClass", "Import object", nullptr));
#endif // QT_NO_TOOLTIP
        actionExportObject->setText(QApplication::translate("WorkspaceClass", "Export object", nullptr));
        actionCameraProjection->setText(QApplication::translate("WorkspaceClass", "Change camera projection", nullptr));
        actionMeshBrowser->setText(QApplication::translate("WorkspaceClass", "Mesh Browser", nullptr));
        mainToolBar->setWindowTitle(QApplication::translate("WorkspaceClass", "Main Toolbar", nullptr));
        rightDock->setWindowTitle(QApplication::translate("WorkspaceClass", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkspaceClass: public Ui_WorkspaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSPACE_H
