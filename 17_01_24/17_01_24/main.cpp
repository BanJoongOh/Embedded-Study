/*

- 포함과 상속
	 IS-A 관계
	HAS-A 관계

- 상속 class를 통해서는 부모 class 자료형을 할당할 수 없음.
	상속 class에서는 상속받은 함수를 접근할 수 있지만, 상속하는 class의 함수를 가리킬 순 없음

- 오버라이딩 : 부모 class의 함수를 상속된 class에서 재정의하여 기능 부여함!
				부모 class의 함수에는 virtual을 붙여줌!


*/



#include <iostream>

using namespace std;


#if 0
class AAA
{
public:
	AAA()
	{
		cout<<" AAA() call!"<<endl;
	}
	AAA(int i)
	{
		cout<<" AAA(int i) call!"<<endl;
	}
	~AAA()
	{
		cout<<" ~AAA() call!"<<endl;
	}
};

class BBB : public AAA
{
public:
	BBB()
	{
		cout<<" BBB() call!"<<endl;
	}
	BBB(int i)
	:AAA(i)
	{
		cout<<" BBB(int i) call!"<<endl;
	}
	~BBB()
	{
		cout<<" ~BBB() call!"<<endl;
	}
};

void main()
{
	cout<<"객체 1 생성"<<endl;
	BBB bbb1;

	cout<<"객체 2 생성"<<endl;
	BBB bbb2(100);
}
#endif




#if 0
class Person
{
public:
	void First()
	{
		cout<<"Person의 First함수"<<endl;
	}
};

class Student : public Person
{
public:
	void Second()
	{
		cout<<"Student의 Second함수"<<endl;
	}
};

class Baby : public Student
{
public:
	void Third()
	{
		cout<<"Baby의 Third함수"<<endl;
	}
};

void main()
{
	Person* p1 = new Student;
	Student* p2 = new Student;
	//Baby* p3 = new Student;	//Baby자료형으로는 Student, Person의 자료형을 가리킬 순 없음
	Baby* p3 = new Baby;

	p1->First();
	//p1->Second();	//Person의 자료형으로는 상속된 Student의 함수를 가리킬 순 없음

	p2->Second();
	p2->First();

	p3->First();	//Baby의 자료형으로는 부모 Class 함수를 접근할 수 있음!
	p3->Second();
	p3->Third();

	delete p1;
	delete p2;
	delete p3;
}
#endif




//////////////////////오버라이딩 함수 호출!
#if 0
class First
{
public:
	virtual void show()
	{
		cout<<"First Show!"<<endl;
	}
};

class Second : public First
{
public:
	void show()
	{
		cout<<"Second Show!!"<<endl;
	}
};

void main()
{
	First* pa = new Second;
	cout<<"첫 번째 시도!"<<endl;
	pa->show();

	cout<<"두 번째 시도!"<<endl;
	pa->First::show();
}
#endif


#if 0
#include "classic.h"

void Bravo(const Cd& disk);

void main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano Sonata", "Alfred","LEON", 2, 57.17);
	Cd* pcd = &c1;

	cout<<"\t\t객체를 직접 사용"<<endl;
	c1.Report();		// Cd 메서드 사용
	c2.Report();		// Classic 메서드 사용

	cout<<"\t\t객체를 지시하는 Cd* 포인터를 사용"<<endl;
	pcd->Report();		// Cd 객체에 Cd 메서드 사용
	pcd = &c2;
	pcd->Report();		// Classic 객체에 Classic 메서드 사용

	cout<<"\t\tCd 참조 매개변수를 사용하여 함수를 호출"<<endl;
	Bravo(c1);
	Bravo(c2);

	cout<<"\t\t대입을 테스트한다"<<endl;
	Classic copy;
	copy = c2;
	copy.Report();
	
}

void Bravo(const Cd& disk)
{
	disk.Report();
}

#endif



#include "company.h"

void main()
{
	Department manage;
	manage.AddEmployee(new Permanent("Hong",1000));
	manage.AddEmployee(new Permanent("Kim",2000));
	manage.AddEmployee(new Temp("Park",30,6000));
	manage.AddEmployee(new Temp("Ban",40,10000));

	manage.ShowPayList();
}















