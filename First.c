/*

프로그램 메모리 = Rom -> Flash로 변함(Rom Writer가 비싸고 데이터를 쓰기 불편하기때문)
  데이터 메모리 = Ram
Q1 : 객체 지향의 특징을 설명하시오,
	*어셈블리어는 CPU마다 달라서 이식성이 좋지않음

*/

/*
#include <stdio.h>	// std : 표준, io : 입/출력 
					// Header : 함수원형을 정의
					// stdio.h = iostream.h = iostream

void main() // main : 프로그램의 시작(예약어) -> main 함수는 운영체제가 호출(0:정상/-1:비정상)
{
	printf("C++의 세계로 \n후회 \n"); // Body : 함수의 수행(실행)문을 정의
}
*/

/*

함수호출(전달인자), 함수정의(매개변수)
"문자열", '문자상수'
서식문자 : %p : 포인터(주소)

*/



#include <stdio.h>	//# : 전처리기(컴파일전에)
  
void main()
{
	char age = 25;
	float score = 3.000;
	double *pw;
	printf("이름 : 반중오 \n");
	printf("주소 : 김포어딘가\n");
	printf("나이 : %d\n",age);
	printf("학점 : %.2f\n",score);	//.2f = 소수점 2자리까지!
	printf("double size = %d\n",sizeof(pw));
}


/*
변수 : 임의의 데이터를 저장하기위해 할당한 메모리 공간
자료형 char(1), short(2), int(4), long(4), float(4), double(8) ##intel PC 기준
sizeof연산자 : sizeof(자료형)

* 데이터 단위 : bit - nibble - byte - word - long


*/











































































