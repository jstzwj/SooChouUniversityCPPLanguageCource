/*
	�ļ�����1527403034_E03.cpp
	���ߣ�����
	ʱ�䣺2016/3/7
	���ܣ�
	��ע��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const string &a,const string &b);
void DictionarySort(vector<string> & mon);
void LenthSort(vector<string> & mon);
int main()
{
	vector<string> month;
	vector<string>::iterator i;
	//��ʼ��
	month.push_back("January");
	month.push_back("February");
	month.push_back("March");
	month.push_back("April");
	month.push_back("May");
	month.push_back("June");
	month.push_back("July");
	month.push_back("August");
	month.push_back("September");
	month.push_back("October");
	month.push_back("November");
	month.push_back("December");
	//���ֵ�����
	DictionarySort(month);
	//���
	cout << "���ֵ���С��������" << endl;
	for(i=month.begin();i!=month.end();i++)
	{
		cout<<*i<<endl;
	}
	//����������
	LenthSort(month);
	//���
	cout << "�������ɴ�С����" << endl;
	for (i = month.begin(); i != month.end(); i++)
	{
		cout << *i << endl;
	}

	return 0;
}

bool compare(const string & a,const string & b)
{
	return a.size() > b.size();
}

void DictionarySort(vector<string>& mon)
{
	sort(mon.begin(),mon.end());
}

void LenthSort(vector<string>& mon)
{
	sort(mon.begin(), mon.end(),compare);
}
