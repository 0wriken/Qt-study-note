#ifndef MUSIC_H_
#define MUSIC_H_
#include  <QWidget>
#include <QLabel>
#include <QpushButton>
#include <QSlider> 
#include <QSPacerItem>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
class Music::public QWidget
{
	Q_OBJECT
public:
	Music(QWidget *parent=0);
	~Music();

private:
	QHBoxLayout *timelay();
	QVBoxLayout *showlay();
	QVBoxLayout *ButtonLay();
	QHBoxLayout * MUsic::InterLay();
	QHBoxLayout *contolLay();
	void mainLay();
private:
	//显示部分
	QLabel *title;      //标签
	QSlider *process;  //进度条
	QLabel *current;   //起始时间
	QSPacerItem *time; //模块框架
	QLabel *totalTime;//终止计时
	QHBoxLayout *timelayout ;////布局
	QVBoxLayout *showLayout;


	//列表部分

	QpushButton *scanLocalFile;//按钮
	QpushButton *showPlayBtn;
	QHBoxLayout *ButonLayout;
	//合并左右
	QHBoxLayout *Interface ;////布局
	

	//控制部分

	QComboBox *playModeCobox;
	QpushButton * presong;
	QpushButton *nextsong;
	QpushButton2 *playBtn;
	QSlider *Volume;
	QLabel *VolumeLabel;
	QSPacerItem *VolumeItem;
	QHBoxLayout *contolLayout;
	//合并上下为主界面
	QVBoxLayout *mainLayout;
};





#endif