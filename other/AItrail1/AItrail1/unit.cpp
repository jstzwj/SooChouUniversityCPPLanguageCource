#include "unit.h"



unit::unit()
{
}


unit::~unit()
{
}

void unit::print()
{
	std::cout << "�ַ���" << data << std::endl;
	std::cout << "Ȩ�أ�" << weight << std::endl;
	std::cout << "���ӣ�\n";
	for (int i = 0; i < link.size();++i)
	{
		std::cout << link[i].first <<"\t"<< link[i].second << std::endl;
	}

}

void unit::forget()
{
	for (int i = 0; i < link.size();++i)
	{
		if (link[i].second>0)
		{
			link[i].second--;
		}
		
	}
	if(weight>0)
	weight--;
}




