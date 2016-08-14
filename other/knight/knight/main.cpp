#include<iostream>
using namespace std;

#define size 8

struct pos
{
	int x;
	int y;
	int time;
};
typedef struct pos pos;

pos deque[640];
int chess[size][size];

int pstart = 0;
int pend = 0;

void move(int x,int y)
{
	int xtemp, ytemp;
	for (xtemp = x - 2; xtemp <= x + 2;xtemp++)
	{
		if (xtemp!=x&&xtemp>=0&&xtemp<size)
		{
			for (ytemp = x - 2; ytemp <= x + 2; ytemp++)
			{
				if (ytemp != y&&ytemp >= 0 && ytemp<size)
				{
					if (chess[xtemp][ytemp] == -1&&(ytemp-y)*(ytemp-y)+(xtemp-x)*(xtemp-x)==5)
					{
						deque[pend].x = xtemp;
						deque[pend].y = ytemp;
						deque[pend].time = chess[x][y] + 1;
						pend++;
						if (pend == 640)
						{
							pend = 0;
						}
						if (pend == pstart - 1 || pend == 63 && pstart == 0)
						{
							cout << "队列已满！" << endl;
						}
					}
					
				}
			}
		}
	}
}
int main()
{
	int m, n;
	int k;
	for (int i = 0; i < size;++i)
	{
		for (int j = 0; j < size;++j)
		{
			chess[i][j] = -1;
		}
	}
	cout << "请输入坐标"<<endl;
	cin >> m >> n;
	chess[m][n] = 0;
	deque[pstart].x = 0;
	deque[pstart].y = 0;
	deque[pstart].time = 0;
	pend++;
	while (pstart != pend)
	{ 
		if(deque[pstart].x!=m&&deque[pstart].y!=n)
		chess[deque[pstart].x][deque[pstart].y] = deque[pstart].time;
		move(deque[pstart].x, deque[pstart].y);
		pstart++;
		if (pstart == 640)
		{
			pstart = 0;
		}
		
	}
	cout << "请输入位置与步数" << endl;
	cin >> m >> n >> k;
	if ((k-chess[m][n])%2==0)
	{
		cout << "可以" << endl;
	}
	else
	{
		cout << "不可以" << endl;
	}
	system("pause");
	return 0;
}