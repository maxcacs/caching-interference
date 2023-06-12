#include "Function.h"

//计算每个用户的接入速率，并写入到文档
void ST_throughput(double *Rate, int *User_Mode_Num,double * ST_rate, int (& Access_table)[MaxUserNum][MaxRelayNum], int (& Mode_Table)[Mode_Num][MaxRelayNum]);

//显示每个用户的接入速率
void Print_ST(double * ST_rate);

//将用户接入矩阵写入到本地文档
void Out_Access_table(int (& Access_table)[MaxUserNum][MaxRelayNum]);