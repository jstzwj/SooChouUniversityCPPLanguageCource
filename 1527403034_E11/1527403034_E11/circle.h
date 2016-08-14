#include<iostream>
#include<cmath>
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
	double getx()const { return x; };
	double gety()const { return y; };
	double getr()const { return r; };
	void setx(double num) { x = num; };
	void sety(double num) { y = num; };
	void setr(double num) { r = num; };
	void setCentre(double x, double y);
	void setRadius(double r);
	double getArea()const { return PI*r*r; };
	double getCircumference()const { return 2 * PI*r; };
public:
	static bool doubleEqual(double lhs, double rhs)
	{
		return lhs - rhs > -10e-6&&lhs - rhs < 10e-6;
	}
	//操作符
	friend Circle operator+(const Circle& lhs, const Circle & rhs);
	friend Circle operator-(const Circle& lhs, const Circle & rhs);
	Circle & operator++();
	Circle operator++(int);
	Circle & operator--();
	Circle operator--(int);
	friend ostream & operator<<(ostream &os, const Circle &rhs);
	friend bool operator>(const Circle &lhs, const Circle &rhs);
	friend bool operator<(const Circle &lhs, const Circle &rhs);
	friend bool operator==(const Circle &lhs, const Circle &rhs);
	friend bool operator!=(const Circle &lhs, const Circle &rhs);

	friend bool operator&(const Circle &lhs, const Circle &rhs);
	Circle::relation operator|(const Circle &rhs);

};
