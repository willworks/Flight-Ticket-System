#ifndef _plane_h_
#define _plane_h_
#include<iostream>
using namespace std;

class Plane
{
public:
	int note;//ɾ����ǣ�1����ɾ��0��δɾ��
	int number;//�����
	char destination[20];//�����
	char time[10];//���ʱ��
	int total;//��Ʊ��
	int rest;//ʣ��Ʊ��
	int seat[200];
public:
	int getnote();//���ȡ����־
	int getnumber();//��ú����
	char *getdestination();//��õ����
	char *gettime();//������ʱ��
	int gettotal();//�����Ʊ��
	int getrest();//���ʣ����Ʊ��

	int getseat();//��ÿյ���λ��
	void delseat(int SEAT);//��Ʊ��ʱ�����Ӧ����λ���Ϊ��

	void reverse();//��Ʊʱִ��,����ʣ��Ʊ��
	void refund();//��Ʊʱִ��,����ʣ��Ʊ��
	
	//�����õľ������
	int add(int NUMBER,char *DESTINATION,char *TIME,int TOTAL);
	int change(char*TIME);
	int cancel();
	int list();
};
#endif