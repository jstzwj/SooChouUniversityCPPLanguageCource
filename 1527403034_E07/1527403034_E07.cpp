/*
�ļ�����1527403034_E07.cpp
����������
���ڣ�2016��3��22��
��ע��
*/

#include <iostream>
#include <string>
using namespace std;

int GetLength(char *str)
{
	int len(0);
	while (str[len] != 0)
	{
		len++;
	}
	return len;
}

int GetLength(const string &str)
{
	return str.length();
}

int GetLength(int num)
{
	int len(0);
	for (len = 0; num>0; len++)
	{
		num = num / 10;
	}
	return len;
}

int GetLength(char)
{
	return 1;
}

int main()
{
	string type;
	string input_str;
	char input_char;
	int input_int;
	//����
	cout << "���������ͣ�\n" << endl;
	cin >> type;
	if (type == "char")
	{
		cout << "���������ݣ�\n";
		cin >> input_char;
		cout << "����Ϊ��";
		cout << GetLength(input_char);
	}
	else if (type == "string")
	{
		cout << "���������ݣ�\n";
		cin >> input_str;
		cout << "����Ϊ��";
		cout << GetLength(input_str);
	}
	else if (type == "int")
	{
		cout << "���������ݣ�\n";
		cin >> input_int;
		cout << "����Ϊ��";
		cout << GetLength(input_int);
	}
	else
	{
		cerr << "�����ڴ����ͣ�\n";
	}
	system("pause");
	return 0;
}

