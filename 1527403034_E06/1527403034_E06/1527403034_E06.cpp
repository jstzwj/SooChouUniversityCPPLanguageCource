/*
	文件名：1527403034_E06.cpp
	作者：王俊
	时间：2016/3/7
	功能：
	备注：
*/

#include<iostream>
using namespace std;
int cal(int lhs,int rhs,int &gcd,int &lcm)
{
	//计算最小公约数
	int temp;
	int a,b;
	a=lhs;
	b=rhs;
	//小于0的情况
	if(lhs<=0)
	{
		cerr << "第一个数不是自然数\n";
		return 1;
	}
	if(rhs<=0)
	{
		cerr << "第二个数不是自然数\n";
		return 1;
	}
	//计算最大公约数
	if(lhs<rhs)
	{
		temp=lhs;
		lhs=rhs;
		rhs=temp;
	}
	if(rhs==0)
	{
		return 1;
	}
	while(temp>0)
	{
		temp=lhs%rhs;
		lhs=rhs;
		rhs=temp;
	}
	//计算最小公倍数
	gcd=lhs;
	lcm=a*b/gcd;
	return 0;
}
int main()
{
	int a,b;
	int gcd,lcm;
	int state = 0;
	cout<<"请输入两个数："<<endl;
	cin>>a>>b;
	state=cal(a,b,gcd,lcm);
	if (state == 0)
	{
		cout<<"最大公约数为："<<gcd<<endl;
		cout<<"最小公倍数为："<<lcm<<endl;
	}
	system("pause");
	return 0;
}