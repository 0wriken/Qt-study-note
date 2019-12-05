#ifndef MYLABLE_H_
#define MYLABLE_H_

#include <QLable>
class MyLable:public QLable
{
public:
	explicit MyLable(QWidget *parent=0);//创建纯虚函数	
protected:
	void mousePress(QMouseEvent *ev);
	void mouseRelease(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);
	void enetrEvent(QMouseEvent *ev);
	void leavemouce(QMouseEvent *ev);

}


#endif