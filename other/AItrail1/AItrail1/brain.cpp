#include "brain.h"

using namespace std;
brain::brain()
{
}


brain::~brain()
{
}

bool brain::isContain(char c)
{
	for (int i = 0; i < cells.size();++i)
	{
		if (c==cells[i].data)
		{
			return true;
		}
	}
	return false;
}

void brain::stim(int offset)
{
	int limit = 3;
	stim_deque.push_back(offset);
	while(!stim_deque.empty())
	{
		if (limit>0)
		{
			for (int i = 0; i < cells[offset].link.size(); ++i)
			{
				cells[cells[offset].link[i].first].weight += cells[offset].link[i].second*cells[offset].weight;
				stim_deque.push_back(cells[offset].link[i].first);
			}
			limit--;
		}
		
		offset = stim_deque.front();
		stim_deque.pop_front();
	} 
}

void brain::addlink()
{
	int top;
	top = cells.size();
	for (int i = 0; i < cells.size(); ++i)
	{
		if (cells[i].weight>0)
		{
			for (int j = 0; j < top;++j)
			{
				if (cells[j].weight > 0)
				{
					//判断是否添加过
					
					if (find(history.begin(), history.end(),make_pair(i,j))!=history.end())
					{

						cells[].weight++;
					}
					else
					{
						//添加
						unit temp;
						temp.link.push_back(make_pair(i, 1.0));
						temp.link.push_back(make_pair(j, 1.0));
						cells.push_back(temp);
						//反向
						cells[i].link.push_back(make_pair(cells.size() - 1, 1.0));
						cells[j].link.push_back(make_pair(cells.size() - 1, 1.0));
						history.insert(make_pair(make_pair(i, j),size()-1));
					}
				}
				

			}
		}
	}
}

void brain::print()
{
	for (int i = 0; i < cells.size();++i)
	{
		cells[i].print();
	}
}

void brain::forget()
{
}
