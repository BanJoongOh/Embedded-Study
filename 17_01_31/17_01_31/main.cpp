/*

FILE 스트림
	- 문자 단위로 읽는 함수
		getc(), getchar(), fgetc(FILE *)
	- 문자 단위로 쓰는 함수
		putc(char c), fputc(char c, FILE *)
	- 문자열(한줄씩) 읽는 함수
		gets() : 표준 입력, fgets() : 지정한 스트림
	- 문자열(한줄씩) 쓰는 함수
		puts() : 표준 출력, fputs() : 지정한 스트림
	
printf 함수 포맷
	int _cdecl printf(const char *c, ...)	//...은 가변인자;
		* 함수호출규약 : 함수가 사용할 stack 메모리 관리를 누가 할지를...(cdecl도 그 중 하나)

	cdecl은 안정적이지만 속도가 느림
		
Stack의 종류
	EA, ED, FA, FD -> 이 중 C의 표준은 FD임
	Empty Stack은 SP가 빈 곳을 가리키기 때문에 바로 push가능 - Full Stack은 SP가 채운 곳을 가리킴
	SP를 크기만큼 증가시키고 순차적으로 데이터를 채워넣음(SP+0 , SP+4, SP+8)


*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void main()
{
	int ch;
	char buf[255];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	fp2 = fopen("../17_01_31/a.txt", "w");
	puts("메세지를 입력하거라");

	while ((ch = getchar()) != '\n')
	{
		fputc(ch, fp2);			// ../17_01_31/a.txt 에 입력한 내용으로 생성
	}

	fp1 = fopen("../17_01_31/a.txt", "r");

	if (fp1 == NULL)
	{
		printf("files open error\n");
		exit(-1);
	}
	
	while ((ch = fgetc(fp1)) != EOF)	// EOF는 -1을 의미하며 파일의 끝
	{
		putc(ch, stdout);	// 문자를 하나씩 읽어서 콘솔에 출력
	}
}
#endif


#if 0
void main()
{
	int ch;
	char buf[255];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	fp2 = fopen("../17_01_31/a.txt", "w");
	puts("메세지를 입력하거라");

	while (strncmp("end", buf, 3))	// 3개의 문자인 end 문자열과 비교하여 반복
	{
		gets_s(buf);	// 엔터를 제외한 문자열을 저장
		fputs(buf, fp2);
		fputs("\n", fp2);
	}
	fclose(fp2);

	fp1 = fopen("../17_01_31/a.txt", "r");

	if (fp1 == NULL)
	{
		printf("files open error\n");
		exit(-1);
	}

	while (fgets(buf, 255, fp1) != NULL)	// 255-1개의 문자를 읽음(엔터가 입력되기전까지)
	{
		//puts(buf);
		printf("%s", buf);
	}
	fclose(fp1);
}
#endif


#if 0
int add(int c, ...);
void main()
{
	printf("%d \n", add(5, 1, 2, 3, 4, 5));
}

int add(int c, ...)	// SP에 할당된 가변인자들을 int c 기준, 주소를 이용하여 순차적 접근
{
	int sum = 0;
	for (int count = 0; count < c; ++count)
		sum += *(&c + count);
	return sum;
}
#endif

/*
- 문자 단위로 읽는 함수
getc(), getchar(), fgetc(FILE *)
- 문자 단위로 쓰는 함수
putc(char c), fputc(char c, FILE *)
- 문자열(한줄씩) 읽는 함수
gets() : 표준 입력, fgets() : 지정한 스트림
- 문자열(한줄씩) 쓰는 함수
puts() : 표준 출력, fputs() : 지정한 스트림
*/
/////////////////////////linked list로 파일 읽고 쓰기
///////////////////////// 1. 맨뒤 추가, 2. 수정, 3. 삭제, 4. 종료

typedef struct one
{
	char st[255];
	struct one* link1;
}TEXT;

void add(TEXT *Aptr, const char* Ach, int *Aline);
void modify(TEXT *Mptr, const char* Mch);
void junk(TEXT *Jptr1, TEXT *Jptr2, TEXT *Jptr3, int Jnum);
void main()
{
	int ch,select,temp;
	int line = 0;
	char flag = 1;
	char buf[255];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	TEXT *start = NULL;
	TEXT *past = NULL;

	fp2 = fopen("../17_01_31/a.txt", "rt");
	
	if (fp2 == NULL)
	{
		printf("file open error");
		exit(-1);
	}

	while (!feof(fp2))
	{
		fgets(buf, 255, fp2);
		line++;
	}
	printf("라인 수 : %d", line);

	TEXT *ptr = (TEXT*)malloc(sizeof(TEXT)*line);

	for (int count=0; count<line; ++count)
	{
		fgets(buf, 255, fp2);
		strcpy(ptr[count].st, buf);
		if (flag!=line)
		{
			ptr[count].link1 = &ptr[count + 1];
			flag++;
		}
	}

	printf("메뉴를 선택하거라\n1. 맨 뒤 추가  2. 수정  3. 삭제  4. 종료 : ");
	scanf("%d", &select);
	
	while(select != 4)
	{
		switch (select)
		{
		case 1:
			printf("맨 뒤에 추가할 문자열 입력 : ");
			scanf("%s", buf);
			add(&ptr[line-1], buf, &line);
			break;
		case 2:
			printf("수정할 위치 : ");
			scanf("%d", &temp);
			printf("수정할 문자열 : ");
			scanf("%s", buf);
			modify(&ptr[temp-1], buf);
			break;
		case 3:
			printf("삭제할 위치 : ");
			scanf("%d", &temp);
			junk(&ptr[temp-1], &ptr[temp-2], &ptr[temp], temp);
			break;
		case 4:
			printf("종료합니다.\n");
			break;
		default:
			printf("1-4 중에 하나만 입력하거라\n");
			break;
		}
		printf("메뉴를 선택하거라\n1. 맨 뒤 추가  2. 수정  3. 삭제  4. 종료 : ");
		scanf("%d", &select);
	}
	/*
	while ((ch = getchar()) != '\n')
	{
		fputc(ch, fp2);			// ../17_01_31/a.txt 에 입력한 내용으로 생성
	}

	fp1 = fopen("../17_01_31/a.txt", "r");

	if (fp1 == NULL)
	{
		printf("files open error\n");
		exit(-1);
	}

	while ((ch = fgetc(fp1)) != EOF)	// EOF는 -1을 의미하며 파일의 끝
	{
		putc(ch, stdout);	// 문자를 하나씩 읽어서 콘솔에 출력
	}
	*/
}

void add(TEXT *Aptr, const char* Ach, int *Aline)
{
	TEXT *temp = (TEXT*)malloc(sizeof(TEXT));
	strcpy(temp->st, Ach);
	*Aline++;
	Aptr->link1 = temp;
}
void modify(TEXT *Mptr, const char* Mch)
{
	strcpy(Mptr->st, Mch);
}
void junk(TEXT *Jptr1, TEXT *Jptr2, TEXT *Jptr3, int Jnum)
{
	Jptr1->link1 = Jptr3;
	delete Jptr2;
}





