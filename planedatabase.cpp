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
	fstream file;//��Ķ���
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


void Planedatabase::add(int NUMBER,char*DESTINATION,char*TIME,int TOTAL)//�ж���ǰ����ֹ�����ù���һ���ٴ����ޣ�����
{
	/*
	Plane *p=search(NUMBER);
	if(p==NULL)
	{
	*/
	all++;
	plane[all].add(NUMBER,DESTINATION,TIME,TOTAL);
	cout<<"��Ӻ���ɹ���"<<endl;
	/*
	}
	else
	{
		cout<<"��Ӧ����ź����Ѿ����ڣ��޷����"<<endl;
	}
	*/
}



void Planedatabase::change(int NUMBER,char*TIME)//�ж���ǰ����ֹ�����ù���һ���ٴ����ޣ�����
{
	/*
	Plane *p=search(NUMBER);
	if(p!=NULL)
	{
	*/

	//ע����ʾ�����������±�����𣡣�����
	for(int i=0;i<=all;i++)//������Ӧ���������±�
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].change(TIME);
			cout<<"���ĺ���ɹ���"<<endl;
		}
	}
	
	/*
	}
	else
	{
		cout<<"��Ӧ����ź��಻���ڣ��޷�����"<<endl;
	}
	*/
}


void Planedatabase::cancel(int NUMBER)
{
	Plane *p=search(NUMBER);
	if(p!=NULL)
	{
		for(int i=0;i<=all;i++)//��ѯ�����
		{
			if(plane[i].getnumber()==NUMBER)
			{				
				plane[i].cancel();
				cout<<"ȡ������ɹ���"<<endl;
			}
		}
		
	}
	else
	{
		cout<<"��Ӧ����ź��಻���ڣ��޷�ȡ��"<<endl;
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
			if(strcmp(plane[i].getdestination(),DESTINATION)==0)//����string��ߵ�strcmp����������������������ֱ�ӱȽ�
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

void Planedatabase::reverse(int NUMBER)//��Ʊʱִ��
{
	for(int i=0;i<=all;i++)//������Ӧ���������±�
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].reverse();

		}
	}
}


void Planedatabase::refund(int NUMBER)//��Ʊʱִ��
{
	for(int i=0;i<=all;i++)//������Ӧ���������±�
	{
		if(plane[i].getnumber()==NUMBER)
		{
			plane[i].refund();

		}
	}
}




