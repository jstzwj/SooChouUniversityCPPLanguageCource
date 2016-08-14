#include "bpnet.h"



bpnet::bpnet():
{
	error = 1.0;
	e = 0.0;
	//注意顺序
	layers[1].setnext(&layers[2]);
	layers[0].setnext(&layers[1]);
	
	layers[1].setlast(&layers[0]);
	layers[2].setlast(&layers[1]);

}


bpnet::~bpnet()
{
}

void bpnet::train(const vector<double>& sample, const vector<double>& output)
{
	double pp[hidenode];//隐含结点的校正误差  
	double qq[];//希望输出值与实际输出值的偏差  
	double yd[outnode];//希望输出值  

	double x[innode]; //输入向量  
	double x1[hidenode];//隐含结点状态值  
	double x2[outnode];//输出结点状态值  
	double o1[hidenode];//隐含层激活值  
	double o2[hidenode];//输出层激活值  

	vector<double> result;
		

	//构造每个样品的输入和输出标准  
	result=layers[0].stim(sample);
	result=layers[1].stim(result);

	for (int k = 0; k<outnode; k++)
	{
		qq[k] = (yd[k] - x2[k])*x2[k] * (1 - x2[k]); //希望输出与实际输出的偏差  
		for (int j = 0; j<hidenode; j++)
			w1[j][k] += rate_w1*qq[k] * x1[j];  //下一次的隐含层和输出层之间的新连接权  
	}

	for (int j = 0; j<hidenode; j++)
	{
		pp[j] = 0.0;
		for (int k = 0; k<outnode; k++)
			pp[j] = pp[j] + qq[k] * w1[j][k];
		pp[j] = pp[j] * x1[j] * (1 - x1[j]); //隐含层的校正误差  

		for (int i = 0; i<innode; i++)
			w[i][j] += rate_w*pp[j] * x[i]; //下一次的输入层和隐含层之间的新连接权  
	}

	for (int k = 0; k<outnode; k++)
	{
		e += fabs(yd[k] - x2[k])*fabs(yd[k] - x2[k]); //计算均方差  
	}
	error = e / 2.0;

	for (int k = 0; k<outnode; k++)
		b2[k] = b2[k] + rate_b2*qq[k]; //下一次的隐含层和输出层之间的新阈值  
	for (int j = 0; j<hidenode; j++)
		b1[j] = b1[j] + rate_b1*pp[j]; //下一次的输入层和隐含层之间的新阈值  
	
}

vector<double> bpnet::recognize(const vector<double> & p)
{
	vector<double> x = p; //输入向量  
	vector<double> result;
	
	result=layers[0].stim(x);
	result=layers[1].stim(result);
	
	return result;
}

void bpnet::WriteFile(char * f)
{

}

void bpnet::ReadFile(char *f)
{
}

void bpnet::init()
{


}

