//对话框
#include <QMessageBox>
#include <QfileDialog>
QAction *p3=menu->addAction("模态对话框");
connect(p3,&QAction::triggerred,
	[]()
	{
			qDialog dlg;
			dlg.exec();
			qDebug()<<"111";
	});

QAction *p4=menu->addAction("关于对话框");
connect(p4,&QAction::triggerred,
	[]()
	{
			QMessageBox::about(this,"about","关于QT");//显示到主窗口	
	});
QAction *p5=menu->addAction("问题对话框");
connect(p5,&QAction::triggerred,
	[]()
	{
		//由返回值判断按钮
			int ret=QMessageBox::question(this,"question","问点什么",
			QMessageBox::OK|QMessageBox::Cancle

					);//显示问题对话框
			switch(ret)
			{
				case QMessageBox::OK:
					qDebug()<<"i am ok";
					break;
				case QMessageBox::Cancle
					qDebug()<<"i am cancle";
					break;
				default :
				break;
			}
	});

QAction *p5=menu->addAction("文件对话框");
connect(p5,&QAction::triggerred,
	[=]()
	{
		//返回值为字符串 
		QString str=QfileDialog::getopenFileName(this,
			"open",
			"./",
			);
		qDebug()<<str;
		//过滤多个格式;;
				QString str=QfileDialog::getopenFileName(this,
			"open",
			"./",
			"souce(*.cpp *.h);;Text(*.txt);;all(*.*)"//选择打开的格式
			);
	});

//UI编辑
ui->setupUI(this);
ui->myButton->settext("113");//UI指向对象即可操作
connect(ui->myButton,&QPushButton::clicked,this,&MainWindow::close);
//编辑与获取内容
text();
setText(s);

//git
本地仓库：
	git init 创建仓库
	创建文件
	git add 文件
	git status
	git commit  -m  文件
	删除仓库
	rm -rf 文件
	git rm 文件
	git commit -m  "" 提交操作
 远端仓库：
 	同步:
 	删除 git remote rm origin
 	git remote add origin https://github.com/0wriken/TestGit.git
 	git push origin master
	git pull origin master




  个人站点:
  	新建仓库：用户名.github.io
  	必须带有html文件作为访问页面













