#pragma once
#include<vector>
using std::vector;
class bplayer
{
public:
	bplayer(int num = 1);
	~bplayer();
	int nodenum;
	
	double rate_w;	//权重学习率
	double rate_b;	//阀值学习率
	
	vector<vector<double> > w;//权值
	vector<double> b;//阀值

	double(*stimfun)(double,double);
	bplayer *next;
	bplayer *last;

	void WriteFile(char *f);
	void ReadFile(char *f);
	void set(const vector<vector<double> > &weight, const vector<double> &tb);
	void setnext(bplayer *pnext) { next = pnext; }
	void setlast(bplayer * plast) { last = plast; }
	void init();
	int size() { return nodenum; }
	void setStimFun(double(*fun)(double,double)) { stimfun = fun; }
	vector<double> stim(const vector<double> & from);
	void updatew();
	void updateb();
};

double defaultStimFun(double x, double b) { 1.0 / (1.0 + exp(-x - b)); }
