
#include <stdio.h>
#include <stdlib.h>
/*	1. �Է�		2. ���		3. ����		4.����		5.���� 
		�Է½ÿ� insert()�Լ�ȣ��
			insert�Լ������� STU ����ü��ŭ �����Ҵ��Ͽ� �޸𸮸� Ȯ���ϰ� ������ ������ ����
		����Լ������� ������ �Է¸�ŭ ������� ��

		#�߰���� : ���� �� ����
		->2���� link �׸��� ���������ͷ� ����
*/
typedef struct student
{
	char name[30];
	int age;
	double score;
	struct student* link1;
	struct student* link2;
}STU;

void insert(int* num, STU** start, STU** pasttemp);	//�߰� ����ü����
void display1(STU* pastptr, int* num);				//������ ���
void display2(STU* pastptr, int* num);				//������ ���
void modify(STU* modiptr, int* num);				//����ü ����
void deletedata(STU** delstart, STU** delpast, int* num);	//�ش� �̸��� ����ü ����
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
							display1(start, &count);	//������ ����� ���� ���۱���ü�� �ּҸ� �޾���
						else if(modeselect==2)
							display2(pasttemp, &count);	//������ ����� ���� ����������ü�� �ּҸ� �޾���
						else	
							printf("\t�����޴��� ���ư��ϴ� \n");	//3�Ǵ� �׿��� �Է�
					}
					modeselect=0;//mode �ʱ�ȭ
					break;
		case 3 :	modify(start, &count);
					break;
		case 4 :	deletedata(&start,&pasttemp,&count);
					break;
		case 5 :	printf("�����մϴ� ^^.\n");
					for(temp = 0; temp<count; ++temp)	//����ü�� ����ŭ �޸𸮸� ���
					{
						pasttemp = start->link1;
						free(start);
						start = pasttemp;
					}
					break;
		default :	printf("1~5�� ���ڸ��� �ȹٷ� �Է��Ͻÿ�.!\n");
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

	temp->link2 = (*inpasttemp);	//������ ����� ���� ���ο� ����ü�� ��ũ�� �����ּҸ� ����Ŵ
	if((*num)==0)	//start�ּҸ� ��� ���� ����
	{
		*instart = temp;
		*inpasttemp = temp;
	}
	else	//������ ����� ���� ��������ü�� ��ũ�� ���ο��ü�� �ּҸ� ����Ŵ
	{
		(*inpasttemp)->link1 = temp;
		(*inpasttemp) = temp;
	}
	(*num)++;	//����ü�� �� ����
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
		pastptr = pastptr->link1;	//�������� ���� link1�� �ּҸ� ��� refresh����
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
		pastptr = pastptr->link2;	//�������� ���� link1�� �ּҸ� ��� refresh����
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
		if(!length)		//��� ���ڰ� ��ġ�� ���
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

void deletedata(STU** delstart, STU** delpast, int* num)	//ù��°,�������� ����Ű�� �ּҰ� �ٲ� �� �ֱ⿡ ���������� ���
{
	int count,alpha,length,flag;
	STU* temp = *delstart;	//�ּ� �ӽ������
	char search[30];
	printf("\tdeletedata �Լ� ���� \n");
	printf("\t�˻��� �̸��� �Է��Ͻÿ� : "); 
	scanf("%s",search);
	printf("\tSearching...\n");
	for(count = 0; count<(*num); ++count)
	{
		for(length = 0; temp->name[length]!='\0'; ++length);	//���ڿ��� ���ϱ����� ���̸� Ȯ��!
		for(alpha = 0; temp->name[alpha]!='\0'; ++alpha)
		{
			if(temp->name[alpha] == search[alpha])
				length--;
		}
		printf("%d��° �̸� : %10s    ",count+1,temp->name);
		if(!length)		//��� ���ڰ� ��ġ�� ���
		{
			printf("��ġ�ϴ� �̸��� ã�ҽ��ϴ�!\n");
			count++;
			break;
		}
		temp = temp->link1;
		printf("\n");
	}		//count�� �̿��ؼ� ���°�� ����ü�� �ش��ϴ��� Ȯ��
	printf("�ش� ����ü�� �����Ͻðڽ��ϱ�? (yes : 1, No : 0) : ");
	scanf("%d",&flag);
	if(flag)
	{
		printf("\t�ش� ����ü�� �̸��� %10s �Դϴ�.\t �����մϴ�.\n",temp->name);
		printf("\t�ش� ����ü�� ���̴� %10d �Դϴ�.\t �����մϴ�.\n",temp->age);
		printf("\t�ش� ����ü�� ������ %10.1lf �Դϴ�.\t �����մϴ�.\n",temp->score);
		if(count==1)	//ù��° ����ü�� ������ ���
		{
			temp->link1->link2 = *delstart;	//�ι�° ����ü ��ũ�� Main ����ü �ּҸ� ����Ŵ
			*delstart = temp->link1;	//�ι�° ����ü�� �ּҸ� ��ũ�� ���� �ٲ��� 
		}
		else if(count==(*num))	//������ ����ü�� ������ ���
			*delpast = temp->link2;	//������ ����ü�� �ּҸ� ��ũ�� ���� �ٲ���
		else
		{
			temp->link2->link1 = temp->link1;	//��ũ�� ���� ��,�Ŀ� �ش��ϴ� �ּҷ� ����
			temp->link1->link2 = temp->link2;	//��ũ�� ���� ��,�Ŀ� �ش��ϴ� �ּҷ� ����
		}
		free(temp);	//������ ������ �޸� ����
		(*num)--;	//����ü���� ����
	}
}




