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
	//��Բ֮��Ĺ�ϵ
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
	//������
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



int main()
{
	int ax, ay;
	int bx, by;
	int ar, br;

	
	cout << "�������һ��Բ������x��y��r��"<<endl;
	cin >> ax>> ay>> ar;
	cout << "������ڶ���Բ������x��y��r��" << endl;
	cin >> bx >> by >> br;

	Circle a(ax,ay,ar), b(bx,by,br);
	//�ж��Ƿ�����
	if ((a|b)==Circle::APART)
	{
		cout << "a��b����" << endl;
		//�������˶�
		double c, d, e;

		while ((a | b) == Circle::APART)
		{
			//�������
			c = a.getx() - b.getx();
			d = a.gety() - b.gety();
			e = sqrt(c*c + d*d);

			//���
			cout << "AԲλ�ã�" << a.getx() << "," << a.gety() << "\t�뾶��" << a.getr() << endl;
			cout << "BԲλ�ã�" << b.getx() << "," << b.gety() << "\t�뾶��" << b.getr() << endl;
			cout << "���룺" << e << endl;
			//�жϰ뾶�Ƿ�Ϊ��
			if (a.getr()<=0 || b.getr()<=0)
			{
				cerr << "Բ�İ뾶С�ڵ���0" << endl;
				break;
			}
			//�ı�����
			a.setx(a.getx() - c / e);
			a.sety(a.gety() - d / e);
			a.setr(a.getr() - 1);
			b.setx(b.getx() + c / e);
			b.sety(b.gety() + d / e);
			b.setr(b.getr() - 1);
		}
		if ((a | b) != Circle::APART)
		{
			cout << "��Բ��ײ��" << endl;
		}
	}
	else
	{
		cout << "a��b�����룡��" << endl;
	}
	system("pause");
	return 0;
}