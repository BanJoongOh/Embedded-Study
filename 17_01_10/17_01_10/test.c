/*

- 얕은복사 : 주소=주소
- 깊은복사 : 주소에 있는 내용을 복사
mycpy(per.name, "Good");
void mycpy(char* pd, char* ps)
{
	while(*ps!='\0')
		*pd++=*ps++;	// pd[num]=ps[num]
}



	배열은 자료형이 일치해야 한다는 단점이 있음.
- 구조체 : 문자,정수,실수 등의 서로 다른 자료형을 그룹화시켜 하나의 자료형으로 표현
	*멤버변수는 컴파일러가 알고 있는 자료형을 쓸 것!

struct person
{
	char name[30];
	int age;
	double score;
};					//30+4+8 -> 42바이트의 구조체

struct person per;	// struct person : 자료형, per : 변수명
(.) - 구조체 직접 접근 연산자
(->)- 구조체 간접 접근 연산자
	ex) per.age = 26;			// 구조체 멤버접근
		per.name = "good"(X)	// 불가능함 깊은복사를 해줘야됨
		* 배열명 : 배열의 시작주소이자 포인터 상수


- typedef를 이용한 구조체 변수 선언
	1.	typedef struct person PER;
		PER per == struct person per
	2. 
		typedef struct person
		{
			char name[30];
			int age;
			double score;
			struct person *link	// 자기참조 포인터
		}PER;	//PER는 사용자가 만든 자료형임!

PER p1;
PER p2;
p2.link = &p1;	//struct person == PER


*/




#include <stdio.h>
#include <stdlib.h>		//malloc 함수를 사용하기 위함

#if 0
/////////////////////////////구조체 예시
typedef struct person
{
	char name[30];
	int age;
	double score;
	struct person* link;
}PER;

void main()
{
	PER P1;
	int num = 0;
	char name[30];
	int age;
	double score;
	printf("이름 입력 : ");
	scanf("%s",name);
	printf("나이 입력 : ");
	scanf("%d",&age);
	printf("시력 입력 : ");
	scanf("%lf",&score);

	for(num = 0; name[num]!='\0'; ++num)
		P1.name[num] = name[num];
	P1.name[num] = '\0';
	P1.age = age;
	P1.score = score;

	printf("이름 출력 : %s\n",P1.name);
	printf("나이 출력 : %d\n",P1.age);
	printf("시력 출력 : %.1lf\n",P1.score);
}
#endif



#if 0
typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

void insert_data(CandyBar* change);
void main()
{
	CandyBar snack = {"Mocha Munch",2.3,350};	// 구조체변수 선언과 동시에 초기화
	printf("  이름 출력 : %s\n",snack.title);	// snack.title는 포인터상수
	printf("  중량 출력 : %.1lf\n",snack.weight);
	printf("칼로리 출력 : %d\n",snack.cal);
	
	insert_data(&snack);	// 구조체변수의 주소를 인자로줌
	printf("  이름 출력 : %s\n",snack.title);
	printf("  중량 출력 : %.1lf\n",snack.weight);
	printf("칼로리 출력 : %d\n",snack.cal);
}
void insert_data(CandyBar* change)	//*(change+1)은 구조체 크기 다음이기 때문에 쓰레기 값임
{
	int num;
	char temp[20] = "오뜨";
	for(num = 0; temp[num]!='\0'; ++num)
		(*change).title[num]=temp[num];	//여기서 *change는 snack과 동일한 의미를 가진다.
	(*change).weight = 3.2;
	change->cal = 530;	// 구조체 간접 접근 연산자
}
#endif



#if 0
///////////////////////////구조체 배열, 포인터를 선언후 구조체 포인터로 수정하여 출력하기
typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

void insert_data(CandyBar* change);
void main()
{
	CandyBar snack[3] = {	{"Hello",11.11,3000},
							{"Good",22.22,4000},
							{"Morning",33.33,6000}};	// 구조체변수 선언과 동시에 초기화
	printf("  이름 출력 : %s\n",snack[0].title);	// snack.title는 포인터상수
	printf("  중량 출력 : %.1lf\n",snack[0].weight);
	printf("칼로리 출력 : %d\n",snack[0].cal);
	
	insert_data(snack);	// 구조체변수의 주소를 인자로줌
	printf("  이름 출력 : %s\n",snack[0].title);
	printf("  중량 출력 : %.1lf\n",snack[0].weight);
	printf("칼로리 출력 : %d\n",snack[0].cal);

	printf("  이름 출력 : %s\n",snack[1].title);
	printf("  중량 출력 : %.1lf\n",snack[1].weight);
	printf("칼로리 출력 : %d\n",snack[1].cal);

	printf("  이름 출력 : %s\n",snack[2].title);
	printf("  중량 출력 : %.1lf\n",snack[2].weight);
	printf("칼로리 출력 : %d\n",snack[2].cal);
}
void insert_data(CandyBar* change)	// change는 snack배열의 주소를 가리키는 구조체 포인터
{
	int num;
	char temp[30] = "정수1000,소수12.88 바꿔";
	for(num = 0; temp[num]!='\0'; ++num)
		change[0].title[num]=temp[num];
	change[0].title[num] = '\0';
	change[0].weight = 12.88;
	change[0].cal = 1000;	//즉, change == snack이기때문에 직접참조연산을 쓰면됨
}
#endif



typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

CandyBar* input_data();
void main()
{
	CandyBar* snack;
	snack = input_data();	// 구조체변수의 주소를 인자로줌
	printf("  이름 출력 : %s\n",snack[0].title);
	printf("  중량 출력 : %.1lf\n",snack[0].weight);
	printf("칼로리 출력 : %d\n",snack[0].cal);

	printf("  이름 출력 : %s\n",snack[1].title);
	printf("  중량 출력 : %.1lf\n",snack[1].weight);
	printf("칼로리 출력 : %d\n",snack[1].cal);

	printf("  이름 출력 : %s\n",snack[2].title);
	printf("  중량 출력 : %.1lf\n",snack[2].weight);
	printf("칼로리 출력 : %d\n",snack[2].cal);
	free(snack);
}
CandyBar* input_data()	// change는 snack배열의 주소를 가리키는 구조체 포인터
{
//	int num;
	CandyBar* ptr = (CandyBar*)malloc(sizeof(CandyBar)*3);
	ptr[0].title[0] = 'a';	//(*(ptr+0)).title[0] == ptr->title[0]	(둘다 쓰지말것)
	ptr[0].title[1] = '\0';
	ptr[0].weight = 10.21;
	ptr[0].cal = 2000;

	ptr[1].title[0] = 'k';	//(ptr+1)->title[0](쓰지말것)
	ptr[1].title[1] = '\0';
	ptr[1].weight = 17.28;
	ptr[1].cal = 3500;

	ptr[2].title[0] = 't';
	ptr[2].title[1] = '\0';
	ptr[2].weight = 73.58;
	ptr[2].cal = 5000;

	return ptr;
}






