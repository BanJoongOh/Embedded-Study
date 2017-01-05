/* 

- sizeof(배열명) - 배열의 총 byte수
ex) int arr[5];
	sizeof(arr) = 4 x 5 = 20byte
	*활용 - sizeof(arr)/sizeof(int) == 배열의 길이

- 포인터변수 : 가리키는 주소를 바꿀 수 있음
- 포인터상수 : 가리키는 주소가 고정됨(배열)

	int* ptr = arr(&arr[0])
	 매개변수    전달인자

int arr[5];
int* pa = arr;
*(pa+0) == pa[0] == arr[0];
*(pa+1) == pa[1] == arr[1];
*(pa+2) == pa[2] == arr[2];


int temp = 5;
int* ptmp = &temp;

- 싱글 포인터 : 일반 변수의 시작 주소값을 저장
ptmp == 0x800(temp의 주소를 담고있음)
	ptmp == 0x800 == &temp			-> 주소
	*(ptmp) == *(0x800) == *(&temp) == temp	-> 주소의 값

- 더블 포인터 : 싱글 포인터의 시작 주소값을 저장
int** ptd = &ptmp // &ptmp==&(&temp);
	ptd = &ptmp
	*ptd == ptmp == &temp	// 싱글포인터가 가리키는 주소
	**ptd == temp == 5		// 싱글포인터가 가리키는 주소의 값
	*ptmp == temp == 5
	

- 문자열 상수
문자열 상수는 시작주소를 반환함 ; 포인터를 써야함
char* ps = "good student";		//문자열상수를 가리키는 포인터(시작주소만)
// 문자열상수는 프로그램 수행중에 수정 불가능 / 메모리에만 올라가있고 접근 불가능

- 포인터 배열
; 일반형태의 배열은 데이터, 포인터 배열은 주소를 담고있음.
char Arr[4];
	sizeof(Arr) = 1x4 = 4
char* psArr[4] = {"Good","Hello","Bye","Apple"};
	sizeof(psArr) = 4x4 = 16



*/

#include <stdio.h>

/*
//특정 함수에서 10개의 정수를 입력 받아서 배열에 저장(홀수를 앞에 짝수를 뒤에 저장)
void even_odd_insert(int* parr, int* ecc)
{
	int ecount=9;//짝수
	int ocount=0;//홀수
	int keyin;
	while((ecount+1)!=ocount)
	{
		printf("양의 정수 입력 : ");
		scanf("%d",&keyin);
		if(keyin%2==1)
			parr[ocount++]=keyin;
		else
			parr[ecount--]=keyin;
	}
	*ecc=ecount;
}

void bsort(int* parr, int ecount)//짝수4개면 ecount==5
{
	int count1,count2;
	int temp;
	int max = 9;
	printf("ecount = %d \n",ecount);
	for(count2 = 0; count2<ecount; ++count2)
	{
		for(count1 = 0; count1<ecount; ++count1)
		{
			if(parr[count1]>parr[count1+1])
			{
				temp = parr[count1+1];
				parr[count1+1]=parr[count1];
				parr[count1] = temp;
			}
		}
	}
	for(count2 = ecount+1; count2<9; ++count2)
	{
		for(count1 = ecount+1; count1<9; ++count1)
		{
			if(parr[count1]>parr[count1+1])
			{
				temp = parr[count1+1];
				parr[count1+1]=parr[count1];
				parr[count1] = temp;
			}
		}
	}
}

void main()
{
	int arr[10];
	int count;
	int temp;
	int* ptemp = &temp;
	even_odd_insert(arr,ptemp);
	for(count = 0; count<sizeof(arr)/sizeof(int); ++count)
		printf("배열의 %d번째 정수 : %d\n",count,arr[count]);
	bsort(arr,temp);
	for(count = 0; count<sizeof(arr)/sizeof(int); ++count)
		printf("%d ",arr[count]);
}
*/


/*
//포인터가 가리키는 주소를 바꿔줌
void reverse_data(int** num1, int** num2)
{
	int* tmp;		//주소를 담기위한 포인터 변수 선언
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void main()
{
	int tmp = 5;
	int val = 8;
	int *pt = &tmp;
	int *pv = &val;

	printf("tmp : %d, val : %d\n",tmp,val);
	printf("*pt : %d, *pv : %d\n",*pt,*pv);
	reverse_data(&pt,&pv);
	printf("tmp : %d, val : %d\n",tmp,val);
	printf("*pt : %d, *pv : %d\n",*pt,*pv);
	
}
*/



void display(char** dArr, int dcount)
{
	int dnum;
	printf("\tdisplay 함수 진입 \n");
	for(dnum = 0; dnum<dcount; ++dnum)
		printf("%s \n",dArr[dnum]);
}

int alphacount(char** dArr, int acount)
{
	int count,anum,lcount;
	char* temp;
	lcount = 0;
	printf("\talphacount 함수 진입 \n");
	for(anum = 0; anum<acount; ++anum) 
	{
		count=0;
		temp = dArr[anum];
		while(temp[count]!='\0')
		{
			if(temp[count]=='l')
				lcount++;
			count++;
		}
	}
	return lcount;
}

void main()
{
	char buf[30] = "test program";	//문자배열
	char* ps1 = "Good Student";		//문자열상수를 가리키는 포인터(시작주소만)
	char* ps2 = "Hello World";
	char* ps3 = "Bye";
	char* ps4 = "Apple";
	char* psArr[4] = {"Good Student","Hello World","Bye","Apple"};
	int num,count;

	printf("buf : %s \n",buf);
	printf("ps1 : %s \n",ps1);

	buf[0]='k';
	printf("buf : %s \n",buf);
	printf("ps1 : %s \n",ps1);
	
	count = sizeof(psArr)/sizeof(char*);
	for(num = 0; num<count; ++num)
		printf("%s \n",psArr[num]);
	display(psArr,count);

	printf("알파벳 소문자 l의 갯수 : %d\n",alphacount(psArr,count));
}



/*
void menu(char** mselect, char mchoice)
{
	switch(mchoice)
	{
		case 'c' :
		case 'C' : printf("%s 하나 사자\n",mselect[0]);
					break;
		case 'p' :
		case 'P' : printf("%s 배우고싶다\n",mselect[1]);
					break;
		case 't' :
		case 'T' : printf("이 책은 %s로 만들었지\n",mselect[2]);
					break;

		case 'g' :
		case 'G' : printf("%s한판할까\n",mselect[3]);
					break;

		default : printf("c, p, t, g 중에서 하나를 선택하거라.(끝내려면 q or Q) \n");
	}
}

void main()
{
	char choice;
	char* select[4] = {"Camera","Pianist","Tree","Game"};

	printf("다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q or Q)\n");
	printf("c, p, t, g 중에서 하나를 선택하거라.\n");
	
	scanf("%c",&choice);
	fflush(stdin);

	while(choice!='q'&&choice!='Q')
	{	
		menu(select, choice);
		scanf("%c",&choice);
		fflush(stdin);	
	}
}
*/




















