/*

data,bss - object에서 이미 존재
stack,heap - 프로그램 시작 후
text - 프로그램 code, 상수 등이 저장됨 // 쓰기 불가능

전역변수 : bss에 할당(스타터에서 0으로 초기화됨)

for loop에서 레지스터 변수를 사용하면 속도개선 가능!(r0, r1...)
	단, 레지스터는 주소가 없기 때문에 stack 포인터 변수로 저장 불가능하지만
		컴파일러가 레지스터변수를 stack에 또 할당하여 오류를 나타내진느 않음(속도개선효과가 없어짐)

Q 객체지향 프로그래밍이 뭔가?
	객체는 현실세계에 있는 것을 프로그램에 모델링 하는 것
	프로그램에 필요한 사람, 사물 등을 객체로 표현하여 프로그램에 의미를 부여

요즘 알고리즘 테스트를 보는 추세...

이미 object 파일이 생성되면 주석처리를 할지라도 에러가 발생
-> 컴파일할 필요 없는 코드는 빌드제외를 해야함

*/

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
Data *head = NULL;
Data *tail = NULL;
char *path = "a.txt";

void main()
{
	init();
	puts("추가전");
	printA();
	add("aaa\n");
	add("bbb\n");
	add("ccc\n");
	puts("add 함수로 문자열 추가\n");
	printA();
	//printB();	//역순 출력
	printf("edit함수로 문자열 수정\n");
	edit();
	printA();
	fileWrite();
	stop();
}
#endif


#if 0
#include <iostream>
using namespace std;

class A
{
public:
	virtual void func1()	//동적 결합(오버라이딩)
	{
		cout << "A : func1" << endl;
	}
};
 
class B : public A
{
public:
	void func1()
	{
		cout << "B : func1" << endl;
	}
};

void main()
{
	A a;
	B b;
	a.func1();
	b.func1();

	A *pa = &b;	//동적결합으로 함수를 호출하려면 포인터를 써야함
	B *pb = &b;
	pa->func1();
	pb->func1();
}
#endif



//////////////////////캐스팅을 이용한 다형성 다마고찌
#include <iostream>
#include <typeinfo>	//해당 클래스가 무엇인지 확인하기 위한 헤더
#include "monster.h"

using namespace std;

void main()
{
	Demon *d;	//업캐스팅을 하기 위함
	bool flag = false;
	char select=0;
	puts("케릭터 선택");
	
	while (!flag)
	{
		puts("1. 피카츄, 2. 꼬부기, 3. 파이리");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			d = new Pica;
			flag = true;
			break;
		case 2:
			d = new Gobu;
			flag = true;
			break;
		case 3:
			d = new Pi;
			flag = true;
			break;
		default:
			puts("1-3 중 하나만 입력하시오");
			flag = false;
			break;
		}
	}

	while (flag)
	{
		puts("1. 밥먹기 2. 잠자기 3. 운동하기 4. 놀기 5. 정보확인 6. 특기 공격");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			d->eat();
			break;
		case 2:
			d->sleep();
			break;
		case 3:
			flag = d->exercise();
			break;
		case 4:
			flag = d->play();
			break;
		case 5:
			d->printInfo();
			break;
		case 6:
			if (typeid(*d) == typeid(Pica))
				flag = ((Pica*)d)->electronic();
			else if (typeid(*d) == typeid(Gobu))
				flag = ((Gobu*)d)->water();
			else if (typeid(*d) == typeid(Pi))
				flag = ((Pi*)d)->fire();
			break;
		default :
			puts("그 외에는 다 종료란다");
			flag = false;
			break;
		}
	}
	delete d;
}




