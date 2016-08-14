#pragma once
#include<vector>
#include<utility>
#include<iostream>
using std::vector;
using std::pair;
class unit
{
public:
	unit();
	unit(char c,double w=1.0) :data(c),weight(w) {}
	~unit();
	
	vector<pair<int,double> > link;
	char data;
	double weight;
	void print();
	void forget();
};

