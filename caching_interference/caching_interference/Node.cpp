 
#include "Node.h"
// ʵ�ֹ��캯��
Node::Node()		
{
	x_axis=0;
	y_axis=0;
	nodenum=0;
}

Node::Node(double x, double y)	
{
	x_axis=x;
	y_axis=y;
	nodenum=0;
}

Node::~Node()
{
	
}

//��ýڵ�ĺ�����
double Node::NodeGetXAxis() const
{
	return x_axis;
}

//��ýڵ��������
double Node::NodeGetYAxis() const
{
	return y_axis;
}

//��ýڵ���
int Node::NodeGetnodenum() const
{
	return nodenum;
}

//���ýڵ������
void Node::NodeSetXAxis(double x)
{
	x_axis = x;
}

//���ýڵ�������
void Node::NodeSetYAxis(double y)
{
	y_axis = y;
}

//���ýڵ���
void Node::NodeSetnodenum(int nodenumber)
{
	nodenum =nodenumber;
}

//��ʾ����Ľڵ�
void Node::ShowNode() const
{
	cout<< "�ڵ�" << this->NodeGetnodenum() << "������Ϊ����" << this->NodeGetXAxis() << "," << this->NodeGetYAxis()<<")" << endl;
}