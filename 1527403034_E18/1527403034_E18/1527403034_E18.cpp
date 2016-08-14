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
		name = "��";
		author = "��"; 
		price = 0.0; 
		publisher = "��"; 
	}  
	CBook(const CBook &);    
	// �������캯�� 
	CBook(string , string, double, string);   
	// �������Ĺ��캯��
	CBook(char*, char*, double, char*);      
	// �������Ĺ��캯��
	~CBook();
	// ��������  
	void SetName(char*);     
	// ���������ĳ�Ա����  
	void SetName(string&);  
	// ���������ĳ�Ա���� 
	void print()const;        
	// ����Ļ����ʾ�����Ϣ�ĳ�Ա����
	friend ostream & operator<<(ostream& out, const CBook &); 
	// ������������� �غ���
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
	cout <<"\""<< name << "\"���������ˣ�" << endl;
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
	out << "������" << book.name<<endl;
	out << "���ߣ�"<<book.author << endl;
	out << "�۸�" <<book.price<< endl;
	out << "�����磺" <<book.publisher<< endl;
	return out;
}

void main() 
{
	string n = "C++�������", a = "����", pub = "���ݴ�ѧ������";
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
	CBook *b4 = new CBook("VC++", "���", 45.0, "�廪��ѧ������"); 
	cout << *b4 << endl;  
	delete b4;
}