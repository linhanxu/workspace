#include "global.h"
#include "Workspace.h"
#include <QVBoxLayout>
#include <QFileInfo>

Workspace::Workspace(QWidget *parent, Qt::WindowFlags flags)	: QMainWindow(parent, flags)
{
	activeScene = NULL;
	sceneCount = 0;

	ui.setupUi(this);

	
	QVBoxLayout * rightLayout = (QVBoxLayout *) ui.rightDockWidget->layout();

	tf = new TransformationPanel();
	rightLayout->addWidget(tf);
	
	mi = new MeshInfoPanel();
	rightLayout->addWidget(mi);

	dl = new DrawLinePanel();
	rightLayout->addWidget(dl);

	// Create mesh document manager
	mDoc = new QMeshDoc(this);

	// Connect to mesh management
	connect(ui.actionImportObject, SIGNAL(triggered()), mDoc, SLOT(importObject()));

	// Connect to mesh browser
	connect(ui.actionMeshBrowser, SIGNAL(triggered()), mDoc, SLOT(importObjectBrowser()));

	// Add new scene action
	connect(ui.actionNewScene, SIGNAL(triggered()), SLOT(addNewScene()));

	
	rightLayout->addStretch();
}

Workspace::~Workspace()
{
	
}

void Workspace::addNewScene()
{
	Scene * newScene = new Scene(this);

	ui.sceneArea->addSubWindow(newScene)->show();
	sceneCount++;

	newScene->showMaximized();
	newScene->setWindowTitle("Untitled");

	// Workspace window
	connect(newScene, SIGNAL(gotFocus(Scene*)), SLOT(setActiveScene(Scene*)));
	connect(newScene, SIGNAL(lostFocus(Scene*)), SLOT(disconnectScene(Scene*)));
	connect(newScene, SIGNAL(sceneClosed(Scene*)), SLOT(sceneClosed(Scene*)));

	// MeshDoc
	connect(newScene, SIGNAL(objectDiscarded(QString)), mDoc, SLOT(deleteObject(QString)));

	// Object transformation
	connect(newScene, SIGNAL(gotFocus(Scene*)), tf, SLOT(setActiveScene(Scene*)));
	connect(tf, SIGNAL(objectModified()), newScene, SLOT(updateActiveObject()));

	// Object info panel
	connect(newScene, SIGNAL(gotFocus(Scene*)), mi, SLOT(setActiveScene(Scene*)));

	// Object drawLine panel自己添加的
	connect(newScene, SIGNAL(gotFocus(Scene*)), dl, SLOT(setActiveScene(Scene*)));

	setActiveScene(newScene);
}

void Workspace::setActiveScene(Scene* scene)
{
	QString title = QString("%1").arg(QFileInfo(QApplication::applicationFilePath()).baseName());
	
	activeScene = scene;

	if(activeScene)
	{
		// View operations
		connect(ui.actionCameraProjection, SIGNAL(triggered()), activeScene, SLOT(toggleCameraProjection()), Qt::UniqueConnection);
	
		// Connect mDoc
		activeScene->connect(ui.actionExportObject, SIGNAL(triggered()), SLOT(exportActiveObject()), Qt::UniqueConnection);
		activeScene->connect(mDoc, SIGNAL(objectImported(QSegMesh*)), SLOT(setActiveObject(QSegMesh*)), Qt::UniqueConnection);
		activeScene->connect(mDoc, SIGNAL(printMessage(QString)), SLOT(print(QString)), Qt::UniqueConnection);
		mDoc->connect(activeScene, SIGNAL(exportActiveObject(QSegMesh*)), SLOT(exportObject(QSegMesh*)), Qt::UniqueConnection);

		title += QString(" - %2").arg(scene->windowTitle());
	}

	// Set active scene
	tf->setActiveScene(activeScene);
	mi->setActiveScene(activeScene);
	dl->setActiveScene(activeScene);

	this->setWindowTitle(title);
}

void Workspace::disconnectScene(Scene* scene)
{
	mDoc->disconnect();
	ui.actionCameraProjection->disconnect();
}

void Workspace::sceneClosed( Scene* scene )
{
	int count = ui.sceneArea->subWindowList().size() - 1;

	if(count == 0)
	{
		setActiveScene(activeScene = NULL);
		printf("No scenes! %d\n", count);
	}
}
