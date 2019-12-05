#include "TV.h"
using namespace std;
int main(int argc, char const *argv[])
{
	TV A("小米",1000);
	TV B("魅族"，3000);
	TV C("VIVO"，2000)；
	A.prinrt_message();
	A.set_message("华为",251);
	A.prinrt_message();
	return 0;
}
//圆柱
#include "circle.h"
using namespace std;
int main(int argc, char const *argv[])
{
	cylinder C(0,0,5.0,9);
	C.circle::show();
	C.point::show();
	c.show();
	C.area();
	C. volume ();
	return 0;
}