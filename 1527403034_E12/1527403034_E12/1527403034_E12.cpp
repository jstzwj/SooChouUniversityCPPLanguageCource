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
	// 设置利息
	static void SetInterestRate(double num);
	// 获取利息
	static double GetInterestRate();
	// 存钱
	void SaveMoney(const CDate &day, double money);
	// 取款
	double LendMoney(const CDate &day, double money);
	// 计算利息
	double CalcInterest(const CDate &day);
	// 结算利息
	double SaveInterest(const CDate &day);
	//获得金额
	double getMoney()const { return m_Money; }
	//获得日期
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


// 设置利息
void CAccount::SetInterestRate(double num)
{
	m_InterestRate = num;
}


// 获取利息
double CAccount::GetInterestRate()
{
	return m_InterestRate;
}


// 存钱
void CAccount::SaveMoney(const CDate &day, double money)
{
	if (day.isVaild() == true)
	{
		m_date = day;
		m_Money = money;
	}
	else
	{
		cout << "日期不合法，存钱失败！" << endl;
	}
	
}


// 取款
double CAccount::LendMoney(const CDate &day, double money)
{
	if (day.isVaild() == false)
	{
		cout << "日期不合法，取款失败！" << endl;
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
			cout << "日期有误" << endl;
			
		}
	}
	else
	{
		cout << "本金不足" << money << endl;
	}
	return 0.0;
}


// 计算利息
double CAccount::CalcInterest(const CDate &day)
{
	if (day-m_date<0)
	{
		cout << "日期不合法！无法计算" << endl;
		return 0.0;
	}
	if (day.isVaild()==false)
	{
		cout << "日期不合法！" << endl;
		return 0.0;
	}
	return  m_Money*m_InterestRate / 360 * (day - m_date);
}


// 结算利息
double CAccount::SaveInterest(const CDate &day)
{
	if (day.isVaild() == false)
	{
		cout << "日期不合法！" << endl;
		return 0.0;
	}
	if (day - m_date >= 0)
	{
		m_Money = m_Money + m_Money*m_InterestRate / 360 * (day - m_date+1);
		m_date = day;
	}
	else
	{
		cout << "日期有误" << endl;
	}
	return m_Money;
}



int main()
{
	double money;
	int y, m, d;
	CAccount account;
	//存款
	cout << "请输入存款日期："<<endl;
	cin >> y >> m >> d;
	cout << "请输入存款金额："<<endl;
	cin >> money;

	account.SaveMoney(CDate(y,m,d),money);

	//结算利息
	cout << "请输入结算利息的日期" << endl;
	cin >> y >> m >> d;
	account.SaveInterest(CDate(y,m,d));

	cout << "余额增加至" << account.getMoney()<<endl;
	cout << "存款日期改为" << account.getDate().getYear()<<"年"<<account.getDate().getMonth()<<"月"<<account.getDate().getDay()<<"日"<<endl;

	//取款
	cout << "请输入取款日期：" << endl;
	cin >> y >> m >> d;
	cout << "请输入取款金额：" << endl;
	cin >> money;

	cout << "取款金额：" << account.LendMoney(CDate(y, m, d), money) <<endl;
	cout << "余额：" << account.getMoney()<<endl;
	return 0;
} 
