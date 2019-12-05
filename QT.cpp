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


#include "smallwidget.h"
#include <QSPinbox>//编辑区
#include <QSlide>//滑块
#include <QHBOXLayout>//布局
smallwidget::smallwidget(QWidget *parent):QWidget(parent)
{
	QSPinbox * spin =new QSPinbox(this);
	QSlide *slide =new QSlide(this);
	//插入到布局中
	QHBOXLayout *hbox=new QHBOXLayout(this);
	hbox->addWidget(spin);
	hbox->addWidget(slide);
	//指定函数重载
	connect(spin,static_cast<void (*QSPinbox::*)(int )>(&QSPinbox::valueChange),slide,&QSlide::setValue);
	connect(slide,&QSlide::valueChange,spin,&QSPinbox::setValue);
}
//QT样式表
	u->Setup(this);
	//整个控件有效
	this->setStyleSheet("QLable{color:red;""background-color:bule;""}");
	ui->lable->setStyleSheet("QLable{color:red;""background-color:red;""}");
	ui->lable->setStyleSheet("QLable{color:red;""background-color:red;"
	"border-image:url(:./);""}");//显示图片
	//鼠标控制按键切换图片
	ui->PushButton->setStyleSheet("QPushButton{""
	border-image:url(:./1.jpg);""}"
	"QPushButton:hover{""border-image:url(:./2.jpg);""}"
	"QPushButton:pressed{""border-image:url(:./3.jpg);""}"
	);


//事件
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

#include<stdio.h>
#include<stdlib.h>
#define true  1
#define false  0
#define N    50

struct NOM
{
	char ch;
	struct NOM *next;
};
struct Stack
{
	struct NOM *pTop;        /*栈顶指针*/
	struct NOM *pBottom;     /*栈底指针*/
};

void Stack_init(struct Stack *ps);         //初始化一个栈
void Stack_push(struct Stack *ps,char val);//压栈，输入数据
int Stack_empty(struct Stack *ps);         //判断栈是否为空
int Stack_pop(struct Stack *ps,char *val); //出栈，
int Stack_GetTop(struct Stack *ps,char *val);  //得到栈顶元素
void Translate_PostfixExpression(char pstr[],char pbuf[]);  //中缀表达式转为后缀表达式
float Calculate_PostfixExpression(char pbuf[]); //计算后缀表达式

int main()
{
   char str[N]; //存储中缀表达式
   char buf[N]; //存储后缀表达式
   float result=0;  //接收后缀表达式的结果值

   printf("请输入某个中缀表达式：");
   gets(str);
   Translate_PostfixExpression(str,buf);
   printf("转换成后缀表达式为：");
   puts(buf);

   printf("计算得到的结果为：");
   result=Calculate_PostfixExpression(buf);
   printf("%f\n",result);
    
   return 0;
}

/*计算后缀表达式的值*/
float Calculate_PostfixExpression(char pbuf[])
{ 
    float data[N];    /*将数字字符转换为整数保存在该数组中*/
    int val=0;    /*数字字符转换为整数值*/
    float result=0;   /*保存最后计算的结果值*/
    int i=0;
    int j=-1;        /*用于最后结束做判断*/
    float d1=0,d2=0;

    while(pbuf[i])    /*对字符串中的每一个字符做处理*/
    {
        if(pbuf[i]>='0'&&pbuf[i]<='9') /*判断当前字符是不是数字字符*/
        {
            val=0;
           while(pbuf[i]!=' ')   /*有的数字字符是两位数以上，用空格隔开*/
           {
               val=val*10+pbuf[i]-'0';
               i++;
           }
           j++;
           data[j]=val;  /*将转换后的整数存储于实型数组中*/
        }
        /*如果不是数字字符就是运算符字符,将数组中的数连续取两次，并用当前运算符计算,
        最后将计算结果重新存储于数组中*/
        else
        {
           if(pbuf[i]=='+')
           {
                d1=data[j];   /*将数组中的数字连续取出两次用于计算*/
                j--;          /*取第二个数，从栈顶取*/
                d2=data[j];
                result=d1+d2;
                data[j]=result;/*将第计算结果最终保存在数组中*/
           }
           else if(pbuf[i]=='-')
           {
               d1=data[j];
               j--;
               d2=data[j];
               result=d2-d1;
               data[j]=result;
           }
           else if(pbuf[i]=='*')
           {
               d1=data[j];
               j--;
               d2=data[j];
               result=d2*d1;
               data[j]=result;
           }
           else if(pbuf[i]=='/')
           {
               d1=data[j];
               j--;
               d2=data[j];
               result=d2/d1;
               data[j]=result;
           }
        }
        i++;
    }
    /*计算完成，如果没有差错，则数组中最后有一个值，就是我们最终计算的结果值*/
    if(j!=-1)
    {
        result=data[j--];
        if(j==-1)
            return result;
        else
            printf("后缀表达式出错\n");
    }
}
/*将中缀表达式转换为后缀表达式*/
void Translate_P0ostfixExpression(char pstr[],char pbuf[])
{
    struct Stack ST;    /*定义一个栈*/
    char ch;
    int i=0,j=0;

    Stack_init(&ST);     /*初始化一个栈*/

    while(pstr[i])     /*运算符表达式字符串没有结束的时候*/
    {
        switch(pstr[i])
        {
            /*如果接收到的是左括号，则将其压栈*/
            case '(': Stack_push(&ST,pstr[i]);break;
            case ')':
            /*如果接收到的是右括号，则栈中的运算符出栈,保存在数组中 */
                while(Stack_GetTop(&ST,&ch)&&ch!='(')
                {
                    Stack_pop(&ST,&ch);
                    pbuf[j++]=ch;
                }
                Stack_pop(&ST,&ch); /*将左括号也出栈*/
                break;
            case '+':
            case '-':
            /*如果是+或者-,其优先级低于栈顶元素的优先级，即使同级也需要先
            将栈顶元素出栈保存在数组中，然后将当前运算符压栈*/
                while(!Stack_empty(&ST)&&Stack_GetTop(&ST,&ch)&&ch!='(')
                {
                    Stack_pop(&ST,&ch);
                        pbuf[j++]=ch;
                }
                 Stack_push(&ST,pstr[i]); /*当前运算符压栈*/
                 break;
            case '*':
            case '/':
            /*如果是*或者/，则将同级运算符出栈，然后当前元素压栈*/
                 while(!Stack_empty(&ST)&&Stack_GetTop(&ST,&ch)&&ch=='*'||ch=='/')
                {
                    Stack_pop(&ST,&ch);
                        pbuf[j++]=ch;
                }
                 Stack_push(&ST,pstr[i]); /*当前运算符压栈*/
                 break;
            case ' ':  break;  /*如果遇到空格，则忽略不计*/
            default:
          /*如果遇到的是操作数而不是运算符，则将操作数存入数组中，并且数字字符之间用空格隔开*/
                while(pstr[i]>='0'&& pstr[i]<='9')
                {
                    pbuf[j]=pstr[i];
                    j++;
                    i++;
                }
            /*录入字符之后，i多加了一次*/
                i--;
                pbuf[j]=' ';
                j++;
        }
        i++;     /*接收下一个字符，继续处理*/
    }

    /*字符串表达式全部读入完成之后，如果栈中还有运算符，则全部出栈，存入数组*/
    while(!Stack_empty(&ST))
    {
        Stack_pop(&ST,&ch);
        pbuf[j++]=ch;
    }
    pbuf[j]='\0';
}

//创建一个空栈，或者初始化栈
void Stack_init(struct Stack *ps)
{
	ps->pTop=(struct NOM *)malloc(sizeof(struct NOM));    /*动态申请一块内存空间*/

	if(ps==NULL)
	{
		printf("内存分配失败！\n");
	}
	else
	{
		ps->pBottom=ps->pTop;   /*栈顶指针和栈底指针同时指向该块空间*/
		ps->pTop->next=NULL;
		printf("栈创建成功\n");
	}
	return ;
}
//压栈，将一个数据入栈
void Stack_push(struct Stack *ps,char val)
{
	struct NOM *pNew=(struct NOM *)malloc(sizeof(struct NOM));

	pNew->ch=val;      /*数据存入*/

	pNew->next=ps->pTop;   /*原来的栈顶元素的地址域存放新的结点的地址*/
	ps->pTop=pNew;        /*新插入的元素变成新的栈顶元素，栈顶指针指向新的栈顶元素*/

	return ;
}

//判断栈是否为空，为空返回1
int Stack_empty(struct Stack *ps)
{
	 if(ps->pTop==ps->pBottom)
		 return true;
	 else
		 return false;
}

//出栈，删除一个数据，并将数据保存在一个变量中
int Stack_pop(struct Stack *ps,char *val)
{
  if(Stack_empty(ps))
  {
	  printf("该栈是空栈!\n");
	  return false;
  }
  else
  {
	  struct NOM *p=ps->pTop;
	  *val=p->ch;
	  ps->pTop=p->next;     /*删除栈顶元素，栈顶指针指向下一个元素，成为新的栈顶元素*/
	  free(p);       /*释放之前的栈顶元素的空间*/
	  p=NULL;
  }
  return true;
}


int Stack_GetTop(struct Stack *ps,char *val)
{
  if(Stack_empty(ps))
  {
	  printf("该栈是空栈!\n");
	  return false;
  }
  *val=ps->pTop->ch;

  return true;
}


























