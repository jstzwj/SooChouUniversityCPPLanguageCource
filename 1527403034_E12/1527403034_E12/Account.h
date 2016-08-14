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
	// 设置利息
	static void SetInterestRate(double num);
	// 获取利息
	static double GetInterestRate();
	// 存钱
	void SaveMoney(const CDate &day,double money);
	// 取款
	double LendMoney(const CDate &day,double money);
	// 计算利息
	double CalcInterest(const CDate &day);
	// 结算利息
	double SaveInterest(const CDate &day);
};

