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
	printf("���� �� : %d", line);

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

	printf("�޴��� �����ϰŶ�\n1. �� �� �߰�  2. ����  3. ����  4. ���� : ");
	scanf("%d", &select);
	
	while(select != 4)
	{
		switch (select)
		{
		case 1:
			printf("�� �ڿ� �߰��� ���ڿ� �Է� : ");
			scanf("%s", buf);
			add(&ptr[line-1], buf, &line);
			break;
		case 2:
			printf("������ ��ġ : ");
			scanf("%d", &temp);
			printf("������ ���ڿ� : ");
			scanf("%s", buf);
			modify(&ptr[temp-1], buf);
			break;
		case 3:
			printf("������ ��ġ : ");
			scanf("%d", &temp);
			junk(&ptr[temp-1], &ptr[temp-2], &ptr[temp], temp);
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
	/*
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





