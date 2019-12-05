#ifndef CIRLCE_H_
#define CIRLCE_H_
#include <iostream>
#define PI 3.1415926
class point
{
public:
	point(int x,int y);
	~point();
private:
	int x;
	int y;
public:
	void show();
	int get_x();
	int get_y();
}
class circle ::public point
{
private:
	float r;
public:
	circle(int x1,int y1, float r);
	~circle();
	float get_r();
public:
	void show();
}
class cylinder ::public circle
{

public:
	cylinder(int x1,int y1, float r1,int h);
	~cylinder();
	void show();
	void area();
	void volume ();
private:
	int h;
}

#endif