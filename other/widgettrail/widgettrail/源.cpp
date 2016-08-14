#include<iostream>
using std::cout;
using std::endl;
class widget
{
public:
	enum inner { a };
	friend inner operator |(const widget &lhs, const widget &rhs);
};

widget::inner operator |(const widget &lhs, const widget &rhs)
{
	return widget::a;
}
int main(int argc, char *argv[])
{
	widget a, b;
	cout << (a | b) << endl;
	return 0;
}


