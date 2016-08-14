#pragma once
#include<vector>
using std::vector;
class bplayer
{
public:
	bplayer(int num = 1);
	~bplayer();
	int nodenum;
	
	double rate_w;	//Ȩ��ѧϰ��
	double rate_b;	//��ֵѧϰ��
	
	vector<vector<double> > w;//Ȩֵ
	vector<double> b;//��ֵ

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
