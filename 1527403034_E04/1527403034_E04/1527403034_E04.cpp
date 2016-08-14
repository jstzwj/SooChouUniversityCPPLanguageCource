/*
�ļ�����1527403034_E04.cpp
���ߣ�����
ʱ�䣺2016/3/7
���ܣ�
��ע��
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
	int ID; //ѧ��
	string name; //����
	float score[3]; //���ſγ̳ɼ�
};
//��ѧ�űȽ�
bool IDCompare(struct Student &a,struct Student &b);
//��������ѧ����Ϣ
void InPut(vector<Student> &info,int num);
//����ѧ������
void IdSort(vector<Student> &info);
//���ѧ����Ϣ
void Print(vector<Student> &info);
//ɾ��ѧ����Ϣ
void DelStu(vector<Student> &info,string &name);
//������ļ�
int SaveFile(vector<Student> &info, char *addr);
int main()
{
	vector<Student> info;
	InPut(info,5);
	IdSort(info);
	Print(info);
	DelStu(info,string("TOM"));
	SaveFile(info, "D:\\res.dat");
	system("pause");
	return 0;
}

bool IDCompare(Student & a, Student & b)
{
	return a.ID<b.ID;
}

void InPut(vector<Student>& info,int num)
{
	struct Student temp;
	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "λѧ����ѧ��" << endl;
		cin >> temp.ID;
		cout << "�������" << i + 1 << "λѧ��������" << endl;
		cin >> temp.name;
		cout << "�������" << i + 1 << "λѧ��������ѧ�Ƴɼ�" << endl;
		cin >> temp.score[0] >> temp.score[1] >> temp.score[2];
		info.push_back(temp);
	}
}

void IdSort(vector<Student>& info)
{
	sort(info.begin(), info.end(), IDCompare);
}

void Print(vector<Student>& info)
{
	vector<Student>::iterator it;
	cout << setw(10) << right << "ѧ��";
	cout << setw(10) << right << "����";
	cout << setw(10) << setprecision(3) << right << "�γ�һ";
	cout << setw(10) << setprecision(3) << right << "�γ̶�";
	cout << setw(10) << setprecision(3) << right << "�γ���" << endl;
	for (it = info.begin(); it != info.end();it++)
	{
		cout << setw(10) << right << it->ID;
		cout << setw(10) << right << it->name;
		cout << setw(10) << setprecision(3) << right << it->score[0];
		cout << setw(10) << setprecision(3) << right << it->score[1];
		cout << setw(10) << setprecision(3) << right << it->score[2]<<endl;
	}
}

void DelStu(vector<Student>& info, string & name)
{
	vector<Student>::iterator it;
	for (it = info.begin(); it != info.end(); it++)
	{
		if (it->name == name)
		{
			info.erase(it);
		}
	}
}

int SaveFile(vector<Student>& info, char * addr)
{
	vector<Student>::iterator it;
	ofstream outfile(addr);
	if (!outfile)
	{
		cout << "�ļ���ʧ�ܣ�\n";
		return 1;
	}
	for (it = info.begin(); it != info.end(); it++)
	{
		outfile << setw(10) << right << it->ID;
		outfile << setw(10) << right << it->name;
		outfile << setw(10) << setprecision(3) << right << it->score[0];
		outfile << setw(10) << setprecision(3) << right << it->score[1];
		outfile << setw(10) << setprecision(3) << right << it->score[2] << endl;
	}
	return 0;
}
