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
	//�Ƿ����
	bool isContain(char c);
	//�Ƿ�Ϊ��
	bool empty() { return cells.empty(); }
	//���ش�С
	int size() { return cells.size();}
	//�̼�
	void stim(int offset);
	//�����ϵ
	void addlink();
	//���
	void print();
	//forget
	void forget();
};

