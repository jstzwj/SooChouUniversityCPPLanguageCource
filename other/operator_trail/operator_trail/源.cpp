#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class widget
{
public:
	int smth;
	widget & operator <<(int num);
};
int main()
{
	widget a;


	cout << "����" << endl;
	system("pause");
	a.smth = 100;
	a << 1;
	cout << a.smth;
	system("pause");
	return 0;
}

widget & widget::operator<<(int num)
{
	smth -= num;
	return *this;
}
