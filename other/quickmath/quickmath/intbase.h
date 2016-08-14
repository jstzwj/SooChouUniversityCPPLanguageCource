#pragma once
typedef long long LLONG;
const long long LMT=10e9;
class intbase
{
public:
	intbase();
	intbase(int num);
	intbase(intbase &from);
	intbase operator=(intbase &from);
	~intbase();
protected:

private:
	static int m_num;
	LLONG * m_start;
};

