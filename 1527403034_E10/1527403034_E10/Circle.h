#pragma once
#include<iostream>
using namespace std;

const double PI = 3.1415926535898;

class Circle
{
public:
	Circle();
	Circle(double x, double y, double r = 0);
public:
	//两圆之间的关系
	enum relation { INTERSECTION, TANGENT, APART, CONTAIN };

private:
	
	double x;
	double y;
	double r;
public:
	void setCentre(double x, double y);
	void setRadius(double r);
	double getArea()const { return PI*r*r; };
	double getCircumference()const { return 2 * PI*r; };
public:
	//操作符
	friend Circle operator+(const Circle& lhs,const Circle & rhs);
	friend Circle operator-(const Circle& lhs, const Circle & rhs);
	Circle & operator++();
	Circle operator++(int);
	Circle & operator--();
	Circle operator--(int);
	friend ostream & operator<<(ostream &os,const Circle &rhs);
	friend bool operator>(const Circle &lhs, const Circle &rhs);
	friend bool operator<(const Circle &lhs, const Circle &rhs);
	friend bool operator==(const Circle &lhs, const Circle &rhs);
	friend bool operator!=(const Circle &lhs, const Circle &rhs);

	friend bool operator&(const Circle &lhs, const Circle &rhs);
	Circle::relation operator|(Circle &rhs);

};

