#include"passengerdatabase.h"
#include"planedatabase.h"
#include"passenger.h"
#include"plane.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


Passengerdatabase::Passengerdatabase()
{
	Passenger p;
	all=-1;
	fstream file;//类的对象
    file.open("passenger.dat",ios::in|ios::binary);
	while(1)
	{ 
		file.read((char*)&p,sizeof(p));
		if(!file)
		{
			break;
		}
		all++;
		passenger[all]=p;
	}
	file.close();
}

Passengerdatabase::~Passengerdatabase()
{  
	fstream file;
	file.open("passenger.dat",ios::out|ios::binary);
	for(int i=0;i<=all;i++)
	{
		if(passenger[i].getnote()==0)
		{
			file.write((char*)&passenger[i],sizeof(passenger[i]));
		}
	}
	file.close();
}


//辅助函数
Passenger *Passengerdatabase::search(long int IDENTIFICATION)//查询
{
	for(int i=0;i<=all;i++)
	{
		if(passenger[i].getidentification()==IDENTIFICATION&&passenger[i].getnote()==0)
		{
			return &passenger[i];
		}
	}
	return NULL;
}



void Passengerdatabase::reverse(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME)//订票时执行的后台乘客记录操作
{
	Passenger *p=search(IDENTIFICATION);
	if(p==NULL)
	{
		all++;
		passenger[all].add(IDENTIFICATION,FLIGHT,SEAT,NAME);
		//cout<<"添加乘客成功！"<<endl;
	}
	else
	{
		cout<<"对应证件号乘客已经存在，无法添加"<<endl;
	}
}



void Passengerdatabase::refund(long int IDENTIFICATION)//退票时后台执行(需要补充判断是否存在)
{
	Passenger *p=search(IDENTIFICATION);
	if(p!=NULL)
	{
		for(int i=0;i<=all;i++)
		{
			if(passenger[i].getidentification()==IDENTIFICATION)
			{				
				passenger[i].del();
				//cout<<"删除乘客成功！"<<endl;
			}
		}

	}
	else
	{
		cout<<"对应证件号乘客不存在，无法删除"<<endl;
	}
}





void Passengerdatabase::list()
{
	for(int i=0;i<=all;i++)
	{
		if(passenger[i].getnote()==0)
		{
			passenger[i].list();
		}
		else
		{
			continue;
		}
	}
	cout<<endl;
}


void Passengerdatabase::list2(int FLIGHT)
{
	for(int i=0;i<=all;i++)
	{
		if(passenger[i].getnote()==0)
		{
			if(FLIGHT==passenger[i].getflight())
			{
				passenger[i].list();
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}
