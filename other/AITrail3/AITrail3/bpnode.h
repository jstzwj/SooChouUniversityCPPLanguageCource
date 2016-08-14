#pragma once
#include<vector>
#include"bplink.h"
class bpnode
{
public:
	bpnode();
	~bpnode();

	std::vector < bplink > link;//Á´½Ó
	std::vector<double> rate;
	std::vector<double> bias;
	
};

