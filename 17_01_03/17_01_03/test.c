/*

comfile time : 문법적 오류 검증 & 변환
    run time : 데이터 연산

*--------------배열명은 배열의 시작주소

'\0' -> NULL문자(컴파일러는 0으로 인식)
'0' -> 숫자 0
'o' -> 영문 o
문자는 ' '로 표현할때 한개의 문자만 표현하는데 이때 Null문자는 없음
문자열은 " "로 표현하는데 문자열맨끝에는 Null문자가 들어감 NULL = '\0'
	ex) 'a' - 문자상수 // "a" - 문자열('\0'이 포함되어있음)

**함수

라이브러리(printf,scanf... 등을 포함)
사용자 정의 함수
	함수원형(main 함수 위) ->> 컴파일러에게 특정 함수가 호출될 예정
	함수호출(main 함수 내부)-> 특정함수정의 부분으로 점프하는 역할
	함수정의(main 함수 밖) ->> 함수가 동작하는 기능에 대한 명령을 나열	//매개변수선언
		*만약에 정의함수명과 호출함수명을 다르게할 경우 link error발생

	Main함수의 지역변수는 전역변수와 동일하게 프로그램이 끝날때 사라짐

함수호출 형태(C의 기준으로는 2개, C++의 기준으로는 reference변수(참조변수)가 추가)
	call by value		- 값의 복사에 의한 호출
	call by address		- pointer로 주소접근
	call by reference	- C++의 reference변수를 사용
	

*/


#include <stdio.h>

/*
/////////정수 5개를 입력받아 평균을 출력하는 프로그램(배열사용)
void main()
{
	int arr[5];
	int count;
	for(count = 0; count < 5; ++count)
	{
		printf("정수 입력 : ");
		scanf("%d",&arr[count]);
	}
	printf("5개 정수 평균 : %f\n",(float)(arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5);
}
*/

/*
/////////본인의 영문이름을 입력받아 출력하는 프로그램
void main()
{
	char name[20];
	
	scanf("%s",&name[0]);
	printf("Full Name = %s \n",name);
}
*/



/*
////////성과 이름을 입력받아 제3의 문자열로 출력하기
void main()
{
	char first[10];
	char last[10];
	char full[20];
	int fcount = 0;
	int lcount = 0;

	printf("First Name을 입력하시오 : ");
	scanf("%s",&first[0]);
	printf(" Last Name을 입력하시오 : ");
	scanf("%s",&last[0]);

	while(first[fcount]!=0)
	{
		full[fcount]=first[fcount];
		fcount++;
	}
	full[fcount++] = ',';
	full[fcount++] = ' ';
	while(last[lcount]!=0)
	{
		full[fcount]=last[lcount];
		fcount++;
		lcount++;
	}
	full[fcount] = '\0';

	printf("Full Name = %s \n",full);
}
*/



/*
///////////src에 문자열을 입력받고 dest에는 문자열을 뒤집어서 집어 넣고 회문인지 아닌지 출력할 것
void main()
{
	char src[30];
	char dest[30];
	int Scount,count;
	int result = 0;

	printf("문자열을 입력하거라 : ");
	scanf("%s",&src[0]);

	for(Scount = 0; src[Scount]!=0; ++Scount);	//문자열 길이 카운트
	for(count = 0; count<Scount; ++count)
		dest[Scount-(count+1)] = src[count];
	dest[count] = '\0';	//뒤집은 문자열 완성

	for(Scount=0; src[Scount]!='\0'; ++Scount)	//문자열의 동일한 문자 카운트
	{
		if(dest[Scount] == src[Scount])
			result++;
	}

	if(result==count)	//문자열 길이와 카운트값 비교
		printf("%s는 회문입니다.\n",src);
	else
		printf("%s는 회문이 아닙니다.\n",src);
	
	printf("src = %s\ndest = %s\n", src,dest); //출력확인용
}
*/

/*
void inprint(char input, int scount)
{
	int incount;
	for(incount = 0; incount<scount; ++incount)
		printf("%c",input);
	printf("\n");
}

void main()
{
	char keyin;
	int count;

	while(1)
	{
		printf("문자를 입력해보거라 : ");
		scanf("%c",&keyin);
		if(keyin=='q')
			break;
		printf("정수를 입력해보거라 : ");
		scanf("%d", &count);
		fflush(stdin);		//Enter 입력을 지우기 위한 명령어
		inprint(keyin,count);
	}
}
*/




