#pragma once
class Circle
{
public:
	Circle();
	Circle(double x,double y,double r=0);
private:
	const double PI = 3.1415926535898;
	double x;
	double y;
	double r;
public:
	void setCentre(double x,double y);
	void setRadius(double r);
	double getArea()const { return PI*r*r; };
	double getCircumference()const { return 2 * PI*r; };
};

