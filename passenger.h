#ifndef _passenger_h_
#define _passenger_h_
#include<iostream>
using namespace std;

class Passenger
{
public:
	int note;//ɾ����ǣ�1����ɾ��0��δɾ��
	long int identification;//���֤
	int flight;//�����
	int seat;//��λ��
	char name[20];//����
public:
	int getnote();//���ɾ�����
	int getflight();//��ú����
	int getidentification();//������֤����
	char *getname();//��ó˿�����
	int getseat();//��ó˿���λ��
	int list();

	//��̨��¼�˿���Ϣ�����õľ������
	int add(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME);
	int del();//��Ʊʱִ��

};
#endif