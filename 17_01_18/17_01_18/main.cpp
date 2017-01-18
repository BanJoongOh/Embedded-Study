/*

class Bank
{
	int tmp;
public:
	Bank();	//클래스명과 동일한 생성자 함수(객체가 생성될 때 초기화 하기 위함!)
};

Bank Ba;	//Ba는 Bank클래스의 객체임!


- 생성자 : 내부적으로 컴파일러에 의해 자동으로 호출됨!(default함수)
	* 생성자 함수가 자동으로 호출되어 수행할 명령어를 한번도 새로 정의하지 않았으면,
	그러면 생성자 함수의 중괄호만 갖는 디폴트 생성자함수를 자동으로 추가하여
	디폴트 생성자 함수를 수행한다.(private으로 선언된 변수를 초기화하는 용도로씀)
	public함수 내에서의 호출은 강제호출이지만, 생성자는 객체가 생성될 때 자동으로 호출됨!


	- 객체는 구조체와 달리, 1. 메모리할당 / 2. 생성자함수의 호출

	1. 클래스의 이름과 같은 이름을 지닌다.
	2. 리턴타입이 X
	3. 매개변수를 가진다.(즉, 디폴트 매개변수, 오버로딩도 가능)
	4. public이여야만함(자동으로 호출되어 수행)
	5. 정의가 안되어있을 경우 디폴트 생성자 함수(냉무)
		##디폴트 매개변수 정의 = 함수의 원형(main위)에서 사용함!! 






*/


#include <iostream>
using namespace std;


#if 0
			//데이터 저장 - 동적할당/정적할당
class TEMP
{
	int* ptr;
public:
	TEMP()
	{
		cout<<"생성자 함수 호출"<<endl;
	}
	void show()
	{
		ptr = new int;
		*ptr = 8;
		cout<<"\tshow 함수입니다. *ptr = "<<*ptr<<endl;
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

	//문자열 길이 카운트 후 길이 만큼 메모리 할당, 데이터 복사
	for(num = 0; Tname[num]!='\0'; ++num);
	name = new char[num+1];
	for(num = 0; Tname[num]!='\0'; ++num)
		name[num] = Tname[num];
	name[num] = '\0';
	
	//문자열 길이 카운트 후 길이 만큼 메모리 할당, 데이터 복사
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
		cout<<"!!이름을 쓰거라"<<endl;
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

	//문자열 길이 카운트 후 길이 만큼 메모리 할당, 데이터 복사
	for(num = 0; Tlname[num]!='\0'; ++num);
	lname = new char[num+1];
	for(num = 0; Tlname[num]!='\0'; ++num)
		lname[num] = Tlname[num];
	lname[num] = '\0';
	
	//문자열 길이 카운트 후 길이 만큼 메모리 할당, 데이터 복사
	for(num = 0; Tfname[num]!='\0'; ++num);
	fname = new char[num+1];
	for(num = 0; Tfname[num]!='\0'; ++num)
		fname[num] = Tfname[num];
	fname[num] = '\0';
}
void Person::Show()
{
	cout<<"Show 함수는 이름 성씨 형태입니다."<<endl;
	cout<<"\t\t"<<lname<<" "<<fname<<endl;
}
void Person::FormalShow()
{
	cout<<"FormalShow 함수는 성씨, 이름 형태입니다."<<endl;
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
	cout<<"Move 클래스 정상 시작!"<<endl;
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
		cout<<"\tMove Show 함수"<<endl;
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
	cout<<"\tMove reset 함수입니다."<<endl;
	cout<<"기존 x = "<<x<<"는 ";
	x = num1;
	cout<<x<<"으로 초기화 되었습니다."<<endl;

	cout<<"기존 y = "<<y<<"는 ";
	y = num2;
	cout<<y<<"으로 초기화 되었습니다."<<endl<<endl;
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

	cout<<"주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
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
					cout<<"추가할 주문서의 번호를 입력하십시오. ";
					cin>>po;
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


#include "sales.h"

void main()
{
	int input;
	double arr[4] = {0.08, 7.77, 10.11, 999.11};
	
	cout<<"몇 개를 입력받고 싶은가? ";
	cin>>input;

	Sales temp(arr, input);
	temp.showSales();
	if(input>4) 
		input = 4;

	for(int count = 0; count<input; ++count)
	{
		cout<<count+1<<"번 째 입력 : ";
		cin>>arr[count];
	}
	temp.showSales();
}