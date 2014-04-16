#ifndef _passenger_h_
#define _passenger_h_
#include<iostream>
using namespace std;

class Passenger
{
public:
	int note;//删除标记（1：已删，0：未删）
	long int identification;//身份证
	int flight;//航班号
	int seat;//座位号
	char name[20];//姓名
public:
	int getnote();//获得删除标记
	int getflight();//获得航班号
	int getidentification();//获得身份证号码
	char *getname();//获得乘客姓名
	int getseat();//获得乘客座位号
	int list();

	//后台记录乘客信息待调用的具体操作
	int add(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME);
	int del();//退票时执行

};
#endif