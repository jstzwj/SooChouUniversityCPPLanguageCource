/*
姓名：王俊
日期：2016.5.17
备注：
*/
#include<iostream>
#include<string>
using namespace std;
class CString {
	char * m_pbuff;  //指向字符串的指针  
	int  m_length;   //表示当前字符串的最大允许长度，也就是字符数组的长度 
public:  
	CString(); //构造函数1，设置为空字符串，m_length=100
	~CString();
	CString(const CString &src);
	CString(char *src);  //构造函数2，在考虑了src的长度后初始化当前对象,m_length>=src的长度+1 
	CString(char ch); //构造函数3，0号元素赋值为ch, m_length=100  
	CString &operator=(const CString &src);
	int setString(char *src);  //设置字符串，在考虑了src的长度后设置当前对象,m_length>=src的长度+1  
	friend ostream& operator<<(ostream& Out, const CString& S);  //输出字符串 
};

CString::CString() :m_pbuff(NULL), m_length(0)
{
	m_pbuff = new char[1];
	m_pbuff[0] = '\0';
}

CString::~CString()
{
	if (m_length!=0)
	{
		delete []m_pbuff;
	}
}
CString::CString(const CString &src)
{
	m_pbuff = new char[src.m_length+1];
	if (m_pbuff==NULL)
	{
		return;
	}
	strcpy_s(m_pbuff, src.m_length + 1,src.m_pbuff);
	m_length = src.m_length;
}

CString & CString::operator=(const CString & src)
{
	char *temp = m_pbuff;
	m_pbuff = new char[src.m_length + 1];	
	strcpy_s(m_pbuff, src.m_length + 1, src.m_pbuff);
	if (m_length != 0)
	{
		delete m_pbuff;
	}
	m_length = src.m_length;
	return *this;
}

CString::CString(char * src)
{
	int len = strlen(src)+1;
	m_pbuff = new char[len];
	if (m_pbuff == NULL)
	{
		return;
	}
	strcpy_s(m_pbuff, len,src);
	m_length = len;
}

CString::CString(char ch)
{
	m_pbuff = new char[1];
	m_pbuff[0] = ch;
	m_pbuff[1] = '\0';
	m_length = 1;
}

int CString::setString(char * src)
{
	int len = strlen(src) + 1;
	char *temp = m_pbuff;
	m_pbuff = new char[len];
	if (m_pbuff == NULL)
	{
		return -1;
	}
	strcpy_s(m_pbuff, len, src);
	m_length = len;
	if (m_length != 0)
	{
		delete []temp;
	}
	return len;
}

ostream & operator<<(ostream & Out, const CString & S)
{
	Out << S.m_pbuff;
	return Out;
}
void main()
{
	CString s1; 
	cout << s1; 
	s1.setString("abc1"); 
	cout << s1;
	CString s2("abc2");  
	cout << s2;
	CString s3('a');
	cout << s3;
	CString s4(s2);  
	cout << s4;
	system("pause");
}
