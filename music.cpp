#include  "music.h"
MUsic:Music(QWidget *parent)
	:QWidget(parent)
{
	//显示部分
	QLabel a(this);
	a.setText("hello");//局部变量会释放

	QLabel *b=new QLabel("hello",this);//也是局部变量，但是不好释放

	//this->setLayout(timelayout);//认个爹
	
}
Music::~Music()
{
	delete 	title;
}
QHBoxLayout * Music::timelay()
{
	title =new QLabel("无歌曲");//设置为全局变量,先不着急认父

	process=new QSlider(QT::Horizontal);//水平布局
    currenttime=new QLabel("00:00");   //起始时间
	time=new QpacerItem(200,20); //
	totalTime=new QLabel("00:00"); //

	QHBoxLayout *timelayout =new QHBoxLayout;
	 //添加布局
	//水平布局 时间与显示条
	timelayout ->addQpacerItem(time);      
	timelayout ->addWidget(currenttime);   
	timelayout ->addWidget(totalTime); 
	return timelayout;
}
QVBoxLayout * Music::showlay()
{
	//垂直布局

	QVBoxLayout *showLayout= new QVBoxLayout(this);

	showLayout->addWidget(process);
	showLayout ->addWidget(title);
	showLayout ->addLayout(timelayout);
	return showLayout;
}
QvBoxLayout * Music::ButtonLay()
{
	//列表部分
	QpushButton *scanLocalFile=new QpushButton("",this); //按钮
	QpushButton *showPlayBtn=new QpushButton("",this);
	ButonLayout=new QVBoxLayout;
	ButonLayout->addWidget(showPlayBtn);
	ButonLayout->addWidget(scanLocalFile);
	return ButonLayout;
}
QHBoxLayout * MUsic::InterLay()
{
//水平布局按键与显示界面
	Interface=new QHBoxLayout ;
	Interface ->addLayout(ButtonLay());
	Interface ->addLayout(showlay());
	return Interface;
}
QHBoxLayout * Music::contolLay()
{
	//控制部分
	playModeCobox= new QComboBox();
	playModeCobox->addText("顺序播放");
	playModeCobox->addText("随机播放");
	playModeCobox->addText("单曲循环");
	presong=new QpushButton("上一首");
	nextsong=new QpushButton("下一首");
	playBtn=new QpushButton("停止");
	Volume=new QSlider(QT::Horizontal);
	VolumeLabel=new QLabel("音量");
	VolumeItem=new QSPacerItem(200,20,QSizePolicy::Expanding);//选择策略为扩展模式

	contolLayout=new QHBoxLayout;
	contolLayout ->addWidget(playModeCobox);
	contolLayout ->addWidget(presong);
	contolLayout ->addWidget(nextsong);
	contolLayout ->addWidget(playBtn);
	contolLayout ->addWidget(Volume);
	contolLayout ->addSpacerItem(VolumeItem);
}
void Music::mainLay()
{
	//合并上下
	mainLayout=new QVBoxLayout;
	mainLayout ->addLayout(contolLayout);
	mainLayout->addLayout(Interface);

	this->setLayout(mainLayout);
}