#include<iostream>
#include<string>
using namespace std;

class CPerson
{
private:
	string m_name; // ����
	int m_age; // ����
	char m_sex; // �Ա� ��M"��ʾ���� ��F"��ʾŮ��
public:
	CPerson(const string& name, int age, char sex)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
	}
	CPerson()
	{
		m_name = "����";
		m_age = 18;
		m_sex = 'M';
	}
	void print()
	{
		cout<<"\n ������"<<m_name<<"\n ���䣺"<<m_age<<"\n";
		if (m_sex == 'M')
		cout<<"�Ա� ��"<<endl;
		else
		cout<<"�Ա� Ů"<<endl;
	}
};

class CStudent:public CPerson
{
private:
	string m_university;
	int m_grade;
public:
	CStudent()
		:CPerson("����",17,'M'),m_university("���ݴ�ѧ"),m_grade(1){}
	CStudent(const string& name, int age, char sex,const string& collageName, int grade)
		:CPerson(name,age,sex),m_university(collageName),m_grade(grade){}
	void print()
	{
		CPerson::print();
		cout<<"��ѧ:"<<m_university<<endl<<"�꼶:"<<m_grade<<endl;
	}
};

int main()
{
	CStudent student1;
	student1.print();
	CStudent student2("Liming",21,'M',"���ݴ�ѧ",1);
	student2.print();

	string name,university;
	char sex;
	int  age,grade;
	cout<<"����������ѧ�������������䡢�Ա�ѧУ���꼶����Ϣ"<<endl;
	cin>>name>>age>>sex>>university>>grade;
	CStudent somebody(name,age,sex,university,grade);
	somebody.print();
	return 0;
}
