/*
	����������
	ʱ�䣺2016/4/20
	��ע��
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
	cout << "���������뾶�͸�" << std::endl;
	cin >> r >> h;
	col.setBottomRadius(r);
	col.setHeight(h);
	cout << "�����ܳ���" << std::endl;
	cout << col.getBottomCircumference()<<std::endl;
	cout << "�������" << std::endl;
	cout << col.getBottomArea() << std::endl;
	cout << "�������" << std::endl;
	cout << col.getLateralArea() << std::endl;
	cout << "�����" << std::endl;
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
		std::cerr << "�뾶����Ϊ����";
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
		std::cerr << "�뾶����Ϊ����";
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
	//��hΪ������bottomΪ����Բ
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


