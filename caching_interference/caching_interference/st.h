#include "Function.h"

//����ÿ���û��Ľ������ʣ���д�뵽�ĵ�
void ST_throughput(double *Rate, int *User_Mode_Num,double * ST_rate, int (& Access_table)[MaxUserNum][MaxRelayNum], int (& Mode_Table)[Mode_Num][MaxRelayNum]);

//��ʾÿ���û��Ľ�������
void Print_ST(double * ST_rate);

//���û��������д�뵽�����ĵ�
void Out_Access_table(int (& Access_table)[MaxUserNum][MaxRelayNum]);