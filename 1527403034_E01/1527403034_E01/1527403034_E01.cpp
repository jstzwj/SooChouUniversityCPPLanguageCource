/*�ļ�����1527403034_E01.c
*���ߣ�����
*ʱ�䣺2016��3��5��
*���ܣ�
*��ע��
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
	//����
	for (int i = 0; i < 26; i++)
	{
		abc[i].ch = 'a' + i;
		abc[i].f= 0;
	}
	//����
	cout << "������һ���ַ���" << endl;
	cin >> str;
	//����Ƶ��
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
	//����
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
	//���
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