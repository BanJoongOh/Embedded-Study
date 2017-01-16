/*
Header - 전처리 쓰는 이유 : main함수를 한 화면에 보이게 하기 위해

	이름공간 : program의 size가 커지면서 같은 이름을 가진 함수와 변수를 분류해서 사용함.
		ex) using namespace std;(using namespace는 예약어)

		printf("문자열 상수");	//문자열 상수는 시작주소를 반환함
		printf(const char* ps);	//함수

- C++에서는 cin, cout 객체를  사용
	자료형에 따른 서식문자를 쓸 필요 없음.

	\n(0x0A) = 줄바꿈
	\r(0x0D) = 줄바꿈이후 커서를 맨 앞으로
		\n과 \r을 같이 씀!

	cout<<"test program\n"; == count<<"test program"<<endl;

- 연산자 우선순위
	헷갈릴경우 괄호쳐버리면됨

- 오버로딩: 연산자에 추가적인 기능을 부여	//ex) 3*5와 *temp 에서 '*'
	OOP(객체지향)의 특징: 캡슐화/다형성/상속/정보은닉/폰트재활용(표준템플릿-stl)
	*함수 오버로딩 : C++에서는 함수명이 같아도 매개변수가 다르면 수행할 수 있음
		**return type은 무관함

- 디폴트 매개변수(시험) : 함수 호출에서 전달인자를 주지 않았을때 기본적으로 처리하는 매개변수의 값
	누군가가 버그 예정 : * 정의부분은 그대로, 함수 원형(main위)에서 사용함!(디폴트 매개변수 정의)
	매개변수가 여러개일경우 모두 채워서 할 것!

cin.get -> 매개변수로 받은 문자열길이를 넘게되면 짤라버림

- C++에서의 동적할당 : new, delete(생성자함수를 호출해줌 : 객체지향)
	char* name = new char[30]; // == (char*)malloc(sizeof(char)*30);
	delete []name;	// == free(name)

- #if,#else,#endif : 조건부 컴파일






*/



#include <iostream>
#include <cstring>	//strlen(), strcpy()를 사용하기 위해
using namespace std;
#if 0
void main()
{
	int carrots;

	carrots = 25;

	cout<<"나는 당근을 ";
	cout<< carrots;
	cout<<"개 가지고 있다.";
	cout<<endl;
	carrots = carrots-1;
	cout<<"아삭아삭, 이제 당근은 "<<carrots<<"개이다."<<endl;
}
#endif



#if 0
void main()
{
	int carrots;

	cout<<"당근을 몇 개 가지고 있니? ";
	cin>>carrots;
	cout<<"저는 당근을 "<<carrots<<"개 가지고 있어요"<<endl;
}
#endif



#if 0
void main()
{
	char name[30];
	char address[50];
	
	cout<<"이름을 입력하세요 : ";
	cin>>name;
	cout<<"주소를 입력하세요 : ";
	cin>>address;
	cout<<"당신의 이름은 : "<<name<<endl;
	cout<<"당신의 주소는 : "<<address<<endl;
}
#endif



#if 0
void changetemp(double* temp)
{
	*temp = (1.8 * (*temp))+32.0;
}

void main()
{
	double temp;
	
	cout<<"섭씨 온도를 입력하세요 : ";
	cin>>temp;
	cout<<"섭씨 "<<temp<<"도는 화씨 ";
	changetemp(&temp);
	cout<<temp<<"도 입니다."<<endl;
}
#endif




#if 0
#define ArSize 20
void main()
{
	char name[ArSize];
	char dessert[ArSize];
	cout<<"이름을 입력하시오 : ";
	cin.getline(name,ArSize);
	cout<<"디저트를 입력하시오 : ";
	cin.getline(dessert,ArSize);
	cout<<"맛있는 "<<dessert<<"를 준비하겠습니다.\n";
	cout<<name<<"님\n";
}
#endif



#if 0
/////////////////////자동차 갯수만큼 동적할당하여 main에서 출력
typedef struct
{
	char name[30];
	int years;
}CAR;

void carlist(CAR** Ftemp, int* Fcount);
void main()
{
	int count;
	CAR* temp = NULL;
	cout<<"몇 대의 차를 목록으로 관리하시겠습니까? ";
	cin>>count;
	carlist(&temp,&count);	//포인터가 가리키는 값을 바꾸기 위해 주소를 받아야함!
	cout<<"현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
	for(int num = 0; num<count; ++num)
		cout<<temp[num].years<<"년형 "<<temp[num].name<<endl;
	delete []temp;
}

void carlist(CAR** Ftemp, int* Fcount)
{
	CAR* Fcar = new CAR[*Fcount];
	for(int num = 0; num<(*Fcount); ++num)
	{
		cout<<"자동차 #"<<num+1<<endl;
		cout<<"제작업체: ";
		cin>>Fcar[num].name;
		cout<<"제작년도: ";
		cin>>Fcar[num].years;
	}
	*Ftemp = Fcar;
}
#endif




typedef struct
{
	char* str;	//문자열을 지시
	int ct;		//문자열의 길이
}TEST;
void set(TEST& set, char* temp);
void show(TEST show, int count = 1);	//count는 디폴트 매개변수
void show(char* show, int count = 1);
void main()
{
	TEST beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);	
	
	cout<<"\t함수 한번 출력\n";
	show(beany);		// 문자열 멤버를 한 번 출력
	cout<<"\t함수 두번 출력\n";
	show(beany, 2);	// 문자열 멤버를 두 번 출력
	testing[0] = 'D';
	testing[1] = 'u';
	
	cout<<"\ttesting 한번 출력\n";
	show(testing);	//문자열 1회 출력
	cout<<"\ttesting 세번 출력\n";
	show(testing, 3);	//문자열 3회 출력
	show("Done");
	printf("동적할당 주소 : %p",beany.str);
	delete beany.str;
}

void set(TEST& set, char* temp)
{
	set.ct = strlen(temp);	//문자열의 길이를 beany 구조체에 저장
	char* strtemp = new char[(set.ct)+1];	//문자열의 길이+1만큼 동적할당
	printf("동적할당 주소 : %p",strtemp);
	strcpy(strtemp, temp);	//할당한 heap영역에 문자길이 복사
	set.str = strtemp;		//beany구조체의 str이 heap의 주소를 가리킴
}

void show(TEST show, int count)
{
	for(int temp = 0; temp<count; ++temp)
		cout<<"str : "<<show.str<<endl<<"length : "<<show.ct<<endl;
}

void show(char* show, int count)
{
	for(int temp = 0; temp<count; ++temp)
		cout<<"testing : "<<show<<endl;
}










