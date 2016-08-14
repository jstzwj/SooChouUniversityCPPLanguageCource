/*
文件名：1527403034_E04.cpp
作者：王俊
时间：2016/3/7
功能：
备注：
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
	int ID; //学号
	string name; //姓名
	float score[3]; //三门课程成绩
};
//按学号比较
bool IDCompare(struct Student &a,struct Student &b);
//依次输入学生信息
void InPut(vector<Student> &info,int num);
//按照学号排序
void IdSort(vector<Student> &info);
//输出学生信息
void Print(vector<Student> &info);
//删除学生信息
void DelStu(vector<Student> &info,string &name);
//输出到文件
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
		cout << "请输入第" << i + 1 << "位学生的学号" << endl;
		cin >> temp.ID;
		cout << "请输入第" << i + 1 << "位学生的姓名" << endl;
		cin >> temp.name;
		cout << "请输入第" << i + 1 << "位学生的三门学科成绩" << endl;
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
	cout << setw(10) << right << "学号";
	cout << setw(10) << right << "姓名";
	cout << setw(10) << setprecision(3) << right << "课程一";
	cout << setw(10) << setprecision(3) << right << "课程二";
	cout << setw(10) << setprecision(3) << right << "课程三" << endl;
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
		cout << "文件打开失败！\n";
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
