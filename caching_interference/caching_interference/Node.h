#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include<ctime>
#include <math.h>
#include <fstream>
#include <conio.h>
#include <cassert>
#include <math.h>
using namespace std;
#define MaxRelayNum 5      //��վ��
#define MaxUserNum  100  //�û���
#define MaxFileNum 200       //�ļ�����
const int SubcarrierNum=25;    //RB��Ŀ
const int Cache_Max=10;        //����ռ�Cn,5%
const double ��= 0.7;          //�ļ��ܻ�ӭ�ȵķֲ�����
const int RAN_MAX =100000; 
//const int SEED=200;
//�ǵþ��ȵ�����~~~

const int TRANSMISSION_DISTANCE = 50;         //��վ�Ĵ��䷶Χ
const int INTERFERENCE_DISTANCE = 50;

const double Rate_Request =0.0;           //�û���������bit/s/Hz
const double Band = 0.18;               //�����ŵ��Ĵ���180kHz
const int RANGE=50;                     //��վ�Ĵ���뾶
//const int H=225;
#define POWER 13.0103                         //���书��dBm
#define T 1                           //����

const int Mode_Num = 5000;               //Ԥ��Ĵ���ģʽ�ĸ���
const int variable_num = 5000;           //Ԥ��ı�����
const int equation_num=MaxRelayNum;             //Ԥ��ĵ�ʽ���������
const int inequality_num=5000;           //Ԥ��Ĳ���ʽ��������

const int MAX_NODENUM=MaxRelayNum+MaxUserNum;
const double Environmentalnoise=8.417*1e-16;    //������������λ��W

class Node
{
private:
	double x_axis; //�ڵ������
	double y_axis; //�ڵ�������
	int nodenum;//�ڵ���

public:
	Node();
	Node(double, double);
	~Node();
	double NodeGetXAxis() const;//��ýڵ�ĺ�����
	double NodeGetYAxis() const;//��ýڵ��������
	int NodeGetnodenum() const;//��ýڵ���

	void NodeSetXAxis(double);
	void NodeSetYAxis(double);
	void NodeSetnodenum(int);
	void ShowNode() const;	
};


#endif 