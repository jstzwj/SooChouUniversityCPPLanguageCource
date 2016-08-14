#include<string>
#include<iostream>
using namespace std;
class  CBook 
{
private: 
	string name; 
	string author;
	double price;  
	string publisher; 
public:  
	CBook() 
	{
		name = "无";
		author = "无"; 
		price = 0.0; 
		publisher = "无"; 
	}  
	CBook(const CBook &);    
	// 拷贝构造函数 
	CBook(string , string, double, string);   
	// 带参数的构造函数
	CBook(char*, char*, double, char*);      
	// 带参数的构造函数
	~CBook();
	// 析构函数  
	void SetName(char*);     
	// 设置书名的成员函数  
	void SetName(string&);  
	// 设置书名的成员函数 
	void print()const;        
	// 在屏幕上显示书的信息的成员函数
	friend ostream & operator<<(ostream& out, const CBook &); 
	// 输出操作符的重 载函数
}; 
CBook::CBook(const CBook &book)
{
	name = book.name;
	author = book.author;
	price = book.price;
	publisher = book.publisher;
}

CBook::CBook(string othername, string otherauthor, double otherprice, string otherpublisher)
{
	name = othername;
	author = otherauthor;
	price = otherprice;
	publisher = otherpublisher;
}

CBook::CBook(char *othername, char *otherauthor, double otherprice, char *otherpublisher)
{
	name = othername;
	author = otherauthor;
	price = otherprice;
	publisher = otherpublisher;
}
CBook::~CBook()
{
	cout <<"\""<< name << "\"对象被析构了！" << endl;
}

void CBook::SetName(char *othername)
{
	name = othername;
}

void CBook::SetName(string &othername)
{
	name = othername;
}

void CBook::print() const
{
	cout << *this;
}

ostream & operator<<(ostream & out, const CBook &book)
{
	out << "书名：" << book.name<<endl;
	out << "作者："<<book.author << endl;
	out << "价格：" <<book.price<< endl;
	out << "出版社：" <<book.publisher<< endl;
	return out;
}

void main() 
{
	string n = "C++程序设计", a = "王涛", pub = "苏州大学出版社";
	CBook b1;  
	cout << b1 << endl; 
	b1.SetName(n); 
	b1.print(); 
	b1.SetName("VB"); 
	cout << b1 << endl;
	CBook b2 = b1; 
	cout << b2 << endl;
	CBook b3(n, a, 35.0, pub); 
	cout << b3 << endl;
	CBook *b4 = new CBook("VC++", "李国", 45.0, "清华大学出版社"); 
	cout << *b4 << endl;  
	delete b4;
}