#include "bplayer.h"
#include<ctime>
#include<fstream>
#include<iostream>
using namespace std;

double(*stimfun)(double,double) = defaultStimFun;

bplayer::bplayer(int num) :nodenum(num) 
{
	w.resize(nodenum);
	b.resize(nodenum);

	for (int i = 0; i < nodenum; i++)
	{
		for (int j = 0; j < next->nodenum; ++j)
		{
			w[i][j] = (2.0*(double)rand() / RAND_MAX) - 1;
		}
		
		b[i] = (2.0*(double)rand() / RAND_MAX) - 1;
	}
		
}



bplayer::~bplayer()
{
}

void bplayer::set(const vector<vector<double> >& weight, const vector<double>& tb)
{
	w = weight;
	b = tb;
}

void bplayer::init()
{

}

vector<double> bplayer::stim(const vector<double>& from)
{
	vector<double> result;
	result.resize(nodenum);
	for (int j = 0; j<nodenum; j++)
	{
		result[j] = 0.0;
		for (int i = 0; i<from.size(); i++)
			result[j] = result[j] + w[i][j] * from[i]; //隐含层各单元激活值  
		result[j] = stimfun(result[j],b[j]); //隐含层各单元输出  
												   //if(o1[j]+b1[j]>0) x1[j]=1;  
												   //    else x1[j]=0;  
	}
	return result;
}

void bplayer::WriteFile(char * f)
{
	ofstream out(f);
	if (!out)
	{
		std::cerr << "文件打开失败" << std::endl;
	}
	out << nodenum<<'\n';
	for (int i = 0; i < nodenum;++i)
	{
		for (int j = 0; j < next->nodenum;++j)
		{
			out << w[i][j] << ' ';
		}
	}
	out << '\n';
	for (int i = 0; i < nodenum; ++i)
	{
		out << b[i] << ' ';
	}
	
}

void bplayer::ReadFile(char * f)
{
	ifstream in(f);
	if (!in)
	{
		std::cerr << "文件打开失败" << std::endl;
	}
	in >> nodenum;
	w.resize(nodenum);
	b.resize(nodenum);
	for (int i = 0; i < nodenum; ++i)
	{
		for (int j = 0; j < next->nodenum; ++j)
		{
			in >> w[i][j];
		}
	}

	for (int i = 0; i < nodenum; ++i)
	{
		in>> b[i] ;
	}

}
