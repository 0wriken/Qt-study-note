#include "circle.h"
point::point(int x,int y)
{
	this->x=x;
	this->y=y;
}
point :: ~point()
{
	this->x=0;

	this->y=0;
}
void point::show()
{
	cout<<"x:"<<this->x<<"y:"<<y<<endl;
}
int point ::get_x()
{
	return this->x;
}
int point ::get_y()
{
	return this->y;
}
circle::circle(int x1,int y1, float r):point(x,y)
{
	x=x1;
	y=y1;
	this->r=r;
}
circle::~circle()
{
	this->r=0;
}
void circle::show()
{
	cout<<"r:"<<r<<endl;
}
float circle::get_r()
{
	return this->r;
}
cylinder::cylinder(int x1,int y1, float r1,int h):circle(x,y,r)
{
	x=x1;
	y=y1;
	r=r1;
	this->h=h;
}cylinder::~cylinder()
{
	this->h=0;
}
void cylinder::show()
{
	cout<<"h:"<<h<endl;
}
void cylinder::area()
{
	float area=0;
	area=2*(this->h+this->circle::get_r())*this->circle::get_r()*PI;
	cout<<"面积为："<<area<<endl;
}
void cylinder::volume ()
{	
	float volume=0;
	volume=PI*(this->circle::get_r())*(this->circle::get_r())*this->h;
	cout<<"体积为:"<<volume<<endl;

}