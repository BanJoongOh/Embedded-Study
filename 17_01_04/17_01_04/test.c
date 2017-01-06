/*

함수
	1) void main(void)  : 매개변수+전달인자 X, return X
	2) void main(int a) : 매개변수+전달인자 O, return X
	3)  int main(void)  : 매개변수+전달인자 X, return 0
	4)  int main(int a) : 매개변수+전달인자 O, return O

함수원형 - 매개변수명보다는 자료형이 훨씬 더 중요함



- 직접접근(변수명 접근)
	ex) temp = 8;
- 간접접근(메모리 주소)
	포인터 변수 : 메모리 주소값을 저장하기 위한 점수
	ex) int *ptr = &temp;
		**일반적으로 포인터 변수는 선언과 동시에 초기화(주소 또는 NULL)
		**포인터 변수명은 *ptr이 아니라 ptr임
			메모리 참조연산할때 *ptr을 씀 // ptr은 &변수명(변수주소)를 가리킴
			<	*ptr == temp // ptr == &temp	>
				*(&temp) == temp -> *와 &는 상쇄됨
		**포인터 변수의 자료형 크기는 4bytes(32bits운영체제)
		**포인터 변수의 자료형은 간접접근시 시작주소부터 몇byte를 접근할지를
			결정하는 역할을 함.

	<<0x12345678일경우>>
		ARM, Intel - Little Endian(하위비트~상위비트순으로 저장 0x5000-78)
		모토로라계열 - Big Endian(상위비트-하위비트순으로 저장 0x5000-12)

	한번더 강조!! 모든 포인터 변수(자료형무관)는 4Byte = 주소를 가리키기 때문

- 포인터 연산
	*오로지 +,-만 사용할 것!(x연산시 overflow위험)
	ptr+1 -> !자료형의 크기!만큼 더한 것을 가리킴(char일경우 1byte증가 int일경우 4byte증가)
	ptr++ -> 현재 주소가 !자료형의 크기!만큼으로 더해짐

*/


#include <stdio.h>

#if 0
////////////////temp를 간접접근해서 20만들기
void main()
{
	int temp = 8;
	int* ptr = &temp;

	printf("temp : %d\n",temp);
	printf("*ptr : %d\n",*ptr);
	printf("temp Address : 0x%x\n",&temp);
	printf("ptr : 0x%x\n",ptr);

	*ptr = 20;
	printf("temp : %d\n",temp);
}
#endif


#if 0
void reverse(int* num1, int* num2)	//call by address
{
	int rtemp = *num1;	// rtemp = &temp
	*num1 = *num2;		// &temp = &val
	*num2 = rtemp;		// &val = rtemp
}

void main()
{
	int temp = 8;
	int val = 5;
	printf("temp : %d, val = %d\n",temp,val);
	reverse(&temp, &val);
	printf("temp : %d, val = %d\n",temp,val);
}
#endif


#if 0
void main()
{
	int temp = 0x12345678;			
	char* ptr = (char*)&temp;		//endian을 판단하기 위해 1byte의 값만 char형으로 저장.(캐스팅연산)
	printf("temp : %x\n",temp);
	printf("*ptr : %x\n",*ptr);
	if(*ptr==0x78)
		printf("첫주소의 값은 : %x 이고 little endian입니다.\n",*ptr);	//Intel & ARM
	else
		printf("첫주소의 값은 : %x 이고 big endian입니다.\n",*ptr);
	printf("*ptr의 세번째 값 : %x\n",*(ptr+3));
}
#endif


#if 0
void mystringcopy(char* string1, char* string2) //char* string1 = src
{
		printf("src주소(p) : %p\n",string1);
		printf("src주소(s) : %s\n",string1);
		printf("src주소(s) : %c\n",*string1);
	while(*string1!='\0')
		*string2++ = *string1++;
	*string2 = '\0';
}

void main()
{
	char src[50];
	char dest[50];
	char* ptr = src;
	printf("문자를 입력해보렴 : ");
	scanf("%s",src);
	fflush(stdin);
		printf("ptr주소(p) : %p\n",ptr);
		printf("ptr주소(s) : %s\n",ptr);
		printf("ptr주소(s) : %c\n",*ptr);
	mystringcopy(src,dest);
	printf(" src : %s.\n",src);
	printf("dest : %s.\n",dest);
}
#endif



//sec 배열에 영문자, 숫자, 특수문자등을 입력받음
//modify()함수 호출후에는 dest에 영어 대소문자만 받음
//apha_counting()함수 호출후에는 dest에 있는 알파벳 'a'의 갯수를 받는다.(자료형 int)
void modify(char* str1, char* str2);
int alpha_counting(char* alpha);
void main()
{
	char src[50];
	char dest[50];

	printf("임의의 문자를 입력하거라 : ");
	scanf("%s",src);
	modify(src,dest);
	printf("src : %s, dest : %s, a의 개수 : %d\n",src,dest,alpha_counting(dest));
}

void modify(char* str1, char* str2)
{
	while(*str1!='\0')
	{
		if((*str1>64 && *str1<91) || (*str1>96 && *str1<123))
			*str2++ = *str1;
		*str1++;
	}
	*str2 = '\0';
	
}

int alpha_counting(char* alpha)
{
	int temp = 0;
	while(*alpha!='\0')
	{
		if(*alpha=='a')
			temp++;
		*alpha++;
	}
	return temp;
}

























