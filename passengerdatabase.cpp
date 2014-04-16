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
	fstream file;//��Ķ���
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


//��������
Passenger *Passengerdatabase::search(long int IDENTIFICATION)//��ѯ
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



void Passengerdatabase::reverse(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME)//��Ʊʱִ�еĺ�̨�˿ͼ�¼����
{
	Passenger *p=search(IDENTIFICATION);
	if(p==NULL)
	{
		all++;
		passenger[all].add(IDENTIFICATION,FLIGHT,SEAT,NAME);
		//cout<<"��ӳ˿ͳɹ���"<<endl;
	}
	else
	{
		cout<<"��Ӧ֤���ų˿��Ѿ����ڣ��޷����"<<endl;
	}
}



void Passengerdatabase::refund(long int IDENTIFICATION)//��Ʊʱ��ִ̨��(��Ҫ�����ж��Ƿ����)
{
	Passenger *p=search(IDENTIFICATION);
	if(p!=NULL)
	{
		for(int i=0;i<=all;i++)
		{
			if(passenger[i].getidentification()==IDENTIFICATION)
			{				
				passenger[i].del();
				//cout<<"ɾ���˿ͳɹ���"<<endl;
			}
		}

	}
	else
	{
		cout<<"��Ӧ֤���ų˿Ͳ����ڣ��޷�ɾ��"<<endl;
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
