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
	//���
	friend ostream & operator<<(ostream & os,const CComplex & complex);
	//���
	friend CComplex operator+(const CComplex &lhs,const CComplex &rhs);
	//������ʵ�����
	friend CComplex operator+(const CComplex &lhs,double rhs);
	friend CComplex operator+(double lhs,const CComplex &rhs);
	//��һ
	CComplex &operator++();
	CComplex operator++(int);
	//��ȡ����
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
	
	cout << "�������һ��������ʵ�� �鲿��" << endl;
	cin >> x >> y;
	a.setValue(x,y);

	cout << "������ڶ���������ʵ�� �鲿��" << endl;
	cin >> x >> y;
	b.setValue(x,y);
	
	cout << "��ӣ�" << endl;
	cout << "�������:" << a+b << endl;

	cout << "������һ��ʵ����" << endl;
	cin >> x;
	cout << "���һ�������:" << a+x << endl;
	cout << "��ڶ��������:" << b+x << endl;

	cout << "ǰ������" << endl;
	cout << "��һ��:" << ++a << endl;
	cout << "�ڶ���:" << ++b << endl;

	cout << "��������" << endl;
	cout << "��һ��:" << a++ << endl;
	cout << "�ڶ���:" << b++ << endl;

	system("pause");
	return 0;
}