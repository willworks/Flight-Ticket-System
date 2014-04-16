#ifndef _planedatabase_h_
#define _planedatabase_h_
#include"plane.h"
#include<iostream>
using namespace std;

const int MAXPLANE=200;//��󵥼亽�չ�˾������

class Planedatabase
{
private:
	int all;//����洢ָ��
	Plane plane[MAXPLANE];
public:
	//�ļ���д
	Planedatabase();
	~Planedatabase();

	//��������
	Plane *search(int NUMBER);	//��ѯ������Ҫ�ĺ���
	void list1(char*DESTINATION);

	void add(int NUMBER,char*DESTINATION,char*TIME,int TOTAL);
	void change(int NUMBER,char*TIME);
	void cancel(int NUMBER);
	void clear();//������г˿�����
	void list();
	void reverse(int NUMBER);//��Ʊʱִ��
	void refund(int NUMBER);//��Ʊʱִ��

};
#endif