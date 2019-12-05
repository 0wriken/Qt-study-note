#include "TV.h"
using namespace std;

TY::TV(char *buf=NULL,int price=0)
{
	if(bubf==NULL)
	{
		this->price=0;
		return ;
	}
	char *brand=new char[strlen(buf)];
	strcpy(brand,buf);
	this->price=price;
}
TV::~TV()
{
	delete this->brand;
	this->brand=NULL;
	price=0;
}
void TV::prinrt_message()
{
	if(this->brand==NULL)
	{
	cout<<"品牌:"<<00;
	cout<<"价格为"<<this->price<endl;
		return ;
	}
	cout<<"品牌:"<<this->brand;
	cout<<"价格为"<<this->price<endl;
}
void TV::set_message(char *buf,int price)
{
	strcpy(this->brand,buf);
	this->price=price;
}