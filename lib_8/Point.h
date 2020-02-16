#pragma once
#include "H.h"
class Point
{
	int x = 0;
	int y = 0;
public:
	Point(int xx = 0, int yy = 0);
	Point& operator+=(Point &ref_in);
	Point& operator+=(int XY);
	bool operator <(const Point &b) const;
	bool operator ==(const Point &b) const;
	//Point& operator+(const int XY); Посмотреть что не так!!!!
	Point operator+(const Point &ref_in);
	friend ostream& operator<<(ostream& os, const Point &ms);
	friend ostream& operator<<(ostream& os, const Point *ms);

	//friend Point& operator-( Point &ref_in, int dec);
	//friend Point& operator-(Point &ref_in, Point &ref);
};