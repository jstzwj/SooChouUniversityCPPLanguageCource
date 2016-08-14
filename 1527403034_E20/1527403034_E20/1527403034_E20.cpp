#include<string>
#include<iostream>
using namespace std;
class CContry 
{
private:  
	char *name;      // �������� 
	char *caption;   // �׶�����  
	double  area;     // �����������λ��ƽ������  
	double  person_num;  // �˿���������λ ��
public:  
	CContry()                // �޲ι��캯��  
	{ 
		name = new char[100];   
		strcpy_s(name,99, "�й�");  
		caption = new char[100];
		strcpy_s(caption, 99,"����");  
		area = 960; 
		person_num = 130000.00;
	} 
	CContry(const CContry&);  // �������캯��  
	CContry(const char*, const char* ,double, double);   // �������Ĺ��캯�� 
	CContry& operator=(const CContry&); 
	~CContry();                // ��������
	void set(const char*, const char*, double, double);     // �������Եĳ�Ա����  
	void print()const;          // ����Ļ�����CContry�������Ϣ 
}; 
CContry::CContry(const CContry &from)
{
	name = new char[100];
	strcpy_s(name,99,from.name);
	caption = new char[100];
	strcpy_s(caption,99,from.caption);
	area = from.area;
	person_num = from.person_num;
}
CContry::CContry(const char *out_name, const char *out_caption, double out_area, double out_person_num):area(out_area),person_num(out_person_num)
{
	name = new char[100];
	strcpy_s(name, 99,out_name);
	caption = new char[100];
	strcpy_s(caption,99, out_caption);
	area = out_area;
	person_num = out_person_num;
}
CContry & CContry::operator=(const CContry &from)
{
	char * name_temp = name;
	char * caption_temp = caption;
	name = new char[100];
	strcpy_s(name,99, from.name);
	caption = new char[100];
	strcpy_s(caption, 99, from.caption);
	area = from.area;
	person_num = from.person_num;
	delete[]name_temp;
	delete[]caption_temp;
	return *this;
}
void CContry::set(const char *out_name, const char *out_caption, double out_area, double out_person_num)
{
	char * name_temp = name;
	char * caption_temp = caption;
	name = new char[100];
	strcpy_s(name, 99, out_name);
	caption = new char[100];
	strcpy_s(caption, 99, out_caption);
	area = out_area;
	person_num = out_person_num;
	delete[]name_temp;
	delete[]caption_temp;
}
CContry::~CContry()
{
	cout << name<<"���������ˣ�";
}
void CContry::print() const
{
	cout << "�������ƣ�" << name << endl << "�׶����ƣ�" << caption << endl << "�����" << area << endl << "�˿�������" << person_num << endl;
}

int main()
{
	string a, b;
	double c, d;
	CContry b1;
	b1.print();
	CContry b2 = b1;
	b2.print();
	cout << "������һ�����ҵ����ơ��׶���������˿ڣ�"<< endl;
	cin >> a >> b >> c >> d;
	CContry b3(a.c_str(), b.c_str(), c, d);
	b3.print();
	CContry *Japan = new CContry("�ձ�", "����", 36.835, 12665.9683);
	Japan->print();
	delete Japan;
	system("pause");
	return 0;
}