
#include "Function.h"

//�ļ����ܻ�ӭ��
void Pro_Generator(double *p);
void Print_Pro(double *p);

//�û������ļ��ܻ�ӭ�Ȳ���
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum],double *File_Pro);

//�û������������
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum]);

void Print_Request(int *User_Request);

//���û����ļ���������������ĵ�
void Out_Request(int (& User_Request)[MaxUserNum][MaxFileNum]);