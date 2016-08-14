#include<iostream>
#include<string>
using namespace std;

class CPerson
{
private:
	string m_name; // 姓名
	int m_age; // 年龄
	char m_sex; // 性别 ‘M"表示男性 ‘F"表示女性
public:
	CPerson(const string& name, int age, char sex)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
	}
	CPerson()
	{
		m_name = "无名";
		m_age = 18;
		m_sex = 'M';
	}
	void print()
	{
		cout<<"\n 姓名："<<m_name<<"\n 年龄："<<m_age<<"\n";
		if (m_sex == 'M')
		cout<<"性别： 男"<<endl;
		else
		cout<<"性别： 女"<<endl;
	}
};

class CStudent:public CPerson
{
private:
	string m_university;
	int m_grade;
public:
	CStudent()
		:CPerson("无名",17,'M'),m_university("苏州大学"),m_grade(1){}
	CStudent(const string& name, int age, char sex,const string& collageName, int grade)
		:CPerson(name,age,sex),m_university(collageName),m_grade(grade){}
	void print()
	{
		CPerson::print();
		cout<<"大学:"<<m_university<<endl<<"年级:"<<m_grade<<endl;
	}
};

int main()
{
	CStudent student1;
	student1.print();
	CStudent student2("Liming",21,'M',"苏州大学",1);
	student2.print();

	string name,university;
	char sex;
	int  age,grade;
	cout<<"请依次输入学生的姓名、年龄、性别、学校、年级的信息"<<endl;
	cin>>name>>age>>sex>>university>>grade;
	CStudent somebody(name,age,sex,university,grade);
	somebody.print();
	return 0;
}
