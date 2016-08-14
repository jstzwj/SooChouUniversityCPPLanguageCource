#pragma once
#include<vector>
#include"bpnode.h"


using std::vector;
class bplayer
{
public:
	bplayer(int num = 1);
	~bplayer();
	int nodenum;
	vector<bpnode> nodes;
	
	
	double(*stimfun)(double,double);

	void WriteFile(char *f);
	void ReadFile(char *f);
	void set(const vector<vector<double> > &weight, const vector<vector<double> > &bias);
	
	void init();
	int size() { return nodenum; }
	void setStimFun(double(*fun)(double,double)) { stimfun = fun; }
	vector<double> stim(const vector<double> & from);
	void updatew();
	void updateb();
};

double defaultStimFun(double x, double b) { 1.0 / (1.0 + exp(-x - b)); }
