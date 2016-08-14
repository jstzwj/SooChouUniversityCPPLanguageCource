#include<iostream>
using namespace std;
class CRmb 
{
private: 
	int yuan;
	int jiao;  
	int fen; 
public:  
	CRmb() 
	{ 
		yuan = 0;
		jiao = 0; 
		fen = 0; 
	} 
	CRmb(int, int, int);   // �������Ĺ��캯�� 
	CRmb(const CRmb &);      // �������캯�� 
	CRmb(double);        // ����ת�����캯��,��һ��ʵ������ת��������Ҷ���
	~CRmb();                // �������� 
	friend ostream & operator<<(ostream& out, const CRmb &);
	CRmb &operator++();
	CRmb operator++(int);
	friend CRmb operator+(const CRmb &lhs,const CRmb &rhs);
	friend CRmb operator+(const CRmb &lhs, double rhs);
	friend CRmb operator+(double lhs, const CRmb &rhs);
	// ����Ļ����� Rmb��ֵ�������ʽ���£� 
	//  �����У� Ԫ  ��  ��  
	//======���º����Լ����ԭ��========== 
	//(1)ǰ������������غ�����Ҫ��ʵ�ֶԷ�����1�����ҿ��ǽ�λ����  
	//(2)��������������غ�����Ҫ��ʵ�ֶԷ�����1�����ҿ��ǽ�λ����  
	//(3)���ء�+���������Ҫ��ʵ���������ּӷ�����  
	//a��CRmb����+CRmb���� 
	//b��CRmb����+double���� 
}; 
CRmb::CRmb(int inputyuan, int inputjiao, int inputfen)
{
	yuan = inputyuan;
	jiao = inputjiao;
	fen = inputfen;
}
CRmb::CRmb(const CRmb & other)
{
	yuan = other.yuan;
	jiao = other.jiao;
	fen = other.fen;
}

CRmb::CRmb(double num)
{
	yuan = int(num);
	jiao = int((num-yuan)*10);
	fen = int((num  - yuan - jiao/10.0)*100);
}

CRmb::~CRmb()
{
	cout<<"��������������!";
}
ostream & operator<<(ostream & out, const CRmb &rhs)
{
	out << rhs.yuan << "Ԫ" << rhs.jiao << "��" << rhs.fen << "��";
	return out;
}
CRmb & CRmb::operator++()
{
	if (++fen==10)
	{
		fen = 0;
		if (++jiao==10)
		{
			jiao = 0;
			++yuan;
		}
	}
	return *this;
}
CRmb CRmb::operator++(int)
{
	CRmb temp = *this;
	if (++fen == 10)
	{
		fen = 0;
		if (++jiao == 10)
		{
			jiao = 0;
			++yuan;
		}
	}
	return temp;
}
CRmb operator+(const CRmb & lhs, const CRmb & rhs)
{
	CRmb result;
	int temp;
	result.fen = lhs.fen + rhs.fen;
	if (result.fen >= 10)
	{
		result.fen %= 10;
	}
	temp = result.fen / 10;
	result.jiao = lhs.jiao + rhs.jiao;
	if (result.jiao >= 10)
	{
		result.jiao %= 10;
	}
	result.yuan= result.jiao / 10+lhs.yuan+rhs.yuan;
	return result;
}
CRmb operator+(const CRmb & lhs, double rhs)
{
	CRmb temp(rhs);
	return temp+lhs;
}
CRmb operator+(double lhs, const CRmb & rhs)
{
	CRmb temp(lhs);
	return temp + rhs;
}
void fn(const CRmb& x) 
{ 
	cout << "In fn: " << x << endl; 
}
void main()
{
	CRmb m1;  
	cout << m1 << endl << endl << endl;
	CRmb m2(1001, 9, 9); 
	m2++; 
	cout << m2 << endl; 
	++m2;  
	cout << m2 << endl << endl << endl;
	CRmb m3(m2);  
	cout << m3 << endl << endl << endl;

	CRmb m4 = m1 + m2;  
	cout << m4 << endl;  
	m4 = m1 + 50.0;  
	cout << m4 << endl << endl << endl;
	fn(50.13);
}