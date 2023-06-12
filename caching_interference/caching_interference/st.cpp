#include "st.h"

void ST_throughput(double *Rate, int *User_Mode_Num, double * ST_rate, int (& Access_table)[MaxUserNum][MaxRelayNum], int (& Mode_Table)[Mode_Num][MaxRelayNum])
{
	double throughput = 0.0;  //记录总的吞吐量
	double mmax = 0.0;   //记录每个用户的最大接入速率
    int temp = 0;     //记录传输模式遍历的下标
    int i=0;           //记录用户id
	int j=0;
	int k=0;
	//初始化接入矩阵
	for(i=0; i<MaxUserNum; ++i)
	{
		for(j=0; j<MaxRelayNum; ++j)
		{
			Access_table[i][j]=0;
		}
	}
	while(i<MaxUserNum)
	{
		if(User_Mode_Num[i] == 1)
		{
			ST_rate[i] = Rate[temp];
			++temp;
			++i;
		}
		else
		{
			mmax = 0.0;
			for(j=temp+1; j<temp+User_Mode_Num[i]; ++j)
			{
				if(mmax < Rate[j])
				{
					mmax = Rate[j];
				}
			}
			ST_rate[i] = mmax;
			temp += User_Mode_Num[i];
			++i;
		}
	}
}

void Print_ST(double * ST_rate)
{
	cout<<"每个用户的接入速率为："<<endl;
    for(int i=0; i<MaxUserNum; ++i)
	{
	   cout<<"user "<<i<<": "<<ST_rate[i]<<endl;
	}
}	
	
void Out_Access_table(int (& Access_table)[MaxUserNum][MaxRelayNum])
{
	ofstream file;
	file.open("用户接入矩阵.txt");
	//cout<<"用户接入矩阵为："<<endl;
	for(int i=0;i<MaxUserNum;i++)
	{
		for(int j=0;j<MaxRelayNum;j++)
		{
			file<<Access_table[i][j]<<" ";
			//cout<<Access_table[i][j]<<" ";
		}
		file<<endl;
		//cout<<endl;
	}
	file.close();
}