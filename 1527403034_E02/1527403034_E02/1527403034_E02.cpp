/*�ļ�����1527403034_E02.c
*���ߣ�����
*ʱ�䣺2016��3��5��
*���ܣ�
*��ע��
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	int num[9];
	int j;
	ifstream infile("Data.txt", ios::in);
	if (!infile)
	{
		cout << "Data.txt��ʧ�ܣ�" << endl;
		system("pause");
		return 0;
	}
	fstream file("Res.dat", ios::binary|ios::in|ios::out);
	if (!file)
	{
		cout << "Res.dat��ʧ�ܣ�" << endl;
		system("pause");
		return 0;
	}
	cout << "����Ϊ��" << endl;
	for (int i = 0; i < 9; i++)
	{
		infile >> num[i];
		cout << num[i] << endl;
		file.write((char *)(&num[i]), sizeof(int));
	}
	//�ٴζ�ȡ
	file.seekp(SEEK_SET);
	file.read((char *)num, sizeof(int) * 9);
	//���
	ofstream outfile("Res.txt", ios::out);
	if (!outfile)
	{
		cout << "Res.txt��ʧ�ܣ�" << endl;
		system("pause");
		return 0;
	}
	j = 0;
	while (j < 9)
	{
		outfile << setw(10) << setfill('c') << right << num[j];
		j++;
		if (j < 9)
		{
			outfile << setw(10) << setfill('c') << right << num[j] << endl;
			j++;
		}
	}
	system("pause");
	return 0;
}