/*
- 클래스에서의 멤버변수 : 'm_멤버변수명'의 형식으로 사용함!
객체의 동적할당 : new를 써야만함!, c의 malloc함수로는 생성자함수를 호출하지않아서 인스턴스화가 안됨

stock* pstock = new stock("EE",20);
 멤버 접근 : pstock->buy(포인터를 통한 외부접근, 접근불가 : private이기 때문)
	* 만약에 배열로 할당되었을경우 : [](각괄호)와 .을 이용하여 접근하면됨 - pstock[0].buy

- 소멸자
; 동적할당할때만 정의해주면됨!

- this 포인터
; 생성자 함수를 호출한 객체를 가리키는 포인터(같은 멤버함수의 가독성을 높이기 위해 사용)

- 복사생성자
; 사용자가 쓰지 않으면 자동으로 생성됨(디폴트 복사생성자)
동적메모리할당(heap)을 하게되면 디폴트 복사 생성자를 쓸 수 없다.(얕은 복사에 의해)
	class명(const 클래스명& p)
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

	cout<<"보유 주식 리스트"<<endl;					
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
		this->num2=num2;	//this가 객체를 가리키는 포인터라서 간접접근연산자를씀
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
	Person temp2=temp1;	// == Person temp2(temp1)  복사생성자이용
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
		cout << "내부 블록을 시작한다.\n";
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
	cout<<"\t\tmain()의 끝\n";
}

void call1(StringBad& rsb)
{
	cout<<"참조로 전달된 StringBad : \n"<<" \"";
	rsb.display();
}

void call2(StringBad& sb)
{
	cout<<"참조로 전달된 StringBad : \n"<<" \"";
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

	cout<<"고객를 추가하려면 A, 고객을 삭제하려면 P, \n"
		<<"종료하려면 Q를 입력하시오.\n";

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
					cout<<"추가할 고객의 이름를 입력하십시오. ";
					cin>>po.fullname;
					if(st.isfull())
						cout<<"스택이 가득 차 있습니다.\n";
					else
						st.push(po);
					break;
		case 'P':
		case 'p':
			if(st.isempty())
				cout<<"스택이 비어 있습니다.\n";
			else
			{
				st.pop(po);
				cout<<"#"<<po<<"주문서를 처리했습니다.\n";
			}
			break;
		}
		cout<<"주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
		<<"종료하려면 Q를 입력하시오.\n";
	}
	cout<<"프로그램을 종료합니다.\n";
}
#endif



