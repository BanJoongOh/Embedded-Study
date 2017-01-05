/* 

- sizeof(�迭��) - �迭�� �� byte��
ex) int arr[5];
	sizeof(arr) = 4 x 5 = 20byte
	*Ȱ�� - sizeof(arr)/sizeof(int) == �迭�� ����

- �����ͺ��� : ����Ű�� �ּҸ� �ٲ� �� ����
- �����ͻ�� : ����Ű�� �ּҰ� ������(�迭)

	int* ptr = arr(&arr[0])
	 �Ű�����    ��������

int arr[5];
int* pa = arr;
*(pa+0) == pa[0] == arr[0];
*(pa+1) == pa[1] == arr[1];
*(pa+2) == pa[2] == arr[2];


int temp = 5;
int* ptmp = &temp;

- �̱� ������ : �Ϲ� ������ ���� �ּҰ��� ����
ptmp == 0x800(temp�� �ּҸ� �������)
	ptmp == 0x800 == &temp			-> �ּ�
	*(ptmp) == *(0x800) == *(&temp) == temp	-> �ּ��� ��

- ���� ������ : �̱� �������� ���� �ּҰ��� ����
int** ptd = &ptmp // &ptmp==&(&temp);
	ptd = &ptmp
	*ptd == ptmp == &temp	// �̱������Ͱ� ����Ű�� �ּ�
	**ptd == temp == 5		// �̱������Ͱ� ����Ű�� �ּ��� ��
	*ptmp == temp == 5
	

- ���ڿ� ���
���ڿ� ����� �����ּҸ� ��ȯ�� ; �����͸� �����
char* ps = "good student";		//���ڿ������ ����Ű�� ������(�����ּҸ�)
// ���ڿ������ ���α׷� �����߿� ���� �Ұ��� / �޸𸮿��� �ö��ְ� ���� �Ұ���

- ������ �迭
; �Ϲ������� �迭�� ������, ������ �迭�� �ּҸ� �������.
char Arr[4];
	sizeof(Arr) = 1x4 = 4
char* psArr[4] = {"Good","Hello","Bye","Apple"};
	sizeof(psArr) = 4x4 = 16



*/

#include <stdio.h>

/*
//Ư�� �Լ����� 10���� ������ �Է� �޾Ƽ� �迭�� ����(Ȧ���� �տ� ¦���� �ڿ� ����)
void even_odd_insert(int* parr, int* ecc)
{
	int ecount=9;//¦��
	int ocount=0;//Ȧ��
	int keyin;
	while((ecount+1)!=ocount)
	{
		printf("���� ���� �Է� : ");
		scanf("%d",&keyin);
		if(keyin%2==1)
			parr[ocount++]=keyin;
		else
			parr[ecount--]=keyin;
	}
	*ecc=ecount;
}

void bsort(int* parr, int ecount)//¦��4���� ecount==5
{
	int count1,count2;
	int temp;
	int max = 9;
	printf("ecount = %d \n",ecount);
	for(count2 = 0; count2<ecount; ++count2)
	{
		for(count1 = 0; count1<ecount; ++count1)
		{
			if(parr[count1]>parr[count1+1])
			{
				temp = parr[count1+1];
				parr[count1+1]=parr[count1];
				parr[count1] = temp;
			}
		}
	}
	for(count2 = ecount+1; count2<9; ++count2)
	{
		for(count1 = ecount+1; count1<9; ++count1)
		{
			if(parr[count1]>parr[count1+1])
			{
				temp = parr[count1+1];
				parr[count1+1]=parr[count1];
				parr[count1] = temp;
			}
		}
	}
}

void main()
{
	int arr[10];
	int count;
	int temp;
	int* ptemp = &temp;
	even_odd_insert(arr,ptemp);
	for(count = 0; count<sizeof(arr)/sizeof(int); ++count)
		printf("�迭�� %d��° ���� : %d\n",count,arr[count]);
	bsort(arr,temp);
	for(count = 0; count<sizeof(arr)/sizeof(int); ++count)
		printf("%d ",arr[count]);
}
*/


/*
//�����Ͱ� ����Ű�� �ּҸ� �ٲ���
void reverse_data(int** num1, int** num2)
{
	int* tmp;		//�ּҸ� ������� ������ ���� ����
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void main()
{
	int tmp = 5;
	int val = 8;
	int *pt = &tmp;
	int *pv = &val;

	printf("tmp : %d, val : %d\n",tmp,val);
	printf("*pt : %d, *pv : %d\n",*pt,*pv);
	reverse_data(&pt,&pv);
	printf("tmp : %d, val : %d\n",tmp,val);
	printf("*pt : %d, *pv : %d\n",*pt,*pv);
	
}
*/



void display(char** dArr, int dcount)
{
	int dnum;
	printf("\tdisplay �Լ� ���� \n");
	for(dnum = 0; dnum<dcount; ++dnum)
		printf("%s \n",dArr[dnum]);
}

int alphacount(char** dArr, int acount)
{
	int count,anum,lcount;
	char* temp;
	lcount = 0;
	printf("\talphacount �Լ� ���� \n");
	for(anum = 0; anum<acount; ++anum) 
	{
		count=0;
		temp = dArr[anum];
		while(temp[count]!='\0')
		{
			if(temp[count]=='l')
				lcount++;
			count++;
		}
	}
	return lcount;
}

void main()
{
	char buf[30] = "test program";	//���ڹ迭
	char* ps1 = "Good Student";		//���ڿ������ ����Ű�� ������(�����ּҸ�)
	char* ps2 = "Hello World";
	char* ps3 = "Bye";
	char* ps4 = "Apple";
	char* psArr[4] = {"Good Student","Hello World","Bye","Apple"};
	int num,count;

	printf("buf : %s \n",buf);
	printf("ps1 : %s \n",ps1);

	buf[0]='k';
	printf("buf : %s \n",buf);
	printf("ps1 : %s \n",ps1);
	
	count = sizeof(psArr)/sizeof(char*);
	for(num = 0; num<count; ++num)
		printf("%s \n",psArr[num]);
	display(psArr,count);

	printf("���ĺ� �ҹ��� l�� ���� : %d\n",alphacount(psArr,count));
}



/*
void menu(char** mselect, char mchoice)
{
	switch(mchoice)
	{
		case 'c' :
		case 'C' : printf("%s �ϳ� ����\n",mselect[0]);
					break;
		case 'p' :
		case 'P' : printf("%s ����ʹ�\n",mselect[1]);
					break;
		case 't' :
		case 'T' : printf("�� å�� %s�� �������\n",mselect[2]);
					break;

		case 'g' :
		case 'G' : printf("%s�����ұ�\n",mselect[3]);
					break;

		default : printf("c, p, t, g �߿��� �ϳ��� �����ϰŶ�.(�������� q or Q) \n");
	}
}

void main()
{
	char choice;
	char* select[4] = {"Camera","Pianist","Tree","Game"};

	printf("���� ���� ���� �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q or Q)\n");
	printf("c, p, t, g �߿��� �ϳ��� �����ϰŶ�.\n");
	
	scanf("%c",&choice);
	fflush(stdin);

	while(choice!='q'&&choice!='Q')
	{	
		menu(select, choice);
		scanf("%c",&choice);
		fflush(stdin);	
	}
}
*/




















