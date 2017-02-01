/*

FILE ��Ʈ��
	- ���� ������ �д� �Լ�
		getc(), getchar(), fgetc(FILE *)
	- ���� ������ ���� �Լ�
		putc(char c), fputc(char c, FILE *)
	- ���ڿ�(���پ�) �д� �Լ�
		gets() : ǥ�� �Է�, fgets() : ������ ��Ʈ��
	- ���ڿ�(���پ�) ���� �Լ�
		puts() : ǥ�� ���, fputs() : ������ ��Ʈ��
	
printf �Լ� ����
	int _cdecl printf(const char *c, ...)	//...�� ��������;
		* �Լ�ȣ��Ծ� : �Լ��� ����� stack �޸� ������ ���� ������...(cdecl�� �� �� �ϳ�)

	cdecl�� ������������ �ӵ��� ����
		
Stack�� ����
	EA, ED, FA, FD -> �� �� C�� ǥ���� FD��
	Empty Stack�� SP�� �� ���� ����Ű�� ������ �ٷ� push���� - Full Stack�� SP�� ä�� ���� ����Ŵ
	SP�� ũ�⸸ŭ ������Ű�� ���������� �����͸� ä������(SP+0 , SP+4, SP+8)


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
	puts("�޼����� �Է��ϰŶ�");

	while ((ch = getchar()) != '\n')
	{
		fputc(ch, fp2);			// ../17_01_31/a.txt �� �Է��� �������� ����
	}

	fp1 = fopen("../17_01_31/a.txt", "r");

	if (fp1 == NULL)
	{
		printf("files open error\n");
		exit(-1);
	}
	
	while ((ch = fgetc(fp1)) != EOF)	// EOF�� -1�� �ǹ��ϸ� ������ ��
	{
		putc(ch, stdout);	// ���ڸ� �ϳ��� �о �ֿܼ� ���
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
	puts("�޼����� �Է��ϰŶ�");

	while (strncmp("end", buf, 3))	// 3���� ������ end ���ڿ��� ���Ͽ� �ݺ�
	{
		gets_s(buf);	// ���͸� ������ ���ڿ��� ����
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

	while (fgets(buf, 255, fp1) != NULL)	// 255-1���� ���ڸ� ����(���Ͱ� �ԷµǱ�������)
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

int add(int c, ...)	// SP�� �Ҵ�� �������ڵ��� int c ����, �ּҸ� �̿��Ͽ� ������ ����
{
	int sum = 0;
	for (int count = 0; count < c; ++count)
		sum += *(&c + count);
	return sum;
}
#endif

/*
- ���� ������ �д� �Լ�
getc(), getchar(), fgetc(FILE *)
- ���� ������ ���� �Լ�
putc(char c), fputc(char c, FILE *)
- ���ڿ�(���پ�) �д� �Լ�
gets() : ǥ�� �Է�, fgets() : ������ ��Ʈ��
- ���ڿ�(���پ�) ���� �Լ�
puts() : ǥ�� ���, fputs() : ������ ��Ʈ��
*/
/////////////////////////linked list�� ���� �а� ����
///////////////////////// 1. �ǵ� �߰�, 2. ����, 3. ����, 4. ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////linked list�� ���� �а� ����
///////////////////////// 1. �ǵ� �߰�, 2. ����, 3. ����, 4. ����

/*
typedef struct one
{
char st[255];
int num;
struct one* link;
}TEXT;

TEXT* insert(TEXT* pastptr, int* num);
void display(TEXT* pastptr, int* num);

void main()
{
int keyin=0;
int count=0;
TEXT* temp = NULL;
FILE *fp1 = NULL;
FILE *fp2 = NULL;

fp2 = fopen("../17_01_31/a.txt", "rt");


//   while (!feof(fp2))
//   {
//      fgets(buf, 255, fp2);
//      line++;
//   }
//   printf("���� �� : %d", line);

//   TEXT *ptr = (TEXT*)malloc(sizeof(TEXT)*line);

//   for (int count=0; count<line; ++count)
//   {
//      fgets(buf, 255, fp2);
//      strcpy(ptr[count].st, buf);
//      if (flag!=line)
//      {
//         ptr[count].link1 = &ptr[count + 1];
//         flag++;
//      }
//   }

while(keyin!=3)
{
printf("�޴��� �����ϰŶ�\n1. �� �� �߰�  2. ����  3. ����  4. ���� : ");
scanf("%d",&keyin);
switch(keyin)
{
case 1 :   temp = insert(temp, &count);
break;
case 2 :   display(temp, &count);
break;
case 3 :   printf("�����մϴ� ^^.\n");
break;
default :   printf("�ȹٷ� �Է��ϰŶ�.!\n");
break;
}
}
}

TEXT* insert(TEXT* pastptr, int* num)
{
TEXT* ptr;
printf("%d��° �Է��Դϴ�.\n",(*num)+1);
ptr = (TEXT*)malloc(sizeof(TEXT));
printf("%d��° ���ڿ� : ",(*num)+1);
scanf("%s",ptr->st);         //heap�� �ּҸ� ����Ű�� ������ �������ٿ����� ���
printf("%d��° ���� : ",(*num)+1);
ptr->num = (*num)+1;
ptr->link = pastptr;
(*num)++;
return ptr;   //ptr��ü�� heap�� �����ּҸ� ����Ŵ
}

void display(TEXT* pastptr, int* num)
{
int count;
printf("\tdisplay�Լ� ���� \n");
for(count = 0; count<(*num); ++count)
{
printf("%d��° ���ڿ� : %s\t",(*num)-count,pastptr->st);
printf("%d��° ���� : %d\t\t",(*num)-count,pastptr->num);
printf("\n");
pastptr = pastptr->link;
}
}

*/


typedef struct one
{
	char st[255];
	struct one* link1;
}TEXT;

TEXT* add(TEXT *Aptr, const char* Ach, int *Aline);
void modify(TEXT *Mptr, const char* Mch);
void junk(TEXT *Jptr1, TEXT *Jptr2, TEXT *Jptr3, int Jnum);
int linecount();
void main()
{
	int ch, select, temp;
	int line = 0;
	char flag = 1;
	char buf[255];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	TEXT *start = NULL;
	TEXT *past = NULL;
	TEXT *Slink = NULL;

	line = linecount();
	TEXT *ptr = (TEXT*)malloc(sizeof(TEXT)*line);

	fp2 = fopen("../17_01_31/a.txt", "r");
	if (fp2 == NULL)
	{
		printf("file open error");
		exit(-1);
	}

	start = &ptr[0];   // ���� �ּ�
	past = &ptr[line - 1];// �� ������ �ּ�
	for (int count = 0; count<line; ++count)
	{
		fgets(buf, 255, fp2);
		strcpy(ptr[count].st, buf);
		if (count < line - 1)
			ptr[count].link1 = &ptr[count + 1];
	}
	flag = line;

	printf("�޴��� �����ϰŶ�\n1. �� �� �߰�  2. ����  3. ����  4. ���� : ");
	scanf("%d", &select);

	while (select != 4)
	{
		switch (select)
		{
		case 1:
			printf("�� �ڿ� �߰��� ���ڿ� �Է� : ");
			scanf("%s", buf);
			past = add(past, buf, &line);
			break;
		case 2:
			printf("������ ��ġ : ");
			scanf("%d", &temp);
			printf("������ ���ڿ� : ");
			scanf("%s", buf);
			modify(&ptr[temp - 1], buf);
			break;
		case 3:
			printf("������ ��ġ : ");
			scanf("%d", &temp);
			junk(&ptr[temp - 1], &ptr[temp - 2], &ptr[temp], temp);
			break;
		case 4:
			printf("�����մϴ�.\n");
			break;
		default:
			printf("1-4 �߿� �ϳ��� �Է��ϰŶ�\n");
			break;
		}
		printf("�޴��� �����ϰŶ�\n1. �� �� �߰�  2. ����  3. ����  4. ���� : ");
		scanf("%d", &select);
	}

	fp1 = fopen("../17_01_31/a.txt", "w");
	Slink = start;
	for (int count = 0; count < line; ++line)
	{
		fprintf(fp1, Slink->st);
		printf("test : %s", Slink->st);
		if (count + 1 == line)
			break;
		Slink = Slink->link1;
	}
	free (ptr);
}
 
TEXT* add(TEXT *Aptr, const char* Ach, int *Aline)
{
	TEXT *temp = (TEXT*)malloc(sizeof(TEXT));
	strcpy(temp->st, Ach);
	*Aline++;
	Aptr->link1 = temp;
	return temp;
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

int linecount()
{
	int line = 0;
	char buf[255];
	FILE *fp = NULL;
	fp = fopen("../17_01_31/a.txt", "rt");

	if (fp == NULL)
	{
		printf("file open error");
		exit(-1);
	}

	while (!feof(fp))
	{
		fgets(buf, 255, fp);
		line++;
	}
	fclose(fp);
	printf("���� �� : %d\n", line);

	return line;
}