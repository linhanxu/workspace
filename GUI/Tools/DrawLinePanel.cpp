#include "DrawLinePanel.h"
#include "GUI/global.h"
#include <vector>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
using namespace std;



DrawLinePanel::DrawLinePanel()
{
	drawWidget.setupUi(this);
	//resize(200, 200);    //窗口大小设置
	pix = QPixmap(width(), height());//画布大小设置，背景为透明色
	pix.fill(Qt::transparent);		
}
void DrawLinePanel::setActiveScene(Scene * scene)
{
	if (activeScene != scene)
		activeScene = scene;
}
QSegMesh* DrawLinePanel::activeObject()
{
	if (activeScene)
		return activeScene->activeObject();
	else
		return NULL;
}

//paintEvent函数不需要手动调用，系统会自动调用
void DrawLinePanel::paintEvent(QPaintEvent *)
{
	QPainter painter(this);//往this上画，即DrawLinePanel，painter是网格		 
			
	painter.drawPixmap(0, 0, pix);//在(0,0)处绘制画布	
	painter.setRenderHint(QPainter::Antialiasing,true);
	painter.setWindow(-0.5*width(), -0.5*height(), width(), height());//painter的逻辑绘图区域，左上角为(-0.5*width(),-0.5*height())，右下角为(width(), height())
	//painter.drawPoint(QPointF(0, 0));//画出坐标原点（0,0）位置
	//输入降维后的五个点，生成的三角剖分后的每个三角形
	extern vector<vector<vector<float>>> d_triangles;
	double multiple = 0.5* height();
	for (int index=0; index < d_triangles.size(); index++)
	{
		float x1 = d_triangles[index][0][0] * multiple; float y1 = -(d_triangles[index][0][1] * multiple) ;
		float x2 = d_triangles[index][1][0] * multiple; float y2 = -(d_triangles[index][1][1] * multiple);
		float x3 = d_triangles[index][2][0] * multiple; float y3 = -(d_triangles[index][2][1] * multiple);
		QPointF points[3] = {
			QPointF(x1 , y1),
			QPointF(x2 , y2),
			QPointF(x3 , y3),
		};
		painter.drawPolygon(points, 3);
		//细分三角剖分后的每个三角形
		double x11 = x1 + (x2 - x1)*0.25 * 1, y11 = y1 + (y2 - y1)*0.25 * 1, x12 = x1 + (x2 - x1)*0.25 * 2, y12 = y1 + (y2 - y1)*0.25 * 2, x13 = x1 + (x2 - x1)*0.25 * 3, y13 = y1 + (y2 - y1)*0.25 * 3;
		double x21 = x2 + (x3 - x2)*0.25 * 1, y21 = y2 + (y3 - y2)*0.25 * 1, x22 = x2 + (x3 - x2)*0.25 * 2, y22 = y2 + (y3 - y2)*0.25 * 2, x23 = x2 + (x3 - x2)*0.25 * 3, y23 = y2 + (y3 - y2)*0.25 * 3;
		double x31 = x3 + (x1 - x3)*0.25 * 1, y31 = y3 + (y1 - y3)*0.25 * 1, x32 = x3 + (x1 - x3)*0.25 * 2, y32 = y3 + (y1 - y3)*0.25 * 2, x33 = x3 + (x1 - x3)*0.25 * 3, y33 = y3 + (y1 - y3)*0.25 * 3;		
		painter.drawLine(QPointF(x11, y11), QPointF(x23, y23));
		painter.drawLine(QPointF(x12, y12), QPointF(x22, y22));
		painter.drawLine(QPointF(x13, y13), QPointF(x21, y21));

		painter.drawLine(QPointF(x11, y11), QPointF(x33, y33));
		painter.drawLine(QPointF(x12, y12), QPointF(x32, y32));
		painter.drawLine(QPointF(x13, y13), QPointF(x31, y31));

		painter.drawLine(QPointF(x23, y23), QPointF(x31, y31));
		painter.drawLine(QPointF(x22, y22), QPointF(x32, y32));
		painter.drawLine(QPointF(x21, y21), QPointF(x33, y33));
	}		
	
	QPainter pp(&pix);    //往画布上画，pp是画的线， 根据鼠标指针前后两个位置绘制直线   
	pp.setRenderHint(QPainter::Antialiasing, true);
	pp.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap));
	pp.drawLine(lastPoint, endPoint);    // 让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线  
	lastPoint = endPoint;	
}

void DrawLinePanel::mousePressEvent(QMouseEvent *event)
{
	qDebug() << event->pos();
	if (event->button() == Qt::LeftButton) //鼠标左键按下       
		lastPoint = event->pos();	
}

void DrawLinePanel::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << event->pos();
	if (event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标    
	{
		endPoint = event->pos();
		update(); //执行painterEvent函数进行重绘
	}
}

void DrawLinePanel::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) //鼠标左键释放    
	{
		endPoint = event->pos();
		update();
	}
}





