/*
�ļ�����1527403034_E05.cpp
���ߣ�����
ʱ�䣺2016/3/7
���ܣ�
��ע��
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int temp[] ={ 35,46,57,13,24,35, 68,13,79,88,46 };
	vector<int> num(&temp[0],&temp[10]+1);
	vector<int>::iterator i;
	vector<int>::iterator j;
	//ȥ���ظ�
	for (i = num.begin(); i < num.end(); i++)
	{
		for (j = i+1; j < num.end(); j++)
		{
			if (*i == *j)
			{
				j = num.erase(j);
				j--;
			}
		}
	}
	//����
	sort(num.begin(), num.end());
	//���
	for (vector<int>::iterator it = num.begin(); it != num.end();it++)
	{
		cout << *it<<endl;
	}
	system("pause");
	return 0;
}