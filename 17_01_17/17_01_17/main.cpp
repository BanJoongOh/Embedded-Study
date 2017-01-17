/*
- �����ϴ� : ���������� �˻� �� �޸� �Ҵ�
- ���۷��� : �޸𸮰� ������!(������ ������ ����)
			 * �����Ϳ� �޸� ����� ���ÿ� �ʱ�ȭ�������
			   ex) int &rval = val;	// rval==val
					���۷���(�Ű�����), ������(��������) ---->>>> call by reference
	���������ʱ�ȭ�ÿ��� ������ ������ ���� �ʱ�ȭ �ȴٰ� �����ϸ� ��!
	��ġ, int* const pt = &num;		//�̰Ͱ� ����� ������!
					 pt = &temp;	//������ ����!
	*���� : �޸𸮸� ��Ƹ��� �ʰ�, ���������� ����!
	*���� : �Լ�ȣ�⸸ ������, call by value�� ������ �� ����!

OOP�� �ֿ� ���
- �߻�ȭ
- ĸ��ȭ, ������ ����
- ����
- ���
- �ڵ��� ��Ȱ��

- Class = ��� ���� + ��� �Լ� //������ �ƴ϶� ��ü!
	����ü : �޸��Ҵ縸�ϸ� ��� ����
	Ŭ���� : �޸��Ҵ� �� �����ڰ� �� ȣ��Ǿ���(�ν��Ͻ�ȭ)
				 public : �ܺο����� ���ٰ���
				private : ���ο����� ���ٰ���(�⺻����)
			* Ŭ������ �ʱ�ȭ�� �����ڸ� �̿��� ��!

	�����ͺ�ȣ - private(��þ��ϸ��), public(�Լ��� ���ٰ����ϰ�)

	- ���Ǻ� ������
#ifndef TEMP	//if not define
#define TEMP
	����
#endif






*/


#include <iostream>
using namespace std;

////////////////////reference ���� ����
#if 0
void main()
{
	int rats = 100;
	int& rodents = rats;
	int newval = 50;

	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	rats++;
	cout<<"\trats++���"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	rodents++;
	cout<<"\trodents++���"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	cout<<"\t�� �ּ� ��"<<endl;
	cout<<"   rats = "<<&rats<<endl;
	cout<<"rodents = "<<&rodents<<endl;
	cout<<" newval = "<<&newval<<endl;

	rodents = newval;
	cout<<"\tradents = newval"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	cout<<"\t�� �ּ� ��"<<endl;
	cout<<"   rats = "<<&rats<<endl;
	cout<<"rodents = "<<&rodents<<endl;
	cout<<" newval = "<<&newval<<endl;
}
#endif


#if 0
//////////////////////////////////////////call by value,address,reference ��
void SwapReference(int& ref1, int& ref2);
void SwapAddress(int* ptr1, int* ptr2);
void SwapValue(int temp1, int temp2);
void main()
{
	int wallet1 = 2000;
	int wallet2 = 5000;

	cout<<"����1 : "<<wallet1<<endl;
	cout<<"����2 : "<<wallet2<<endl;

	cout<<"\t������ ���� ���� ��ȭ!"<<endl;
	SwapReference(wallet1, wallet2);
	cout<<"����1 : "<<wallet1<<endl;
	cout<<"����2 : "<<wallet2<<endl;

	cout<<"\t�ּҸ� ���� ���� ��ȭ!"<<endl;
	SwapAddress(&wallet1, &wallet2);
	cout<<"����1 : "<<wallet1<<endl;
	cout<<"����2 : "<<wallet2<<endl;

	cout<<"\t�� ������ ���� ���� ��ȭ!"<<endl;
	SwapValue(wallet1, wallet2);
	cout<<"����1 : "<<wallet1<<endl;
	cout<<"����2 : "<<wallet2<<endl;
}

void SwapReference(int& ref1, int& ref2)
{
	ref1+=777;
	ref2+=777;
}
void SwapAddress(int* ptr1, int* ptr2)
{
	*ptr1+=222;
	*ptr2+=222;
}
void SwapValue(int temp1, int temp2)
{
	temp1+=55;
	temp2+=55;
}
#endif



#if 0
typedef struct
{
	int age;
	char name[20];
}Person;

void ShowData(const Person& ref);
void main()
{
	int count;
	Person temp;
	char strtemp[20] = "My Brother";

	for(count = 0; strtemp[count]!='\0'; ++count)
		temp.name[count] = strtemp[count];
	temp.name[count] = strtemp[count];
	temp.age = 20;

	ShowData(temp);
	cout<<"temp.age  = "<<temp.age<<endl;
	cout<<"temp.name = "<<temp.name<<endl;
}

void ShowData(const Person& ref)
{
	cout<<"ref.age  = "<<ref.age<<endl;
	cout<<"ref.name = "<<ref.name<<endl;
}
#endif



#if 0
class Count{
	int val;
public:
	void increment()	//public interface
	{
		val=0;			//class ��������
		val++;			//class ��������
		cout<<val<<endl;//class ��������
	}
};

void main()
{
	Count cnt;
	//cnt.val = 0;		//class �ܺ�����
	cnt.increment();	//class �ܺ�����
	//cout<<cnt.val<<endl;//class �ܺ�����
}
#endif



#if 0
#include "door.h"

void main()
{
	Door temp;
	temp.Open();
	temp.ShowState();
	temp.Close();
	temp.ShowState();
}
#endif



#if 0
#include "stock.h"
void main()
{
	Stock Temp;
	Temp.acquire("NanoSmart", 20, 12.50);
	Temp.show();
	Temp.buy(15, 18.125);
	Temp.show();
	Temp.sell(400, 20.00);
	Temp.show();
	Temp.buy(300000, 40.125);
	Temp.show();
	Temp.sell(300000, 0.125);
	Temp.show();
}
#endif




#include "bank.h"
void main()
{
	Bank temp;
	temp.Acount("Mr.Ban","111-123456-999",1000);
	temp.Show();
	temp.Plus(500);
	temp.Show();
	temp.Minus(700);
	temp.Show();
}






















