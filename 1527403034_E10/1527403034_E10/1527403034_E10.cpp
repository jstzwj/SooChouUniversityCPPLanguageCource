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



int main()
{
	double x, y, r;
	Circle a, b;

	cout << "请输入两个圆：" << endl;
	cout << "第一个圆：" << endl;
	cin >> x >> y >> r;
	a.setCentre(x,y);
	a.setRadius(r);

	cout << "第二个圆：" << endl;
	cin >> x >> y >> r;
	b.setCentre(x, y);
	b.setRadius(r);


	cout << a<<endl;
	cout << b << endl;

	switch (a|b)
	{
	case Circle::INTERSECTION:
		cout << "两圆相交" << endl;
		break;
	case Circle::TANGENT:
		cout << "两圆相切" << endl;
		break;
	case Circle::CONTAIN:
		cout << "两圆包含" << endl;
		break;
	case Circle::APART:
		cout << "两圆相离" << endl;
		break;
	}
	system("pause");
	return 0;
}




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
	else if ((doubleEqual(d , (r>rhs.r ? r - rhs.r : rhs.r - r)))|| doubleEqual(d , r + rhs.r))
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
	os << "圆心坐标：" << "(" << rhs.x << "," << rhs.y << ")" << endl;
	os << "半径：" << rhs.r << endl;
	os << "周长：" << rhs.getCircumference() << endl;
	os << "面积：" << rhs.getArea() << endl;
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
	return (Circle::doubleEqual(lhs.r,rhs.r)) && (Circle::doubleEqual(lhs.x , rhs.x)) && (Circle::doubleEqual(lhs.y , rhs.y));
}

bool operator!=(const Circle & lhs, const Circle & rhs)
{
	return (!Circle::doubleEqual(lhs.r, rhs.r)) || (!Circle::doubleEqual(lhs.x, rhs.x)) || (!Circle::doubleEqual(lhs.y, rhs.y));
}

bool operator&(const Circle & lhs, const Circle & rhs)
{
	return (Circle::doubleEqual(lhs.x , rhs.x)) && (Circle::doubleEqual(lhs.y , rhs.y));
}


