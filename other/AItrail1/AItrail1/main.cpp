#include"unit.h"
#include"brain.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	brain br;
	while (cin>>str)
	{
		//����
		for (int i = 0; i < str.length(); ++i)
		{
			//��ӻ���Ԫ��
			if (!br.isContain(str[i]))
			{
				br.cells.push_back(unit(str[i],1.0));
			}
		}

		//������ز�
		br.addlink();
		//�̼�
		for (int i = 0; i < str.length(); ++i)
		{
			br.stim(i);
		}
		br.print();
		//˥��

	}
	return 0;
}