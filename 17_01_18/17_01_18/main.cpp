/*

class Bank
{
	int tmp;
public:
	Bank();	//Ŭ������� ������ ������ �Լ�(��ü�� ������ �� �ʱ�ȭ �ϱ� ����!)
};

Bank Ba;	//Ba�� BankŬ������ ��ü��!


- ������ : ���������� �����Ϸ��� ���� �ڵ����� ȣ���!(default�Լ�)
	* ������ �Լ��� �ڵ����� ȣ��Ǿ� ������ ��ɾ �ѹ��� ���� �������� �ʾ�����,
	�׷��� ������ �Լ��� �߰�ȣ�� ���� ����Ʈ �������Լ��� �ڵ����� �߰��Ͽ�
	����Ʈ ������ �Լ��� �����Ѵ�.(private���� ����� ������ �ʱ�ȭ�ϴ� �뵵�ξ�)
	public�Լ� �������� ȣ���� ����ȣ��������, �����ڴ� ��ü�� ������ �� �ڵ����� ȣ���!


	- ��ü�� ����ü�� �޸�, 1. �޸��Ҵ� / 2. �������Լ��� ȣ��

	1. Ŭ������ �̸��� ���� �̸��� ���Ѵ�.
	2. ����Ÿ���� X
	3. �Ű������� ������.(��, ����Ʈ �Ű�����, �����ε��� ����)
	4. public�̿��߸���(�ڵ����� ȣ��Ǿ� ����)
	5. ���ǰ� �ȵǾ����� ��� ����Ʈ ������ �Լ�(�ù�)
		##����Ʈ �Ű����� ���� = �Լ��� ����(main��)���� �����!! 






*/


#include <iostream>
using namespace std;


#if 0
			//������ ���� - �����Ҵ�/�����Ҵ�
class TEMP
{
	int* ptr;
public:
	TEMP()
	{
		cout<<"������ �Լ� ȣ��"<<endl;
	}
	void show()
	{
		ptr = new int;
		*ptr = 8;
		cout<<"\tshow �Լ��Դϴ�. *ptr = "<<*ptr<<endl;
		delete ptr;
	}
};

void main()
{
	TEMP test;
	test.show();
}
#endif



#if 0
class Person
{
	char* name;
	char* phone;
	int age;
public:
	Person(int Tage = 10, char *Tname = "What is?", char *Tphone = "Give Phone");
	void ShowData();
};

void main()
{
	Person Test1;
	Test1.ShowData();
	Person Test2(26);
	Test2.ShowData();
	Person Test3(26, "Mr.Ban");
	Test3.ShowData();
}

Person::Person(int Tage, char *Tname, char *Tphone)
{
	int num;

	//���ڿ� ���� ī��Ʈ �� ���� ��ŭ �޸� �Ҵ�, ������ ����
	for(num = 0; Tname[num]!='\0'; ++num);
	name = new char[num+1];
	for(num = 0; Tname[num]!='\0'; ++num)
		name[num] = Tname[num];
	name[num] = '\0';
	
	//���ڿ� ���� ī��Ʈ �� ���� ��ŭ �޸� �Ҵ�, ������ ����
	for(num = 0; Tphone[num]!='\0'; ++num);
	phone = new char[num+1];
	for(num = 0; Tphone[num]!='\0'; ++num)
		phone[num] = Tphone[num];
	phone[num] = '\0';
	age = Tage;
}

void Person::ShowData()
{
	cout<<"  age = "<<age<<endl;
	cout<<" name = "<<name<<endl;
	cout<<"phone = "<<phone<<endl;
	cout<<endl;
	delete []Person.name;
	delete []Person.phone;
}
#endif



#if 0
#define LIMIT 25
class Person
{
private:
	char* lname;
	char* fname;
public:
	Person()
	{
		cout<<"!!�̸��� ���Ŷ�"<<endl;
		lname = new char;
		fname = new char;
		*lname = '\0';
		*fname = '\0';
	}
	Person(const char* Tlname, const char* Tfname = "First Name");
	void Show();
	void FormalShow();
	void reset();
};

void main()
{
	Person temp1;
	Person temp2("Ban");
	Person temp3("Ban","JO");
	temp1.Show();
	temp1.FormalShow();
	temp2.Show();
	temp2.FormalShow();
	temp3.Show();
	temp3.FormalShow();
	temp1.reset();
	temp2.reset();
	temp3.reset();
}

Person::Person(const char* Tlname, const char* Tfname)
{
	int num;

	//���ڿ� ���� ī��Ʈ �� ���� ��ŭ �޸� �Ҵ�, ������ ����
	for(num = 0; Tlname[num]!='\0'; ++num);
	lname = new char[num+1];
	for(num = 0; Tlname[num]!='\0'; ++num)
		lname[num] = Tlname[num];
	lname[num] = '\0';
	
	//���ڿ� ���� ī��Ʈ �� ���� ��ŭ �޸� �Ҵ�, ������ ����
	for(num = 0; Tfname[num]!='\0'; ++num);
	fname = new char[num+1];
	for(num = 0; Tfname[num]!='\0'; ++num)
		fname[num] = Tfname[num];
	fname[num] = '\0';
}
void Person::Show()
{
	cout<<"Show �Լ��� �̸� ���� �����Դϴ�."<<endl;
	cout<<"\t\t"<<lname<<" "<<fname<<endl;
}
void Person::FormalShow()
{
	cout<<"FormalShow �Լ��� ����, �̸� �����Դϴ�."<<endl;
	cout<<"\t\t"<<fname<<", "<<lname<<endl;
}
void Person::reset()
{
	delete []lname;
	delete []fname;
}
#endif



#if 0
class Move
{
private:
	double x;
	double y;
	double xy;
	char flag;
public:
	Move(double num1 = 0, double num2 = 0);
	void sum();
	void show();
	void add(double num1 = 0, double num2 = 0);
	void reset(double num1 = 0, double num2 = 0);
};

void main()
{
	Move temp1(3.14,6.14);
	Move temp2;
	temp1.add(100.3,1000.3);
	temp1.sum();
	temp1.show();
	temp1.reset();
	temp2.add(10.3,100.3);
	temp2.sum();
	temp2.show();
	temp2.reset();
}


Move::Move(double num1, double num2)
{
	x = num1;
	y = num2;
	cout<<"Move Ŭ���� ���� ����!"<<endl;
	flag = 1;
}
void Move::sum()
{
	xy = x + y;
}
void Move::show()
{
	if(flag)
	{
		cout<<"\tMove Show �Լ�"<<endl;
		cout<<"  x = "<<x<<endl;
		cout<<"  y = "<<y<<endl;
		cout<<"x+y = "<<xy<<endl;
	}
}
void Move::add(double num1, double num2)
{
	x += num1;
	y += num2;
}
void Move::reset(double num1, double num2)
{
	cout<<"\tMove reset �Լ��Դϴ�."<<endl;
	cout<<"���� x = "<<x<<"�� ";
	x = num1;
	cout<<x<<"���� �ʱ�ȭ �Ǿ����ϴ�."<<endl;

	cout<<"���� y = "<<y<<"�� ";
	y = num2;
	cout<<y<<"���� �ʱ�ȭ �Ǿ����ϴ�."<<endl<<endl;
}
#endif


#if 0
#include <cctype>
#include "stack.h"

void main()
{
	Stack st;
	char ch;
	unsigned long po;

	cout<<"�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
		<<"�����Ϸ��� Q�� �Է��Ͻÿ�.\n";

	while(cin>>ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a':
					cout<<"�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�. ";
					cin>>po;
					if(st.isfull())
						cout<<"������ ���� �� �ֽ��ϴ�.\n";
					else
						st.push(po);
					break;
		case 'P':
		case 'p':
			if(st.isempty())
				cout<<"������ ��� �ֽ��ϴ�.\n";
			else
			{
				st.pop(po);
				cout<<"#"<<po<<"�ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}
		cout<<"�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
		<<"�����Ϸ��� Q�� �Է��Ͻÿ�.\n";
	}
	cout<<"���α׷��� �����մϴ�.\n";
}
#endif


#include "sales.h"

void main()
{
	int input;
	double arr[4] = {0.08, 7.77, 10.11, 999.11};
	
	cout<<"�� ���� �Է¹ް� ������? ";
	cin>>input;

	Sales temp(arr, input);
	temp.showSales();
	if(input>4) 
		input = 4;

	for(int count = 0; count<input; ++count)
	{
		cout<<count+1<<"�� ° �Է� : ";
		cin>>arr[count];
	}
	temp.showSales();
}