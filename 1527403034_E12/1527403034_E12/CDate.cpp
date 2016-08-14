#include"Date.h"
bool CDate::isVaild()
{
	if(m_month>=1&&m_month<=12&&m_day>=1&&m_day<=30)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int operator-(const CDate &lhs,const CDate &rhs)
{
	return 360*(lhs.m_year-rhs.m_year)+30*(lhs.m_month-rhs.m_month)+lhs.m_day-rhs.m_day;
}

CDate operator-(const CDate &lhs,int day)
{
	return CDate(lhs.m_year-day/360,lhs.m_month-day/30,lhs.m_day-day%30);
}

CDate operator+(const CDate &lhs,int day)
{
	return CDate(lhs.m_year+day/360,lhs.m_month+day/30,lhs.m_day+day%30);
}
CDate & CDate::operator ++()
{
	return *this+1;
}
CDate & CDate::operator --()
{
	return *this-1;
}
CDate CDate::operator ++(int)
{
	CDate temp(*this);
	*this=*this+1;
	return temp;
}
CDate CDate::operator --(int)
{
	CDate temp(*this);
	*this=*this-1;
	return temp;
}
