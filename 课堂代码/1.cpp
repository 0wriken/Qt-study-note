#include <iostream>
using namespace std;
int mian()
{
	//引用对变量取别名
	int a=100;
	int &pa=a;
	int b=20;
	pa=b;//a=b;

	it num[4]={0};
	int (&pn)[4]=num;

	string buf("hello");
	string &pb=buf;

	int *p = new int;
	delete p;//释放
	p=NULL;

	int a[4]=new int[4];
	delete []a;
	string buf[5]=new string[5];
	delete []buf;
	buf=NULL;
	临时对象  静态函数+成员
	
	类型适应 虚函数 

    共同基	虚基派生

} 


