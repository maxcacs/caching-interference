//#include "Node.h"

#include "Request.h"
//#include "st.h"

//ȫ�ֱ���
	//��վ�������
	int Cache_data[MaxRelayNum][MaxFileNum];
 	//�ڵ��ھӾ������ڱ�ʾ�ڵ��Ƿ�Ϊ�ھ�
	int NodeNeighborTable[MaxRelayNum][MaxUserNum];	
	//��¼�����û��Ĵ���ģʽ
	int Mode_Table[Mode_Num][MaxRelayNum]; 
	//��ʽϵ������
	//int Matrix_equation[equation_num][variable_num];
	//����ʽϵ������
	int Matrix_inequality[inequality_num][variable_num];
	//ln,i
	int Access_table[MaxUserNum][MaxRelayNum];
	
 void main()
{
	
	int NodeNum=MAX_NODENUM;

	//�ڵ����飺�û��洢�ڵ�   P.S.:ǰMaxRelayNum����ʾ��վ����Ŀ����MaxUserNum����ʾ�û�����Ŀ
	Node Nodesarray[MAX_NODENUM];
	//�����ڵ�
	NodesGenerator(NodeNum,Nodesarray);        
	//���������Ľڵ�
	//print_node(NodeNum,Nodesarray);   

	//��վ��ʼ����״̬
	//int Cache_data[MaxRelayNum][MaxFileNum];
	//int Cache_remain[MaxRelayNum];
	//Cache_Generator(Cache_data,Cache_remain);
	//Print_Cache(Cache_data,Cache_remain);

	//�ļ��ܻ�ӭ��
	double File_Pro[MaxFileNum] = {0.0};
	Pro_Generator(File_Pro);
	//Print_Pro(File_Pro);
	//�û�����
	int User_Request[MaxUserNum][MaxFileNum]={0};
	//���ļ��ܻ�ӭ�Ȳ���
	Request_Generator(User_Request, File_Pro);
	//�������
	//Request_Generator(User_Request);
	//Print_Request(User_Request[0]);
	//���û����ļ��������������
	Out_Request(User_Request);

 	//�ڵ��ھӾ������ڱ�ʾ�ڵ��Ƿ�Ϊ�ھ�
	//int NodeNeighborTable[MaxRelayNum][MaxUserNum];	
	//���relay�ڵ��ھӱ�:�д���ͬ��relay�ڵ㣻�д���ͬ���û��ڵ�
	GetNodeNeighborTable(NodeNeighborTable[0],Nodesarray);
	//��ʾ�ڵ��ھӱ�
	//Print_NodeNeighborTable(NodeNeighborTable[0]);

	//UserRelayTable ��¼��ÿ���û��������ӵĻ�վ����Ŀ
	int UserRelayArray[MaxUserNum] = {0};
	Get_UserRelayArray(NodeNeighborTable,UserRelayArray);
    //Print_UserRelayArray(UserRelayArray);

	//�õ�����ģʽ�ľ���
	//int Mode_Table[Mode_Num][MaxRelayNum]; 
	int User_Mode_Num[MaxUserNum];     //��¼ÿ���û����ڵĴ���ģʽ�ĸ���
	int Mode_Num_Real=Get_Mode_Table(NodeNeighborTable,Nodesarray,UserRelayArray,Mode_Table,User_Mode_Num);
	//Print_Mode_Table(Mode_Table,Mode_Num_Real);   //��ʾ����ģʽѡ�����
	Out_Mode_Table(Mode_Table,Mode_Num_Real);   //������ģʽ����д�뵽�����ĵ���

	//Print_User_Mode_Num(User_Mode_Num);         //��ʾÿ���û��м��ֿ�ѡ�Ĵ���ģʽ	
	Out_User_Mode_Num(User_Mode_Num);               //��ÿ���û��Ĵ���ģʽ����������ĵ���
		
	//������ÿһ�ִ���ģʽ���û��˿ɴ������,������������������
	double Rate[Mode_Num]={0.0};
	Get_Rate(Rate,Mode_Num_Real,Mode_Table,User_Mode_Num,Nodesarray,NodeNeighborTable);
	Out_Rate(Rate,Mode_Num_Real);
	//Out_Cache(variable_number,Mode_Num_Real);

	//���㵥�����µ�������
	//double ST_rate[MaxUserNum] = {0.0};
	//ST_throughput(Rate, User_Mode_Num,ST_rate, Access_table, Mode_Table);
	//Print_ST(ST_rate);
	//Out_Access_table(Access_table);  //���û��������д�뵽�����ĵ�

    const int variable_number=Get_variable_number(User_Mode_Num);  //��ѧģ����ʵ�ʵı�������
	int Objective_function[variable_num]={0};                      //Ŀ�꺯��

	//���Ŀ�꺯����Objective_function		
	Get_Objective_function(Objective_function,NodeNeighborTable,User_Request,Cache_data,Mode_Table,Mode_Num_Real,User_Mode_Num);
	Print_Objective_function(Objective_function,variable_number);

	//�����ʽ����ϵ����Matrix_equation
	int Matrix_equation[equation_num][variable_num];
	int Matrix_equation_value[MaxRelayNum];
	int equation_number = MaxRelayNum;
	Get_Matrix_equation(Matrix_equation_value,Matrix_equation, Mode_Table, Mode_Num_Real,equation_number,User_Mode_Num);
	Print_Matrix_equation(Matrix_equation_value,Matrix_equation,equation_number,variable_number);
	
	//�������ʽ����ϵ����Matrix_inequality 	
	//int Matrix_inequality[inequality_num][variable_num];
	int Matrix_inequality_value[inequality_num];         // ����ʽ����ֵ
    const int inequality_number=Get_Matrix_inequality(Mode_Table,Matrix_inequality_value,Mode_Num_Real,User_Mode_Num,NodeNeighborTable,Rate,Cache_data, Matrix_inequality);
    Print_Matrix_inequality(Matrix_inequality_value,inequality_number,variable_number, Matrix_inequality);
	
   //getchar();
}










