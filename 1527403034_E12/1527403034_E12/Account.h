#pragma once
#include"Date.h"

class CAccount
{
public:
	CAccount();
	~CAccount();

private:
	double m_Money;
	static double m_InterestRate;
	CDate m_date;
public:
	// ������Ϣ
	static void SetInterestRate(double num);
	// ��ȡ��Ϣ
	static double GetInterestRate();
	// ��Ǯ
	void SaveMoney(const CDate &day,double money);
	// ȡ��
	double LendMoney(const CDate &day,double money);
	// ������Ϣ
	double CalcInterest(const CDate &day);
	// ������Ϣ
	double SaveInterest(const CDate &day);
};

