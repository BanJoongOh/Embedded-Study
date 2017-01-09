/*
��������
	1. �������� - ������ Ȱ��
	2. �������� - �����ͺ��� Ȱ��

�迭�� - �迭�� �����ּ�, ������ ���
		��, ptr = arr(����) // arr = ptr(�Ұ���)

- int arr[5] ���ٹ��
int* pa = arr;
	*(pa+0) == arr[0]
	*(pa+1) == arr[1]

char* ps1 = "test program";
���ڿ� ����� �����ּҸ� ��ȯ��(read only)
	��, ps1[5]='k'(�Ұ���)

- �����͹迭
char* parr[3] = {"test","good","student"};
- ����������
char** pd = parr;
	��, pd == parr, pd[1] == parr[1]
- �迭������
; int arr[3][5]�� ����Ű�� ������
int (*pa)[5]	// (4x5)20byte�� �ּҸ� �ǳʶ�� ��������
	ex)pa[0][1] == *(*(pa+0)+1)
	�� �ڷ���
	   arr[0] == int*
	   arr == int (*p)[5]
*/


/*

- �޸� �Ҵ�
	- ���� �Ҵ� : ������ Ÿ�ӿ����� �޸� �Ҵ�(����,����,static ��)
				���� : ���ټӵ��� ����, ������ ����
				���� : �޸� ����, �ڵ� ���������� �����

	- ���� �Ҵ� : ���� Ÿ�ӿ����� �޸� �Ҵ�
				���� : �޸� ȿ�������, �ڵ� �������� ����
				���� : ���ټӵ��� ����, �ڵ� ������ �����(������ ����)

- �޸� ����(stack : FIFO, Queue : LIFO)
	1. data		: ����,static ����
	2. heap		: �����Ҵ翵��		//�޸� �Ҵ翡 ���� �����ּҸ� ��ȯ
	3. stack	: ����,�Ű� ����

	#include <stdlib.h>
		malloc();	== new
		free();		== delete

void* malloc(Size_t size);
	#typedef unsigned int Size_t;

void* ptr = malloc(sizeof(int)*5);	// 20byte�Ҵ�, malloc�� �ּҰ��� ��ȯ��(������ : -1)
	# ���⼭ void�� �����͸� ���� ������ ��� �ڷ����� �ּҰ��� ������ �� �ִ�!
		��, ���ٽ� �� byte�� �������� �� �� ����.
		*ptr = 8		// �̷� ������ �Ұ����ϴ�.
		int* pnew = (int*)ptr = 8;	// ����ȯ�� �ʿ�
		*pnew = 8		// ���� ������

int* pnew = (int*)malloc(sizeof(int)*5);	//����ȯ�� ���� �����Ҵ��� ���ٷ� �� �� ����!
free(pnew);	//�ּҸ��˷��ָ� �Ҵ�� �޸𸮸� ������














*/


#include <stdio.h>
#include <stdlib.h>
/*
///////////////////���������� 5���� �Է��ϴ� �Լ�, ����� �����͸� ����ϴ� �Լ�
int* insert();
void display(int* dptr);
void main()
{
	int* num;
	num = insert();
	display(num);
}

int* insert()
{
	//ptr�� stack�� �Ҵ�Ǿ� heap�� �Ҵ�� ���� �ּҸ� ����Ŵ
	int* ptr = (int*)malloc(sizeof(int)*5);	//heap�� �Ҵ�Ǳ⶧���� �Լ��� ����ǵ� �ʱ�ȭ�ȵ�
	int num;
	printf("insert���� Ȯ���� ptr�� �����ּ� : %p \n",ptr);
	for(num=0; num<5; ++num)
	{
		printf("���� �Է� : ");
		scanf("%d",ptr+num);
	}
	return ptr;	//ptr�� ����ִ� heap�� �ּҸ� ��ȯ(ptr�� stack���� �Լ� ����� ����)
}

void display(int* dptr)
{
	int num;
	printf("display���� Ȯ���� ptr�� �����ּ� : %p \n",dptr);
	for(num=0; num<5; ++num)
		printf("���� ��� : %d\n",*(dptr+num));
	free(dptr);
}
*/


/////////////while & switch-case// 1.�̸��Է� 2.�̸���� 3.����
char* insert_name(int* icount);
void display_name(char** dptr, int* dcount);
void main()
{
	int select_mode=10;
	int count = 0;
	char* name[5];
	while(select_mode!=0)
	{
		printf("1. �̸��Է�\t2. �̸����\t0.���� : ");
		scanf("%d",&select_mode);
		switch(select_mode)
		{
		case 1 :
			name[count-1] = insert_name(&count);	//����� heap�� �ּҸ� ������ �迭�� ����
			//printf("count = %d\n",count);
			//printf("switch������ �̸� : %s\n",name[count-1]);
			break;
		case 2 :
			display_name(name,&count);
			break;
		case 0 :
			printf("\t�����մϴ�.\n");
			break;
		default :
			printf("0,1,2�� �ϳ��� �Է��Ͻÿ�..\n");
			break;
		}
		if(count==5)
		{
			display_name(name,&count);
			break;
		}
	}
}

char* insert_name(int* icount)
{
	char keyin[100];
	int num;
	char* ptr;
	printf("%d��° �̸� �Է� : ",(*icount)+1);
	scanf("%s",keyin);
	for(num = 0; keyin[num]!='\0'; ++num);		//�Էµ� ������ ���̸� ī��Ʈ
	printf("%d��° �̸��� ���� : %d\n",(*icount)+1,num);
	ptr = (char*)malloc(sizeof(char)*(num+1));	//�Էµ� ������ ����+1��ŭ �޸� �Ҵ�
	for(num = 0; keyin[num]!='\0'; ++num)
		*(ptr+num) = *(keyin+num);
	*(ptr+num)='\0';	//������ NULL���ڸ� �������ν� ���ڿ� �ϼ�
	//printf("������̸� : %s\n",ptr);
	(*icount)++;
	return ptr;
}

void display_name(char** dptr, int* dcount)
{
	int num = 0;
	int temp = *dcount;
	while(temp!=0)
	{
		printf("display �Լ� %d��° �̸� : %s\n",num+1,*(dptr+num));
		temp--;
		num++;
	}
}





























