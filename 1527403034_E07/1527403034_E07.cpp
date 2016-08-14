/*
文件名：1527403034_E07.cpp
姓名：王俊
日期：2016年3月22日
备注：
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
	//输入
	cout << "请输入类型：\n" << endl;
	cin >> type;
	if (type == "char")
	{
		cout << "请输入数据：\n";
		cin >> input_char;
		cout << "长度为：";
		cout << GetLength(input_char);
	}
	else if (type == "string")
	{
		cout << "请输入数据：\n";
		cin >> input_str;
		cout << "长度为：";
		cout << GetLength(input_str);
	}
	else if (type == "int")
	{
		cout << "请输入数据：\n";
		cin >> input_int;
		cout << "长度为：";
		cout << GetLength(input_int);
	}
	else
	{
		cerr << "不存在此类型！\n";
	}
	system("pause");
	return 0;
}

