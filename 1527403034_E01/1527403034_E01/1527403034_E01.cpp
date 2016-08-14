/*文件名：1527403034_E01.c
*作者：王俊
*时间：2016年3月5日
*功能：
*备注：
*/
#include<iostream>
#include<string>
using namespace std;
class alphabet
{
public:
	char ch;
	int f;
};
int main()
{
	alphabet abc[26];
	string str;
	alphabet temp;
	//构造
	for (int i = 0; i < 26; i++)
	{
		abc[i].ch = 'a' + i;
		abc[i].f= 0;
	}
	//输入
	cout << "请输入一个字符串" << endl;
	cin >> str;
	//计算频率
	for (string::iterator it = str.begin(); it < str.end(); it++)
	{
		if (*it >= 'a'&&*it <= 'z')
		{
			abc[*it - 'a'].f++;

		}
		else if (*it >= 'A'&&*it <= 'Z')
		{
			abc[*it - 'A'].f++;
		}
	}
	//排序
	for (int i = 0; i < 26; i++)
	{
		for (int j = 25; j >i; j--)
		{
			if (abc[j].f > abc[j - 1].f)
			{
				temp= abc[j];
				abc[j]= abc[j - 1];
				abc[j - 1] = temp;
			}
		}
	}
	//输出
	for (int i = 0; i < 26;i++)
	{
		if (abc[i].f != 0)
		{
			cout << abc[i].ch << '\t' << abc[i].f<<endl;
		}

	}

	system("pause");
	return 0;
}