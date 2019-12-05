#include <QApplication>
#include <QLineEdit>
int main(int argc, char const *argv[])
{
	QApplication a(argc,ragv);
	QLineEdit w;
	w.sjow();
	return a.exec();
}
//指定父部件
#include <QApplication>
#include <QLineEdit>
#include <QpushButton>
#include <Qdebug>
int main(int argc, char const *argv[])
{
	QApplication a(argc,ragv);

	QLineEdit w;
	
	QpushButton b(&w);
	QpushButton n(QString("确定"),&w);
	

	w.show();

	cout<<"x:"<<w.x()<<endl;
	cout<<"y:"<<w.y()<<endl;

	qDebug()<<"pos:"<<w.pos();//专用输出
	qDebug()<<"geo:"<<w.frameGeometry();
	return a.exec();
}
#include <QApplication>
#include "music.h"
#include <QString>
#include <QDebug>
int main(int argc, char const *argv[])
{
	QApplication a(argc,argv);
	signal w;

	QString str="hello";
	QString stp(str);//共享

	str=QString("%1 %2 %3").arg(12).arg("hellow").arg(15.15);
	w.show();
	
	qDebug()<<"str :"<<str;

	//转换数据类型
	str.toInt();
	return a.exec();
}





















