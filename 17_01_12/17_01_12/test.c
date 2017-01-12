
#include <stdio.h>
#include <stdlib.h>
/*	1. 입력		2. 출력		3. 수정		4.삭제		5.종료 
		입력시에 insert()함수호출
			insert함수에서는 STU 구조체만큼 동적할당하여 메모리를 확보하고 임의의 데이터 저장
		출력함수에서는 누적된 입력만큼 출력해줄 것

		#추가기능 : 수정 및 삭제
		->2개의 link 그리고 더블포인터로 구현
*/
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link1;
	struct student* link2;
}STU;

void insert(int* num, STU** start, STU** pasttemp);	//추가 구조체저장
void display1(STU* pastptr, int* num);				//정방향 출력
void display2(STU* pastptr, int* num);				//역방향 출력
void modify(STU* modiptr, int* num);				//구조체 수정
void deletedata(STU** delstart, STU** delpast, int* num);	//해당 이름의 구조체 삭제
void main()
{
	int keyin=0;
	int count=0;
	int temp;
	int modeselect=0;
	STU* pasttemp = NULL;
	STU* start = NULL;
	while(keyin!=5)
	{
		printf("1. 입력\t\t2. 출력\t\t3. 수정\t\t4. 삭제\t\t5. 종료 : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	insert(&count,&start,&pasttemp);
					break;
		case 2 :	while(modeselect!=3)
					{
						printf("\t<출력모드 선택>\n\t1. 정방향출력\t2. 역방향출력\t3. 이전메뉴 : ");
						scanf("%d",&modeselect);
						if(modeselect==1)
							display1(start, &count);	//정방향 출력을 위해 시작구조체의 주소를 받아줌
						else if(modeselect==2)
							display2(pasttemp, &count);	//역방향 출력을 위해 마지막구조체의 주소를 받아줌
						else	
							printf("\t이전메뉴로 돌아갑니다 \n");	//3또는 그외의 입력
					}
					modeselect=0;//mode 초기화
					break;
		case 3 :	modify(start, &count);
					break;
		case 4 :	deletedata(&start,&pasttemp,&count);
					break;
		case 5 :	printf("종료합니다 ^^.\n");
					for(temp = 0; temp<count; ++temp)	//구조체의 수만큼 메모리를 비움
					{
						pasttemp = start->link1;
						free(start);
						start = pasttemp;
					}
					break;
		default :	printf("1~5의 숫자만을 똑바로 입력하시오.!\n");
					break;
		}
		printf("\n");
	}
}

void insert(int* num, STU** instart, STU** inpasttemp)
{
	STU* temp;
	printf("\t%d번째 입력입니다.\n",(*num)+1);
	temp = (STU*)malloc(sizeof(STU));

	printf("%d번째 이름 입력 : ",(*num)+1);
	scanf("%s",temp->name);			//heap의 주소를 가리키기 때문에 간접접근연산자 사용
	printf("%d번째 나이 입력 : ",(*num)+1);
	scanf("%d",&temp->age);
	printf("%d번째 점수 입력 : ",(*num)+1);
	scanf("%lf",&temp->score);

	temp->link2 = (*inpasttemp);	//역방향 출력을 위해 새로운 구조체의 링크를 이전주소를 가리킴
	if((*num)==0)	//start주소를 담기 위한 조건
	{
		*instart = temp;
		*inpasttemp = temp;
	}
	else	//정방향 출력을 위해 이전구조체의 링크로 새로운구조체의 주소를 가리킴
	{
		(*inpasttemp)->link1 = temp;
		(*inpasttemp) = temp;
	}
	(*num)++;	//구조체의 수 증가
}

void display1(STU* pastptr, int* num)
{
	int count;
	printf("\t\t정방향 display함수 진입 \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d번째 이름 : %10s    ",count+1,pastptr->name);
		printf("%d번째 나이 : %5d    ",count+1,pastptr->age);
		printf("%d번째 점수 : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link1;	//정방향을 위해 link1의 주소를 계속 refresh해줌
	}
	printf("\n");
}

void display2(STU* pastptr, int* num)
{
	int count;
	printf("\t\t역방향 display함수 진입 \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d번째 이름 : %10s    ",count+1,pastptr->name);
		printf("%d번째 나이 : %5d    ",count+1,pastptr->age);
		printf("%d번째 점수 : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link2;	//역방향을 위해 link1의 주소를 계속 refresh해줌
	}
	printf("\n");
}

void modify(STU* modiptr, int* num)
{
	int count,alpha,length,flag;
	char search[30];
	printf("\tmodify 함수 진입 \n");
	printf("\t검색할 이름을 입력하시오 : ");
	scanf("%s",search);
	printf("\tSearching...\n");
	for(count = 0; count<(*num); ++count)
	{
		for(length = 0; modiptr->name[length]!='\0'; ++length);	//문자열을 비교하기전에 길이를 확인!
		for(alpha = 0; modiptr->name[alpha]!='\0'; ++alpha)
		{
			if(modiptr->name[alpha] == search[alpha])
				length--;
		}
		printf("%d번째 이름 : %10s    ",count+1,modiptr->name);
		if(!length)		//모든 문자가 일치할 경우
		{
			printf("일치하는 이름을 찾았습니다!\n");
			break;
		}
		modiptr = modiptr->link1;
		printf("\n");
	}
	printf("수정하시겠습니까? (yes : 1, No : 0) : ");
	scanf("%d",&flag);
	if(flag)
	{
		printf("기존 이름은 %10s 입니다.\t 새로운 이름 : ",modiptr->name);
		scanf("%s",modiptr->name);
		printf("기존 나이는 %10d 입니다.\t 새로운 나이 : ",modiptr->age);
		scanf("%d",&modiptr->age);
		printf("기존 점수는 %10.1lf 입니다.\t 새로운 점수 : ",modiptr->score);
		scanf("%lf",&modiptr->score);
	}
}

void deletedata(STU** delstart, STU** delpast, int* num)	//첫번째,마지막을 가리키는 주소가 바뀔 수 있기에 더블포인터 사용
{
	int count,alpha,length,flag;
	STU* temp = *delstart;	//주소 임시저장용
	char search[30];
	printf("\tdeletedata 함수 진입 \n");
	printf("\t검색할 이름을 입력하시오 : "); 
	scanf("%s",search);
	printf("\tSearching...\n");
	for(count = 0; count<(*num); ++count)
	{
		for(length = 0; temp->name[length]!='\0'; ++length);	//문자열을 비교하기전에 길이를 확인!
		for(alpha = 0; temp->name[alpha]!='\0'; ++alpha)
		{
			if(temp->name[alpha] == search[alpha])
				length--;
		}
		printf("%d번째 이름 : %10s    ",count+1,temp->name);
		if(!length)		//모든 문자가 일치할 경우
		{
			printf("일치하는 이름을 찾았습니다!\n");
			count++;
			break;
		}
		temp = temp->link1;
		printf("\n");
	}		//count를 이용해서 몇번째의 구조체에 해당하는지 확인
	printf("해당 구조체를 삭제하시겠습니까? (yes : 1, No : 0) : ");
	scanf("%d",&flag);
	if(flag)
	{
		printf("\t해당 구조체의 이름은 %10s 입니다.\t 삭제합니다.\n",temp->name);
		printf("\t해당 구조체의 나이는 %10d 입니다.\t 삭제합니다.\n",temp->age);
		printf("\t해당 구조체의 점수는 %10.1lf 입니다.\t 삭제합니다.\n",temp->score);
		if(count==1)	//첫번째 구조체가 삭제될 경우
		{
			temp->link1->link2 = *delstart;	//두번째 구조체 링크는 Main 구조체 주소를 가리킴
			*delstart = temp->link1;	//두번째 구조체의 주소를 링크를 통해 바꿔줌 
		}
		else if(count==(*num))	//마지막 구조체가 삭제될 경우
			*delpast = temp->link2;	//마지막 구조체의 주소를 링크를 통해 바꿔줌
		else
		{
			temp->link2->link1 = temp->link1;	//링크를 통해 전,후에 해당하는 주소로 변경
			temp->link1->link2 = temp->link2;	//링크를 통해 전,후에 해당하는 주소로 변경
		}
		free(temp);	//삭제된 데이터 메모리 비우기
		(*num)--;	//구조체수가 감소
	}
}




