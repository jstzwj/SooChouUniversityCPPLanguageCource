/*
文件名：1527403034_E05.cpp
作者：王俊
时间：2016/3/7
功能：
备注：
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int temp[] ={ 35,46,57,13,24,35, 68,13,79,88,46 };
	vector<int> num(&temp[0],&temp[10]+1);
	vector<int>::iterator i;
	vector<int>::iterator j;
	//去除重复
	for (i = num.begin(); i < num.end(); i++)
	{
		for (j = i+1; j < num.end(); j++)
		{
			if (*i == *j)
			{
				j = num.erase(j);
				j--;
			}
		}
	}
	//排序
	sort(num.begin(), num.end());
	//输出
	for (vector<int>::iterator it = num.begin(); it != num.end();it++)
	{
		cout << *it<<endl;
	}
	system("pause");
	return 0;
}