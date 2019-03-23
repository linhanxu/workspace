#include "DrawLinePanel.h"
#include <QPainter>

DrawLinePanel::DrawLinePanel()
{
	drawWidget.setupUi(this);	
	
	//resize(200, 200);    //窗口大小设置   //.................（8-10行与59-63行为一组）
	pix = QPixmap(200, 200);//画布大小设置，背景白色
	pix.fill(Qt::white);
	
	/*connect(drawButton, &QPushButton::clicked, this, &DrawLinePanel::paintEvent);
	connect(clearButton, &QPushButton::clicked, this, &DrawLinePanel::clearPaint);*/
}



void DrawLinePanel::setActiveScene(Scene * scene)
{
	if (activeScene != scene)
		activeScene = scene;
}

DrawLinePanel::~DrawLinePanel()
{
	
}

QSegMesh* DrawLinePanel::activeObject()
{
	if (activeScene)
		return activeScene->activeObject();
	else
		return NULL;
}


//void DrawLinePanel::paintEvent(QPaintEvent *)
//{
//
//	QPainter painter(this);
//	painter.setRenderHint(QPainter::Antialiasing);
//	painter.translate(40, 40);// 把坐标原点移动到(0,0)
//
//	static const QPointF points[5] = {
//		QPointF(20.0, 70.0),
//		QPointF(90.0, 20.0),
//		QPointF(160.0, 70.0),
//		QPointF(125.0, 130.0),
//		QPointF(55.0, 130.0)
//		};
//
//		painter.drawPolygon(points, 5);	
//	
//
//}


void DrawLinePanel::paintEvent(QPaintEvent *)
{

	QPainter painter(this);
	

	QPainter pp(&pix);    // 根据鼠标指针前后两个位置绘制直线   //.................（8-10行与59-63行为一组）
	pp.drawLine(lastPoint, endPoint);    // 让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线    
	lastPoint = endPoint;	
	painter.drawPixmap(0, 0, pix);//在(0,0)处绘制画布
	
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(0, 0);// 把坐标原点移动到(0,0)
	//painter.drawPoint(QPointF(0, 0));//画出（0,0）位置	

	float x1 = 50.0, y1 = 90.0;
	float x2 = 185.0, y2 = 60.0;
	float x3 = 220.0, y3 = 110.0;
	float x4 = 195.0, y4 = 150.0;
	float x5 = 145.0, y5 = 160.0;
	static const QPointF points[5] = {
		QPointF(x1, y1),
		QPointF(x2, y2),
		QPointF(x3, y3),
		QPointF(x4, y4),
		QPointF(x5, y5)
	};
	painter.drawPolygon(points, 5);	

	//画细分线
	double x11 = x1 + (x2 - x1)*0.25 * 1, y11 = y1 + (y2 - y1)*0.25 * 1, x12 = x1 + (x2 - x1)*0.25 * 2, y12 = y1 + (y2 - y1)*0.25 * 2, x13 = x1 + (x2 - x1)*0.25 * 3, y13 = y1 + (y2 - y1)*0.25 * 3;
	double x21 = x2 + (x3 - x2)*0.25 * 1, y21 = y2 + (y3 - y2)*0.25 * 1, x22 = x2 + (x3 - x2)*0.25 * 2, y22 = y2 + (y3 - y2)*0.25 * 2, x23 = x2 + (x3 - x2)*0.25 * 3, y23 = y2 + (y3 - y2)*0.25 * 3;
	double x31 = x3 + (x4 - x3)*0.25 * 1, y31 = y3 + (y4 - y3)*0.25 * 1, x32 = x3 + (x4 - x3)*0.25 * 2, y32 = y3 + (y4 - y3)*0.25 * 2, x33 = x3 + (x4 - x3)*0.25 * 3, y33 = y3 + (y4 - y3)*0.25 * 3;
	double x41 = x4 + (x5 - x4)*0.25 * 1, y41 = y4 + (y5 - y4)*0.25 * 1, x42 = x4 + (x5 - x4)*0.25 * 2, y42 = y4 + (y5 - y4)*0.25 * 2, x43 = x4 + (x5 - x4)*0.25 * 3, y43 = y4 + (y5 - y4)*0.25 * 3;;
	double x51 = x5 + (x1 - x5)*0.25 * 1, y51 = y5 + (y1 - y5)*0.25 * 1, x52 = x5 + (x1 - x5)*0.25 * 2, y52 = y5 + (y1 - y5)*0.25 * 2, x53 = x5 + (x1 - x5)*0.25 * 3, y53 = y5 + (y1 - y5)*0.25 * 3;
	double x61 = x5 + (x2 - x5)*0.25 * 1, y61 = y5 + (y2 - y5)*0.25 * 1, x62 = x5 + (x2 - x5)*0.25 * 2, y62 = y5 + (y2 - y5)*0.25 * 2, x63 = x5 + (x2 - x5)*0.25 * 3, y63 = y5 + (y2 - y5)*0.25 * 3;
	double x71 = x5 + (x3 - x5)*0.25 * 1, y71 = y5 + (y3 - y5)*0.25 * 1, x72 = x5 + (x3 - x5)*0.25 * 2, y72 = y5 + (y3 - y5)*0.25 * 2, x73 = x5 + (x3 - x5)*0.25 * 3, y73 = y5 + (y3 - y5)*0.25 * 3;
	
	painter.drawLine(QPointF(x5, y5), QPointF(x2, y2));
	painter.drawLine(QPointF(x5, y5), QPointF(x3, y3));

	painter.drawLine(QPointF(x11, y11), QPointF(x61, y61));
	painter.drawLine(QPointF(x12, y12), QPointF(x62, y62));
	painter.drawLine(QPointF(x13, y13), QPointF(x63, y63));
	painter.drawLine(QPointF(x51, y51), QPointF(x13, y13));
	painter.drawLine(QPointF(x52, y52), QPointF(x12, y12));
	painter.drawLine(QPointF(x53, y53), QPointF(x11, y11));
	painter.drawLine(QPointF(x53, y53), QPointF(x63, y63));
	painter.drawLine(QPointF(x52, y52), QPointF(x62, y62));
	painter.drawLine(QPointF(x51, y51), QPointF(x61, y61));
	
	
	painter.drawLine(QPointF(x23, y23), QPointF(x61, y61));
	painter.drawLine(QPointF(x22, y22), QPointF(x62, y62));
	painter.drawLine(QPointF(x21, y21), QPointF(x63, y63));
	painter.drawLine(QPointF(x71, y71), QPointF(x21, y21));
	painter.drawLine(QPointF(x72, y72), QPointF(x22, y22));
	painter.drawLine(QPointF(x73, y73), QPointF(x23, y23));
	painter.drawLine(QPointF(x73, y73), QPointF(x63, y63));
	painter.drawLine(QPointF(x72, y72), QPointF(x62, y62));
	painter.drawLine(QPointF(x71, y71), QPointF(x61, y61));
	
	
	painter.drawLine(QPointF(x33, y33), QPointF(x71, y71));
	painter.drawLine(QPointF(x32, y32), QPointF(x72, y72));
	painter.drawLine(QPointF(x31, y31), QPointF(x73, y73));
	painter.drawLine(QPointF(x41, y41), QPointF(x73, y73)); 
	painter.drawLine(QPointF(x42, y42), QPointF(x72, y72)); 
	painter.drawLine(QPointF(x43, y43), QPointF(x71, y71));
	painter.drawLine(QPointF(x43, y43), QPointF(x31, y31));
	painter.drawLine(QPointF(x42, y42), QPointF(x32, y32));
	painter.drawLine(QPointF(x41, y41), QPointF(x33, y33));
	
	
	
}

void DrawLinePanel::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) //鼠标左键按下       
		lastPoint = event->pos();
}

void DrawLinePanel::mouseMoveEvent(QMouseEvent *event)
{
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

void DrawLinePanel::clearPaint()
{
	
	
	
}



