#ifndef _passengerdatabase_h_
#define _passengerdatabase_h_
#include"passenger.h"
#include<iostream>
using namespace std;

const int MAXPASSENGER=200;//最大单机乘客数量

class Passengerdatabase
{
private:
	int all;//乘客存储指针
	Passenger passenger[MAXPASSENGER];
public:
	//文件读写
	Passengerdatabase();
	~Passengerdatabase();
	void list2(int FLIGHT);
	//辅助函数
	Passenger *search(long int IDENTIFICATION);//查询	
	void reverse(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME);//订票时执行
	void refund(long int IDENTIFICATION);//退票时执行
	void list();


};
#endif