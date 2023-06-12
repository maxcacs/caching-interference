#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Node.h"

//��һ�����ɷ�ʽ,�����ڵ�����
void NodesGenerator(int num,Node *p);
bool Judge_Node(double x1,double y1,Node *q);
/*
//�ڶ������ɷ�ʽ
void NodesGenerator1(int linenumber,int columnnumber,Node *p)
{
	double x,y;		
	for(int l=0;l<linenumber; l++)			//��
	{
		for(int m=0;m<columnnumber; m++)		//��
		{
			x=(double)l*10;
			y=(double)m*10;
			*p=Node(x,y);
			p++;
		}
	}
		
}*/

//���������Ľڵ�
void print_node(int num,Node *p);

//����������վ����״̬
void Cache_Generator(int (& Cache_data)[MaxRelayNum][MaxFileNum],int *Cache_remain);
void Print_Cache(int (& Cache_data)[MaxRelayNum][MaxFileNum],int *Cache_remain);

//�û�����
//void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum]);
//void Print_Request(int *User_Request);

//�Ƚ������ڵ�֮��ľ���
double DistanceCalculation(Node src,Node dest);
//�ж������ڵ�֮���Ƿ��ڽ�
bool NodeDistanceJudgement(Node src,Node dest);
//��dBmת��ΪW
double Dbm_To_W(double dBm);
//����ھӾ���
void GetNodeNeighborTable(int * NodeNeighborTable,Node *Nodesarray);
void Print_NodeNeighborTable(int *NodeNeighborTable);

//��¼ÿ���û������ӵĻ�վ����Ŀ
void Get_UserRelayArray(int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],int *UserRelayArray);
void Print_UserRelayArray(int *UserRelayNum);

//���㴫��ģʽ���õ�����ģʽ�ľ���

bool Judge_Temp(int *Temp,int num1,int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum]);
int Get_Mode_Table(int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],Node *Nodesarray,int *UserRelayArray,int (& Mode_Table)[Mode_Num][MaxRelayNum],int *User_Mode_Num);
int Get_variable_number(int *User_Mode_Num);
void Print_Mode_Table(int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real);
void Out_Mode_Table(int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real);

void Print_User_Mode_Num(int *User_Mode_Num);
void Out_User_Mode_Num(int *User_Mode_Num);  

   

//����ÿһ�ִ���ģʽ���û��˿ɴ����������,����������������
double Calculate_Power(Node dest,Node src,int (& Power_Relay)[MaxRelayNum][MaxUserNum]);
double DistanceCalculation(Node dest,Node src);
void Get_Rate(double *Rate,int Mode_Num_Real,int (& Mode_Table)[Mode_Num][MaxRelayNum],int *User_Mode_Num,Node *Nodesarray,int(& NodeNeighborTable)[MaxRelayNum][MaxUserNum]);
void Out_Rate(double *Rate,int Mode_Num_Real);
//void Out_Cache(int variable_number,int Mode_Num_Real);

//Ŀ�꺯����
void Get_Objective_function(int (& Objective_function)[variable_num],int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],int (& User_Request)[MaxUserNum][MaxFileNum],int (& Cache_data)[MaxRelayNum][MaxFileNum],int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real,int *User_Mode_Num);
void Print_Objective_function(int (& Objective_function)[variable_num],int variable_number);

//��ʽԼ����
void Get_Matrix_equation(int (& Matrix_equation_value)[equation_num], int ( & Matrix_equation)[equation_num][variable_num],int ( & Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real,int equation_number, int *User_Mode_Num);
void Print_Matrix_equation(int (& Matrix_equation_value)[equation_num], int ( & Matrix_equation)[equation_num][variable_num],int equation_number,int variable_number);


//����ʽԼ����
int Get_Matrix_inequality(int (& Mode_Table)[Mode_Num][MaxRelayNum],int (& Matrix_inequality_value)[inequality_num],int Mode_Num_Real,int *User_Mode_Num,int(& NodeNeighborTable)[MaxRelayNum][MaxUserNum],double *Rate,int (& Cache_data)[MaxRelayNum][MaxFileNum], int(& Matrix_inequality)[inequality_num][variable_num]);
void Print_Matrix_inequality(int (&Matrix_inequality_value)[inequality_num],int inequality_number,int variable_number, int(& Matrix_inequality)[inequality_num][variable_num]);	


#endif 