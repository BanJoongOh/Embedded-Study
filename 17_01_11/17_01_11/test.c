/*

typedef struct
{
	char title[30];
	double cal;
	int weight;
}CANDY;

CANDY snack;
snack.title = "새우깡";(X,포인터 상수는 수정 불가능)
-> scanf("%s",snack.title); //(O, 주소에 접근하여 입력받는건 가능)

정적배열 = 선언과 동시에 초기화가능
동적배열 = 선언과 동시에 초기화불가능, 이름이 없고 오로지 heap의 주소만을 반환함
	CANDY* ptr = (CANDY*)malloc(sizeof(CANDY)*3);


1. 지역함수내에서 구조체의 주소만 매개변수로 받을경우
	CANDY snack;
	insert(&snack);
	insert(CANDY* ptr)
	{
		ptr->title[0] = 'a';
	}
2. 지역함수내에서 구조체배열의 주소를 매개변수로 받을경우
	CANDY snack[3];
	insert(snack);
	insert(CANDY* ptr)
	{
		ptr[0].title[0] = 'a'; //(*(ptr+0)).title[0] == ptr->title[0]	(둘다 쓰지말것)
	}

- Const 선언은 주로 포인터가 매개변수일때 씀
	const char* ps = &ch;	//가리키는 주소를 변경할 수 있으나, 값의 수정 불가능
		*ps = 'K'	//(X)	//주소내의 값을 수정할 수 없음
		 ps = &buff	//(O)

	char* const ps = &ch;	//가리키는 주소가 고정되어 있으나, 주소변경 가능.
		*ps = 'B'	//(O)
		 ps = &buff	//(X)	//가리키는 주소를 수정할 수 없음
*/




/*

- 구조체+포인터

	1. 구조체를 가리키는 포인터
	2. 구조체멤버변수로 포인터를 변수를 갖는 구조체

typedef struct
{
	char name[30];
	int age;
	double score;
	int* ptr;
}STU;

int temp = 5;
STU person = {"홍길동", 30, 93.5, &temp};
*(person.ptr) = 10;//person.ptr가 주소임!

*/



/*

typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* ptr;	//자기참조포인터
}STU;

*/








#include <stdio.h>
#include <stdlib.h>

#if 0

#define SLEN 30
typedef struct
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
}STU;

int getinfo(STU* gptr, int num);
void display1(STU dps);				//구조체를 매개변수로
void display2(STU* dptr);			//구조체의 주소를 매개변수로
void display3(STU* dpa, int num);	//구조체 배열의 첫번째 원소의 주소와 배열의 원소수

void main()
{
	int class_size,enter,count;
	STU* ptr_stu;
	printf("학생 수를 입력하시오 : ");
	scanf("%d",&class_size);
	ptr_stu = (STU*)malloc(sizeof(STU)*class_size);
	
	enter = getinfo(ptr_stu, class_size);
	for(count = 0; count<enter; ++count)
	{
		display1(ptr_stu[count]);
		display2(&ptr_stu[count]);
	}
	display3(ptr_stu, enter);
	printf("프로그램 종료.\n");
	free(ptr_stu);
}

int getinfo(STU* gptr, int num)
{
	int count,keyin;
	for(count = 0; count<num; ++count)
	{
		printf("%d번 학생의 이름을 입력하시오 : ",count+1);
		scanf("%s",gptr[count].fullname);
		printf("%d번 학생의 취미를 입력하시오 : ",count+1);
		scanf("%s",gptr[count].hobby);
		printf("%d번 학생의 수준을 입력하시오 : ",count+1);
		scanf("%d",&gptr[count].ooplevel);
		printf("\t여기까지 : 0, 계속 : 1 ");
		scanf("%d",&keyin);
		if(keyin==0)
			break;
	}
	return count;
}

void display1(STU dps)
{
	printf("\tdisplay1 함수 진입\n");
	printf("학생의 이름 : %s\n",dps.fullname);
	printf("학생의 취미 : %s\n",dps.hobby);
	printf("학생의 수준 : %d\n",dps.ooplevel);
}
void display2(STU* dptr)
{
	printf("\tdisplay2 함수 진입\n");
	printf("학생의 이름 : %s\n",dptr->fullname);
	printf("학생의 취미 : %s\n",dptr->hobby);
	printf("학생의 수준 : %d\n",dptr->ooplevel);
}
void display3(STU* dpa, int num)
{
	int count;
	printf("\tdisplay3 함수 진입\n");
	for(count = 0; count<num; ++count)
	{
		printf("\t%d번째 학생의 이름 : %s\n",count+1,dpa[count].fullname);
		printf("\t%d번째 학생의 취미 : %s\n",count+1,dpa[count].hobby);
		printf("\t%d번째 학생의 수준 : %d\n",count+1,dpa[count].ooplevel);
	}
}


#endif



#if 0
typedef struct
{
	char name[30];
	int age;
	double score;
	int* ptr;
}STU;

void display(STU* dptr);
void main()
{
	int temp = 5;
	STU person = {"홍길동", 30, 93.5, &temp};

	printf("     person의 주소 : %p\n",&person);
	printf("person.name의 주소 : %p\n",person.name);
	printf("이름 : %s\n",person.name);
	printf("나이 : %d\n",person.age);
	printf("점수 : %lf\n",person.score);
	printf("변경 : %d\n",*(person.ptr));
	display(&person);
}

void display(STU* dptr)
{
	printf("\tdisplay함수 진입\n");
	printf("이름 : %s\n",dptr->name);	//구조체 변수를 주소로 받았기 때문에 간접접근연산자(->)를 사용
	printf("나이 : %d\n",dptr->age);
	printf("점수 : %lf\n",dptr->score);
	printf("변경 : %d\n",*(dptr->ptr));
}
#endif



#if 0
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

void main()
{
	STU* ptr;
	STU p1,p2,p3;
	int count;
	ptr = &p1;

	printf("1번 이름 입력 : ");
	scanf("%s",p1.name);
	p1.age = 25;
	p1.score = 3.45;
	p1.link = &p2;

	printf("2번 이름 입력 : ");
	scanf("%s",p2.name);
	p2.age = 26;
	p2.score = 3.62;
	p2.link = &p3;

	printf("3번 이름 입력 : ");
	scanf("%s",p3.name);
	p3.age = 27;
	p3.score = 3.78;
	p3.link = NULL;
	
	for(count = 0; count<3; ++count)// == while(ptr!=NULL)
	{
		printf("%d번 이름 : %s\n",count+1,ptr->name);				//주소를 받았기 때문에 간접접근연산자
		printf("%d번 나이 : %d\n",count+1,ptr->age);			
		printf("%d번 점수 : %.1lf\n",count+1,ptr->score);	
		ptr = ptr->link;	//link를 여러개 사용하는건 비효율적임
	}
}
#endif



/*	1. 입력 2. 출력 3. 종료 세개의 메뉴
		입력시에 insert()함수호출
			insert함수에서는 STU 구조체만큼 동적할당하여 메모리를 확보하고 임의의 데이터 저장
		출력함수에서는 누적된 입력만큼 출력해줄 것
*/
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

STU* insert(int* num);
void display(STU* pastptr, int* num);
void main()
{
	int keyin=0;
	int count=0;
	int flag=0;
	int temp;
	STU* pasttemp = NULL;
	STU* pretemp = NULL;
	STU* start = NULL;
	while(keyin!=3)
	{
		printf("1. 입력\t2. 출력\t3.종료 : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	if(!flag)
					{
						pasttemp = insert(&count);
						start = pasttemp;
						flag=1;
					}
					else
					{
						pretemp = insert(&count);
						pasttemp->link = pretemp;
						pasttemp = pretemp;
					}
					break;
		case 2 :	display(start, &count);
					break;
		case 3 :	printf("종료합니다 ^^.\n");
					for(temp = 0; temp<count; ++temp)
					{
						pretemp = start->link;
						free(start);
						start = pretemp;
					}
					break;
		default :	printf("똑바로 입력하거라.!\n");
					break;
		}
	}
}

STU* insert(int* num)
{
	STU* ptr;
	printf("%d번째 입력입니다.\n",(*num)+1);
	ptr = (STU*)malloc(sizeof(STU));
	printf("%d번째 이름 입력 : ",(*num)+1);
	scanf("%s",ptr->name);			//heap의 주소를 가리키기 때문에 간접접근연산자 사용
	printf("%d번째 나이 입력 : ",(*num)+1);
	scanf("%d",&ptr->age);
	printf("%d번째 점수 입력 : ",(*num)+1);
	scanf("%lf",&ptr->score);
	(*num)++;
	return ptr;	//ptr자체는 heap의 시작주소를 가리킴
}

void display(STU* pastptr, int* num)
{
	int count;
	printf("\tdisplay함수 진입 \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d번째 이름 : %10s    ",count+1,pastptr->name);
		printf("%d번째 나이 : %5d    ",count+1,pastptr->age);
		printf("%d번째 점수 : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link;
	}
}



#if 0
////////////////////////////역으로 출력
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

STU* insert(STU* pastptr, int* num);
void display(STU* pastptr, int* num);
void main()
{
	int keyin=0;
	int count=0;
	STU* temp = NULL;
	while(keyin!=3)
	{
		printf("1. 입력\t2. 출력\t3.종료 : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	temp = insert(temp, &count);
					break;
		case 2 :	display(temp, &count);
					break;
		case 3 :	printf("종료합니다 ^^.\n");
					break;
		default :	printf("똑바로 입력하거라.!\n");
					break;
		}
	}
}

STU* insert(STU* pastptr, int* num)
{
	STU* ptr;
	printf("%d번째 입력입니다.\n",(*num)+1);
	ptr = (STU*)malloc(sizeof(STU));
	printf("%d번째 이름 입력 : ",(*num)+1);
	scanf("%s",ptr->name);			//heap의 주소를 가리키기 때문에 간접접근연산자 사용
	printf("%d번째 나이 입력 : ",(*num)+1);
	scanf("%d",&ptr->age);
	printf("%d번째 점수 입력 : ",(*num)+1);
	scanf("%lf",&ptr->score);
	ptr->link = pastptr;
	(*num)++;
	return ptr;	//ptr자체는 heap의 시작주소를 가리킴
}

void display(STU* pastptr, int* num)
{
	int count;
	printf("\tdisplay함수 진입 \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d번째 이름 : %s\t",(*num)-count,pastptr->name);
		printf("%d번째 나이 : %d\t\t",(*num)-count,pastptr->age);
		printf("%d번째 점수 : %.1lf\t",(*num)-count,pastptr->score);
		printf("\n");
		pastptr = pastptr->link;
	}
}

#endif



