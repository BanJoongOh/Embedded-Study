/*
- 컴파일단 : 문법적오류 검사 및 메모리 할당
- 레퍼런스 : 메모리가 안잡힘!(변수의 별명같은 개념)
			 * 포인터와 달리 선언과 동시에 초기화해줘야함
			   ex) int &rval = val;	// rval==val
					레퍼런스(매개변수), 변수명(전달인자) ---->>>> call by reference
	참조변수초기화시에는 참조할 변수도 같이 초기화 된다고 생각하면 됨!
	마치, int* const pt = &num;		//이것과 비슷한 개념임!
					 pt = &temp;	//문법적 오류!
	*장점 : 메모리를 잡아먹지 않고, 문법적으로 쉬움!
	*단점 : 함수호출만 봤을때, call by value로 오해할 수 있음!

OOP의 주요 기능
- 추상화
- 캡슐화, 데이터 은닉
- 다형
- 상속
- 코드의 재활용

- Class = 멤버 변수 + 멤버 함수 //변수가 아니라 객체!
	구조체 : 메모리할당만하면 사용 가능
	클래스 : 메모리할당 후 생성자가 꼭 호출되야함(인스턴스화)
				 public : 외부에서도 접근가능
				private : 내부에서만 접근가능(기본값임)
			* 클래스의 초기화는 생성자를 이용할 것!

	데이터보호 - private(명시안하면됨), public(함수는 접근가능하게)

	- 조건부 컴파일
#ifndef TEMP	//if not define
#define TEMP
	내용
#endif






*/


#include <iostream>
using namespace std;

////////////////////reference 변수 기초
#if 0
void main()
{
	int rats = 100;
	int& rodents = rats;
	int newval = 50;

	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	rats++;
	cout<<"\trats++결과"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	rodents++;
	cout<<"\trodents++결과"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	cout<<"\t세 주소 비교"<<endl;
	cout<<"   rats = "<<&rats<<endl;
	cout<<"rodents = "<<&rodents<<endl;
	cout<<" newval = "<<&newval<<endl;

	rodents = newval;
	cout<<"\tradents = newval"<<endl;
	cout<<"   rats = "<<rats<<endl;
	cout<<"rodents = "<<rodents<<endl;

	cout<<"\t세 주소 비교"<<endl;
	cout<<"   rats = "<<&rats<<endl;
	cout<<"rodents = "<<&rodents<<endl;
	cout<<" newval = "<<&newval<<endl;
}
#endif


#if 0
//////////////////////////////////////////call by value,address,reference 비교
void SwapReference(int& ref1, int& ref2);
void SwapAddress(int* ptr1, int* ptr2);
void SwapValue(int temp1, int temp2);
void main()
{
	int wallet1 = 2000;
	int wallet2 = 5000;

	cout<<"지갑1 : "<<wallet1<<endl;
	cout<<"지갑2 : "<<wallet2<<endl;

	cout<<"\t참조를 통한 내용 변화!"<<endl;
	SwapReference(wallet1, wallet2);
	cout<<"지갑1 : "<<wallet1<<endl;
	cout<<"지갑2 : "<<wallet2<<endl;

	cout<<"\t주소를 통한 내용 변화!"<<endl;
	SwapAddress(&wallet1, &wallet2);
	cout<<"지갑1 : "<<wallet1<<endl;
	cout<<"지갑2 : "<<wallet2<<endl;

	cout<<"\t값 전달을 통한 내용 변화!"<<endl;
	SwapValue(wallet1, wallet2);
	cout<<"지갑1 : "<<wallet1<<endl;
	cout<<"지갑2 : "<<wallet2<<endl;
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
		val=0;			//class 내부접근
		val++;			//class 내부접근
		cout<<val<<endl;//class 내부접근
	}
};

void main()
{
	Count cnt;
	//cnt.val = 0;		//class 외부접근
	cnt.increment();	//class 외부접근
	//cout<<cnt.val<<endl;//class 외부접근
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






















