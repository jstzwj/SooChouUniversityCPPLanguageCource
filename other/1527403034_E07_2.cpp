#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

int ReadWordFromFile(char const * addr,vector<string> &vec_words)
{
	//打开文件
	ifstream inFile(addr);
	string temp;
	//判断是否读取成功
	if(!inFile)
	{
		cerr<<"文件读取失败！\n";
		//cout<<"文件读取失败！";
		return 1;
	}
	//写入vector
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

	cout<<"请输入data.txt文件路径：\n";
	//路径会有空格
	getline(cin,addr);
	//读入数据
	if(ReadWordFromFile(addr.c_str(),vec_words)!=0)
	{
		system("pause");
		return 1;
	}
	//计算ascii码值的和
	StringToInt(vec_words,vec_ints);
	//排序
	VecSort(vec_words);
	VecSort(vec_ints);
	//输出
	cout<<"排序后为：\n";
	PrintVec(vec_words);
	PrintVec(vec_ints);
	//删除
	DelLessThanANum(vec_words);
	DelLessThanANum(vec_ints);
	//输出
	cout<<"删除后为：\n";
	PrintVec(vec_words);
	PrintVec(vec_ints);
	system("pause");
	return 0;
}