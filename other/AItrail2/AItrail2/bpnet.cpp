#include "bpnet.h"



bpnet::bpnet():
{
	error = 1.0;
	e = 0.0;
	//ע��˳��
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
	double pp[hidenode];//��������У�����  
	double qq[];//ϣ�����ֵ��ʵ�����ֵ��ƫ��  
	double yd[outnode];//ϣ�����ֵ  

	double x[innode]; //��������  
	double x1[hidenode];//�������״ֵ̬  
	double x2[outnode];//������״ֵ̬  
	double o1[hidenode];//�����㼤��ֵ  
	double o2[hidenode];//����㼤��ֵ  

	vector<double> result;
		

	//����ÿ����Ʒ������������׼  
	result=layers[0].stim(sample);
	result=layers[1].stim(result);

	for (int k = 0; k<outnode; k++)
	{
		qq[k] = (yd[k] - x2[k])*x2[k] * (1 - x2[k]); //ϣ�������ʵ�������ƫ��  
		for (int j = 0; j<hidenode; j++)
			w1[j][k] += rate_w1*qq[k] * x1[j];  //��һ�ε�������������֮���������Ȩ  
	}

	for (int j = 0; j<hidenode; j++)
	{
		pp[j] = 0.0;
		for (int k = 0; k<outnode; k++)
			pp[j] = pp[j] + qq[k] * w1[j][k];
		pp[j] = pp[j] * x1[j] * (1 - x1[j]); //�������У�����  

		for (int i = 0; i<innode; i++)
			w[i][j] += rate_w*pp[j] * x[i]; //��һ�ε�������������֮���������Ȩ  
	}

	for (int k = 0; k<outnode; k++)
	{
		e += fabs(yd[k] - x2[k])*fabs(yd[k] - x2[k]); //���������  
	}
	error = e / 2.0;

	for (int k = 0; k<outnode; k++)
		b2[k] = b2[k] + rate_b2*qq[k]; //��һ�ε�������������֮�������ֵ  
	for (int j = 0; j<hidenode; j++)
		b1[j] = b1[j] + rate_b1*pp[j]; //��һ�ε�������������֮�������ֵ  
	
}

vector<double> bpnet::recognize(const vector<double> & p)
{
	vector<double> x = p; //��������  
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

