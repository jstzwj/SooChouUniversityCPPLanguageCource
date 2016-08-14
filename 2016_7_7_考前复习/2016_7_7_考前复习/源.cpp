#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class CGoods
{
private:
	int m_num;	//��Ʒ���
	string m_name;	//��Ʒ����
	float m_price;	//��Ʒ�۸�

public:
	CGoods(int num, const string& name, float price);
	friend ostream& operator<<(ostream&, const CGoods&);
	//��Ʒ���ơ���Ʒ��ź���Ʒ�۸����ʾ��ʽ��Ҫ��Ϊռ10�С��Ҷ���
};
CGoods::CGoods(int num, const string& name, float price)
	:m_num(num), m_name(name), m_price(price) 
{}
ostream& operator<<(ostream& out, const CGoods& rhs)
{
	out << setw(10) << right << rhs.m_num
		<< setw(10) << right << rhs.m_name
		<< setw(10) << right << rhs.m_price;

}


//CRouter����
class CRouter :public  CGoods
{
private:
	float m_frequency;
	int m_portnum;
public:
	CRouter(int num = 1, const string& name="M8", float price = 100.0f, float frequency = 2.4f, int portnum = 8);
	int GetChannels() { return m_portnum; }
	float GetFrequency() { return m_frequency; }
	CRouter &operator++();
	CRouter operator++(int);
	friend ostream & opertor << (ostream &out,const CRouter & rhs);

};
ostream & opertor << (ostream &out, const & CRouter rhs)
{

}
CRouter::CRouter(int num, const string& name, float price, float frequency, int portnum)
	:CGoods(num, name, price) ,m_frequency(frequency),m_portnum(portnum)
{
}

CRouter & CRouter::operator++()
{
	++(this->m_portnum);
	return *this;
}
CRouter CRouter::operator++(int)
{
	CRouter temp(*this);
	++(this->m_portnum);
	return temp;
}

void main()
{
	vector<CRouter> s;

	ReadData(s, "D:\\Data.txt");
	cout << "��ȡ��ɺ������Ϊ" << endl;
	DisplayData(s);

	CRouter t;
	cout << endl << "·��������ĳ�ʼֵΪ" << endl << t << endl;

	t = FindMax(s);
	cout << endl << "�˻���������Ԫ��Ϊ" << endl << t << endl;

	cout << endl << "�˻���������Ԫ�ؽ��������������ֱ�����:" << endl;
	cout << t++ << endl;
	cout << t << endl;

	cout << ++t << endl;
	cout << t << endl;
}
