/*
	姓名：王俊
	时间：2016/4/20
	备注：
*/
#include<iostream>
using std::cout;
using std::cin;

const double PI = 3.1415926535898;

class Circle
{
public:
	Circle();
	Circle(double x, double y, double r = 0);
private:
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
	Column(const Circle &bottom, double h);
private:
	Circle bottom;
	double h;
public:
	void setBottomCentre(double x, double y);
	void setBottomRadius(double r);
	void setHeight(double h);
	double getBottomArea()const;
	double getBottomCircumference()const;
	double getLateralArea()const;
	double getVolume()const;
};

int main()
{
	double r, h;
	Column col;
	cout << "请输入底面半径和高" << std::endl;
	cin >> r >> h;
	col.setBottomRadius(r);
	col.setHeight(h);
	cout << "底面周长：" << std::endl;
	cout << col.getBottomCircumference()<<std::endl;
	cout << "底面积：" << std::endl;
	cout << col.getBottomArea() << std::endl;
	cout << "侧面积：" << std::endl;
	cout << col.getLateralArea() << std::endl;
	cout << "体积：" << std::endl;
	cout << col.getVolume() << std::endl;
	system("pause");
	return 0;
}

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

Column::Column() :bottom(), h(0) {}

Column::Column(const Circle & bottom, double h) : bottom(bottom), h(h) {}

void Column::setBottomCentre(double x, double y)
{
	bottom.setCentre(x, y);
}

void Column::setBottomRadius(double r)
{
	bottom.setRadius(r);
}

void Column::setHeight(double h)
{
	//若h为负，则bottom为顶面圆
	this->h = h;
}

double Column::getBottomArea() const
{
	return bottom.getArea();
}

double Column::getBottomCircumference() const
{
	return bottom.getCircumference();
}

double Column::getLateralArea() const
{
	return bottom.getCircumference()*h;
}

double Column::getVolume() const
{
	return bottom.getArea()*h;
}


