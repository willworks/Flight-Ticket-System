#ifndef _planedatabase_h_
#define _planedatabase_h_
#include"plane.h"
#include<iostream>
using namespace std;

const int MAXPLANE=200;//最大单间航空公司航班数

class Planedatabase
{
private:
	int all;//航班存储指针
	Plane plane[MAXPLANE];
public:
	//文件读写
	Planedatabase();
	~Planedatabase();

	//辅助函数
	Plane *search(int NUMBER);	//查询，很重要的函数
	void list1(char*DESTINATION);

	void add(int NUMBER,char*DESTINATION,char*TIME,int TOTAL);
	void change(int NUMBER,char*TIME);
	void cancel(int NUMBER);
	void clear();//清除所有乘客数据
	void list();
	void reverse(int NUMBER);//订票时执行
	void refund(int NUMBER);//退票时执行

};
#endif