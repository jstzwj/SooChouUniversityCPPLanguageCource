#include "Account.h"
#include<iostream>
using namespace std;
double CAccount::m_InterestRate=0.036;

CAccount::CAccount():m_Money(0.0){}


CAccount::~CAccount()
{
}


// ������Ϣ
void CAccount::SetInterestRate(double num)
{
	m_InterestRate=num;
}


// ��ȡ��Ϣ
double CAccount::GetInterestRate()
{
	return m_InterestRate;
}


// ��Ǯ
void CAccount::SaveMoney(const CDate &day,double money)
{
	m_date=day;
	m_Money=money;
}


// ȡ��
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
			cout << "��������" << endl;
		}
	}
	else
	{
		cout << "������" << money << endl;
	}
}


// ������Ϣ
double CAccount::CalcInterest(const CDate &day)
{

	return  m_Money*m_InterestRate / 360 * (day - m_date);
}


// ������Ϣ
double CAccount::SaveInterest(const CDate &day)
{
	if (day - m_date >= 0)
	{
		m_Money = m_Money + m_Money*m_InterestRate / 360 * (day - m_date);
		m_date = day;
	}
	else
	{
		cout << "��������" << endl;
	}
	return m_Money;
}
