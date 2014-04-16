#include"planedatabase.h"
#include"plane.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


Planedatabase::Planedatabase()
{
	Plane p;
	all=-1;
	fstream file;//类的对象
    file.open("plane.dat",ios::in|ios::binary);
	while(1)
	{ 
		file.read((char*)&p,sizeof(p));
		if(!file)
		{
			break;
		}
		all++;
		plane[all]=p;
	}
	file.close();
}


Planedatabase::~Planedatabase()
{  
	fstream file;
	file.open("plane.dat",ios::out|ios::binary);
	for(int i=0;i<=all;i++)
	{
		if(plane[i].getnote()==0)
		{
			file.write((char*)&plane[i],sizeof(plane[i]));
		}
	}
	file.close();
}



Plane *Planedatabase::search(int NUMBER)
{
	for(int i=0;i<=all;i++)
	{
		if(plane[i].getnumber()==NUMBER&&plane[i].getnote()==0)
		{
			return &plane[i];
		}
	}
	return NULL;
}


void Planedatabase::add(int NUMBER,char*DESTINATION,char*TIME,int TOTAL)//判断提前，防止做无用功，一错再错！点赞！！！
{
	/*
	Plane *p=search(NUMBER);
	if(p==NULL)
	{
	*/
	all++;
	plane[all].add(NUMBER,DESTINATION,TIME,TOTAL);
	cout<<"添加航班成功！"<<endl;
	/*
	}
	else
	{
		cout<<"对应航班号航班已经存在，无法添加"<<endl;
	}
	*/
}



void Planedatabase::change(int NUMBER,char*TIME)//判断提前，防止做无用功，一错再错！点赞！！！
{
	/*
	Plane *p=search(NUMBER);
	if(p!=NULL)
	{
	*/

	//注意显示数据与数组下标的区别！！！！
	for(int i=0;i<=all;i++)//查找相应航班数组下标
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].change(TIME);
			cout<<"更改航班成功！"<<endl;
		}
	}
	
	/*
	}
	else
	{
		cout<<"对应航班号航班不存在，无法更改"<<endl;
	}
	*/
}


void Planedatabase::cancel(int NUMBER)
{
	Plane *p=search(NUMBER);
	if(p!=NULL)
	{
		for(int i=0;i<=all;i++)//查询航班号
		{
			if(plane[i].getnumber()==NUMBER)
			{				
				plane[i].cancel();
				cout<<"取消航班成功！"<<endl;
			}
		}
		
	}
	else
	{
		cout<<"对应航班号航班不存在，无法取消"<<endl;
	}
}



void Planedatabase::clear()
{
	all=-1;
}



void Planedatabase::list()
{
	for(int i=0;i<=all;i++)
	{
		if(plane[i].getnote()==0)
		{
			plane[i].list();
		}
		else
		{
			continue;
		}
	}
	cout<<endl;
}


void Planedatabase::list1(char*DESTINATION)
{
	for(int i=0;i<=all;i++)
	{
		if(plane[i].getnote()==0)
		{
			if(strcmp(plane[i].getdestination(),DESTINATION)==0)//利用string里边的strcmp函数！！！！！！！不可直接比较
			{
				plane[i].list();
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
	cout<<endl;
}

void Planedatabase::reverse(int NUMBER)//订票时执行
{
	for(int i=0;i<=all;i++)//查找相应航班数组下标
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].reverse();

		}
	}
}


void Planedatabase::refund(int NUMBER)//退票时执行
{
	for(int i=0;i<=all;i++)//查找相应航班数组下标
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].refund();

		}
	}
}




