#include<iostream>
#include<iomanip>
#include"plane.h"
using namespace std;


int Plane::getnote()
{
	return note;
}

int Plane::getnumber()
{
	return number;
}


char *Plane::getdestination()
{
	return destination;
}


char *Plane::gettime()
{
	return time;
}



int Plane::gettotal()
{
	return total;
}


int Plane::getrest()
{
	return rest;
}


int Plane::add(int NUMBER,char *DESTINATION,char *TIME,int TOTAL)
{
	note=0;
	number=NUMBER;
	strcpy(destination,DESTINATION);
	strcpy(time,TIME);
	total=TOTAL;
	rest=TOTAL;
	for(int i=0;i<total;i++)
	{
		seat[i]=0;
	}
	for(int j=total;j<200;j++)
	{
		seat[j]=1;
	}
	return 0;
}



int Plane::change(char*TIME)
{
	strcpy(time,TIME);
	return 0;
}




int Plane::cancel()
{
	note=1;
	return 0;
}



void Plane::reverse()//²Ù×÷Ê£ÓàÆ±Êý
{
	rest=rest-1;
}



void Plane::refund()//²Ù×÷Ê£ÓàÆ±Êý
{
	rest=rest+1;
}


int Plane::getseat()
{
	for(int i=0;i<total;i++)
	{
		if(seat[i]==0)
		{
			seat[i]=1;
			return(i+1);
		}
	}
}


void Plane::delseat(int SEAT)
{
	seat[SEAT-1]=0;
}



int Plane::list()
{
	cout<<setw(13)<<number<<setw(15)<<destination<<setw(15)<<time<<setw(15)<<total<<setw(15)<<rest<<endl;
	return 0;
}