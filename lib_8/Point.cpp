#include "Point.h"
Point::Point(int xx,int yy)
{
	x = xx;
	y = yy;
}
Point& Point::operator+=(Point &ref_in)
{
	if (this != &ref_in)
	{
		x = x + ref_in.x;
		y = y + ref_in.y;
	}
	return *this;
}
Point& Point::operator+=(int XY)
{
		x = x + XY;
		y = y + XY;
	return *this;
}
/*Point& Point::operator+(const int XY)
{
	return Point(x + XY, y + XY);
}*/
Point Point::operator+(const Point &ref_in)
{
	return Point(x + ref_in.x, y + ref_in.y);
}
