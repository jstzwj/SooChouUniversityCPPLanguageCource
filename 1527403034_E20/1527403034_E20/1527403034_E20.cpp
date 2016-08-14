#include<string>
#include<iostream>
using namespace std;
class CContry 
{
private:  
	char *name;      // 国家名称 
	char *caption;   // 首都名称  
	double  area;     // 国家面积，单位万平方公里  
	double  person_num;  // 人口数量，单位 万
public:  
	CContry()                // 无参构造函数  
	{ 
		name = new char[100];   
		strcpy_s(name,99, "中国");  
		caption = new char[100];
		strcpy_s(caption, 99,"北京");  
		area = 960; 
		person_num = 130000.00;
	} 
	CContry(const CContry&);  // 拷贝构造函数  
	CContry(const char*, const char* ,double, double);   // 带参数的构造函数 
	CContry& operator=(const CContry&); 
	~CContry();                // 析构函数
	void set(const char*, const char*, double, double);     // 设置属性的成员函数  
	void print()const;          // 在屏幕上输出CContry对象的信息 
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
	cout << name<<"对象被析构了！";
}
void CContry::print() const
{
	cout << "国家名称：" << name << endl << "首都名称：" << caption << endl << "面积：" << area << endl << "人口数量：" << person_num << endl;
}

int main()
{
	string a, b;
	double c, d;
	CContry b1;
	b1.print();
	CContry b2 = b1;
	b2.print();
	cout << "请输入一个国家的名称、首都、面积、人口："<< endl;
	cin >> a >> b >> c >> d;
	CContry b3(a.c_str(), b.c_str(), c, d);
	b3.print();
	CContry *Japan = new CContry("日本", "东京", 36.835, 12665.9683);
	Japan->print();
	delete Japan;
	system("pause");
	return 0;
}