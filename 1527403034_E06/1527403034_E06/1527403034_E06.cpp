/*
	�ļ�����1527403034_E06.cpp
	���ߣ�����
	ʱ�䣺2016/3/7
	���ܣ�
	��ע��
*/

#include<iostream>
using namespace std;
int cal(int lhs,int rhs,int &gcd,int &lcm)
{
	//������С��Լ��
	int temp;
	int a,b;
	a=lhs;
	b=rhs;
	//С��0�����
	if(lhs<=0)
	{
		cerr << "��һ����������Ȼ��\n";
		return 1;
	}
	if(rhs<=0)
	{
		cerr << "�ڶ�����������Ȼ��\n";
		return 1;
	}
	//�������Լ��
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
	//������С������
	gcd=lhs;
	lcm=a*b/gcd;
	return 0;
}
int main()
{
	int a,b;
	int gcd,lcm;
	int state = 0;
	cout<<"��������������"<<endl;
	cin>>a>>b;
	state=cal(a,b,gcd,lcm);
	if (state == 0)
	{
		cout<<"���Լ��Ϊ��"<<gcd<<endl;
		cout<<"��С������Ϊ��"<<lcm<<endl;
	}
	system("pause");
	return 0;
}