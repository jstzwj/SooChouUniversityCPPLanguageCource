#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
typedef vector<int> vecint;
const int LMT = 10000;

class cint
{
public:
	cint();
	cint(int num);
	inline void push_back(int num);
	cint operator+(const cint &rhs);
	cint & operator=(int rhs);
	//cint operator+=(const cint &rhs);
	cint multi(int num);
	void multitwo();
	friend ostream & operator<<(ostream &out,const cint &a);
	~cint();
private:
	vecint data;
};

cint::cint()
{
	data.reserve(3000);
}

cint::cint(int num)
{
	data.push_back(num);
	data.reserve(3000);
}

void cint::push_back(int num)
{
	data.push_back(num);
}

cint cint::operator+(const cint & rhs)
{
	cint result;
	const cint *greater;
	const cint * lesser;
	int temp;
	int next=0;
	vecint::iterator it;

	result.data.clear();
	if (this->data.size() > rhs.data.size())
	{
		greater = this;
		lesser = &rhs;
	}
	else
	{
		greater = &rhs;
		lesser = this;
	}
	//计算
	for (size_t i = 0; i < lesser->data.size();i++)
	{
		temp = greater->data[i] + lesser->data[i]+next;
		if (temp > LMT)
		{
			temp = temp - LMT;
			next = 1;
		}
		else
		{
			next = 0;
		}
		result.push_back(temp);
	}
	for (size_t i = lesser->data.size(); i < greater->data.size();i++)
	{
		temp = greater->data[i] +  next;
		if (temp > LMT)
		{
			temp = temp - LMT;
			next = 1;
		}
		else
		{
			next = 0;
		}
		result.push_back(temp);
	}
	if (next == 1)
	{
		result.push_back(1);
	}
	return result;
}

cint & cint::operator=(int rhs)
{
	// TODO: 在此处插入 return 语句
	data.clear();
	data.push_back(rhs);
	return *this;
}




cint cint::multi(int num)
{
	cint result;
	int temp;
	int next=0;

	for (size_t i = 0; i < data.size();i++)
	{
		temp = data[i] * num+next;
		if (temp > LMT)
		{
			next = temp/LMT;
			temp = temp % LMT;
		}
		else
		{
			next = 0;
		}
		result.push_back(temp);
	}
	if (next !=0)
	{
		result.push_back(next);
	}
	return result;
}

void cint::multitwo()
{
	int temp;
	int next = 0;
	size_t i;
	for (i = 0; i < data.size(); i++)
	{
		temp = data[i] *2 + next;
		if (temp > LMT)
		{
			next = temp / LMT;
			temp = temp % LMT;
		}
		else
		{
			next = 0;
		}
		this->data[i] = temp;
	}
	if (next != 0)
	{
		this->data.push_back(next);
	}
}

ostream & operator<<(ostream & out,const cint& a)
{
	if(a.data.size()!=0)
	cout << a.data[a.data.size()-1];
	if (a.data.size() > 1)
	{
		for (int i = a.data.size()-2; i >=0; i--)
		{
			cout << setfill('0') <<setw(5)<< a.data[i];
		}
	}
	return out;
}


cint::~cint()
{
}


int main()
{
	string input;
	string::reverse_iterator it;
	cint zhishu(1);
	cint result(0);
	while (1)
	{
		zhishu = 1;
		result = 0;
		cout << "请输入数字";
		cin >> input;
		for (it = input.rbegin(); it != input.rend();it++)
		{
			if (*it == '1')
			{
				result = result + zhishu;
			}
			zhishu.multitwo();
		}
		cout << result;
		system("pause");
	}
	
	return 0;
}