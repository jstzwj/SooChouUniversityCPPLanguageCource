/*
姓名：王俊
日期：2016.5.17
备注：
*/
#include<iostream>
using namespace std;

#define MAXLENGTH 1000
class CString 
{  
	char m_buff[MAXLENGTH]; 
public:  
	CString();    //构造函数1，设置为空字符串  
	CString(char *src);		//构造函数2，在考虑了src的长度是否合法后初始化当前对象 
	CString(char ch);	 //构造函数3，0号元素赋值为ch  
	int setString(char *src);	 //设置字符串，在考虑了src的长度是否合法后设置当前对象 
	char & operator[](int index);
	friend ostream& operator<<(ostream& Out, const CString& S);		//输出字 符串
}; 

CString::CString()
{
	m_buff[0] = '\0';
}

CString::CString(char * src)
{
	int i = 0;
	//获取长度
	for (; src[i] != '\0'; ++i);
	if (i > MAXLENGTH - 1)
	{
		throw "Out of length error";
	}
	//依次赋值
	i = 0;
	while (src[i]!='\0')
	{
		m_buff[i] = src[i];
		++i;
	}
	m_buff[i] = '\0';
}

CString::CString(char ch)
{
	if (m_buff[0]!='\0')
	{
		m_buff[0] = ch;
		m_buff[1] = '\0';
	}
	
}


int CString::setString(char * src)
{
	int len = 0;
	//获取长度
	for (; src[len] != '\0'; ++len);
	if (len > MAXLENGTH - 1)
	{
		throw "Out of length error";
	}
	//依次赋值
	int i = 0;
	while (src[i] != '\0')
	{
		m_buff[i] = src[i];
		++i;
	}
	m_buff[i] = '\0';
	return len;
}


ostream & operator<<(ostream & Out, const CString & S)
{
	Out << S.m_buff;
	return Out;
}

char & CString::operator[](int index)
{
	return m_buff[index];
}

void main() {
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
}