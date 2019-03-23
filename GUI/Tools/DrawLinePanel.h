#pragma once

#include <QWidget>
#ifndef DrawLinePanel_H
#define DrawLinePanel_H

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
	~DrawLinePanel();


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
	void clearPaint();

	

private:
	QPixmap pix;
	QPoint lastPoint;
	QPoint endPoint;
	QPushButton *drawButton;
	QPushButton *clearButton;
};

#endif // DrawLinePanel_H

