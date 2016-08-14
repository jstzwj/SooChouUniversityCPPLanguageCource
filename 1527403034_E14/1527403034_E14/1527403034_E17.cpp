/*
����������
���ڣ�2016.5.17
��ע��
*/
#include <iostream>
#include <cmath>
using namespace std;
class CTime
{
	int m_hour,m_minute,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//���ʱ��Ϸ�����ֵ������ֵ0 ʱ0 ��0 ��
	int SetTime(int hour=0,int minute=0,int second=0);
	//���ʱ��Ϸ�����ֵ������1�����򲻸�ֵ��������0
	int getHour(){return m_hour;}
	int getMinute(){return m_minute;}
	int getSecond(){return m_second;}
	//flag ΪTrue ����24 Сʱ����ʾʱ�䣬������ AM PM �ķ�ʽ��ʾ
	void ShowTime(bool flag);
	//�Լ������Ƿ���Ҫ���������Ա����
	bool isValid();
};
class CDate
{
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//������ںϷ�����ֵ������ֵ2000 ��1 ��1 ��
	int SetDate(int year=2000,int month=1,int day=1);
	//������ںϷ�����ֵ������1�����򲻸�ֵ��������0
	int GetYear(){return m_year;}
	int GetMonth(){return m_month;}
	int GetDay(){return m_day;}
	void ShowDate(bool flag);
	//flag ΪTRUE���������ĵķ�ʽ��ʾ���ڣ�������MM/DD/YYYY �ķ�ʽ��ʾ����
	//�Լ������Ƿ���Ҫ���������Ա����
	bool isValid();
	//����
	bool isLeap();
};
class CDateTime
{
	CTime m_time;
	CDate m_date;
public:
	//��ӱ�Ҫ�Ĺ��캯��
	CDateTime (int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
	//int SetDateTime(...); �Լ���Ʋ��������Ǹú����ķ���ֵ���Ա�ʾȫ����ȷ�����ڲ��ԡ�ʱ�䲻�Ե����
	int SetDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
	//void ShowDateTime(...); �Լ���Ʋ��������ǿ����������ں��������ڸ�ʽ���Լ�24 Сʱ��AM PM �����Կ���
	void ShowDateTime(bool chinese,bool amorpm);

	int GetYear() { return m_date.GetYear(); }
	int GetMonth() { return m_date.GetMonth(); }
	int GetDay() { return m_date.GetDay(); }
	int GetHour() { return m_time.getHour(); }
	int GetMinute() { return m_time.getMinute(); }
	int GetSecond() { return m_time.getSecond(); }

	//����Լ���Ϊ��Ҫ��������Ա����
	bool isValid();
};
//������������֤������Ĺ��ܣ�Ҫ���������������ʾ������������޸ģ�
void main()
{
	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true); //��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��24Сʱ�Ʒ�ʽ��ʾʱ��
	CDateTime d2;
	d2.ShowDateTime(true, false); //��1��������ʾ�����ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��
	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"���ں�ʱ������������ȷ!"<<endl;
	break;
	case -1:
		cout<<"�����������ò���ȷ!"<<endl;
	break;
	case -2:
		cout<<"ʱ���������ò���ȷ!"<<endl;
	break;
	}
	d2.ShowDateTime(false, false); //��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��
	cout<<"��="<<d2.GetMonth()<<endl; //���濼��һ�����ʵ�ִ˲�����
	cout<<"����="<<d2.GetMinute()<<endl; //���濼��һ�����ʵ�ִ˲�����
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
		cout<<m_year<<"��"<<m_month<<"��"<<m_day<<"��";
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
