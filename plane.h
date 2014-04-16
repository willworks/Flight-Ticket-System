#ifndef _plane_h_
#define _plane_h_
#include<iostream>
using namespace std;

class Plane
{
public:
	int note;//删除标记（1：已删，0：未删）
	int number;//航班号
	char destination[20];//到达港
	char time[10];//起飞时间
	int total;//总票数
	int rest;//剩余票数
	int seat[200];
public:
	int getnote();//获得取消标志
	int getnumber();//获得航班号
	char *getdestination();//获得到达港
	char *gettime();//获得起飞时间
	int gettotal();//获得总票数
	int getrest();//获得剩余总票数

	int getseat();//获得空的座位号
	void delseat(int SEAT);//退票的时候把相应的座位标记为空

	void reverse();//订票时执行,操作剩余票数
	void refund();//退票时执行,操作剩余票数
	
	//待调用的具体操作
	int add(int NUMBER,char *DESTINATION,char *TIME,int TOTAL);
	int change(char*TIME);
	int cancel();
	int list();
};
#endif