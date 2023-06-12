#include "st.h"

void ST_throughput(double *Rate, int *User_Mode_Num, double * ST_rate, int (& Access_table)[MaxUserNum][MaxRelayNum], int (& Mode_Table)[Mode_Num][MaxRelayNum])
{
	double throughput = 0.0;  //��¼�ܵ�������
	double mmax = 0.0;   //��¼ÿ���û�������������
    int temp = 0;     //��¼����ģʽ�������±�
    int i=0;           //��¼�û�id
	int j=0;
	int k=0;
	//��ʼ���������
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
	cout<<"ÿ���û��Ľ�������Ϊ��"<<endl;
    for(int i=0; i<MaxUserNum; ++i)
	{
	   cout<<"user "<<i<<": "<<ST_rate[i]<<endl;
	}
}	
	
void Out_Access_table(int (& Access_table)[MaxUserNum][MaxRelayNum])
{
	ofstream file;
	file.open("�û��������.txt");
	//cout<<"�û��������Ϊ��"<<endl;
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