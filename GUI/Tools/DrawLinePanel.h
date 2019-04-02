#pragma once

#include <QWidget>
#include "GUI/Scene.h"
#include "ui_DrawLineWidget.h"
#include <QDialog>
#include <QMouseEvent>

namespace Ui {
	class DrawLinePanel;
}

class DrawLinePanel : public QWidget
{
	Q_OBJECT

public:
	DrawLinePanel();	

	Ui::DrawLineWidget drawWidget;

	Scene * activeScene;
	QSegMesh* activeObject();

	public slots:
	void setActiveScene(Scene * scene);



signals:
	void objectModified();

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	

	

private:
	QPixmap pix;
	QPoint lastPoint;
	QPoint endPoint;	
	
};

