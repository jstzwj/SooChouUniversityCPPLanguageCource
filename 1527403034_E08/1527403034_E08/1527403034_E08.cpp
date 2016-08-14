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

int main()
{
	Circle cir;
	double x,y,r;
	cout << "������Բ��x��y������뾶��" << std::endl;
	cin >> x >> y >> r;
	cir.setCentre(x,y);
	cir.setRadius(r);
	cout << "���Ϊ:" << cir.getArea()<<std::endl;
	cout << "�ܳ�Ϊ:" << cir.getCircumference()<<std::endl;
	system("pause");
	return 0;
}

Circle::Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	if (r>=0)
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