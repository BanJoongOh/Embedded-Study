

#include <stdio.h>

#if 0
////////////Ex 정수5개 입력 후 합,평균 출력
void main()
{
	int count,keyin;
	double sum=0;
	for(count = 0; count<5; ++count)
	{
		printf("정수 입력 : ");
		scanf("%d",&keyin);
		sum+=keyin;
	}
	printf("입력의 합 : %.0f, 입력의 평균 : %.2f\n",sum,sum/5);//강제 형변환 -> (double)sum/5
	// 대입연산자를 쓸때는 양쪽의 자료형을 동일하게 할 것!
}
#endif


#if 0
/////////////Ex 두 정수와 그 사이의 합
void main()
{
	int keyin1,keyin2,count;
	int sum = 0;
	printf("정수를 입력하시오 : ");
	scanf("%d",&keyin1);
	printf("정수를 입력하시오 : ");
	scanf("%d",&keyin2);

	for(count = 0; count<keyin2-keyin1+1; ++count)
		sum+=keyin1+count;

	printf("%d와 %d사이의 합은 : %d\n",keyin1, keyin2, sum);
}
#endif


#if 0
void main()
{
	char ch;
	int space = 0;
	int total = 0;

	scanf("%c",&ch);
	while(ch!='.')
	{
		if(ch==' ')
			space++;
		total++;
		scanf("%c",&ch);	//scanf는 주소를 참조해서 값을 넣기때문에 문장을 대입할 수 있음!
	}
	printf("입력한 문자의 수 : %d\n",total);
	printf("입력한 빈칸의 수 : %d\n",space);
}
#endif


#if 0
void main()
{
	int keyin;
	printf("문자를 입력하시오 : ");
	scanf("%d",&keyin);
	while(keyin!=0)
	{
		if(keyin%2==0)
			printf("\t지금 입력한 %d는 짝수입니다.\n",keyin);
		else
			printf("\t지금 입력한 %d는 홀수입니다.\n",keyin);
		printf("문자를 입력하시오 : ");
		scanf("%d",&keyin);
	}
}
#endif

#if 0
// 65~90 대문자, 97~122 소문자
void main()
{
	char keyin;
	printf("문자를 입력하시오 : ");
	scanf("%c",&keyin);
	fflush(stdin);
	if(keyin>64 && keyin<91)
		keyin+=32;
	else if(keyin>96 && keyin<123)
		keyin-=32;

	while(keyin!='.')
	{
		printf("대소문자 변환결과 : %c\n\n",keyin);
		printf("문자를 입력하시오 : ");
		scanf("%c",&keyin);
		fflush(stdin);
		if(keyin>64 && keyin<91)
			keyin+=32;
		else if(keyin>96 && keyin<123)
			keyin-=32;
	}
}
#endif


#if 0
void main()
{
	char choice;
	scanf("%c",&choice);
	fflush(stdin);
	while(choice!='Q' && choice!='q')
	{
		switch(choice)
		{
			case 'a' :
			case 'A' : printf("a를 입력했군\n");
						break;
			case 'r' :
			case 'R' : printf("report호출\n");
						break;
			case 'l' :
			case 'L' : printf("사장님은 회사갔음\n");
						break;

			case 'c' :
			case 'C' : printf("comfort호출\n");
						break;

			default : printf("다른 것을 입력하거라 \n");
		}
		scanf("%c",&choice);
		fflush(stdin);
	}
}
#endif


#if 0
void main()
{
	char choice;
	printf("다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q or Q)\n");
	printf("c) camera	p) pianist \n");
	printf("t) tree		g) game \n");
	scanf("%c",&choice);
	fflush(stdin);
	while(choice!='Q' && choice!='q')
	{
		switch(choice)
		{
			case 'c' :
			case 'C' : printf("카메라 하나 사자\n");
						break;
			case 'p' :
			case 'P' : printf("피아노 배우고싶다\n");
						break;
			case 't' :
			case 'T' : printf("이 책은 나무로 만들었지\n");
						break;

			case 'g' :
			case 'G' : printf("시계한판할까\n");
						break;

			default : printf("c, p, t, g 중에서 하나를 선택하거라.(끝내려면 q or Q) \n");
		}
		scanf("%c",&choice);
		fflush(stdin);
	}
}
#endif



void main()
{
	int kor,eng,math,aver;
	printf("철수의 성적을 입력해보자 \n");
	printf("국어 성적 : ");
	scanf("%d",&kor);
	printf("영어 성적 : ");
	scanf("%d",&eng);
	printf("수학 성적 : ");
	scanf("%d",&math);
	aver = (kor+eng+math)/3;
	if(aver>89)
		printf("철수의 성적의 평균은 : %d이며, 상태는 우수합니다\n",aver);
	else if(aver>59 && aver<90)
		printf("철수의 성적의 평균은 : %d이며, 상태는 양호합니다\n",aver);
	else
		printf("철수의 성적의 평균은 : %d이며, 상태는 노력중입니다\n",aver);
}

































