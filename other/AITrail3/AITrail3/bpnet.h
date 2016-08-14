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
	void train(const vector<double> &sample_input, const vector<double> &sample_output);//Bpѵ��  
	vector<double> sample_in;     //���������  
	vector<double> sample_out;    //Ҫ���������

	vector<double> recognize(const vector<double> & p);//Bpʶ��  

	vector<bplayer> layers;

	void WriteFile(char *f); 
	void ReadFile(char *f); 

	void init();
	

	double e;//������  
	double error;//�����������  
	vector<double> out;    //Ҫ���������	
};

