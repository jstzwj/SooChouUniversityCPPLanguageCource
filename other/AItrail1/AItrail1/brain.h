#pragma once
#include<vector>
#include<deque>
#include<utility>
#include<map>
#include"unit.h"
using std::vector;
using std::pair;
using std::deque;

class brain
{
public:
	brain();
	~brain();
	vector<unit> cells;
	deque<int> stim_deque;
	vector<> history;
	//是否存在
	bool isContain(char c);
	//是否为空
	bool empty() { return cells.empty(); }
	//返回大小
	int size() { return cells.size();}
	//刺激
	void stim(int offset);
	//添加联系
	void addlink();
	//输出
	void print();
	//forget
	void forget();
};

