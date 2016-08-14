#include"unit.h"
#include"brain.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	brain br;
	while (cin>>str)
	{
		//构建
		for (int i = 0; i < str.length(); ++i)
		{
			//添加基本元素
			if (!br.isContain(str[i]))
			{
				br.cells.push_back(unit(str[i],1.0));
			}
		}

		//添加隐藏层
		br.addlink();
		//刺激
		for (int i = 0; i < str.length(); ++i)
		{
			br.stim(i);
		}
		br.print();
		//衰减

	}
	return 0;
}