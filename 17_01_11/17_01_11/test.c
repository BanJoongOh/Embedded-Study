/*

typedef struct
{
	char title[30];
	double cal;
	int weight;
}CANDY;

CANDY snack;
snack.title = "�����";(X,������ ����� ���� �Ұ���)
-> scanf("%s",snack.title); //(O, �ּҿ� �����Ͽ� �Է¹޴°� ����)

�����迭 = ����� ���ÿ� �ʱ�ȭ����
�����迭 = ����� ���ÿ� �ʱ�ȭ�Ұ���, �̸��� ���� ������ heap�� �ּҸ��� ��ȯ��
	CANDY* ptr = (CANDY*)malloc(sizeof(CANDY)*3);


1. �����Լ������� ����ü�� �ּҸ� �Ű������� �������
	CANDY snack;
	insert(&snack);
	insert(CANDY* ptr)
	{
		ptr->title[0] = 'a';
	}
2. �����Լ������� ����ü�迭�� �ּҸ� �Ű������� �������
	CANDY snack[3];
	insert(snack);
	insert(CANDY* ptr)
	{
		ptr[0].title[0] = 'a'; //(*(ptr+0)).title[0] == ptr->title[0]	(�Ѵ� ��������)
	}

- Const ������ �ַ� �����Ͱ� �Ű������϶� ��
	const char* ps = &ch;	//����Ű�� �ּҸ� ������ �� ������, ���� ���� �Ұ���
		*ps = 'K'	//(X)	//�ּҳ��� ���� ������ �� ����
		 ps = &buff	//(O)

	char* const ps = &ch;	//����Ű�� �ּҰ� �����Ǿ� ������, �ּҺ��� ����.
		*ps = 'B'	//(O)
		 ps = &buff	//(X)	//����Ű�� �ּҸ� ������ �� ����
*/




/*

- ����ü+������

	1. ����ü�� ����Ű�� ������
	2. ����ü��������� �����͸� ������ ���� ����ü

typedef struct
{
	char name[30];
	int age;
	double score;
	int* ptr;
}STU;

int temp = 5;
STU person = {"ȫ�浿", 30, 93.5, &temp};
*(person.ptr) = 10;//person.ptr�� �ּ���!

*/



/*

typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* ptr;	//�ڱ�����������
}STU;

*/








#include <stdio.h>
#include <stdlib.h>

#if 0

#define SLEN 30
typedef struct
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
}STU;

int getinfo(STU* gptr, int num);
void display1(STU dps);				//����ü�� �Ű�������
void display2(STU* dptr);			//����ü�� �ּҸ� �Ű�������
void display3(STU* dpa, int num);	//����ü �迭�� ù��° ������ �ּҿ� �迭�� ���Ҽ�

void main()
{
	int class_size,enter,count;
	STU* ptr_stu;
	printf("�л� ���� �Է��Ͻÿ� : ");
	scanf("%d",&class_size);
	ptr_stu = (STU*)malloc(sizeof(STU)*class_size);
	
	enter = getinfo(ptr_stu, class_size);
	for(count = 0; count<enter; ++count)
	{
		display1(ptr_stu[count]);
		display2(&ptr_stu[count]);
	}
	display3(ptr_stu, enter);
	printf("���α׷� ����.\n");
	free(ptr_stu);
}

int getinfo(STU* gptr, int num)
{
	int count,keyin;
	for(count = 0; count<num; ++count)
	{
		printf("%d�� �л��� �̸��� �Է��Ͻÿ� : ",count+1);
		scanf("%s",gptr[count].fullname);
		printf("%d�� �л��� ��̸� �Է��Ͻÿ� : ",count+1);
		scanf("%s",gptr[count].hobby);
		printf("%d�� �л��� ������ �Է��Ͻÿ� : ",count+1);
		scanf("%d",&gptr[count].ooplevel);
		printf("\t������� : 0, ��� : 1 ");
		scanf("%d",&keyin);
		if(keyin==0)
			break;
	}
	return count;
}

void display1(STU dps)
{
	printf("\tdisplay1 �Լ� ����\n");
	printf("�л��� �̸� : %s\n",dps.fullname);
	printf("�л��� ��� : %s\n",dps.hobby);
	printf("�л��� ���� : %d\n",dps.ooplevel);
}
void display2(STU* dptr)
{
	printf("\tdisplay2 �Լ� ����\n");
	printf("�л��� �̸� : %s\n",dptr->fullname);
	printf("�л��� ��� : %s\n",dptr->hobby);
	printf("�л��� ���� : %d\n",dptr->ooplevel);
}
void display3(STU* dpa, int num)
{
	int count;
	printf("\tdisplay3 �Լ� ����\n");
	for(count = 0; count<num; ++count)
	{
		printf("\t%d��° �л��� �̸� : %s\n",count+1,dpa[count].fullname);
		printf("\t%d��° �л��� ��� : %s\n",count+1,dpa[count].hobby);
		printf("\t%d��° �л��� ���� : %d\n",count+1,dpa[count].ooplevel);
	}
}


#endif



#if 0
typedef struct
{
	char name[30];
	int age;
	double score;
	int* ptr;
}STU;

void display(STU* dptr);
void main()
{
	int temp = 5;
	STU person = {"ȫ�浿", 30, 93.5, &temp};

	printf("     person�� �ּ� : %p\n",&person);
	printf("person.name�� �ּ� : %p\n",person.name);
	printf("�̸� : %s\n",person.name);
	printf("���� : %d\n",person.age);
	printf("���� : %lf\n",person.score);
	printf("���� : %d\n",*(person.ptr));
	display(&person);
}

void display(STU* dptr)
{
	printf("\tdisplay�Լ� ����\n");
	printf("�̸� : %s\n",dptr->name);	//����ü ������ �ּҷ� �޾ұ� ������ �������ٿ�����(->)�� ���
	printf("���� : %d\n",dptr->age);
	printf("���� : %lf\n",dptr->score);
	printf("���� : %d\n",*(dptr->ptr));
}
#endif



#if 0
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

void main()
{
	STU* ptr;
	STU p1,p2,p3;
	int count;
	ptr = &p1;

	printf("1�� �̸� �Է� : ");
	scanf("%s",p1.name);
	p1.age = 25;
	p1.score = 3.45;
	p1.link = &p2;

	printf("2�� �̸� �Է� : ");
	scanf("%s",p2.name);
	p2.age = 26;
	p2.score = 3.62;
	p2.link = &p3;

	printf("3�� �̸� �Է� : ");
	scanf("%s",p3.name);
	p3.age = 27;
	p3.score = 3.78;
	p3.link = NULL;
	
	for(count = 0; count<3; ++count)// == while(ptr!=NULL)
	{
		printf("%d�� �̸� : %s\n",count+1,ptr->name);				//�ּҸ� �޾ұ� ������ �������ٿ�����
		printf("%d�� ���� : %d\n",count+1,ptr->age);			
		printf("%d�� ���� : %.1lf\n",count+1,ptr->score);	
		ptr = ptr->link;	//link�� ������ ����ϴ°� ��ȿ������
	}
}
#endif



/*	1. �Է� 2. ��� 3. ���� ������ �޴�
		�Է½ÿ� insert()�Լ�ȣ��
			insert�Լ������� STU ����ü��ŭ �����Ҵ��Ͽ� �޸𸮸� Ȯ���ϰ� ������ ������ ����
		����Լ������� ������ �Է¸�ŭ ������� ��
*/
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

STU* insert(int* num);
void display(STU* pastptr, int* num);
void main()
{
	int keyin=0;
	int count=0;
	int flag=0;
	int temp;
	STU* pasttemp = NULL;
	STU* pretemp = NULL;
	STU* start = NULL;
	while(keyin!=3)
	{
		printf("1. �Է�\t2. ���\t3.���� : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	if(!flag)
					{
						pasttemp = insert(&count);
						start = pasttemp;
						flag=1;
					}
					else
					{
						pretemp = insert(&count);
						pasttemp->link = pretemp;
						pasttemp = pretemp;
					}
					break;
		case 2 :	display(start, &count);
					break;
		case 3 :	printf("�����մϴ� ^^.\n");
					for(temp = 0; temp<count; ++temp)
					{
						pretemp = start->link;
						free(start);
						start = pretemp;
					}
					break;
		default :	printf("�ȹٷ� �Է��ϰŶ�.!\n");
					break;
		}
	}
}

STU* insert(int* num)
{
	STU* ptr;
	printf("%d��° �Է��Դϴ�.\n",(*num)+1);
	ptr = (STU*)malloc(sizeof(STU));
	printf("%d��° �̸� �Է� : ",(*num)+1);
	scanf("%s",ptr->name);			//heap�� �ּҸ� ����Ű�� ������ �������ٿ����� ���
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%d",&ptr->age);
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%lf",&ptr->score);
	(*num)++;
	return ptr;	//ptr��ü�� heap�� �����ּҸ� ����Ŵ
}

void display(STU* pastptr, int* num)
{
	int count;
	printf("\tdisplay�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %10s    ",count+1,pastptr->name);
		printf("%d��° ���� : %5d    ",count+1,pastptr->age);
		printf("%d��° ���� : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link;
	}
}



#if 0
////////////////////////////������ ���
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

STU* insert(STU* pastptr, int* num);
void display(STU* pastptr, int* num);
void main()
{
	int keyin=0;
	int count=0;
	STU* temp = NULL;
	while(keyin!=3)
	{
		printf("1. �Է�\t2. ���\t3.���� : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	temp = insert(temp, &count);
					break;
		case 2 :	display(temp, &count);
					break;
		case 3 :	printf("�����մϴ� ^^.\n");
					break;
		default :	printf("�ȹٷ� �Է��ϰŶ�.!\n");
					break;
		}
	}
}

STU* insert(STU* pastptr, int* num)
{
	STU* ptr;
	printf("%d��° �Է��Դϴ�.\n",(*num)+1);
	ptr = (STU*)malloc(sizeof(STU));
	printf("%d��° �̸� �Է� : ",(*num)+1);
	scanf("%s",ptr->name);			//heap�� �ּҸ� ����Ű�� ������ �������ٿ����� ���
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%d",&ptr->age);
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%lf",&ptr->score);
	ptr->link = pastptr;
	(*num)++;
	return ptr;	//ptr��ü�� heap�� �����ּҸ� ����Ŵ
}

void display(STU* pastptr, int* num)
{
	int count;
	printf("\tdisplay�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %s\t",(*num)-count,pastptr->name);
		printf("%d��° ���� : %d\t\t",(*num)-count,pastptr->age);
		printf("%d��° ���� : %.1lf\t",(*num)-count,pastptr->score);
		printf("\n");
		pastptr = pastptr->link;
	}
}

#endif



