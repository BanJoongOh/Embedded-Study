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



#if 0
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
#endif



#if 0
////////////////////////////Linked list ������������� ���
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



#if 0
////////////////////////////Linked list ������ + ������������� ���(Heap���� �̿�)
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link;
}STU;

void insert(int* num, STU** start, STU** pasttemp);
void display1(STU* pastptr, int* num);
void display2(STU* pastptr, int* num);
void main()
{
	int keyin=0;
	int count=0;
	int temp;
	int modeselect;
	STU* pasttemp = NULL;
	STU* start = NULL;
	while(keyin!=3)
	{
		printf("1. �Է�\t2. ���\t3.���� : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	insert(&count,&start,&pasttemp);
					break;
		case 2 :	printf("��¸�� ����\n\t1. ���������    2. ���������    3. �����޴� : ");
					scanf("%d",&modeselect);
					if(modeselect==1)
						display1(start, &count);
					else if(modeselect==2)
						display2(start, &count);
					else
						printf("�����޴��Դϴ� \n");
					break;
		case 3 :	printf("�����մϴ� ^^.\n");
					for(temp = 0; temp<count; ++temp)
					{
						pasttemp = start->link;
						free(start);
						start = pasttemp;
					}
					break;
		default :	printf("�ȹٷ� �Է��ϰŶ�.!\n");
					break;
		}
	}
}

void insert(int* num, STU** instart, STU** inpasttemp)
{
	STU* temp;
	printf("%d��° �Է��Դϴ�.\n",(*num)+1);
	temp = (STU*)malloc(sizeof(STU));
	printf("%d��° �̸� �Է� : ",(*num)+1);
	scanf("%s",temp->name);			//heap�� �ּҸ� ����Ű�� ������ �������ٿ����� ���
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%d",&temp->age);
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%lf",&temp->score);
	if((*num)==0)
	{
		*instart = temp;
		*inpasttemp = temp;
	}
	else
	{
		(*inpasttemp)->link = temp;
		(*inpasttemp) = temp;
	}
	(*num)++;
	printf("\n");
}

void display1(STU* pastptr, int* num)
{
	int count;
	printf("\t������ display�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %10s    ",count+1,pastptr->name);
		printf("%d��° ���� : %5d    ",count+1,pastptr->age);
		printf("%d��° ���� : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link;
	}
}

void display2(STU* pastptr, int* num)
{
	int count,charcount;
	STU* temp;
	temp = (STU*)malloc(sizeof(STU)*(*num));	//��ü ����ü ������ŭ �޸� �߰� �Ҵ�
	
	printf("\t������ display�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)		//�Ҵ�� �޸𸮸� �̿��� �����͸� �������� ������
	{
		for(charcount = 0; pastptr->name[charcount]!=0; ++charcount)	//���ڿ� ����
			temp[(*num)-1-count].name[charcount] = pastptr->name[charcount];
		temp[(*num)-1-count].name[charcount] = '\0';	//���ڿ��� ����� ���� NULL���� �߰�
		temp[(*num)-1-count].age = pastptr->age;
		temp[(*num)-1-count].score = pastptr->score;
		pastptr = pastptr->link;
	}
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %10s    ",count+1,temp[count].name);
		printf("%d��° ���� : %5d    ",count+1,temp[count].age);
		printf("%d��° ���� : %5.1lf",count+1,temp[count].score);
		printf("\n");
	}
	free(temp);	//���������� �Ҵ�� heap�� �޸� ����
}

#endif


////////////////////////////Linked list ������+������ 2���� Link ���� -> delete�Ǵ°Ϳ����� Free�� ����� ������
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link1;
	struct student* link2;
}STU;

void insert(int* num, STU** start, STU** pasttemp);
void display1(STU* pastptr, int* num);
void display2(STU* pastptr, int* num);
void modify(STU* modiptr, int* num);
void deletedata(STU** delstart, STU** delpast, int* num);
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
		printf("1. �Է�\t\t2. ���\t\t3. ����\t\t4. ����\t\t5. ���� : ");
		scanf("%d",&keyin);
		switch(keyin)
		{
		case 1 :	insert(&count,&start,&pasttemp);
					break;
		case 2 :	while(modeselect!=3)
					{
						printf("\t<��¸�� ����>\n\t1. ���������\t2. ���������\t3. �����޴� : ");
						scanf("%d",&modeselect);
						if(modeselect==1)
							display1(start, &count);
						else if(modeselect==2)
							display2(pasttemp, &count);
						else	//3�Ǵ� �׿��� �Է�
							printf("\t�����޴��� ���ư��ϴ� \n");
					}
					modeselect=0;//mode �ʱ�ȭ
					break;
		case 3 :	modify(start, &count);
					break;
		case 4 :	deletedata(&start,&pasttemp,&count);
					break;
		case 5 :	printf("�����մϴ� ^^.\n");
					for(temp = 0; temp<count; ++temp)
					{
						pasttemp = start->link1;
						free(start);
						start = pasttemp;
					}
					break;
		default :	printf("�ȹٷ� �Է��ϰŶ�.!\n");
					break;
		}
		printf("\n");
	}
}

void insert(int* num, STU** instart, STU** inpasttemp)
{
	STU* temp;
	printf("\t%d��° �Է��Դϴ�.\n",(*num)+1);
	temp = (STU*)malloc(sizeof(STU));

	printf("%d��° �̸� �Է� : ",(*num)+1);
	scanf("%s",temp->name);			//heap�� �ּҸ� ����Ű�� ������ �������ٿ����� ���
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%d",&temp->age);
	printf("%d��° ���� �Է� : ",(*num)+1);
	scanf("%lf",&temp->score);

	temp->link2 = (*inpasttemp);
	if((*num)==0)
	{
		*instart = temp;
		*inpasttemp = temp;
	}
	else
	{
		(*inpasttemp)->link1 = temp;
		(*inpasttemp) = temp;
	}
	(*num)++;
}

void display1(STU* pastptr, int* num)
{
	int count;
	printf("\t\t������ display�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %10s    ",count+1,pastptr->name);
		printf("%d��° ���� : %5d    ",count+1,pastptr->age);
		printf("%d��° ���� : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link1;
	}
	printf("\n");
}

void display2(STU* pastptr, int* num)
{
	int count;
	printf("\t\t������ display�Լ� ���� \n");
	for(count = 0; count<(*num); ++count)
	{
		printf("%d��° �̸� : %10s    ",count+1,pastptr->name);
		printf("%d��° ���� : %5d    ",count+1,pastptr->age);
		printf("%d��° ���� : %5.1lf",count+1,pastptr->score);
		printf("\n");
		pastptr = pastptr->link2;
	}
	printf("\n");
}

void modify(STU* modiptr, int* num)
{
	int count,alpha,length,flag;
	char search[30];
	printf("\tmodify �Լ� ���� \n");
	printf("\t�˻��� �̸��� �Է��Ͻÿ� : ");
	scanf("%s",search);
	printf("\tSearching...\n");
	for(count = 0; count<(*num); ++count)
	{
		for(length = 0; modiptr->name[length]!='\0'; ++length);	//���ڿ��� ���ϱ����� ���̸� Ȯ��!
		for(alpha = 0; modiptr->name[alpha]!='\0'; ++alpha)
		{
			if(modiptr->name[alpha] == search[alpha])
				length--;
		}
		printf("%d��° �̸� : %10s    ",count+1,modiptr->name);
		if(!length)
		{
			printf("��ġ�ϴ� �̸��� ã�ҽ��ϴ�!\n");
			break;
		}
		modiptr = modiptr->link1;
		printf("\n");
	}
	printf("�����Ͻðڽ��ϱ�? (yes : 1, No : 0) : ");
	scanf("%d",&flag);
	if(flag)
	{
		printf("���� �̸��� %10s �Դϴ�.\t ���ο� �̸� : ",modiptr->name);
		scanf("%s",modiptr->name);
		printf("���� ���̴� %10d �Դϴ�.\t ���ο� ���� : ",modiptr->age);
		scanf("%d",&modiptr->age);
		printf("���� ������ %10.1lf �Դϴ�.\t ���ο� ���� : ",modiptr->score);
		scanf("%lf",&modiptr->score);
	}
}

void deletedata(STU** delstart, STU** delpast, int* num)
{
	int count,alpha,length,flag;
	STU* buf;
	STU* temp = *delstart;
	char search[30];
	printf("\tdeletedata �Լ� ���� \n");
	printf("\t�˻��� �̸��� �Է��Ͻÿ� : "); 
	scanf("%s",search);
	printf("\tSearching...\n");
	for(count = 0; count<(*num); ++count)
	{
		for(length = 0; (*delstart)->name[length]!='\0'; ++length);	//���ڿ��� ���ϱ����� ���̸� Ȯ��!
		for(alpha = 0; (*delstart)->name[alpha]!='\0'; ++alpha)
		{
			if((*delstart)->name[alpha] == search[alpha])
				length--;
		}
		printf("%d��° �̸� : %10s    ",count+1,(*delstart)->name);
		if(!length)
		{
			printf("��ġ�ϴ� �̸��� ã�ҽ��ϴ�!\n");
			count++;
			break;
		}
		(*delstart) = (*delstart)->link1;
		printf("\n");
	}		//count�� �̿��ؼ� ���°�� ����ü�� �ش��ϴ��� Ȯ��
	printf("�ش� ����ü�� �����Ͻðڽ��ϱ�? (yes : 1, No : 0) : ");
	scanf("%d",&flag);
	if(flag)
	{
		printf("\t�ش� ����ü�� �̸��� %10s �Դϴ�.\t �����մϴ�.\n",(*delstart)->name);
		printf("\t�ش� ����ü�� ���̴� %10d �Դϴ�.\t �����մϴ�.\n",(*delstart)->age);
		printf("\t�ش� ����ü�� ������ %10.1lf �Դϴ�.\t �����մϴ�.\n",(*delstart)->score);
		if(count==1)	//ù��° ����ü�� ������ ���
		{
			(*delstart)->link1->link2 = temp;	//�ι�° ����ü ��ũ�� Main ����ü �ּҸ� ����Ŵ
			(*delstart) = (*delstart)->link1;	//�ι�° ����ü�� ����Ŵ 
		}//free(*delstart));
		else if(count==(*num))	//������ ����ü�� ������ ���
		{
			*(delpast) = (*delstart)->link2;
			(*delstart) = temp;	//start ����ü�� �ּҸ� ����
		}//free(*delstart));
		else
		{
			(*delstart)->link2->link1 = (*delstart)->link1;
			(*delstart)->link1->link2 = (*delstart)->link2;
			(*delstart) = temp;	//start ����ü�� �ּҸ� ����
		}//free(*delstart));
		(*num)--;
	}
}





