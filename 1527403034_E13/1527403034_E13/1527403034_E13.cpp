#include<iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;
class CComplex 
{ 
	double m_real;  
	double m_image;
public:  
	void setValue(double real, double image) 
	{ 
		m_real = real;   
		m_image = image; 
	} 
	//输出
	friend ostream & operator<<(ostream & os,const CComplex & complex);
	//相加
	friend CComplex operator+(const CComplex &lhs,const CComplex &rhs);
	//复数与实数相加
	friend CComplex operator+(const CComplex &lhs,double rhs);
	friend CComplex operator+(double lhs,const CComplex &rhs);
	//加一
	CComplex &operator++();
	CComplex operator++(int);
	//获取数据
	double getReal() const{ return m_real; }
	double getImage() const{ return m_image; }
};

ostream & operator<<(ostream & os, const CComplex & complex)
{
	if (complex.m_image>0)
	{
		os << complex.m_real << "+" << complex.m_image << "*i";
	}
	else if (complex.m_image==0)
	{
		os << complex.m_real;
	}
	else
	{
		os << complex.m_real << complex.m_image << "*i";
	}
	return os;
}

CComplex operator+(const CComplex &lhs, const CComplex &rhs)
{
	CComplex temp;
	temp.setValue(lhs.m_real + rhs.m_real, lhs.m_image + rhs.m_image);
	return temp;
}

CComplex operator+(const CComplex &lhs, double rhs)
{
	CComplex temp;
	temp.setValue(lhs.m_real+rhs,lhs.m_image);
	return temp;
}

CComplex operator+(double lhs, const CComplex &rhs)
{
	CComplex temp;
	temp.setValue(rhs.m_real+lhs,rhs.m_image);
	return temp;
}
CComplex & CComplex::operator++()
{
	++m_real;
	++m_image;
	return *this;
}
CComplex CComplex::operator++(int)
{
	CComplex temp(*this);
	++m_real;
	++m_image;
	return temp;
}

int main()
{
	double x, y;
	CComplex a,b;
	
	cout << "请输入第一个复数（实部 虚部）" << endl;
	cin >> x >> y;
	a.setValue(x,y);

	cout << "请输入第二个复数（实部 虚部）" << endl;
	cin >> x >> y;
	b.setValue(x,y);
	
	cout << "相加：" << endl;
	cout << "两者相加:" << a+b << endl;

	cout << "请输入一个实数：" << endl;
	cin >> x;
	cout << "与第一个数相加:" << a+x << endl;
	cout << "与第二个数相加:" << b+x << endl;

	cout << "前自增：" << endl;
	cout << "第一个:" << ++a << endl;
	cout << "第二个:" << ++b << endl;

	cout << "后自增：" << endl;
	cout << "第一个:" << a++ << endl;
	cout << "第二个:" << b++ << endl;

	system("pause");
	return 0;
}