/*
����������
���ڣ�2016.5.17
��ע��
*/
#include<iostream>
using namespace std;

#define MAXLENGTH 1000
class CString 
{  
	char m_buff[MAXLENGTH]; 
public:  
	CString();    //���캯��1������Ϊ���ַ���  
	CString(char *src);		//���캯��2���ڿ�����src�ĳ����Ƿ�Ϸ����ʼ����ǰ���� 
	CString(char ch);	 //���캯��3��0��Ԫ�ظ�ֵΪch  
	int setString(char *src);	 //�����ַ������ڿ�����src�ĳ����Ƿ�Ϸ������õ�ǰ���� 
	char & operator[](int index);
	friend ostream& operator<<(ostream& Out, const CString& S);		//����� ����
}; 

CString::CString()
{
	m_buff[0] = '\0';
}

CString::CString(char * src)
{
	int i = 0;
	//��ȡ����
	for (; src[i] != '\0'; ++i);
	if (i > MAXLENGTH - 1)
	{
		throw "Out of length error";
	}
	//���θ�ֵ
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
	//��ȡ����
	for (; src[len] != '\0'; ++len);
	if (len > MAXLENGTH - 1)
	{
		throw "Out of length error";
	}
	//���θ�ֵ
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