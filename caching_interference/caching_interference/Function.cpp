//#include "Node.h"
#include "Function.h"
#include <math.h>


//������վ�����ɷ�ʽ
void NodesGenerator(int num,Node *p)
{         

	srand((unsigned)time(0)) ;	
	//������վ����
	//p[0] = Node(50,50);
	//p[1] = Node(125,50);
	//������վ����
	p[0] = Node(50,50);
	p[1] = Node(125,50);
	p[2] = Node(200,50);
	p[3] = Node(75,125);
	p[4] = Node(180,125);
	/*p++=Node(125,50);
	*p++=Node(125,100);
	*p++=Node(50,100);
	*p++=Node(100,50);
	*p++=Node(100,150);*/
	int count=0;
	
    for(int i=0;i<5000;i++)
    {

		//double x=rand()%175;      //������վʱ���û�����Ĳ���
		double x=rand()%250;        //������վ���û�����Ĳ���
	    double y=rand()%175;	
		
		for(int j=0;j<MaxRelayNum;j++)
		{
          double x1=p[j].NodeGetXAxis();
		  double y1=p[j].NodeGetYAxis();
		  double distance=sqrt(pow((x-x1),2) + pow((y-y1),2));
		  if(distance<TRANSMISSION_DISTANCE)
		  {
			  p[count+MaxRelayNum] = Node(x,y);
			  count++;
			  break;
		  }

		}	
        if(count==num-MaxRelayNum)
		 {
		   break;
		 }
        
	}			
}



//���������Ľڵ�
void print_node(int num,Node *p)
{ 
	int nodenumber=0;
	for(int i=0;i<num;i++)
	{
		++nodenumber;
		p[i].NodeSetnodenum(nodenumber);
		p[i].ShowNode();
	}
    cout<<endl;
}

//������վ��ʼ�������,ָ����վ��������沿���ļ����򻺴�ȫΪ��(�л���ʱ���÷���һ��û�л���ʱ���÷�����)
void Cache_Generator(int (& Cache_data)[MaxRelayNum][MaxFileNum],int *Cache_remain)
{
	//��ʼ��
	for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
			 Cache_data[i][j]=0;
		}
		Cache_remain[i]=Cache_Max;
	}
	
	//����һ;�������	
/*	srand((unsigned)time(0)) ;
	for(int i=0;i<MaxRelayNum;i++)
    {	  
	  int count = 0;
	  for(int j=0;j<MaxFileNum;j++)
	  {		
		int a = rand()%100;
		if(a<60)
		{
		  Cache_data[i][j]=0;
		}
		else
		{
	     Cache_data[i][j]=1;
		 count++;    //count��¼�˵�ǰ��վռ���˶��ٻ���ռ�
		}
		if(count==Cache_Max)
		{
			break;
		}
	  }
	  Cache_remain[i] = Cache_Max - count;
    }*/
	//������������ȫΪ��
	/*for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
			Cache_data[i][j]=0;
		}
	}*/
}
//����վ��ǰ�Ļ���״̬
void Print_Cache(int (& Cache_data)[MaxRelayNum][MaxFileNum],int *Cache_remain)
{
	cout<<"��վ��ǰ�Ļ���״̬Ϊ�� "<<endl;
	for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
			cout<<Cache_data[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"��վ��ǰ���õĻ���Ϊ�� "<<endl;
	for(int i=0;i<MaxRelayNum;i++)
	{
		cout<<*(Cache_remain++)<<" ";
	}
	cout<<endl<<endl;
}

//�û�����,����һ��request.h��д���������Ͱ��ܻ�ӭ��������β���Ҫ��
/*void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum])
{
	srand((unsigned)time(0)) ;
	for(int i=0;i<MaxUserNum;i++)
    {
	  for(int j=0;j<MaxFileNum;j++)
	  {

		int temp = rand()%MaxFileNum;
		User_Request[i][temp] = 1;   //��֤ÿ��ͳ�Ƶ�ÿ���û���������
		break;
	  }
    }
}
void Print_Request(int *User_Request)
{
	cout<<"�û�����Ϊ "<<endl;
	for(int i=0;i<MaxUserNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
		    cout<<*(User_Request++)<<" ";
		}
		cout<<endl;		
	}
	cout<<endl;	
}*/


//�ж������ڵ�֮���Ƿ��ڽ�
bool NodeDistanceJudgement(Node src,Node dest)
{
	//TRANSMISSION_DISTANCE��ʾ���ڵ�乹����·�������룬����ֵΪtrue����ʾ���ڵ��ܹ�����·��false����
	if(DistanceCalculation(src,dest)<=TRANSMISSION_DISTANCE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GetNodeNeighborTable(int *NodeNeighborTable,Node *Nodesarray)
{
	for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxUserNum;j++)
		{
			if(NodeDistanceJudgement(Nodesarray[j+MaxRelayNum],Nodesarray[i]))
			{
			   *NodeNeighborTable=1;
			}
			else
			{
				*NodeNeighborTable=0;
			}
			NodeNeighborTable++;
		}
	}

}

//��ʾ�ڵ��ھӱ�
void Print_NodeNeighborTable(int *NodeNeighborTable)
{
	cout<<"�û����վ���ڽӹ�ϵ: "<<endl;
	for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxUserNum;j++)
		{
		    cout<<*(NodeNeighborTable++)<<" ";
		}
		cout<<endl;		
	}
	cout<<endl;	
}

//UserRelayTable��һά���飬��¼ÿ���û������ӵĻ�վ����Ŀ
void Get_UserRelayArray(int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],int *UserRelayArray)
{
	 for(int i=0;i<MaxUserNum;i++)
	{
		int a=0;
	    for(int j=0;j<MaxRelayNum;j++)
		{
		    if(NodeNeighborTable[j][i]==1)
			{
			    a = a+1;
			}
		}
		UserRelayArray[i]=a;
	}
}
//���UserRelayTable
void Print_UserRelayArray(int *UserRelayArray)
{
	cout<<"�û������ӵĻ�վ��ĿΪ�� "<<endl;
	for(int i=0;i<MaxUserNum;i++)
	{
		cout<<UserRelayArray[i]<<" ";
	}
	cout<<endl;
}


//���㴫��ģʽ����,������CoMP������
/* int Get_Mode_Table(int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],Node *Nodesarray,int *UserRelayArray,int (& Mode_Table)[Mode_Num][MaxRelayNum],int *User_Mode_Num)
{
	//��ʼ��
	for(int m=0;m<Mode_Num;m++)
	{
		for(int n=0;n<MaxRelayNum;n++)
		{
			Mode_Table[m][n]=0;
		}
	}
	for(int n=0;n<MaxUserNum;n++)
	{
		User_Mode_Num[n]=0;
	}

	int mode_num_real=0;	//��¼ʵ�ʲ����˶��ٸ�����ģʽ
    for(int i=0;i<MaxUserNum;i++)
	{
	   
		 if(UserRelayArray[i]==1)   //�û�ֻ��һ���ڽӻ�վ
		 {
		     User_Mode_Num[i]=1;
			 for(int j=0;j<MaxRelayNum;j++)
			 {
			    if(NodeNeighborTable[j][i]==1)
			    { 
			        Mode_Table[mode_num_real][j]=1;
				    mode_num_real++;
				    break;
			    }	    
		     }
	     }
		 else        //�û��ж���ڽӻ�վ
	      {
	         int a=0;                         //���ڼ�¼�û�iһ�����ж����ִ���ģʽ
             int Temp[MaxRelayNum]={0};      //������ʱ����û�i��һ�ִ���ģʽ
			 fill_n(Temp,MaxRelayNum,1);     //Temp��ʼԪ��ȫ��Ϊ1.���ж����վ�Ĵ���ģʽ��ʼ���𽥼��ٻ�վ
			 int b=1;
			 for(int m=0;m<MaxRelayNum;m++)
			 {
				 b=b*2;
			 }			 
	         for(int k=0;k<(b-1);k++)       //Temp����ִ�е�ȫ0�����
			 {

				 int flag=1;
				 for(int m=0;m<MaxRelayNum;m++)           //�жϴ���ģʽ�еĻ�վ�Ƿ�Ϊ�û����ڽӻ�վ
				  {
					
                    if(Temp[m]==1 && NodeNeighborTable[m][i]==1)   
	                {		              			           
						continue;					              
	                 }
					else if(Temp[m]==1 && NodeNeighborTable[m][i]==0)
					{
						flag=0;
					    break;
					}
                  }
				 if(flag==1)         //˵������ģʽ�ǿ��е�
				 {
					 for(int g=0;g<MaxRelayNum;g++)
					 {
						 Mode_Table[mode_num_real][g]=Temp[g];
					 }
					 mode_num_real++;
					 a++;
				 }
				 //�޸�Temp��ֵ
				 Temp[0]=Temp[0]-1;
				 if(Temp[0]<0)
				 {
					 int j=1;
					 while(Temp[j]!=1)
					 {
						 j++;
					 }
					 Temp[j]=0;
					 for(int e=0;e<j;e++)
					 {
						 Temp[e]=1;
					 } 
				 }
			 }
			
			User_Mode_Num[i]=a;	 
		 }
	    }	   		
		
	  
	ofstream file;
	file.open("����ģʽ����.txt");
	file<<mode_num_real;
	file.close();
	cout<<"����ģʽ�ĸ���Ϊ�� "<<mode_num_real<<endl;	
	return mode_num_real;
}*/


//���㴫��ģʽ����,û����CoMP������
int Get_Mode_Table(int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],Node *Nodesarray,int *UserRelayArray,int (& Mode_Table)[Mode_Num][MaxRelayNum],int *User_Mode_Num)
{
	//��ʼ��
	for(int m=0;m<Mode_Num;m++)
	{
		for(int n=0;n<MaxRelayNum;n++)
		{
			Mode_Table[m][n]=0;
		}
	}
	for(int n=0;n<MaxUserNum;n++)
	{
		User_Mode_Num[n]=0;
	}

	int mode_num_real=0;	//��¼ʵ�ʲ����˶��ٸ�����ģʽ
    for(int i=0;i<MaxUserNum;i++)
	{
	   
		 if(UserRelayArray[i]==1)   //�û�ֻ��һ���ڽӻ�վ
		 {
		     User_Mode_Num[i]=1;
			 for(int j=0;j<MaxRelayNum;j++)
			 {
			    if(NodeNeighborTable[j][i]==1)
			    { 
			        Mode_Table[mode_num_real][j]=1;
				    mode_num_real++;
				    break;
			    }	    
		     }
	     }
		 else        //�û��ж���ڽӻ�վ
	      {
	         int a=0;                         //���ڼ�¼�û�iһ�����ж����ִ���ģʽ
	         for(int k=0;k<MaxRelayNum;k++)       //
			 {

				 if(NodeNeighborTable[k][i]==1)
				 {
					 Mode_Table[mode_num_real][k]=1;
					 mode_num_real++;
					 a++;
				 }
			 }			
			User_Mode_Num[i]=a;	 
		  }
	  }	   		
		
	  
	ofstream file;
	file.open("����ģʽ����.txt");
	file<<mode_num_real;
	file.close();
	cout<<"����ģʽ�ĸ���Ϊ�� "<<mode_num_real<<endl;	
	return mode_num_real;
}
 
 //�жϴ���ģʽTemp����ģʽ�Ƿ����
/*bool Judge_Temp(int *Temp,int num1,int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum])
 {
	 int flag=0;
	 for(int i=0;i<MaxRelayNum;i++)
	 {
		 while(Temp[i]==1)
		 {
			 if(NodeNeighborTable[i][num1]==0)
			 {
				 flag=1;
			 }
		 }
	 }
	 if(flag==0)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }*/

//���Mode_Table
void Print_Mode_Table(int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real)
{
	cout<<"����ģʽ����Ϊ�� "<<endl;
	for(int i=0;i<Mode_Num_Real;i++)
	{
		for(int j=0;j<MaxRelayNum;j++)
		{
			cout<<Mode_Table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//������ģʽ����д�뵽�����ĵ���
void Out_Mode_Table(int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real)
{
	ofstream file;
	file.open("����ģʽ����.txt");
	for(int i=0;i<Mode_Num_Real;i++)
	{
		for(int j=0;j<MaxRelayNum;j++)
		{
			file<<Mode_Table[i][j]<<" ";
		}
		file<<endl;
	}
	file.close();
}

//��ʾÿ���û��м��ִ���ģʽ
void Print_User_Mode_Num(int *User_Mode_Num)
{
	cout<<"ÿ���û��м��ִ���ģʽ�� "<<endl;
	for(int i=0;i<MaxUserNum;i++)
	{
		cout<<User_Mode_Num[i]<<" "<<endl;
	}
	cout<<endl;
}

//��ÿ���û��ĴӴ���ģʽ��������������ĵ���
void Out_User_Mode_Num(int *User_Mode_Num)
{
	ofstream file;
	file.open("ÿ�û�����ģʽ����.txt");
	for(int i=0;i<MaxUserNum;i++)
	{
		file<<User_Mode_Num[i]<<" ";
	}
	file.close();
}


//����ÿһ�ִ���ģʽ���û��˿ɴ����������

//�������û�dest�����յ��Ļ�վsrc���͵Ĺ��ʵĴ�С
double Calculate_Power(Node dest,Node src)   //�û�����վ
{
	double temp=0.0;
	double power=0.0;
	//double b = pow(10,2) * pow(1.5,2);
	//power=(POWER* b)/( pow (DistanceCalculation(dest,src) , 4 ));
	double distan = DistanceCalculation(dest,src)/1000;     //���룬km
	temp = POWER - 152-36.7*log10(distan);                //����dBm	
	power = Dbm_To_W(temp);                                //��dBmת��ΪW 
	return power;
}

//��dBmת��ΪW
double Dbm_To_W(double dBm)
{
	double mW = pow (10.0, dBm/10.0);
    return mW / 1000.0;
}

//�����û�dest����վsrc֮��ľ���
double DistanceCalculation(Node src,Node dest)
{         
	//����ڵ�src�ͽڵ�dest֮��ľ���
	double xy_distance=0;
	double x_src, y_src, x_dest, y_dest; 
	x_src = src.NodeGetXAxis();
	y_src = src.NodeGetYAxis();
	x_dest = dest.NodeGetXAxis();
	y_dest = dest.NodeGetYAxis();
	xy_distance =sqrt(pow((x_dest - x_src),2) + pow((y_dest- y_src),2));
	return xy_distance;
}


void Get_Rate(double *Rate,int Mode_Num_Real,int (& Mode_Table)[Mode_Num][MaxRelayNum],int *User_Mode_Num,Node *Nodesarray,int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum])
{
    //cout<<"������ģʽ�µ�����Ϊ��"<<endl;
    int temp1=0;

	for(int i=0;i<MaxUserNum;i++)
	{
		for(int j=temp1;j<temp1+User_Mode_Num[i];j++)
		{
			double temp2=0.0;
			double temp3=0.0;
			for(int k=0;k<MaxRelayNum;k++)
			{
				
				
				if((Mode_Table[j][k]==1) && (NodeNeighborTable[k][i]==1))                       //�����ź�
				{
					temp2=temp2+Calculate_Power(Nodesarray[i+MaxRelayNum],Nodesarray[k]);      //�����power�ĵ�λ������W
				}
				else if((Mode_Table[j][k]==0) && (NodeNeighborTable[k][i]==1))                 //�����ź�
				{
					temp3=temp3+Calculate_Power(Nodesarray[i+MaxRelayNum],Nodesarray[k]);
				}

			}			
			double sinr = temp2/(temp3 + Environmentalnoise);
			Rate[j] = log10(1+sinr)/log10(2.0);	 //����������Ƶ��Ч�����ó��Դ���Rate[j] = Band * log10(1+sinr)/log10(2.0);
			//cout<<Rate[j]<<endl;
		}
		temp1=temp1+User_Mode_Num[i];
	}
}

//��ÿ�ִ���ģʽ�µ�����������ĵ���
void Out_Rate(double *Rate,int Mode_Num_Real)
{
	ofstream file;		
	file.open("����.txt");
	for(int j=0;j<Mode_Num_Real;j++)
	{
		file<<*(Rate++)<<" ";
	}	
	file.close();
}

//��ʵ�ʱ����л�����ߵĲ�����Ϊ1��������ڼ��㻺������
/*void Out_Cache(int variable_number,int Mode_Num_Real)
{
	ofstream file;	
	int a[variable_num]={0};
	int temp = Mode_Num_Real*SubcarrierNum*2 + Mode_Num_Real + MaxUserNum*SubcarrierNum;
	for(int i=0;i<MaxRelayNum*MaxFileNum;i++)
	{
		a[temp+i] =1;
	}
	file.open("�����ļ�.txt");
	for(int j=0;j<variable_number;j++)
	{
		file<<a[j]<<" ";
	}
	file.close();
}*/

//�õ���ѧģ���б����ĸ���
int Get_variable_number(int *User_Mode_Num)

{
    int variable_number=0;
	int a=0;
	int b=0;
	for(int i=0;i<MaxUserNum;i++)
	 {
	    a=User_Mode_Num[i]+a;
		//b=b+User_Mode_Num[i]*SubcarrierNum;
	 }
	//variable_number=a;     //ln,i��֪
	variable_number=a+MaxRelayNum*MaxFileNum;  //ln,i�Ǳ���
	//cout<<"�ܱ�������Ϊ�� "<<variable_number<<endl;
	return variable_number;
}

//��ʼ��Ŀ�꺯����
void Get_Objective_function(int (& Objective_function)[variable_num],int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum],int (& User_Request)[MaxUserNum][MaxFileNum],int (& Cache_data)[MaxRelayNum][MaxFileNum],int (& Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real,int *User_Mode_Num)
{
	//��ʼ��
	for(int i=0;i<variable_num;i++)
	{
		Objective_function[i]=0;
	}	
	int temp = 0;
   // int fore = Mode_Num_Real*SubcarrierNum;
	//��y��ϵ��
    for(int i=0;i<MaxUserNum;i++)
    {
		int flag=0;
		while(User_Request[i][flag]==0)
		{
			flag = flag+1;       //flag��¼���û�i�����±�Ϊflag���ļ�
		} 
        for(int j=temp;j<temp+User_Mode_Num[i];j++)
	    {
		   	int temp1 = 0;              
		    for(int k=0;k<MaxRelayNum;k++)
		    {
			    if(Mode_Table[temp][k]==1)   //am,i=1�û������ļ� ����wn,i=0��վû�л���
			    {
				    temp1++;
			    }
		    }	
		    Objective_function[j] =temp1; 		    
	    }
		temp=temp+User_Mode_Num[i];
    }
	//��L��ϵ��(�л���ʱ�������л���Ĵ��룻û�л���ʱ����������ζ�����; ������֪ʱ�������´�������)
	int fore1 = Mode_Num_Real;
   //�л���
	for(int i=0;i<MaxRelayNum;i++)
    {
	    for(int j=0;j<MaxFileNum;j++)
	    {
		    int temp2 = 0;
		    for(int k=0;k<MaxUserNum;k++ )
		    {
			    if((NodeNeighborTable[i][k]==1) && (User_Request[k][j]==1))
			    {
				    temp2++;
			    }
		    }
	        Objective_function[fore1 + i*MaxFileNum + j] = -temp2;
	    }
    }
	//û�л���,l��ϵ������0,���߽���l��ϵ��������Σ�������
	/*for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
			Objective_function[fore1 + i*MaxFileNum + j] = 0;
		}
	}*/
}


//���Ŀ�꺯����
void Print_Objective_function(int (& Objective_function)[variable_num],int variable_number)
{
	ofstream file;
	file.open("Ŀ�꺯��.txt");
	for(int i=0;i<variable_number;i++)
	{
		//cout<<Objective_function[i]<<" ";
		file<<Objective_function[i]<<" ";
	}
	//cout<<endl;
	file.close();
	//cout<<"Ŀ�꺯���б�������Ϊ; "<<variable_number<<endl;
}

//�õ���ʽ����ϵ��
void Get_Matrix_equation(int ( & Matrix_equation_value)[equation_num], int ( & Matrix_equation)[equation_num][variable_num],int ( & Mode_Table)[Mode_Num][MaxRelayNum],int Mode_Num_Real,int equation_number,int *User_Mode_Num)
{
	//��ʽ�����ʼ��
	for(int i=0;i<equation_num;i++)
	{
		for(int j=0;j<variable_num;j++)
		{
			Matrix_equation[i][j]=0;
		}
	}	
	//��ʽ����ֵ��ʼ��
	for(int i=0; i<MaxRelayNum; ++i)
	{
		Matrix_equation_value[i] = 0;
	}
	/*int temp = 0;
	//��ʽ1 ��y����ģʽѡ��
	for(int i = 0;i<equation_number;i++)
    {
		for(int j=temp;j<temp+User_Mode_Num[i];j++)
		{
	         Matrix_equation[equation_number][j] = 1;
	    }

	    temp = temp + User_Mode_Num[i];
    }*/
	//Ln,i��վ����
   int fore_num2 = Mode_Num_Real;
   int temp2=0;
   for(int i=0;i<MaxRelayNum;i++)
   {	 
	 for(int j=i*MaxFileNum;j<(i+1)*MaxFileNum;j++)
	 {
		Matrix_equation[i][fore_num2 + j]=1;
	 }	
	Matrix_equation_value[i] = Cache_Max;
	temp2=temp2+MaxFileNum;
   }
	//cout<<"��ʽ����ĿΪ�� "<<equation_number<<endl;
}    

//����ʽ����͵�ʽ����ֵд�뵽�ĵ�
void Print_Matrix_equation(int ( & Matrix_equation_value)[equation_num],int ( & Matrix_equation)[equation_num][variable_num],int equation_number,int variable_number)
{
	cout<<"��ʽ�������� "<<equation_number<<" "<<variable_number<<endl;
	ofstream file;
	file.open("��ʽ����.txt");
	for(int i=0;i<equation_number;i++)
	{
		for(int j=0;j<variable_number;j++)
		{
			//cout<<Matrix_equation[i][j]<<" ";
			file<<Matrix_equation[i][j]<<" ";
		}
		//cout<<endl;
		file<<endl;
	}
	file.close();
	file.open("��ʽ����ֵ.txt");
	for(int i=0;i<MaxRelayNum;i++)
	{
		file<<Matrix_equation_value[i]<<endl;	
	}
	file.close();	
}


int Get_Matrix_inequality(int (& Mode_Table)[Mode_Num][MaxRelayNum],int (& Matrix_inequality_value)[inequality_num],int Mode_Num_Real,int *User_Mode_Num,int(& NodeNeighborTable)[MaxRelayNum][MaxUserNum],double *Rate,int (& Cache_data)[MaxRelayNum][MaxFileNum], int(& Matrix_inequality)[inequality_num][variable_num])
{
	//����ʽ�����ʼ��
	for(int i=0;i<inequality_num;i++)           
	{
		for(int j=0;j<variable_num;j++)
		{
			Matrix_inequality[i][j]=0;         //����ʽϵ������ 
		}
	}	
	int inequality_number = 0;                 //���ڼ�¼ʵ�ʲ����Ĳ���ʽ����

	//����ʽ����ֵ��ʼ��
	for(int i=0;i<inequality_num;i++)  
	{
		Matrix_inequality_value[i]=0;         
	}


	//��ʼ�õ�����ʽ����
   // int fore_num = Mode_Num_Real * SubcarrierNum;
	int temp = 0;
	//����ʽ1 ��y����ģʽѡ��
	for(int i = 0;i<MaxUserNum;i++)
    {
		for(int j=temp;j<temp+User_Mode_Num[i];j++)
		{
	         Matrix_inequality[inequality_number][j] = 1;
	    }
	    Matrix_inequality_value[inequality_number] = 1;
	    inequality_number++;
	    temp = temp + User_Mode_Num[i];
    }
	//cout<<inequality_number<<endl;

	//����ʽ2�����ŵ�����
  /* int fore_num1 = Mode_Num_Real * SubcarrierNum*2 + Mode_Num_Real;
   for(int i=0;i<MaxRelayNum;i++)
   {
	 int user_num = 0;
	 while(NodeNeighborTable[i][user_num]==0)
	 {
		 user_num++;
	 }
	 if(user_num<MaxUserNum)  //˵���ڻ�վi�ķ�Χ�����û�
	 {
		 for(int j=0;j<SubcarrierNum;j++)
	      {
	        for(int k=0;k<MaxUserNum;k++)
		    {
		      if(NodeNeighborTable[i][k]==1)
		       {
			    Matrix_inequality[inequality_number][fore_num1 + k*SubcarrierNum + j] = 1;
		       }
		    }
		   Matrix_inequality_value[inequality_number] = 1;
		   inequality_number++;		
	     }    
     }
   }*/
   //cout<<inequality_number<<endl;

  //����ʽ3��L��վ�������,����ln,i������֪ʱ������ʽ3��Ҫ���أ�
 /*  int fore_num2 = Mode_Num_Real;
   int temp2=0;
   for(int i=0;i<MaxRelayNum;i++)
   {	 
	 for(int j=temp;j<(i+1)*MaxFileNum;j++)
	 {
		Matrix_inequality[inequality_number][fore_num2 + j]=1;
	 }	
	Matrix_inequality_value[inequality_number] = Cache_Max;
	inequality_number++;
	temp2=temp2+MaxFileNum;
   }*/
   //cout<<inequality_number<<endl;

   //����ʽ4����������
   
   int temp3=0;
   for(int i=0;i<MaxUserNum;i++)
   {
	 for(int j=temp3; j<temp3+User_Mode_Num[i];j++)
	 {

		  Matrix_inequality[inequality_number][j] = - (int)Rate[temp3];	   // - (int)(Rate[temp3]*1000), �����ʳ���1000��mbpsת��Ϊkbps
		  
		
	 }
	Matrix_inequality_value[inequality_number] = -Rate_Request;
	inequality_number++;
	temp3=temp3+User_Mode_Num[i];
   }
  //cout<<inequality_number<<endl;

 /*  //����ʽ5 y��Q
   int fore_num4 = Mode_Num_Real * SubcarrierNum;
   int temp4 = 0;
   for(int i=0;i<MaxUserNum;i++)
   {
	 for(int j=temp4;j<temp4+User_Mode_Num[i];j++)
	  {
		for(int k=0;k<SubcarrierNum;k++)
		{
		   Matrix_inequality[inequality_number][fore_num4 + j*SubcarrierNum + k] = -1;
		   Matrix_inequality[inequality_number][fore_num4 * 2 + j] = -1;
		   Matrix_inequality_value[inequality_number] = -1;
		   inequality_number++;
		}		
	  }
     temp4 = temp4+User_Mode_Num[i];
   }
   //cout<<inequality_number<<endl;s

   //����ʽ6 ����Q
   int fore_num5 = Mode_Num_Real * SubcarrierNum;
   int temp5 = 0;
   for(int i=0;i<MaxUserNum;i++)
   {
	 for(int j=temp5;j<temp5+User_Mode_Num[i];j++)
	  {
		for(int k=0;k<SubcarrierNum;k++)
		 {
		   Matrix_inequality[inequality_number][fore_num5 + j*SubcarrierNum + k ] = -1;
		   Matrix_inequality[inequality_number][fore_num5*2 + Mode_Num_Real + i*SubcarrierNum + k] = -1;
		   Matrix_inequality_value[inequality_number] = -1;
		   inequality_number++;
		 }
	  }
	temp5 = temp5+User_Mode_Num[i];	
   }
  //cout<<inequality_number<<endl;

   //����ʽ7��y������Q
   int fore_num_6 = Mode_Num_Real * SubcarrierNum;
   int temp6 = 0;
   for(int i=0;i<MaxUserNum;i++)
    {
	  for(int j=temp6;j<temp6+User_Mode_Num[i];j++)
	   {
		 for(int k=0;k<SubcarrierNum;k++)
		  {
			Matrix_inequality[inequality_number][fore_num_6 + j*SubcarrierNum + k ] = 1;
			Matrix_inequality[inequality_number][fore_num_6 * 2 + j] = 1;
			Matrix_inequality[inequality_number][fore_num_6 * 2 + Mode_Num_Real + i*SubcarrierNum + k] = 1;			
			Matrix_inequality_value[inequality_number] = 2;
			inequality_number++;
	 	  }
	   }
	  temp6 = temp6+User_Mode_Num[i];	
    }
   //cout<<inequality_number<<endl;

   //����ʽ8(�ڲ����ǻ���ʱ������ʽ8��Ҫ����)
   int fore_num7 = Mode_Num_Real * SubcarrierNum * 2 + Mode_Num_Real + MaxUserNum * SubcarrierNum;   
   for(int i=0;i<MaxRelayNum;i++)
   {
	   for(int j=0;j<MaxFileNum;j++)
	   {
		   Matrix_inequality[inequality_number][fore_num7 + i*MaxFileNum + j] = 1;
		   Matrix_inequality_value[inequality_number] = 1-Cache_data[i][j];
		   inequality_number++;
	   }	   
   }*/
   

//	cout<<"����ʽ����ĿΪ��"<<inequality_number<<endl;
	return inequality_number;
}

//�������ʽ����
void Print_Matrix_inequality(int (&Matrix_inequality_value)[inequality_num],int inequality_number,int variable_number, int(& Matrix_inequality)[inequality_num][variable_num])
{
	ofstream file;
	file.open("����ʽ����.txt");
	for(int i=0;i<inequality_number;i++)
	{
		for(int j=0;j<variable_number;j++)
		{
			//cout<<Matrix_inequality[i][j]<<" ";
			file<<Matrix_inequality[i][j]<<" ";
		}
		//cout<<endl;
		file<<endl;

	}
	file.close();
	file.open("����ʽ����ֵ.txt");
	for(int i=0;i<inequality_number;i++)
	{
		file<<Matrix_inequality_value[i]<<endl;	
	}
	file.close();
	cout<<"����ʽ�������� "<<inequality_number<<" "<<variable_number<<endl;
}




