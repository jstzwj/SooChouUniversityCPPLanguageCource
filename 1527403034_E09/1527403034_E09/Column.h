#pragma once
#include<iostream>
using std::cout;
using std::cin;

class Circle
{
public:
	Circle();
	Circle(double x, double y, double r = 0);
private:
	const double PI = 3.1415926535898;
	double x;
	double y;
	double r;
public:
	void setCentre(double x, double y);
	void setRadius(double r);
	double getArea()const { return PI*r*r; };
	double getCircumference()const { return 2 * PI*r; };
};

class Column
{
public:
	Column();
	Column(const Circle &bottom,double h);
private:
	Circle bottom;
	double h;
public:
	void setBottomCentre(double x,double y);
	void setBottomRadius(double r);
	void setHeight(double h);
	double getBottomArea()const;
	double getBottomCircumference()const;
	double getLateralArea()const;
	double getVolume()const;
};

Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	if (r >= 0)
	{
		this->r = r;
	}
	else
	{
		std::cerr << "半径不能为负数";
		this->r = 0;
	}

}

Circle::Circle() :x(0.0), y(0.0), r(0.0) {}

void Circle::setCentre(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Circle::setRadius(double r)
{
	if (r >= 0)
	{
		this->r = r;
	}
	else
	{
		std::cerr << "半径不能为负数";
		this->r = 0;
	};
}
