/*

- OOP�� ���� ū Ư¡
	����
		  �Լ� �����ε� : ���� �Լ����̴��� �Ű����� ����, �ڷ����� ���� ������ ȣ��
		������ �����ε� : ���� ��ȣ���� ��Ȳ������ �ٸ� ������� ����, ��ü�� ������ �� ���ϰ� �ϴ� �ΰ��� ��ɺο�

	Point p,temp;
- p = tmp;		//���, ����Ʈ ���Կ��� : ����� ������� �ڵ������� �������簡 ��(����ü�� ����)
	p.operator=(tmp);
		operator=(const Point& s)
		{
			x = s.x;	// == this->x = s.x;
			y = s.y;	// == this->y = s.y;
		}
- Point p(temp)	//����, ����Ʈ ��������ڿ� ���� �����	
		Point::Point(const Point& s)
		{
			x = s.x;
			y = s.y;
		}
	  ������ �ּҸ� ����Ű�� char* ps�� ������� �����ڿ��� heap�޸� �Ҵ��� �Ͽ� delete�Ҷ���!
	��ü �����ÿ� �������縦 �� ���, delete�� �ߺ��Ǿ� ���׹߻�

- ��� : �ߺ��Ǵ� �κ��� ������� ó���Ͽ� �ߺ��Ǵ� �κ��� �ּ�ȭ��Ŵ
		�������� : �θ�-�ڽ�-����
		�Ҹ���� : ����-�ڽ�-�θ�






*/


#include <iostream>
#include <string>
using namespace std;


#if 0
class Person
{
	int age;
	char name[20];
public:
	int GetAge() const
	{
		return age;
	}
	const char* GetName() const
	{
		return name;
	}
	Person(char* _name = "default name", int _age = 1)
	{
		age = _age;
		strcpy(name, _name);
	}
};

class Student: public Person
{
	char major[30];
public:
	Student(int _age = 1, char* _name = "default name", char* _major = "default major")
	: Person(_name, _age)	// �������� : �ڷ����� ���� �ȵ�!
	{
		strcpy(major, _major);
	}
	const char* GetMajor() const
	{
		return major;
	}
	void ShowData() const
	{
		cout<<"�̸� : "<<GetName()<<endl;
		cout<<"���� : "<<GetAge()<<endl;
		cout<<"���� : "<<GetMajor()<<endl;
	}
};

void main()
{
	Student Ban(26,"Mr.Ban","Electronic Engineering");
	Ban.ShowData();
}
#endif




#if 0
#include <iostream>
#include "tabten.h"
using namespace std;

void main()
{
	TableTennis P1("P1 First","P1 Second", true);
	RatedPlayer RP1(1140,"RP1 First","RP1 Second",true);
	P1.Name();
	if(P1.Table())
		cout<<" : Ź���밡 �ִ� \n";
	else
		cout<<" : Ź���밡 ���� \n";

	RP1.Name();
	if(RP1.Table())
		cout<<" : Ź���밡 �ִ� \n";
	else
		cout<<" : Ź���밡 ���� \n";

	cout<<"�̸� : ";
	RP1.Name();
	cout<<"; ��ŷ : "<<RP1.Rating()<<endl;

	///////////////////TableTennis ��ü�� �̿��� RatedPlayer�� �ʱ�ȭ
	RatedPlayer RP2(1212, P1);
	cout<<"�̸� : ";
	RP2.Name();
	cout<<"; ��ŷ : "<<RP2.Rating()<<endl;
}
#endif




class Account
{
	int id;
	int money;
	char* name;
public:
	Account(int id = 11, char* name = "default name", int money = 10);
	Account(const Account& tp);
	~Account();

	int GetID() const;				//���¹�ȣ ���
	int ShowMoney() const;			//�ܾ� ���
	void AddMoney(int val);			//�Ա�
	void SubMoney(int val);			//���
	const char* GetName() const;
	void ShowAllData() const;
};

//�����͹迭 ����Ȱ���Ͽ� 3����� ���������� ����� ��ü�� ����
//��ü ������ ���ÿ� �ʱ�ȭ �Ǵ� �Է¹޾Ƽ� ����
//ShowAllData()�Լ��� �̿��ؼ� ������ ���������� ���


////////////////////��ü�� �ٷ궩 malloc�� new�� �ٸ�!
////////////////////instance�� �����ϴ� ���̱� ������ ������ �Ű����� �� ä���ٰ�!
void main()
{
	Account *Parr[3] = {new Account(1000,"First Account",100000),
						new Account(),
						new Account(3000,"Third Account",300000)};

	for(int cnt = 0; cnt<3; ++cnt)
	{
		Parr[cnt]->ShowAllData();
		delete Parr[cnt];
	}
}

Account::Account(int id, char* name, int money)
{
	this->id = id;
	this->money = money;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

Account::Account(const Account &tp)
{
	id = tp.id;
	money = tp.money;
	name = new char[strlen(tp.name)+1];
	strcpy(name, tp.name);
}

Account::~Account()
{
	delete []name;
	//delete this;
}

void Account::AddMoney(int val)
{
	money+=val;
}

void Account::SubMoney(int val)
{
	money-=val;
}

int Account::GetID() const
{
	return id;
}

int Account::ShowMoney() const
{
	return money;
}

const char* Account::GetName() const
{
	return name;
}

void Account::ShowAllData() const
{
	cout<<"Account Name : "<<name<<endl;
	cout<<"Account id : "<<id<<endl;
	cout<<"Account money : "<<money<<endl<<endl;
}











