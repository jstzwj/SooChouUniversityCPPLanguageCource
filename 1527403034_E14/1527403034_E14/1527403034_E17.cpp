/*
姓名：王俊
日期：2016.5.17
备注：
*/
#include <iostream>
#include <cmath>
using namespace std;
class CTime
{
	int m_hour,m_minute,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值，否则赋值0 时0 分0 秒
	int SetTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值并返回1，否则不赋值，并返回0
	int getHour(){return m_hour;}
	int getMinute(){return m_minute;}
	int getSecond(){return m_second;}
	//flag 为True 则以24 小时制显示时间，否则以 AM PM 的方式显示
	void ShowTime(bool flag);
	//自己考虑是否需要添加其他成员函数
	bool isValid();
};
class CDate
{
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//如果日期合法，则赋值，否则赋值2000 年1 月1 日
	int SetDate(int year=2000,int month=1,int day=1);
	//如果日期合法，则赋值并返回1，否则不赋值，并返回0
	int GetYear(){return m_year;}
	int GetMonth(){return m_month;}
	int GetDay(){return m_day;}
	void ShowDate(bool flag);
	//flag 为TRUE，则以中文的方式显示日期，否则以MM/DD/YYYY 的方式显示日期
	//自己考虑是否需要添加其他成员函数
	bool isValid();
	//闰年
	bool isLeap();
};
class CDateTime
{
	CTime m_time;
	CDate m_date;
public:
	//添加必要的构造函数
	CDateTime (int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
	//int SetDateTime(...); 自己设计参数，考虑该函数的返回值加以表示全部正确、日期不对、时间不对等情况
	int SetDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
	//void ShowDateTime(...); 自己设计参数，考虑可以中文日期和西文日期格式，以及24 小时和AM PM 都可以控制
	void ShowDateTime(bool chinese,bool amorpm);

	int GetYear() { return m_date.GetYear(); }
	int GetMonth() { return m_date.GetMonth(); }
	int GetDay() { return m_date.GetDay(); }
	int GetHour() { return m_time.getHour(); }
	int GetMinute() { return m_time.getMinute(); }
	int GetSecond() { return m_time.getSecond(); }

	//添加自己认为必要的其他成员函数
	bool isValid();
};
//在主函数中验证上述类的功能，要求的主函数如下所示，不允许进行修改：
void main()
{
	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true); //第1个参数表示以英文方式显示日期, 第2个参数表示以24小时制方式显示时间
	CDateTime d2;
	d2.ShowDateTime(true, false); //第1个参数表示以中文方式显示日期, 第2个参数表示以AM PM的方式显示时间
	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"日期和时间数据设置正确!"<<endl;
	break;
	case -1:
		cout<<"日期数据设置不正确!"<<endl;
	break;
	case -2:
		cout<<"时间数据设置不正确!"<<endl;
	break;
	}
	d2.ShowDateTime(false, false); //第1个参数表示以英文方式显示日期, 第2个参数表示以AM PM的方式显示时间
	cout<<"月="<<d2.GetMonth()<<endl; //认真考虑一下如何实现此操作？
	cout<<"分钟="<<d2.GetMinute()<<endl; //认真考虑一下如何实现此操作？
	system("pause");
}
CTime::CTime(int hour,int minute,int second)
{
	m_hour = hour;
	m_minute = minute;
	m_second = second;
	if(!isValid())
	{
		m_hour = m_minute = m_second = 0;
	}
}
int CTime::SetTime(int hour,int minute,int second)
{
	m_hour=hour;
	m_minute=minute;
	m_second=second;
	if(!isValid())
	{
		m_hour = m_minute = m_second = 0;
		return -1;
	}
	return 1;
}
void CTime::ShowTime(bool flag)
{
	if(flag==true)
	{
		cout<<m_hour<<":"<<m_minute<<":"<<m_second;
	}
	else
	{
		if(m_hour>=1&&m_hour<=12)
		{
			cout<<m_hour<<":"<<m_minute<<":"<<m_second<<"AM";
		}
		else
		{
			if(m_hour==0)
			{
				cout<<12<<":"<<m_minute<<":"<<m_second<<"PM";
			}
			else
			{
				cout<<m_hour-12<<":"<<m_minute<<":"<<m_second<<"PM";
			}
			
		}
		
	}
}
bool CTime::isValid()
{
	return m_hour>=0&&m_hour<=23&&m_minute>=0&&m_minute<=59&&m_second>=0&&m_second<=59;
}
CDate::CDate(int year,int month,int day)
{
	m_year=year;
	m_month=month;
	m_day=day;
	if(!isValid())
	{
		m_year=m_month=m_day=0;
	}
}
int CDate::SetDate(int year,int month,int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
	if(!isValid())
	{
		m_year = m_month = m_day = 0;
		return -1;
	}
	return 1;
}
void CDate::ShowDate(bool flag)
{
	if(flag==true)
	{
		cout<<m_year<<"年"<<m_month<<"月"<<m_day<<"日";
	}
	else
	{
		cout<<m_month<<"/"<<m_day<<"/"<<m_year<<"/";
	}
}
bool CDate::isValid()
{
	int dayInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap())
	{
		dayInMonth[1]=29;
	}
	if(m_month>=1&&m_month<=12&&m_day>=1&&m_day<=dayInMonth[m_month-1])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CDate::isLeap()
{
	if((m_year%4==0)&&(m_year%100!=0)||(m_year%400==0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
CDateTime::CDateTime (int year,int month,int day,int hour,int minute,int second)
{
	m_date.SetDate(year, month, day);
	m_time.SetTime(hour, minute, second);
	if (!isValid())
	{
		m_date.SetDate(0,0,0);
		m_time.SetTime(0,0,0);
	}
}
int CDateTime::SetDateTime(int year, int month, int day, int hour, int minute,int second)
{
	
	m_date.SetDate(year,month,day);
	m_time.SetTime(hour, minute, second);
	if (!m_date.isValid())
	{
		m_date.SetDate(0, 0, 0);
		return -1;
	}
	if (!m_time.isValid())
	{
		m_time.SetTime(0, 0, 0);
		return -2;
	}
	return 1;
}
void CDateTime::ShowDateTime(bool chinese, bool amorpm)
{
	m_date.ShowDate(chinese);
	m_time.ShowTime(amorpm);
}
bool CDateTime::isValid()
{
	return m_date.isValid()&&m_time.isValid();
}
