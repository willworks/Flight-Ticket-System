//ע����ʵ���ݺ������±������
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
	int choice1=3;//��ѯ������ѡ��
	int choice2=1;

	//�ඨ�����
	Plane *pl;
	Passenger *pa;
	Planedatabase pld;
	Passengerdatabase pad;

	//�������

	int NUMBER;//�����
	char DESTINATION[50];//�����
	char TIME[10];//���ʱ��
	int TOTAL;//��Ʊ��

	//�˿Ͳ���
	long int IDENTIFICAION;//���֤
	char NAME[20];//����
	int SEAT;

	while(choice!=0)
	{
		cout<<"=========================����Ʊ�����ϵͳ================================"<<endl;
		cout<<"========================================================================="<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"1:��ѯ     2:��Ʊ     3:��Ʊ     4:�������     5:���г˿�     0.�˳�ϵͳ"<<endl;
		cin>>choice;
		cout<<"-------------------------------------------------------------------------"<<endl;
		switch(choice)
		{
		case 1: choice1=3;//��ֵ���Ա��ں�����ѭ��
				while(choice1!=0)
				{
					cout<<"1.��ѯ����2.��ѯ�˿�0.����"<<endl;
					cin>>choice1;
					switch(choice1)
					{
						case 1: cout<<"����Ŀ�ĵأ�";
								cin>>DESTINATION;
								cout<<setw(15)<<"�����"<<setw(15)<<"�����"<<setw(15)<<"���ʱ��"<<setw(15)<<"��Ʊ��"<<setw(15)<<"ʣ��Ʊ��"<<endl;
								pld.list1(DESTINATION);
								break;
						case 2: cout<<"���뺽��ţ�";
								cin>>NUMBER;
								pl=pld.search(NUMBER);
								while(pl==NULL)//�ж���ǰ����ֹһ���ٴ�
								{
								  cout<<"��Ӧ����ź��಻���ڣ�"<<endl;
								  cout<<"���뺽��ţ�";
								  cin>>NUMBER;
								  pl=pld.search(NUMBER);
								}
								cout<<setw(10)<<"֤����"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(10)<<"��λ��"<<endl;
								pad.list2(NUMBER);
								break;
						case 0: break;
					}
				}
				break;
		case 2: cout<<"����֤���ţ�";
				cin>>IDENTIFICAION;
				pa=pad.search(IDENTIFICAION);
				while(pa!=NULL)
				{
					cout<<"��Ӧ֤���ų˿��Ѿ���Ʊ���޷��ٶ�Ʊ"<<endl;
					cout<<"����֤���ţ�";
					cin>>IDENTIFICAION;
					pa=pad.search(IDENTIFICAION);
				}		
				cout<<"����ţ�";
				cin>>NUMBER;
				pl=pld.search(NUMBER);
				//����Ϊ�ж�
				if(pl!=NULL)
				{
					if(pl->getrest()==0)
					{
						cout<<"�ú����Ʊ��ȫ�����꣬������ѡ��"<<endl;
					}
					else
					{
						cout<<"������";
						cin>>NAME;
						SEAT=pl->getseat();//!!!���ݹ����ʱ������
						pad.reverse(IDENTIFICAION,NUMBER,SEAT,NAME);
						pld.reverse(NUMBER);
						cout<<"��Ʊ�ɹ���";
						cout<<"������λ��Ϊ��"<<SEAT<<endl;
					}
				}
				else
				{
					cout<<"�ú��಻���ڣ�������ѡ��"<<endl;
				}
			    break;
		case 3: cout<<"����֤���ţ�";
				cin>>IDENTIFICAION;
				pa=pad.search(IDENTIFICAION);
				while(pa==NULL)
				{
					cout<<"�ó˿ͻ�û�ж�Ʊ���޷���Ʊ"<<endl;
					cout<<"����֤���ţ�";
					cin>>IDENTIFICAION;
					pa=pad.search(IDENTIFICAION);
				}		
				cout<<"���뺽��ţ�";
				cin>>NUMBER;
				pl=pld.search(NUMBER);
				//����Ϊ�ж�
				if(pl!=NULL)
				{
					while((pa->getflight())!=NUMBER)//��֤�˿��Ƿ��ڸú�����
					{
						cout<<"�ó˿Ͳ��ڸú����ϣ��޷���Ʊ"<<endl;
						cout<<"���뺽��ţ�";
						cin>>NUMBER;
						pl=pld.search(NUMBER);
					}	
					pad.refund(IDENTIFICAION);
					pld.refund(NUMBER);
					pl->delseat(pa->getseat());
					cout<<"��Ʊ�ɹ���"<<endl;
				}
				else
				{
					cout<<"�ú��಻���ڣ�������ѡ��"<<endl;
				}
			    break;
		case 4:	choice2=1;
				while(choice2!=0)
				{
					cout<<"Ʊ��ά����"<<endl;
					cout<<"-------------------------------------------------------------------------"<<endl;
					cout<<"1:��������   2:���ĺ���    3:ȡ������   4:ȫ������    5:�������   0:����"<<endl;
					cin>>choice2;
					cout<<"-------------------------------------------------------------------------"<<endl;
					switch(choice2)
					{
					 case 1:cout<<"���뺽���ţ�";
							cin>>NUMBER;
							pl=pld.search(NUMBER);
							//�ж���ǰ����ֹһ���ٴ�
							if(pl!=NULL)
							{
								cout<<"��Ӧ����ź����Ѿ����ڣ��޷���ӣ�"<<endl;
								break;
							}
							else
							{
								cout<<"���뺽�ൽ��ۣ�";
								cin>>DESTINATION;
								cout<<"�������ʱ�䣺";
								cin>>TIME;
								cout<<"������Ʊ����";
								cin>>TOTAL;
								while(TOTAL>200)
								{
									cout<<"Ʊ�����������������200Ʊ��������������Ʊ����";
									cin>>TOTAL;
								}
								pld.add(NUMBER,DESTINATION,TIME,TOTAL);
							}
							break;

					//���ĵ��Ǻ����ʱ�䣡�����յ�ǰ��ʵ���ɣ��޸ĵص�ʱֱ��ȡ������ȵȾͺá�
					 case 2:cout<<"���뺽���ţ�";
							cin>>NUMBER;
							pl=pld.search(NUMBER);
							//�ж���ǰ����ֹһ���ٴ�
							if(pl==NULL)
							{
								cout<<"��Ӧ����ź��಻���ڣ��޷����ģ�"<<endl;
								break;
							}
							else
							{
							cout<<"�����µ����ʱ�䣺";
							cin>>TIME;
							pld.change(NUMBER,TIME);
							}
							break;

					 case 3:cout<<"���뺽���ţ�";
							cin>>NUMBER;
							pld.cancel(NUMBER);
							break;

					 case 4:cout<<setw(13)<<"�����"<<setw(15)<<"�����"<<setw(15)<<"���ʱ��"<<setw(15)<<"��Ʊ��"<<setw(15)<<"ʣ��Ʊ��"<<endl;
							pld.list();
							break;

					 case 5:pld.clear();
							break;
					} //end switch
				}     
			   break;
		case 5:cout<<setw(15)<<"֤����"<<setw(15)<<"�˿�����"<<setw(15)<<"�����"<<setw(15)<<"��λ��"<<endl;
			   pad.list();//��ɾ�����ܣ����Զ���
			   cout<<"-------------------------------------------------------------------------"<<endl;
			   break;
		}//end switch
	}//end while
	return 0;
}