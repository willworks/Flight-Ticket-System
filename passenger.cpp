#include"passenger.h"
#include<iomanip>
#include<iostream>
using namespace std;




int Passenger::getnote()
{
	return note;
}



int Passenger::getflight()
{
	return flight;
}



int Passenger::getidentification()
{
	return identification;
}



char*Passenger::getname()
{
	return name;
}



int Passenger::getseat()
{
	return seat;
}



int Passenger::list()
{
	cout<<setw(15)<<identification<<setw(15)<<name<<setw(15)<<flight<<setw(15)<<seat<<endl;
	return 0;
}



int Passenger::add(long int IDENTIFICATION,int FLIGHT,int SEAT,char*NAME)//¶©Æ±Ê±Ö´ĞĞ
{
	note=0;
	identification=IDENTIFICATION;
	strcpy(name,NAME);
	flight=FLIGHT;
	seat=SEAT;
	return 0;
}



int Passenger::del()//ÍËÆ±Ê±Ö´ĞĞ
{
	note=1;
	return 0;
}





