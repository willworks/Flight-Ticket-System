//注意现实数据和数组下标的区别
#include"plane.h"
#include"passenger.h"
#include"planedatabase.h"
#include"passengerdatabase.h"
#include<iostream>
#include<iomanip>
using namespace std;



int main()
{
	int choice=1;	
	int choice1=3;//查询的类型选择
	int choice2=1;

	//类定义对象
	Plane *pl;
	Passenger *pa;
	Planedatabase pld;
	Passengerdatabase pad;

	//航班参数

	int NUMBER;//航班号
	char DESTINATION[50];//到达港
	char TIME[10];//起飞时间
	int TOTAL;//总票数

	//乘客参数
	long int IDENTIFICAION;//身份证
	char NAME[20];//姓名
	int SEAT;

	while(choice!=0)
	{
		cout<<"=========================航空票务管理系统================================"<<endl;
		cout<<"========================================================================="<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"1:查询     2:订票     3:退票     4:航班管理     5:所有乘客     0.退出系统"<<endl;
		cin>>choice;
		cout<<"-------------------------------------------------------------------------"<<endl;
		switch(choice)
		{
		case 1: choice1=3;//赋值，以便于后来的循环
				while(choice1!=0)
				{
					cout<<"1.查询航班2.查询乘客0.返回"<<endl;
					cin>>choice1;
					switch(choice1)
					{
						case 1: cout<<"输入目的地：";
								cin>>DESTINATION;
								cout<<setw(15)<<"航班号"<<setw(15)<<"到达港"<<setw(15)<<"起飞时间"<<setw(15)<<"总票数"<<setw(15)<<"剩余票数"<<endl;
								pld.list1(DESTINATION);
								break;
						case 2: cout<<"输入航班号：";
								cin>>NUMBER;
								pl=pld.search(NUMBER);
								while(pl==NULL)//判断提前，防止一错再错
								{
								  cout<<"对应航班号航班不存在！"<<endl;
								  cout<<"输入航班号：";
								  cin>>NUMBER;
								  pl=pld.search(NUMBER);
								}
								cout<<setw(10)<<"证件号"<<setw(10)<<"姓名"<<setw(10)<<"航班号"<<setw(10)<<"座位号"<<endl;
								pad.list2(NUMBER);
								break;
						case 0: break;
					}
				}
				break;
		case 2: cout<<"输入证件号：";
				cin>>IDENTIFICAION;
				pa=pad.search(IDENTIFICAION);
				while(pa!=NULL)
				{
					cout<<"对应证件号乘客已经订票，无法再订票"<<endl;
					cout<<"输入证件号：";
					cin>>IDENTIFICAION;
					pa=pad.search(IDENTIFICAION);
				}		
				cout<<"航班号：";
				cin>>NUMBER;
				pl=pld.search(NUMBER);
				//以下为判断
				if(pl!=NULL)
				{
					if(pl->getrest()==0)
					{
						cout<<"该航班机票已全部售完，请重新选择！"<<endl;
					}
					else
					{
						cout<<"姓名：";
						cin>>NAME;
						SEAT=pl->getseat();//!!!数据过大的时候会溢出
						pad.reverse(IDENTIFICAION,NUMBER,SEAT,NAME);
						pld.reverse(NUMBER);
						cout<<"订票成功！";
						cout<<"您的座位号为："<<SEAT<<endl;
					}
				}
				else
				{
					cout<<"该航班不存在，请重新选择！"<<endl;
				}
			    break;
		case 3: cout<<"输入证件号：";
				cin>>IDENTIFICAION;
				pa=pad.search(IDENTIFICAION);
				while(pa==NULL)
				{
					cout<<"该乘客还没有订票，无法退票"<<endl;
					cout<<"输入证件号：";
					cin>>IDENTIFICAION;
					pa=pad.search(IDENTIFICAION);
				}		
				cout<<"输入航班号：";
				cin>>NUMBER;
				pl=pld.search(NUMBER);
				//以下为判断
				if(pl!=NULL)
				{
					while((pa->getflight())!=NUMBER)//验证乘客是否在该航班上
					{
						cout<<"该乘客不在该航班上，无法退票"<<endl;
						cout<<"输入航班号：";
						cin>>NUMBER;
						pl=pld.search(NUMBER);
					}	
					pad.refund(IDENTIFICAION);
					pld.refund(NUMBER);
					pl->delseat(pa->getseat());
					cout<<"退票成功！"<<endl;
				}
				else
				{
					cout<<"该航班不存在，请重新选择！"<<endl;
				}
			    break;
		case 4:	choice2=1;
				while(choice2!=0)
				{
					cout<<"票务维护："<<endl;
					cout<<"-------------------------------------------------------------------------"<<endl;
					cout<<"1:新增航班   2:更改航班    3:取消航班   4:全部航班    5:清空数据   0:返回"<<endl;
					cin>>choice2;
					cout<<"-------------------------------------------------------------------------"<<endl;
					switch(choice2)
					{
					 case 1:cout<<"输入航班编号：";
							cin>>NUMBER;
							pl=pld.search(NUMBER);
							//判断提前，防止一错再错
							if(pl!=NULL)
							{
								cout<<"对应航班号航班已经存在，无法添加！"<<endl;
								break;
							}
							else
							{
								cout<<"输入航班到达港：";
								cin>>DESTINATION;
								cout<<"输入起飞时间：";
								cin>>TIME;
								cout<<"输入总票数：";
								cin>>TOTAL;
								while(TOTAL>200)
								{
									cout<<"票数超过单机最大限制200票！请重新输入总票数：";
									cin>>TOTAL;
								}
								pld.add(NUMBER,DESTINATION,TIME,TOTAL);
							}
							break;

					//更改的是航班的时间！【按照当前事实规律，修改地点时直接取消航班等等就好】
					 case 2:cout<<"输入航班编号：";
							cin>>NUMBER;
							pl=pld.search(NUMBER);
							//判断提前，防止一错再错
							if(pl==NULL)
							{
								cout<<"对应航班号航班不存在，无法更改！"<<endl;
								break;
							}
							else
							{
							cout<<"输入新的起飞时间：";
							cin>>TIME;
							pld.change(NUMBER,TIME);
							}
							break;

					 case 3:cout<<"输入航班编号：";
							cin>>NUMBER;
							pld.cancel(NUMBER);
							break;

					 case 4:cout<<setw(13)<<"航班号"<<setw(15)<<"到达港"<<setw(15)<<"起飞时间"<<setw(15)<<"总票数"<<setw(15)<<"剩余票数"<<endl;
							pld.list();
							break;

					 case 5:pld.clear();
							break;
					} //end switch
				}     
			   break;
		case 5:cout<<setw(15)<<"证件号"<<setw(15)<<"乘客姓名"<<setw(15)<<"航班号"<<setw(15)<<"座位号"<<endl;
			   pad.list();//待删除功能，测试而已
			   cout<<"-------------------------------------------------------------------------"<<endl;
			   break;
		}//end switch
	}//end while
	return 0;
}