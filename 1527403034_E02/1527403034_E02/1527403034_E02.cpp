/*文件名：1527403034_E02.c
*作者：王俊
*时间：2016年3月5日
*功能：
*备注：
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
		cout << "Data.txt打开失败！" << endl;
		system("pause");
		return 0;
	}
	fstream file("Res.dat", ios::binary|ios::in|ios::out);
	if (!file)
	{
		cout << "Res.dat打开失败！" << endl;
		system("pause");
		return 0;
	}
	cout << "数字为：" << endl;
	for (int i = 0; i < 9; i++)
	{
		infile >> num[i];
		cout << num[i] << endl;
		file.write((char *)(&num[i]), sizeof(int));
	}
	//再次读取
	file.seekp(SEEK_SET);
	file.read((char *)num, sizeof(int) * 9);
	//输出
	ofstream outfile("Res.txt", ios::out);
	if (!outfile)
	{
		cout << "Res.txt打开失败！" << endl;
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