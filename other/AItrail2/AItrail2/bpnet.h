#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include"bplayer.h"
using std::vector;
class bpnet
{
public:
	bpnet();
	~bpnet();
	void train(const vector<double> &sample_input, const vector<double> &sample_output);//Bp训练  
	vector<double> sample_in;     //输入的样本  
	vector<double> sample_out;    //要输出的样本

	vector<double> recognize(const vector<double> & p);//Bp识别  

	vector<bplayer> layers;

	void WriteFile(char *f); 
	void ReadFile(char *f); 

	void init();
	

	double e;//误差计算  
	double error;//允许的最大误差  
	vector<double> out;    //要输出的样本	
};

