#include "Circle.h"


Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	this->r = r;
}

Circle::Circle() :x(0.0), y(0.0), r(0.0) {}

void Circle::setCentre(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Circle::setRadius(double r)
{
	this->r = r;
}

Circle & Circle::operator++()
{
	r++;
	return *this;
}

Circle Circle::operator++(int)
{
	Circle temp(*this);
	this->r++;
	return temp;
}

Circle & Circle::operator--()
{
	r--;
	return *this;
}

Circle Circle::operator--(int)
{
	Circle temp(*this);
	this->r--;
	return temp;;
}

Circle::relation Circle::operator|(Circle & rhs)
{
	double d = (x - rhs.x)*(x - rhs.x) + (y - rhs.y)*(y - rhs.y);
	if (d<(r>rhs.r?r-rhs.r:rhs.r-r))
	{
		return CONTAIN;
	}
	else if((d== (r>rhs.r ? r - rhs.r : rhs.r - r))||(d== r+rhs.r))
	{
		return TANGENT;
	}
	else if ((d>(r>rhs.r ? r - rhs.r : rhs.r - r))&&(d<r+rhs.r))
	{
		return INTERSECTION;
	}
	else if (d > r + rhs.r)
	{
		return APART;
	}
}

Circle operator+(const Circle & lhs, const Circle & rhs)
{
	Circle temp(lhs);
	temp.r = lhs.r + rhs.r;
	return temp;
}

Circle operator-(const Circle & lhs, const Circle & rhs)
{
	Circle temp(lhs);
	temp.r = lhs.r > rhs.r ? lhs.r - rhs.r : rhs.r - lhs.r;
	return temp;
}

ostream & operator<<(ostream & os, const Circle & rhs)
{
	os << "圆心坐标：" << "(" << rhs.x << "," << rhs.y << ")" << endl;
	os << "半径：" << rhs.r << endl;
	os << "周长：" << rhs.getCircumference() << endl;
	os << "面积：" << rhs.getArea() << endl;
	return os;
}

bool operator>(const Circle & lhs, const Circle & rhs)
{
	return lhs.getArea()>rhs.getArea();
}

bool operator<(const Circle & lhs, const Circle & rhs)
{
	return lhs.getArea()<rhs.getArea();
}

bool operator==(const Circle & lhs, const Circle & rhs)
{
	return (lhs.r==rhs.r)&&(lhs.x==rhs.x)&&(lhs.y==rhs.y);
}

bool operator!=(const Circle & lhs, const Circle & rhs)
{
	return (lhs.r != rhs.r) || (lhs.x != rhs.x) || (lhs.y != rhs.y);;
}

bool operator&(const Circle & lhs, const Circle & rhs)
{
	return (lhs.x==rhs.x)&&(lhs.y==rhs.y);
}


