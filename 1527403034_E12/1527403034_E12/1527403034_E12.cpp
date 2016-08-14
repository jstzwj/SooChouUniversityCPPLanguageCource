#include<iostream>
using namespace std;
class CDate
{
public:
	CDate(int year = 0, int month = 0, int day = 0) :m_year(year), m_month(month), m_day(day) {}
	bool isVaild()const;
	friend int operator-(const CDate &lhs, const CDate &rhs);
	friend CDate operator-(const CDate &lhs, int day);
	friend CDate operator+(const CDate &lhs, int day);
	CDate & operator ++();
	CDate & operator --();
	CDate operator ++(int);
	CDate operator --(int);

	int getYear()const { return m_year; }
	int getMonth()const { return m_month; }
	int getDay()const { return m_day; }
private:
	int m_year;
	int m_month;
	int m_day;
};


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
	void SaveMoney(const CDate &day, double money);
	// ȡ��
	double LendMoney(const CDate &day, double money);
	// ������Ϣ
	double CalcInterest(const CDate &day);
	// ������Ϣ
	double SaveInterest(const CDate &day);
	//��ý��
	double getMoney()const { return m_Money; }
	//�������
	CDate getDate()const { return m_date; }
};

bool CDate::isVaild()const
{
	if (m_month >= 1 && m_month <= 12 && m_day >= 1 && m_day <= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int operator-(const CDate &lhs, const CDate &rhs)
{
	return 360 * (lhs.m_year - rhs.m_year) + 30 * (lhs.m_month - rhs.m_month) + lhs.m_day - rhs.m_day;
}

CDate operator-(const CDate &lhs, int day)
{
	return CDate(lhs.m_year - day / 360, lhs.m_month - day / 30, lhs.m_day - day % 30);
}

CDate operator+(const CDate &lhs, int day)
{
	return CDate(lhs.m_year + day / 360, lhs.m_month + day / 30, lhs.m_day + day % 30);
}
CDate & CDate::operator ++()
{
	return *this + 1;
}
CDate & CDate::operator --()
{
	return *this - 1;
}
CDate CDate::operator ++(int)
{
	CDate temp(*this);
	*this = *this + 1;
	return temp;
}
CDate CDate::operator --(int)
{
	CDate temp(*this);
	*this = *this - 1;
	return temp;
}


double CAccount::m_InterestRate = 0.036;

CAccount::CAccount() :m_Money(0.0) {}


CAccount::~CAccount()
{
}


// ������Ϣ
void CAccount::SetInterestRate(double num)
{
	m_InterestRate = num;
}


// ��ȡ��Ϣ
double CAccount::GetInterestRate()
{
	return m_InterestRate;
}


// ��Ǯ
void CAccount::SaveMoney(const CDate &day, double money)
{
	if (day.isVaild() == true)
	{
		m_date = day;
		m_Money = money;
	}
	else
	{
		cout << "���ڲ��Ϸ�����Ǯʧ�ܣ�" << endl;
	}
	
}


// ȡ��
double CAccount::LendMoney(const CDate &day, double money)
{
	if (day.isVaild() == false)
	{
		cout << "���ڲ��Ϸ���ȡ��ʧ�ܣ�" << endl;
		return 0.0;
	}
	if (money <= m_Money)
	{

		if (day - m_date >= 0)
		{
			m_Money = m_Money-money;
			return money + money*m_InterestRate / 360 * (day - m_date + 1);
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
	return 0.0;
}


// ������Ϣ
double CAccount::CalcInterest(const CDate &day)
{
	if (day-m_date<0)
	{
		cout << "���ڲ��Ϸ����޷�����" << endl;
		return 0.0;
	}
	if (day.isVaild()==false)
	{
		cout << "���ڲ��Ϸ���" << endl;
		return 0.0;
	}
	return  m_Money*m_InterestRate / 360 * (day - m_date);
}


// ������Ϣ
double CAccount::SaveInterest(const CDate &day)
{
	if (day.isVaild() == false)
	{
		cout << "���ڲ��Ϸ���" << endl;
		return 0.0;
	}
	if (day - m_date >= 0)
	{
		m_Money = m_Money + m_Money*m_InterestRate / 360 * (day - m_date+1);
		m_date = day;
	}
	else
	{
		cout << "��������" << endl;
	}
	return m_Money;
}



int main()
{
	double money;
	int y, m, d;
	CAccount account;
	//���
	cout << "�����������ڣ�"<<endl;
	cin >> y >> m >> d;
	cout << "���������"<<endl;
	cin >> money;

	account.SaveMoney(CDate(y,m,d),money);

	//������Ϣ
	cout << "�����������Ϣ������" << endl;
	cin >> y >> m >> d;
	account.SaveInterest(CDate(y,m,d));

	cout << "���������" << account.getMoney()<<endl;
	cout << "������ڸ�Ϊ" << account.getDate().getYear()<<"��"<<account.getDate().getMonth()<<"��"<<account.getDate().getDay()<<"��"<<endl;

	//ȡ��
	cout << "������ȡ�����ڣ�" << endl;
	cin >> y >> m >> d;
	cout << "������ȡ���" << endl;
	cin >> money;

	cout << "ȡ���" << account.LendMoney(CDate(y, m, d), money) <<endl;
	cout << "��" << account.getMoney()<<endl;
	return 0;
} 
