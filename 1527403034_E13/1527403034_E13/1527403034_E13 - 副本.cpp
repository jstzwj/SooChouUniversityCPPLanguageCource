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
	os << complex.m_real << "+" << complex.m_image << "*i";
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
string ftoa(double d)
{
	ostringstream os;
	if (os << d)
	{
		return os.str();
	}
	else
	{
		throw "invalid conversion";
		return string();
	}
}
string complex2string(const CComplex &complex)
{
	if (complex.getImage()>=-10e-6&&complex.getImage()<=10e-6)
	{
		return string(ftoa(complex.getReal()));
	}
	else
	{
		return string("("+ftoa(complex.getReal())+"+"+ftoa(complex.getImage())+"*i)");
	}
}

CComplex string2complex(const string & str)
{
	double x, y;
	unsigned int itplus=0;
	unsigned int itbegin=0;
	unsigned int it=0;
	CComplex complex;
	for (it = 0; it < str.length();++it)
	{
		if (str.at(it) >= '0' && str.at(it) <= '9')
		{
			break;
		}
	}
	itbegin = it;
	for (; it < str.length();++it)
	{
		if (str.at(it)=='+')
		{
			itplus = it;
			x = atof(str.substr(itbegin,it).c_str());
		}
		else if (str.at(it)=='*')
		{
			y = atof(str.substr(itplus + 1, it - itplus - 1).c_str());
		}
	}
	if (itplus==0)
	{
		x = atof(str.c_str());
		y = 0.0;
	}
	complex.setValue(x, y);
	return complex;
}



int main()
{
	double x, y;
	CComplex a,b;
	regex re;
	string str;
	string strtemp;
	smatch match;
	
	cout << "请输入表达式，注意复数用括号括起来" << endl;
	cin >> str;
	//后自增
	re.assign("\\((\\d*\\.?\\d+)\\+(\\d*\\.?\\d+)\\*i\\)\\+\\+");
	regex_replace(str,re,"($1+$2*i)");
	//前自增
	re.assign("\\+\\+\\((\\d*\\.?\\d+)\\+(\\d*\\.?\\d+)\\*i\\)");
	while (regex_search(str,match, re))
	{
		strtemp = match[0].str();
		a=string2complex(strtemp);
		++a;//自增
		str =  match.prefix().str()+ complex2string(a) + match.suffix().str();
	}
	//加法
	re.assign("\\d*\\.?\\d+\\+\\(\\d*\\.?\\d+\\+\\d*\\.?\\d+\\*i\\)");
	while (regex_search(str, match, re))
	{
		strtemp = match[0].str();
		unsigned itplus=strtemp.length();
		for (unsigned i = 0; i < strtemp.length();++i)
		{
			if (strtemp[i]=='+'&&strtemp[i+1]=='(')
			{
				itplus = i;
				break;
			}
		}
		a = string2complex(strtemp.substr(0,itplus));
		b= string2complex(strtemp.substr(itplus+1,strtemp.length()-itplus-1));
		a = a + b;//加法
		str = match.prefix().str() + complex2string(a) + match.suffix().str();
	}
	//加法
	re.assign("\\(\\d*\\.?\\d+\\+\\d*\\.?\\d+\\*i\\)\\+\\d*\\.?\\d+");
	while (regex_search(str, match, re))
	{
		strtemp = match[0].str();
		unsigned itplus = strtemp.length();
		for (unsigned i = 1; i < strtemp.length(); ++i)
		{
			if (strtemp[i] == '+'&&strtemp[i-1]==')')
			{
				itplus = i;
				break;
			}
		}
		a = string2complex(strtemp.substr(0, itplus));
		b = string2complex(strtemp.substr(itplus + 1, strtemp.length() - itplus - 1));
		a = a + b;//加法
		str = match.prefix().str() + complex2string(a) + match.suffix().str();
	}
	//加法
	re.assign("\\(\\d*\\.?\\d+\\+\\d*\\.?\\d+\\*i\\)\\+\\(\\d*\\.?\\d+\\+\\d*\\.?\\d+\\*i\\)");
	while (regex_search(str, match, re))
	{
		strtemp = match[0].str();
		unsigned itplus = strtemp.length();
		for (unsigned i = 0; i < strtemp.length(); ++i)
		{
			if (strtemp[i] == '+'&&strtemp[i+1]=='(')
			{
				itplus = i;
				break;
			}
		}
		a = string2complex(strtemp.substr(0, itplus));
		b = string2complex(strtemp.substr(itplus + 1, strtemp.length() - itplus - 1));
		a = a + b;//加法
		str = match.prefix().str() + complex2string(a) + match.suffix().str();
	}
	cout << str<<endl;
	system("pause");
	return 0;
}