/*

comfile time : ������ ���� ���� & ��ȯ
    run time : ������ ����

*--------------�迭���� �迭�� �����ּ�

'\0' -> NULL����(�����Ϸ��� 0���� �ν�)
'0' -> ���� 0
'o' -> ���� o
���ڴ� ' '�� ǥ���Ҷ� �Ѱ��� ���ڸ� ǥ���ϴµ� �̶� Null���ڴ� ����
���ڿ��� " "�� ǥ���ϴµ� ���ڿ��ǳ����� Null���ڰ� �� NULL = '\0'
	ex) 'a' - ���ڻ�� // "a" - ���ڿ�('\0'�� ���ԵǾ�����)

**�Լ�

���̺귯��(printf,scanf... ���� ����)
����� ���� �Լ�
	�Լ�����(main �Լ� ��) ->> �����Ϸ����� Ư�� �Լ��� ȣ��� ����
	�Լ�ȣ��(main �Լ� ����)-> Ư���Լ����� �κ����� �����ϴ� ����
	�Լ�����(main �Լ� ��) ->> �Լ��� �����ϴ� ��ɿ� ���� ����� ����	//�Ű���������
		*���࿡ �����Լ���� ȣ���Լ����� �ٸ����� ��� link error�߻�

	Main�Լ��� ���������� ���������� �����ϰ� ���α׷��� ������ �����

�Լ�ȣ�� ����(C�� �������δ� 2��, C++�� �������δ� reference����(��������)�� �߰�)
	call by value		- ���� ���翡 ���� ȣ��
	call by address		- pointer�� �ּ�����
	call by reference	- C++�� reference������ ���
	

*/


#include <stdio.h>

/*
/////////���� 5���� �Է¹޾� ����� ����ϴ� ���α׷�(�迭���)
void main()
{
	int arr[5];
	int count;
	for(count = 0; count < 5; ++count)
	{
		printf("���� �Է� : ");
		scanf("%d",&arr[count]);
	}
	printf("5�� ���� ��� : %f\n",(float)(arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5);
}
*/

/*
/////////������ �����̸��� �Է¹޾� ����ϴ� ���α׷�
void main()
{
	char name[20];
	
	scanf("%s",&name[0]);
	printf("Full Name = %s \n",name);
}
*/



/*
////////���� �̸��� �Է¹޾� ��3�� ���ڿ��� ����ϱ�
void main()
{
	char first[10];
	char last[10];
	char full[20];
	int fcount = 0;
	int lcount = 0;

	printf("First Name�� �Է��Ͻÿ� : ");
	scanf("%s",&first[0]);
	printf(" Last Name�� �Է��Ͻÿ� : ");
	scanf("%s",&last[0]);

	while(first[fcount]!=0)
	{
		full[fcount]=first[fcount];
		fcount++;
	}
	full[fcount++] = ',';
	full[fcount++] = ' ';
	while(last[lcount]!=0)
	{
		full[fcount]=last[lcount];
		fcount++;
		lcount++;
	}
	full[fcount] = '\0';

	printf("Full Name = %s \n",full);
}
*/



/*
///////////src�� ���ڿ��� �Է¹ް� dest���� ���ڿ��� ����� ���� �ְ� ȸ������ �ƴ��� ����� ��
void main()
{
	char src[30];
	char dest[30];
	int Scount,count;
	int result = 0;

	printf("���ڿ��� �Է��ϰŶ� : ");
	scanf("%s",&src[0]);

	for(Scount = 0; src[Scount]!=0; ++Scount);	//���ڿ� ���� ī��Ʈ
	for(count = 0; count<Scount; ++count)
		dest[Scount-(count+1)] = src[count];
	dest[count] = '\0';	//������ ���ڿ� �ϼ�

	for(Scount=0; src[Scount]!='\0'; ++Scount)	//���ڿ��� ������ ���� ī��Ʈ
	{
		if(dest[Scount] == src[Scount])
			result++;
	}

	if(result==count)	//���ڿ� ���̿� ī��Ʈ�� ��
		printf("%s�� ȸ���Դϴ�.\n",src);
	else
		printf("%s�� ȸ���� �ƴմϴ�.\n",src);
	
	printf("src = %s\ndest = %s\n", src,dest); //���Ȯ�ο�
}
*/

/*
void inprint(char input, int scount)
{
	int incount;
	for(incount = 0; incount<scount; ++incount)
		printf("%c",input);
	printf("\n");
}

void main()
{
	char keyin;
	int count;

	while(1)
	{
		printf("���ڸ� �Է��غ��Ŷ� : ");
		scanf("%c",&keyin);
		if(keyin=='q')
			break;
		printf("������ �Է��غ��Ŷ� : ");
		scanf("%d", &count);
		fflush(stdin);		//Enter �Է��� ����� ���� ��ɾ�
		inprint(keyin,count);
	}
}
*/




