#include "intbase.h"

int m_num = 1;

intbase::intbase()
{
	m_start = new LLONG[m_num];
}

intbase::intbase(int num)
{
	m_num = num;
	m_start = new LLONG[m_num];
}

intbase::intbase(intbase & from)
{
	delete m_start;
	m_num = from.m_num;
	m_start = new LLONG[m_num];
	for (int i = 0; i < from.m_num; i++)
	{
		m_start[i] = from.m_start[i];
	}

}

intbase intbase::operator=(intbase & from)
{
	delete m_start;
	m_num = from.m_num;
	m_start = new LLONG[m_num];
	for (int i = 0; i < from.m_num; i++)
	{
		m_start[i] = from.m_start[i];
	}
	return *this;
}


intbase::~intbase()
{
	delete m_start;
}
