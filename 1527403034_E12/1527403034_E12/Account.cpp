#include "Account.h"
#include<iostream>
using namespace std;
double CAccount::m_InterestRate=0.036;

CAccount::CAccount():m_Money(0.0){}


CAccount::~CAccount()
{
}


// 设置利息
void CAccount::SetInterestRate(double num)
{
	m_InterestRate=num;
}


// 获取利息
double CAccount::GetInterestRate()
{
	return m_InterestRate;
}


// 存钱
void CAccount::SaveMoney(const CDate &day,double money)
{
	m_date=day;
	m_Money=money;
}


// 取款
double CAccount::LendMoney(const CDate &day, double money)
{
	if (money<=m_Money)
	{
		if (day - m_date >= 0)
		{
			m_Money -= money;
			return money + money*m_InterestRate / 360 * (day-m_date);
		}
		else
		{
			cout << "日期有误" << endl;
		}
	}
	else
	{
		cout << "本金不足" << money << endl;
	}
}


// 计算利息
double CAccount::CalcInterest(const CDate &day)
{

	return  m_Money*m_InterestRate / 360 * (day - m_date);
}


// 结算利息
double CAccount::SaveInterest(const CDate &day)
{
	if (day - m_date >= 0)
	{
		m_Money = m_Money + m_Money*m_InterestRate / 360 * (day - m_date);
		m_date = day;
	}
	else
	{
		cout << "日期有误" << endl;
	}
	return m_Money;
}
