/*

CPU에는 ALU와 register(cache)
ALU -> 산술연산, 논리(T/F판단)

요구사항 -> Flow Chart(설계) -> 코드구현 -> 디버깅

변수선언 - 메모리에 할당
변수접근 - 변수이름, 시작주소값
변수 - 배열(1차원) - 함수 - 포인터(배열의 주소에 접근하기 위함) - 포인터배열 - 함수 - 더블포인터
포인터 = 주소에 간접접근

<음의정수 크기 구하기>
2의보수 = 1의보수 + 1

	1000 0000의 1의보수 = 0111 1111 + 1 = 1000 0000
	1000 0000 = -128임

동적할당은 heap 영역을 사용하는데 시작주소만으로 사용하기때문에 포인터가 필수

<<원형Q & link the list>>
<<오버로딩>>

*/

#include <stdio.h>

#if 0
void main()
{
	char ch;

	printf("원하는 문자를 입력하시오 : ");
	scanf("%c",&ch);
	printf("입력한 문자는 %c이고 문자의 주소는 %p이고 0x%x이고 %x. \n",ch,&ch,&ch,&ch);
	*((char*)0x12ff2b)='k';
	printf("수정된 문자는 %c\n",ch);
	printf("%d",3+5<<2|7);
}
#endif

#if 0
void main()
{
	int lat,min,sec;
	printf("위도를 도, 분, 초 단위로 입력해라 : \n");
	printf("도각은 : ");
	scanf("%d",&lat);
	printf("분각은 : ");
	scanf("%d",&min);
	printf("초각은 : ");
	scanf("%d",&sec);
	printf("%d도, %d분, %d초",lat,min,sec);
}
#endif




/*

buffer역할
1. fan out을 늘리기 위함!(전류증폭)
2. delay 시간차를 주기 위해

not gate(inverter)

Atmega128 인터럽트 활성화시에 SREG |= 0x80; 을 수행할 것(7번을 제외한 비트는 건들면 안됨!)

for(count=0; count<5; ++count);
while(count<5);
		for문과 달리 위의 while문은 무한루프에 빠질 수 있기 때문에 반복문에서는 while문보다는 for문을 선호함

*/


#if 0
void main()
{
	int count;
	for(count=0; count<5; ++count);	//Non operation! 조건검사 및 증감만 반복됨
		printf("count의 현재값은 : %d\n",count);
}
#endif






////////////////Ex1 원하는 구구단을 출력
#if 0
void main()
{
	int num,count;
	printf("입력할 숫자 : ");
	scanf("%d",&num);
	for(count=1; count<10; ++count)
		printf("%d단 %d X %d = %d\n",num,num,count,num*count);
}
#endif


////////////////Ex2 입력한 숫자의 높이만큼 *로 정삼각형 출력
#if 1
void main()
{
	int star,space,keyin,count,spacecount,starcount;
	printf("높이를 입력 : ");
	scanf("%d",&keyin);
	
	spacecount=keyin-1;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<spacecount; ++space)
			printf(" ");
		for(star=0; star<(count+1)*2-1; ++star)
			printf("*");
		printf("\n");
		spacecount--;
	}
	printf("\n");


	starcount=keyin;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<count; ++space)
			printf(" ");
		for(star=0; star<(starcount)*2-1; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
	printf("\n");


	starcount=1;
	for(count=0;count<keyin;++count)
	{
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount++;
	}
	starcount-=2;
	for(count=0;count<keyin;++count)
	{
		
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
	printf("\n");


	spacecount=keyin;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<spacecount-1; ++space)
			printf(" ");
		for(star=0; star<count+1; ++star)
			printf("*");
		printf("\n");
		spacecount--;
	}
	starcount=keyin-1;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<count+1; ++space)
			printf(" ");
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
}
#endif















