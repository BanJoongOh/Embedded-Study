/*
변수접근
	1. 직접접근 - 변수명 활용
	2. 간접접근 - 포인터변수 활용

배열명 - 배열의 시작주소, 포인터 상수
		즉, ptr = arr(가능) // arr = ptr(불가능)

- int arr[5] 접근방법
int* pa = arr;
	*(pa+0) == arr[0]
	*(pa+1) == arr[1]

char* ps1 = "test program";
문자열 상수는 시작주소를 반환함(read only)
	즉, ps1[5]='k'(불가능)

- 포인터배열
char* parr[3] = {"test","good","student"};
- 더블포인터
char** pd = parr;
	즉, pd == parr, pd[1] == parr[1]
- 배열포인터
; int arr[3][5]를 가리키는 포인터
int (*pa)[5]	// (4x5)20byte의 주소를 건너띄는 포인터임
	ex)pa[0][1] == *(*(pa+0)+1)
	각 자료형
	   arr[0] == int*
	   arr == int (*p)[5]
*/


/*

- 메모리 할당
	- 정적 할당 : 컴파일 타임에서의 메모리 할당(전역,지역,static 등)
				장점 : 접근속도가 빠름, 구현이 쉬움
				단점 : 메모리 낭비, 코드 유지보수가 어려움

	- 동적 할당 : 실행 타임에서의 메모리 할당
				장점 : 메모리 효율적사용, 코드 유지보수 용이
				단점 : 접근속도가 느림, 코드 구현이 어려움(포인터 접근)

- 메모리 영역(stack : FIFO, Queue : LIFO)
	1. data		: 전역,static 변수
	2. heap		: 동적할당영역		//메모리 할당에 대한 시작주소를 반환
	3. stack	: 지역,매개 변수

	#include <stdlib.h>
		malloc();	== new
		free();		== delete

void* malloc(Size_t size);
	#typedef unsigned int Size_t;

void* ptr = malloc(sizeof(int)*5);	// 20byte할당, malloc은 주소값을 반환함(비정상 : -1)
	# 여기서 void형 포인터를 쓰는 이유는 모든 자료형의 주소값을 저장할 수 있다!
		단, 접근시 몇 byte를 접근할지 알 수 없다.
		*ptr = 8		// 이런 접근이 불가능하다.
		int* pnew = (int*)ptr = 8;	// 형변환이 필요
		*pnew = 8		// 접근 가능함

int* pnew = (int*)malloc(sizeof(int)*5);	//형변환을 통해 동적할당을 한줄로 할 수 있음!
free(pnew);	//주소만알려주면 할당된 메모리를 해제함














*/


#include <stdio.h>
#include <stdlib.h>
/*
///////////////////정수데이터 5개를 입력하는 함수, 저장된 데이터를 출력하는 함수
int* insert();
void display(int* dptr);
void main()
{
	int* num;
	num = insert();
	display(num);
}

int* insert()
{
	//ptr은 stack에 할당되어 heap에 할당된 값의 주소를 가리킴
	int* ptr = (int*)malloc(sizeof(int)*5);	//heap에 할당되기때문에 함수가 종료되도 초기화안됨
	int num;
	printf("insert에서 확인한 ptr의 시작주소 : %p \n",ptr);
	for(num=0; num<5; ++num)
	{
		printf("정수 입력 : ");
		scanf("%d",ptr+num);
	}
	return ptr;	//ptr이 담고있는 heap의 주소를 반환(ptr은 stack에서 함수 종료시 삭제)
}

void display(int* dptr)
{
	int num;
	printf("display에서 확인한 ptr의 시작주소 : %p \n",dptr);
	for(num=0; num<5; ++num)
		printf("정수 출력 : %d\n",*(dptr+num));
	free(dptr);
}
*/


/////////////while & switch-case// 1.이름입력 2.이름출력 3.종료
char* insert_name(int* icount);
void display_name(char** dptr, int* dcount);
void main()
{
	int select_mode=10;
	int count = 0;
	char* name[5];
	while(select_mode!=0)
	{
		printf("1. 이름입력\t2. 이름출력\t0.종료 : ");
		scanf("%d",&select_mode);
		switch(select_mode)
		{
		case 1 :
			name[count-1] = insert_name(&count);	//복사된 heap의 주소를 포인터 배열에 저장
			//printf("count = %d\n",count);
			//printf("switch에서의 이름 : %s\n",name[count-1]);
			break;
		case 2 :
			display_name(name,&count);
			break;
		case 0 :
			printf("\t종료합니다.\n");
			break;
		default :
			printf("0,1,2중 하나만 입력하시오..\n");
			break;
		}
		if(count==5)
		{
			display_name(name,&count);
			break;
		}
	}
}

char* insert_name(int* icount)
{
	char keyin[100];
	int num;
	char* ptr;
	printf("%d번째 이름 입력 : ",(*icount)+1);
	scanf("%s",keyin);
	for(num = 0; keyin[num]!='\0'; ++num);		//입력된 문자의 길이를 카운트
	printf("%d번째 이름의 길이 : %d\n",(*icount)+1,num);
	ptr = (char*)malloc(sizeof(char)*(num+1));	//입력된 문자의 길이+1만큼 메모리 할당
	for(num = 0; keyin[num]!='\0'; ++num)
		*(ptr+num) = *(keyin+num);
	*(ptr+num)='\0';	//끝으로 NULL문자를 넣음으로써 문자열 완성
	//printf("복사된이름 : %s\n",ptr);
	(*icount)++;
	return ptr;
}

void display_name(char** dptr, int* dcount)
{
	int num = 0;
	int temp = *dcount;
	while(temp!=0)
	{
		printf("display 함수 %d번째 이름 : %s\n",num+1,*(dptr+num));
		temp--;
		num++;
	}
}





























