/*

- 문자열 상수는 문자의 시작주소를 반환함(이름이 없으니 시작주소로 접근가능)
	*읽기용도 => 수정불가능
문자상수 하나당 1byte, 따라서 자료형은 char*(문자열 포인터 상수)
주소값을 저장하는 포인터변수의 크기는 4byte

	<컴파일러의 인식>
문자상수 :'A' -> char형
정수상수 : 5  -> int형
실수상수 : 3.4-> double형

- 자동형변환 -> 낮은자료형을 높은자료형으로 승격시킴
	ex) 3x3x3.14 -> 소수점 손실을 없애기위해 3을 double형으로 승격시킴

[ ] == 참조연산
즉, char** pdm == char* pdm[]
변수선언시에 char* pdm[]은 안되기 때문에 매개변수에는 char** pdm(더블포인터)를 쓸 것!


pmenu[0] == *(pmenu+0)
pmenu[1] == *(pmenu+1)
	*dpmenu == pmenu

char* pArr[4] = {"Good Student","Hello World","Test Program","Setting Menu"}
	"Good Student"의 d(한문자)를 참조할때 -> *(pArr[0]+3)
	"Good Student"-문자열을 출력 -> %s, pArr[0]

char** pdm = pArr;
"Good Student"를 출력하고자 할 때(문자열 상수의 시작주소는 문자열을 나타냄!)
	%s, *(pdm+1)  ==  %s, pdm[1]

pdm[1][6] == *(*(pdm+1)+6) // Hello World의 W와 동일함
만약 X를 출력하고자할때
	%c, 'W'+1	==	 %c, *(*(pdm+1)+6)+1	 ==		 %c, pdm[1][6]+1
Setting Menu의 M을 출력하고자 할때,
	%c, *(pdm[3]+8)	== %c, pdm[3][8]


- 2차원 배열
int Darr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
할당 메모리 = 3x5x4 = 60byte
				
20byte를 건너띄는 포인터 자료형을 어떻게 만들까?..(2차원 배열의 행 시작주소를 가리키기 위함)
	int *pd[5] = {{},{},{},{},{}};	// 배열의 각 요소가 int*인 *포인터배열*임.(포인터배열(선언할때 5개의 자료형이 와야함)
	int (*pd)[5] = data_arr;		// 길이가 5인 int*형 2차원 배열을 가리키는 *배열포인터*임(포인터변수)
	char (*pd)[5] => 5byte씩 건너띄는 배열포인터
										

<<<사용자가 만드는 포인터변수(배열포인터)>>>

int arr[5];
int*pa = arr;
	arr[3]==pa[3]

int data_arr[3][5];
int (*darr)[5] = data_arr //이렇게되면 darr은 data_arr과 동일하게 사용가능
	따라서, darr[0][2]==data_arr[0][2]

*/


#include <stdio.h>

#if 0
void display(int (*darr)[5])	//darr은 4byte의 포인터 변수
{
	int count1,count2;	
	for(count1 = 0; count1<3; ++count1)
	{
		for(count2 = 0; count2<5; ++count2)
			printf("darr[%d][%d]의 값 : %d\n",count1,count2,darr[count1][count2]);
	}

	for(count1 = 0; count1<3; ++count1)
	{
		for(count2 = 0; count2<5; ++count2)
		{
			darr[count1][count2]+=100;
			printf("수정된 darr[%d][%d]의 값 : %d\n",count1,count2,darr[count1][count2]);
		}
	}
	printf("darr        : 0x%p\n",darr);
	printf("darr[0]     : 0x%p\n",darr[0]);
	printf("darr+1      : 0x%p\n",darr+1);
	printf("darr[1]     : 0x%p\n",darr[1]);
	printf("darr[2]     : 0x%p\n",darr[2]);
	printf("&darr[0][0] : 0x%p\n",&darr[0][0]);
	printf("&darr[0][1] : 0x%p\n",&darr[0][1]);
}


void main()
{
	int data_arr[3][5] =	{	{1,2,3,4,5,},
								{6,7,8,9,10},
								{11,12,13,14,15}	};
	display(data_arr);	//data_arr, data_arr+1 이 의미하는건 20byte의 크기를 갖는 배열의 행을 가리킴
						//만약에 배열의 행을 1차원 포인터로 받으려면
						//매개변수 = int* dprr, 전달인자 data_arr[0] 으로 하면 행의주소로 접근가능
	printf("data_arr        : 0x%p\n",data_arr);
	printf("data_arr[0]     : 0x%p\n",data_arr[0]);
	printf("data_arr+1      : 0x%p\n",data_arr+1);
	printf("data_arr[1]     : 0x%p\n",data_arr[1]);
	printf("data_arr[2]     : 0x%p\n",data_arr[2]);
	printf("&data_arr[0][0] : 0x%p\n",&data_arr[0][0]);
	printf("&data_arr[0][1] : 0x%p\n",&data_arr[0][1]);
}
#endif


#if 0
////////////////main함수에 선언된 2차원 배열을 참조하여 한사람의 이름,주소를 출력
void inform_insert(char (*inperson)[50])
{
	printf("이름을 입력해보거라 : ");
	scanf("%s",inperson[0]);
	printf("주소를 입력해보거라 : ");
	scanf("%s",inperson[1]);
}

void inform_display(char (*inperson)[50])
{
	printf("그대의 이름은 : %s\n",inperson[0]);
	printf("그대의 주소은 : %s\n",inperson[1]);
}

void main()
{
	char person[2][50];

	inform_insert(person);	//이름, 주소 입력
	inform_display(person);	//이름, 주소 출력
}
#endif


#if 0
/*
	Fill_array()는 double형 값들의 배열 이름과 배열 크기를 매개변수로 취함
		*배열에 저장할 double형 값들을 입력하여 꽉차거나 숫자가 아닐경우 break, 입력받은수를 return
	Show_array()는 double형 값들의 배열 이름과 배열 크기를 매개변수로 취하고 출력
	Reverse_array()는 double형 값들의 배열 이름과 배열 크기를 매개변수로 취하고 저장된 순서를 뒤집음
	
	이 함수를 사용하여
		1. 배열을 채우고	2. 배열을 출력하고		3. 배열의 저장순서를 뒤집고		4. 배열을 출력
		조건 : 첫번째원소와 마지막원소를 제외한 나머지 원소만의 순서만 뒤집을 것!
*/

void Fill_array(double (*Farr)[5], int* Fcount);
void Show_array(double (*Sarr)[5], int* Scount);
void Reverse_array(double (*Rarr)[5], int* Rcount);
void main()
{
	double arr[5][5]={0};
	int count = 0;
	Fill_array(arr,&count);
	Show_array(arr,&count);
	Reverse_array(arr, &count);
	Show_array(arr,&count);
}

void Fill_array(double (*Farr)[5], int* Fcount)
{
	int cnt1,cnt2;
	printf("Fill_array 시작 \n");
	for(cnt1 = 0; cnt1<5; ++cnt1)
	{
		for(cnt2 = 0; cnt2<5; ++cnt2)
		{
			printf("[%d][%d]배열의 요소 입력 : ",cnt1,cnt2);
			scanf("%lf",&Farr[cnt1][cnt2]);
			if(Farr[cnt1][cnt2]<0)
			{
				Farr[cnt1][cnt2] = 0; //scanf에서 입력된 것을 초기화
				printf("Fill 함수에서 증가된 count : %d\n",*Fcount);
				return;		// void함수의 종료는 return;
			}
			else
				(*Fcount)++;
		}
	}
	printf("Fill 함수에서 증가된 count : %d\n",*Fcount);
	return;
}

void Show_array(double (*Sarr)[5], int* Scount)
{
	int cnt1;
	printf("Show_array 시작 \n");
	for(cnt1 = 0; cnt1<*Scount; ++cnt1)
	{
		printf("배열의 원소 출력 : %lf\n",*((*Sarr)+cnt1));
	}
	printf("[5][5]크기 배열의 입력된 원소 수 : %d\n",*Scount);
	return;
}

void Reverse_array(double (*Rarr)[5], int* Rcount)
{
	int cnt1,cnt2;
	double temp;
	printf("Reverse_array 시작 \n");
	cnt2 = *Rcount-2;
	for(cnt1 = 0; cnt1<(*Rcount-2)/2; ++cnt1)
	{
		temp = *((*Rarr)+cnt1+1);
		*((*Rarr)+cnt1+1) = *((*Rarr)+cnt2);
		*((*Rarr)+cnt2) = temp;
		cnt2--;
	}
}
#endif


#if 0
////////////////////////구구단
void gooprint(int (*pgoo)[9]);
void main()
{
	int googoo[8][9] = {	{2,4,6,8,10,12,14,16,18},
							{3,6,9,12,15,18,21,24,27},
							{4,8,12,16,20,24,28,32,36},
							{5,10,15,20,25,30,35,40,45},
							{6,12,18,24,30,36,42,48,54},
							{7,14,21,28,35,42,49,56,63},
							{8,16,24,32,40,48,56,64,72},
							{9,18,27,36,45,54,63,72,81}	};
	gooprint(googoo);
}

void gooprint(int (*pgoo)[9])
{
	int cnt1,cnt2;
	for(cnt1=1; cnt1<10; ++cnt1)
	{
		for(cnt2=1; cnt2<5; ++cnt2)
			printf("%d x %d = %2d\t",cnt2+1,cnt1,pgoo[cnt2-1][cnt1-1]);
		printf("\n");
	}
	for(cnt1=1; cnt1<10; ++cnt1)
	{
		for(cnt2=5; cnt2<9; ++cnt2)
			printf("%d x %d = %2d\t",cnt2+1,cnt1,pgoo[cnt2-1][cnt1-1]);
		printf("\n");
	}
}

#endif


#if 0
////////////////1년간 월간 판매되는 책의 수를 입력받는다.
void accrue(char** Amonth,int* Asale,int* Asales);
void main()
{
	char* month[12] = {	"1월","2월","3월","4월","5월",
						"6월","7월","8월","9월","10월","11월","12월"};
	int saleArr[12];
	int sales=0;
	accrue(month,saleArr,&sales);
	printf("총 판매량 : %d\n",sales);
}
void accrue(char** Amonth,int* AsaleArr,int* Asales)
{
	int cnt;
	for(cnt = 0; cnt<12; ++cnt)
	{
		printf("%s에 판매된 책의 수 : ",*(Amonth+cnt));	//Amonth는 순수하게 포인터배열month의 주소를 불러오기 때문에
													//month주소에 담긴 "1월"의 주소를 불러오려면 *연산자가 필요함
		scanf("%d",&AsaleArr[cnt]);
		*Asales+=AsaleArr[cnt];
	}
}	
#endif


#if 1
///////////////3년간 월간 판매되는 책의 수를 매년 누적하여 출력(2차원배열사용)
void accrue(char** Amonth,int (*AsaleArr)[12],int* Asales);
void main()
{
	char* month[12] = {	"1월","2월","3월","4월","5월",
						"6월","7월","8월","9월","10월","11월","12월"};
	int saleArr[3][12];
	int sales=0;
	accrue(month,saleArr,&sales);
	printf("3년간 총 판매량 : %d\n",sales);
}
void accrue(char** Amonth,int (*AsaleArr)[12],int* Asales)
{
	int cnt1,cnt2;
	int year[3]={0};
	for(cnt1 = 0; cnt1 < 3; ++cnt1)
	{
		for(cnt2 = 0; cnt2<12; ++cnt2)
		{
			printf("%s에 판매된 책의 수 : ",*(Amonth+cnt2));	//Amonth는 순수하게 포인터배열month의 주소를 불러오기 때문에
														//month주소에 담긴 "1월"의 주소를 불러오려면 *연산자가 필요함
			scanf("%d",&AsaleArr[cnt1][cnt2]);
			year[cnt1]+=AsaleArr[cnt1][cnt2];
		}
	}
	printf("1년간 누적판매수 : %d\n",year[0]);
	printf("2년간 누적판매수 : %d\n",year[0]+year[1]);
	printf("3년간 누적판매수 : %d\n",year[0]+year[1]+year[2]);
	*Asales = year[0]+year[1]+year[2];
}

#endif
















