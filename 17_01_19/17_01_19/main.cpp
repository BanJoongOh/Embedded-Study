/*
- Ŭ���������� ������� : 'm_���������'�� �������� �����!
��ü�� �����Ҵ� : new�� ��߸���!, c�� malloc�Լ��δ� �������Լ��� ȣ�������ʾƼ� �ν��Ͻ�ȭ�� �ȵ�

stock* pstock = new stock("EE",20);
 ��� ���� : pstock->buy(�����͸� ���� �ܺ�����, ���ٺҰ� : private�̱� ����)
	* ���࿡ �迭�� �Ҵ�Ǿ������ : [](����ȣ)�� .�� �̿��Ͽ� �����ϸ�� - pstock[0].buy

- �Ҹ���
; �����Ҵ��Ҷ��� �������ָ��!

- this ������
; ������ �Լ��� ȣ���� ��ü�� ����Ű�� ������(���� ����Լ��� �������� ���̱� ���� ���)

- ���������
; ����ڰ� ���� ������ �ڵ����� ������(����Ʈ ���������)
�����޸��Ҵ�(heap)�� �ϰԵǸ� ����Ʈ ���� �����ڸ� �� �� ����.(���� ���翡 ����)
	class��(const Ŭ������& p)
	{
	}












*/

#include <iostream>
using namespace std;


#if 0
#define STKS 4
#include "stock.h"
void main()
{
	Stock stocks[STKS] = {	Stock("NanoSmart",11, 20.1),
							Stock("PicoSmart",15, 20.3),
							Stock("MicroSmart",17, 20.5),
							Stock("MiliSmart",19, 20.7)};

	cout<<"���� �ֽ� ����Ʈ"<<endl;					
	for(int count = 0; count<4; ++count)
		stocks[count].show();
}
#endif


#if 0
class Data
{
	int num1;
	int num2;
public:
	Data(int num1, int num2)
	{
		//num1=num1;
		(*this).num1=num1;
	
		//num2=num2;
		this->num2=num2;	//this�� ��ü�� ����Ű�� �����Ͷ� �������ٿ����ڸ���
	}
	void printAll()
	{
		cout<<num1<<" "<<num2<<endl;
	}
};

void main()
{
	Data temp(100,200);
	temp.printAll();
}
#endif



#if 0
class point
{
	int x,y;
public:
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void ShowData()
	{
		cout<<x<<' '<<y<<endl;
	}
};

void main()
{
	point p1(10,20);
	point p2(p1);
	p1.ShowData();
	p2.ShowData();
}
#endif



#if 0
class Person
{
private:
	char *m_name;
	char *m_phone;
	int m_age;
public:
	Person(char* name, char* phone, int age);
	Person(const Person& p);
	~Person();
	void ShowData();
};

Person::Person(const Person& p)
{
	m_name = new char[strlen(p.m_name)+1];
	strcpy(m_name,p.m_name);

	m_phone = new char[strlen(p.m_phone)+1];
	strcpy(m_phone,p.m_phone);
	m_age = p.m_age;
}

Person::Person(char *name, char *phone, int age)
{
	m_name = new char[strlen(name)+1];
	strcpy(m_name,name);

	m_phone = new char[strlen(phone)+1];
	strcpy(m_phone,phone);
	m_age = age;
}

Person::~Person()
{
	delete []m_name;
	delete []m_phone;
}

void Person::ShowData()
{
	cout<<"  name : "<<m_name<<endl;
	cout<<" phone : "<<m_phone<<endl;
	cout<<"   age : "<<m_age<<endl;
}

void main()
{
	Person temp1("BAN","010-1234-1234",26);
	Person temp2=temp1;	// == Person temp2(temp1)  ����������̿�
	temp1.ShowData();
	temp2.ShowData();
}
#endif



#if 0
#include "stringbad.h"

void call1(StringBad&);
void call2(StringBad&);

void main()
{
	{
		cout << "���� ����� �����Ѵ�.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout<<"headline1 : ";
		headline1.display();
		cout<<"headline2 : ";
		headline2.display();
		cout<<"   sports : ";
		sports.display();

		call1(headline1);
		cout<<"call1 + headline1 : "<<endl;
		headline1.display();
		cout<<endl;

		call2(headline2);
		cout<<"call2 + headline2 : "<<endl;
		headline2.display();
		cout<<endl;
	}
	cout<<"\t\tmain()�� ��\n";
}

void call1(StringBad& rsb)
{
	cout<<"������ ���޵� StringBad : \n"<<" \"";
	rsb.display();
}

void call2(StringBad& sb)
{
	cout<<"������ ���޵� StringBad : \n"<<" \"";
	sb.display();
}
#endif




#if 0
#include "cow.h"
void main()
{
	Cow temp1("Mr.Ban","C++",26);
	Cow temp2(temp1);
	temp1.ShowCow();
	temp2.ShowCow();
}
#endif



#if 1
#include <cctype>
#include "newstack.h"

void main()
{
	Stack st;
	char ch;
	CUSTOMER po;

	cout<<"���� �߰��Ϸ��� A, ���� �����Ϸ��� P, \n"
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
					cout<<"�߰��� ���� �̸��� �Է��Ͻʽÿ�. ";
					cin>>po.fullname;
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



