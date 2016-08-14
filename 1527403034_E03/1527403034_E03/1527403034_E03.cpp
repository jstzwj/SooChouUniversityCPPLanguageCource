/*
	文件名：1527403034_E03.cpp
	作者：王俊
	时间：2016/3/7
	功能：
	备注：
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
	//初始化
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
	//按字典排序
	DictionarySort(month);
	//输出
	cout << "按字典由小到大排序：" << endl;
	for(i=month.begin();i!=month.end();i++)
	{
		cout<<*i<<endl;
	}
	//按长度排序
	LenthSort(month);
	//输出
	cout << "按长度由大到小排序：" << endl;
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
