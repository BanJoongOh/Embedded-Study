/*

- �������� : �ּ�=�ּ�
- �������� : �ּҿ� �ִ� ������ ����
mycpy(per.name, "Good");
void mycpy(char* pd, char* ps)
{
	while(*ps!='\0')
		*pd++=*ps++;	// pd[num]=ps[num]
}



	�迭�� �ڷ����� ��ġ�ؾ� �Ѵٴ� ������ ����.
- ����ü : ����,����,�Ǽ� ���� ���� �ٸ� �ڷ����� �׷�ȭ���� �ϳ��� �ڷ������� ǥ��
	*��������� �����Ϸ��� �˰� �ִ� �ڷ����� �� ��!

struct person
{
	char name[30];
	int age;
	double score;
};					//30+4+8 -> 42����Ʈ�� ����ü

struct person per;	// struct person : �ڷ���, per : ������
(.) - ����ü ���� ���� ������
(->)- ����ü ���� ���� ������
	ex) per.age = 26;			// ����ü �������
		per.name = "good"(X)	// �Ұ����� �������縦 ����ߵ�
		* �迭�� : �迭�� �����ּ����� ������ ���


- typedef�� �̿��� ����ü ���� ����
	1.	typedef struct person PER;
		PER per == struct person per
	2. 
		typedef struct person
		{
			char name[30];
			int age;
			double score;
			struct person *link	// �ڱ����� ������
		}PER;	//PER�� ����ڰ� ���� �ڷ�����!

PER p1;
PER p2;
p2.link = &p1;	//struct person == PER


*/




#include <stdio.h>
#include <stdlib.h>		//malloc �Լ��� ����ϱ� ����

#if 0
/////////////////////////////����ü ����
typedef struct person
{
	char name[30];
	int age;
	double score;
	struct person* link;
}PER;

void main()
{
	PER P1;
	int num = 0;
	char name[30];
	int age;
	double score;
	printf("�̸� �Է� : ");
	scanf("%s",name);
	printf("���� �Է� : ");
	scanf("%d",&age);
	printf("�÷� �Է� : ");
	scanf("%lf",&score);

	for(num = 0; name[num]!='\0'; ++num)
		P1.name[num] = name[num];
	P1.name[num] = '\0';
	P1.age = age;
	P1.score = score;

	printf("�̸� ��� : %s\n",P1.name);
	printf("���� ��� : %d\n",P1.age);
	printf("�÷� ��� : %.1lf\n",P1.score);
}
#endif



#if 0
typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

void insert_data(CandyBar* change);
void main()
{
	CandyBar snack = {"Mocha Munch",2.3,350};	// ����ü���� ����� ���ÿ� �ʱ�ȭ
	printf("  �̸� ��� : %s\n",snack.title);	// snack.title�� �����ͻ��
	printf("  �߷� ��� : %.1lf\n",snack.weight);
	printf("Į�θ� ��� : %d\n",snack.cal);
	
	insert_data(&snack);	// ����ü������ �ּҸ� ���ڷ���
	printf("  �̸� ��� : %s\n",snack.title);
	printf("  �߷� ��� : %.1lf\n",snack.weight);
	printf("Į�θ� ��� : %d\n",snack.cal);
}
void insert_data(CandyBar* change)	//*(change+1)�� ����ü ũ�� �����̱� ������ ������ ����
{
	int num;
	char temp[20] = "����";
	for(num = 0; temp[num]!='\0'; ++num)
		(*change).title[num]=temp[num];	//���⼭ *change�� snack�� ������ �ǹ̸� ������.
	(*change).weight = 3.2;
	change->cal = 530;	// ����ü ���� ���� ������
}
#endif



#if 0
///////////////////////////����ü �迭, �����͸� ������ ����ü �����ͷ� �����Ͽ� ����ϱ�
typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

void insert_data(CandyBar* change);
void main()
{
	CandyBar snack[3] = {	{"Hello",11.11,3000},
							{"Good",22.22,4000},
							{"Morning",33.33,6000}};	// ����ü���� ����� ���ÿ� �ʱ�ȭ
	printf("  �̸� ��� : %s\n",snack[0].title);	// snack.title�� �����ͻ��
	printf("  �߷� ��� : %.1lf\n",snack[0].weight);
	printf("Į�θ� ��� : %d\n",snack[0].cal);
	
	insert_data(snack);	// ����ü������ �ּҸ� ���ڷ���
	printf("  �̸� ��� : %s\n",snack[0].title);
	printf("  �߷� ��� : %.1lf\n",snack[0].weight);
	printf("Į�θ� ��� : %d\n",snack[0].cal);

	printf("  �̸� ��� : %s\n",snack[1].title);
	printf("  �߷� ��� : %.1lf\n",snack[1].weight);
	printf("Į�θ� ��� : %d\n",snack[1].cal);

	printf("  �̸� ��� : %s\n",snack[2].title);
	printf("  �߷� ��� : %.1lf\n",snack[2].weight);
	printf("Į�θ� ��� : %d\n",snack[2].cal);
}
void insert_data(CandyBar* change)	// change�� snack�迭�� �ּҸ� ����Ű�� ����ü ������
{
	int num;
	char temp[30] = "����1000,�Ҽ�12.88 �ٲ�";
	for(num = 0; temp[num]!='\0'; ++num)
		change[0].title[num]=temp[num];
	change[0].title[num] = '\0';
	change[0].weight = 12.88;
	change[0].cal = 1000;	//��, change == snack�̱⶧���� �������������� �����
}
#endif



typedef struct candy
{
	char title[30];
	double weight;
	int cal;
}CandyBar;

CandyBar* input_data();
void main()
{
	CandyBar* snack;
	snack = input_data();	// ����ü������ �ּҸ� ���ڷ���
	printf("  �̸� ��� : %s\n",snack[0].title);
	printf("  �߷� ��� : %.1lf\n",snack[0].weight);
	printf("Į�θ� ��� : %d\n",snack[0].cal);

	printf("  �̸� ��� : %s\n",snack[1].title);
	printf("  �߷� ��� : %.1lf\n",snack[1].weight);
	printf("Į�θ� ��� : %d\n",snack[1].cal);

	printf("  �̸� ��� : %s\n",snack[2].title);
	printf("  �߷� ��� : %.1lf\n",snack[2].weight);
	printf("Į�θ� ��� : %d\n",snack[2].cal);
	free(snack);
}
CandyBar* input_data()	// change�� snack�迭�� �ּҸ� ����Ű�� ����ü ������
{
//	int num;
	CandyBar* ptr = (CandyBar*)malloc(sizeof(CandyBar)*3);
	ptr[0].title[0] = 'a';	//(*(ptr+0)).title[0] == ptr->title[0]	(�Ѵ� ��������)
	ptr[0].title[1] = '\0';
	ptr[0].weight = 10.21;
	ptr[0].cal = 2000;

	ptr[1].title[0] = 'k';	//(ptr+1)->title[0](��������)
	ptr[1].title[1] = '\0';
	ptr[1].weight = 17.28;
	ptr[1].cal = 3500;

	ptr[2].title[0] = 't';
	ptr[2].title[1] = '\0';
	ptr[2].weight = 73.58;
	ptr[2].cal = 5000;

	return ptr;
}






