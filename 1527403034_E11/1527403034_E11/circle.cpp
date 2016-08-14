#include"circle.h"

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

Circle::relation Circle::operator|(const Circle & rhs)
{
	double d = (x - rhs.x)*(x - rhs.x) + (y - rhs.y)*(y - rhs.y);
	d = sqrt(d);
	if (d<(r>rhs.r ? r - rhs.r : rhs.r - r))
	{
		return CONTAIN;
	}
	else if ((doubleEqual(d, (r>rhs.r ? r - rhs.r : rhs.r - r))) || doubleEqual(d, r + rhs.r))
	{
		return TANGENT;
	}
	else if ((d>(r>rhs.r ? r - rhs.r : rhs.r - r)) && (d<r + rhs.r))
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
	os << "Բ�����꣺" << "(" << rhs.x << "," << rhs.y << ")" << endl;
	os << "�뾶��" << rhs.r << endl;
	os << "�ܳ���" << rhs.getCircumference() << endl;
	os << "�����" << rhs.getArea() << endl;
	return os;
}

bool operator>(const Circle & lhs, const Circle & rhs)
{
	return lhs.r>rhs.r;
}

bool operator<(const Circle & lhs, const Circle & rhs)
{
	return lhs.r<rhs.r;
}

bool operator==(const Circle & lhs, const Circle & rhs)
{
	return (Circle::doubleEqual(lhs.r, rhs.r)) && (Circle::doubleEqual(lhs.x, rhs.x)) && (Circle::doubleEqual(lhs.y, rhs.y));
}

bool operator!=(const Circle & lhs, const Circle & rhs)
{
	return (!Circle::doubleEqual(lhs.r, rhs.r)) || (!Circle::doubleEqual(lhs.x, rhs.x)) || (!Circle::doubleEqual(lhs.y, rhs.y));
}

bool operator&(const Circle & lhs, const Circle & rhs)
{
	return (Circle::doubleEqual(lhs.x, rhs.x)) && (Circle::doubleEqual(lhs.y, rhs.y));
}



