#pragma once
class CDate
{
public:
	CDate(int year=0,int month=0,int day=0):m_year(year),m_month(month),m_day(day){}
	bool isVaild();
	friend int operator-(const CDate &lhs,const CDate &rhs);
	friend CDate operator-(const CDate &lhs,int day);
	friend CDate operator+(const CDate &lhs,int day);
	CDate & operator ++();
	CDate & operator --();
	CDate operator ++(int);
	CDate operator --(int);
private:
	int m_year;
	int m_month;
	int m_day;
};


