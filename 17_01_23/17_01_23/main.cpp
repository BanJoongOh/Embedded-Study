/*

- OOP의 가장 큰 특징
	다형
		  함수 오버로딩 : 같은 함수명이더라도 매개변수 갯수, 자료형에 따라 적절한 호출
		연산자 오버로딩 : 같은 기호더라도 상황에따라 다른 기능으로 쓰임, 객체의 연산을 더 편하게 하는 부가적 기능부여

	Point p,temp;
- p = tmp;		//사용, 디폴트 대입연산 : 멤버대 멤버간의 자동적으로 얕은복사가 됨(구조체와 동일)
	p.operator=(tmp);
		operator=(const Point& s)
		{
			x = s.x;	// == this->x = s.x;
			y = s.y;	// == this->y = s.y;
		}
- Point p(temp)	//선언, 디폴트 복사생성자에 의해 복사됨	
		Point::Point(const Point& s)
		{
			x = s.x;
			y = s.y;
		}
	  문제는 주소를 가리키는 char* ps가 있을경우 생성자에서 heap메모리 할당을 하여 delete할때임!
	객체 생성시에 얕은복사를 할 경우, delete가 중복되어 버그발생

- 상속 : 중복되는 부분을 상속으로 처리하여 중복되는 부분을 최소화시킴
		생성순서 : 부모-자식-손주
		소멸순서 : 손주-자식-부모






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
	: Person(_name, _age)	// 전달인자 : 자료형이 오면 안됨!
	{
		strcpy(major, _major);
	}
	const char* GetMajor() const
	{
		return major;
	}
	void ShowData() const
	{
		cout<<"이름 : "<<GetName()<<endl;
		cout<<"나이 : "<<GetAge()<<endl;
		cout<<"전공 : "<<GetMajor()<<endl;
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
		cout<<" : 탁구대가 있다 \n";
	else
		cout<<" : 탁구대가 없다 \n";

	RP1.Name();
	if(RP1.Table())
		cout<<" : 탁구대가 있다 \n";
	else
		cout<<" : 탁구대가 없다 \n";

	cout<<"이름 : ";
	RP1.Name();
	cout<<"; 랭킹 : "<<RP1.Rating()<<endl;

	///////////////////TableTennis 객체를 이용한 RatedPlayer의 초기화
	RatedPlayer RP2(1212, P1);
	cout<<"이름 : ";
	RP2.Name();
	cout<<"; 랭킹 : "<<RP2.Rating()<<endl;
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

	int GetID() const;				//계좌번호 출력
	int ShowMoney() const;			//잔액 출력
	void AddMoney(int val);			//입금
	void SubMoney(int val);			//출금
	const char* GetName() const;
	void ShowAllData() const;
};

//포인터배열 문법활용하여 3명분의 계좌정보를 등록할 객체를 생성
//객체 생성과 동시에 초기화 또는 입력받아서 저장
//ShowAllData()함수를 이용해서 각각의 계좌정보를 출력


////////////////////객체를 다룰땐 malloc과 new가 다름!
////////////////////instance를 생성하는 것이기 때문에 생성자 매개변수 다 채워줄것!
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











