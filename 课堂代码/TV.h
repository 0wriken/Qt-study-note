#ifndef TV_H_
#define TV_H_
#include <iostream>
#include <cstring>
class  TY
{
public:
	 TY(char *buf,int price);
	~ TY();
	void prinrt_message();
	void set_message();
private:
	char *brand;
	int price;
};


#endif
