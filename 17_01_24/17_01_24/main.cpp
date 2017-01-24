/*

- ���԰� ���
	 IS-A ����
	HAS-A ����

- ��� class�� ���ؼ��� �θ� class �ڷ����� �Ҵ��� �� ����.
	��� class������ ��ӹ��� �Լ��� ������ �� ������, ����ϴ� class�� �Լ��� ����ų �� ����

- �������̵� : �θ� class�� �Լ��� ��ӵ� class���� �������Ͽ� ��� �ο���!
				�θ� class�� �Լ����� virtual�� �ٿ���!


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
	cout<<"��ü 1 ����"<<endl;
	BBB bbb1;

	cout<<"��ü 2 ����"<<endl;
	BBB bbb2(100);
}
#endif




#if 0
class Person
{
public:
	void First()
	{
		cout<<"Person�� First�Լ�"<<endl;
	}
};

class Student : public Person
{
public:
	void Second()
	{
		cout<<"Student�� Second�Լ�"<<endl;
	}
};

class Baby : public Student
{
public:
	void Third()
	{
		cout<<"Baby�� Third�Լ�"<<endl;
	}
};

void main()
{
	Person* p1 = new Student;
	Student* p2 = new Student;
	//Baby* p3 = new Student;	//Baby�ڷ������δ� Student, Person�� �ڷ����� ����ų �� ����
	Baby* p3 = new Baby;

	p1->First();
	//p1->Second();	//Person�� �ڷ������δ� ��ӵ� Student�� �Լ��� ����ų �� ����

	p2->Second();
	p2->First();

	p3->First();	//Baby�� �ڷ������δ� �θ� Class �Լ��� ������ �� ����!
	p3->Second();
	p3->Third();

	delete p1;
	delete p2;
	delete p3;
}
#endif




//////////////////////�������̵� �Լ� ȣ��!
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
	cout<<"ù ��° �õ�!"<<endl;
	pa->show();

	cout<<"�� ��° �õ�!"<<endl;
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

	cout<<"\t\t��ü�� ���� ���"<<endl;
	c1.Report();		// Cd �޼��� ���
	c2.Report();		// Classic �޼��� ���

	cout<<"\t\t��ü�� �����ϴ� Cd* �����͸� ���"<<endl;
	pcd->Report();		// Cd ��ü�� Cd �޼��� ���
	pcd = &c2;
	pcd->Report();		// Classic ��ü�� Classic �޼��� ���

	cout<<"\t\tCd ���� �Ű������� ����Ͽ� �Լ��� ȣ��"<<endl;
	Bravo(c1);
	Bravo(c2);

	cout<<"\t\t������ �׽�Ʈ�Ѵ�"<<endl;
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















