#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

int ReadWordFromFile(char const * addr,vector<string> &vec_words)
{
	//���ļ�
	ifstream inFile(addr);
	string temp;
	//�ж��Ƿ��ȡ�ɹ�
	if(!inFile)
	{
		cerr<<"�ļ���ȡʧ�ܣ�\n";
		//cout<<"�ļ���ȡʧ�ܣ�";
		return 1;
	}
	//д��vector
	while(inFile>>temp)
	{
		vec_words.push_back(temp);
	}
	return 0;
}

void StringToInt(const vector<string> & vec_words,vector<int> &vec_ints)
{
	vector<string>::const_iterator it;
	string::const_iterator it2;
	int sum;
	for(it=vec_words.cbegin();it!=vec_words.cend();it++)
	{
		sum=0;
		for(it2=it->cbegin();it2!=it->cend();it2++)
		{
			sum+=*it2;
		}
		vec_ints.push_back(sum);
	}
}

void PrintVec(const vector<string> & vec_words)
{
	vector<string>::const_iterator it;
	int count(1);
	for(it=vec_words.cbegin();it!=vec_words.cend();it++)
	{
		cout<<setw(15)<<*it;
		if(count%5==0)
		{
			cout<<"\n";
		}
		count++;
	}
	cout<<"\n";
}

void PrintVec(const vector<int> & vec_ints)
{
	vector<int>::const_iterator it;
	int count(1);
	for(it=vec_ints.cbegin();it!=vec_ints.cend();it++)
	{
		cout<<setw(10)<<*it;
		if(count%6==0)
		{
			cout<<"\n";
		}
		count++;
	}
	cout<<"\n";
}
bool CompareBySize(const string & a,const string & b)
{
	return a.size()<b.size();
}

void VecSort(vector<string> & vec_words)
{
	sort(vec_words.begin(),vec_words.end(),CompareBySize);
}

void VecSort(vector<int> & vec_ints)
{
	sort(vec_ints.begin(),vec_ints.end());
}

void DelLessThanANum(vector<int> & vec_ints)
{
	vector<int>::iterator it;
	int temp;
	int len;
	for(it=vec_ints.begin();it!=vec_ints.end();it++)
	{
		temp=*it;
		for(len=0;temp>0;len++)
		{
			temp=temp/10;
		}
		if(len<3)
		{
			it=vec_ints.erase(it);
		}
	}
}

void DelLessThanANum(vector<string> & vec_words)
{
	vector<string>::iterator it;
	for(it=vec_words.begin();it!=vec_words.end();it++)
	{
		if(it->length()<3)
		{
			it=vec_words.erase(it);
			it--;
		}
	}
}


int main()
{
	string addr;
	vector<string> vec_words;
	vector<int> vec_ints;

	cout<<"������data.txt�ļ�·����\n";
	//·�����пո�
	getline(cin,addr);
	//��������
	if(ReadWordFromFile(addr.c_str(),vec_words)!=0)
	{
		system("pause");
		return 1;
	}
	//����ascii��ֵ�ĺ�
	StringToInt(vec_words,vec_ints);
	//����
	VecSort(vec_words);
	VecSort(vec_ints);
	//���
	cout<<"�����Ϊ��\n";
	PrintVec(vec_words);
	PrintVec(vec_ints);
	//ɾ��
	DelLessThanANum(vec_words);
	DelLessThanANum(vec_ints);
	//���
	cout<<"ɾ����Ϊ��\n";
	PrintVec(vec_words);
	PrintVec(vec_ints);
	system("pause");
	return 0;
}