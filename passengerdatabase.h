#ifndef _passengerdatabase_h_
#define _passengerdatabase_h_
#include"passenger.h"
#include<iostream>
using namespace std;

const int MAXPASSENGER=200;//��󵥻��˿�����

class Passengerdatabase
{
private:
	int all;//�˿ʹ洢ָ��
	Passenger passenger[MAXPASSENGER];
public:
	//�ļ���д
	Passengerdatabase();
	~Passengerdatabase();
	void list2(int FLIGHT);
	//��������
	Passenger *search(long int IDENTIFICATION);//��ѯ	
	void reverse(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME);//��Ʊʱִ��
	void refund(long int IDENTIFICATION);//��Ʊʱִ��
	void list();


};
#endif