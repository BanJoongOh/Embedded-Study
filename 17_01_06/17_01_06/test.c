/*

- ���ڿ� ����� ������ �����ּҸ� ��ȯ��(�̸��� ������ �����ּҷ� ���ٰ���)
	*�б�뵵 => �����Ұ���
���ڻ�� �ϳ��� 1byte, ���� �ڷ����� char*(���ڿ� ������ ���)
�ּҰ��� �����ϴ� �����ͺ����� ũ��� 4byte

	<�����Ϸ��� �ν�>
���ڻ�� :'A' -> char��
������� : 5  -> int��
�Ǽ���� : 3.4-> double��

- �ڵ�����ȯ -> �����ڷ����� �����ڷ������� �°ݽ�Ŵ
	ex) 3x3x3.14 -> �Ҽ��� �ս��� ���ֱ����� 3�� double������ �°ݽ�Ŵ

[ ] == ��������
��, char** pdm == char* pdm[]
��������ÿ� char* pdm[]�� �ȵǱ� ������ �Ű��������� char** pdm(����������)�� �� ��!


pmenu[0] == *(pmenu+0)
pmenu[1] == *(pmenu+1)
	*dpmenu == pmenu

char* pArr[4] = {"Good Student","Hello World","Test Program","Setting Menu"}
	"Good Student"�� d(�ѹ���)�� �����Ҷ� -> *(pArr[0]+3)
	"Good Student"-���ڿ��� ��� -> %s, pArr[0]

char** pdm = pArr;
"Good Student"�� ����ϰ��� �� ��(���ڿ� ����� �����ּҴ� ���ڿ��� ��Ÿ��!)
	%s, *(pdm+1)  ==  %s, pdm[1]

pdm[1][6] == *(*(pdm+1)+6) // Hello World�� W�� ������
���� X�� ����ϰ����Ҷ�
	%c, 'W'+1	==	 %c, *(*(pdm+1)+6)+1	 ==		 %c, pdm[1][6]+1
Setting Menu�� M�� ����ϰ��� �Ҷ�,
	%c, *(pdm[3]+8)	== %c, pdm[3][8]


- 2���� �迭
int Darr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
�Ҵ� �޸� = 3x5x4 = 60byte
				
20byte�� �ǳʶ�� ������ �ڷ����� ��� �����?..(2���� �迭�� �� �����ּҸ� ����Ű�� ����)
	int *pd[5] = {{},{},{},{},{}};	// �迭�� �� ��Ұ� int*�� *�����͹迭*��.(�����͹迭(�����Ҷ� 5���� �ڷ����� �;���)
	int (*pd)[5] = data_arr;		// ���̰� 5�� int*�� 2���� �迭�� ����Ű�� *�迭������*��(�����ͺ���)
	char (*pd)[5] => 5byte�� �ǳʶ�� �迭������
										

<<<����ڰ� ����� �����ͺ���(�迭������)>>>

int arr[5];
int*pa = arr;
	arr[3]==pa[3]

int data_arr[3][5];
int (*darr)[5] = data_arr //�̷��ԵǸ� darr�� data_arr�� �����ϰ� ��밡��
	����, darr[0][2]==data_arr[0][2]

*/


#include <stdio.h>

#if 0
void display(int (*darr)[5])	//darr�� 4byte�� ������ ����
{
	int count1,count2;	
	for(count1 = 0; count1<3; ++count1)
	{
		for(count2 = 0; count2<5; ++count2)
			printf("darr[%d][%d]�� �� : %d\n",count1,count2,darr[count1][count2]);
	}

	for(count1 = 0; count1<3; ++count1)
	{
		for(count2 = 0; count2<5; ++count2)
		{
			darr[count1][count2]+=100;
			printf("������ darr[%d][%d]�� �� : %d\n",count1,count2,darr[count1][count2]);
		}
	}
	printf("darr        : 0x%p\n",darr);
	printf("darr[0]     : 0x%p\n",darr[0]);
	printf("darr+1      : 0x%p\n",darr+1);
	printf("darr[1]     : 0x%p\n",darr[1]);
	printf("darr[2]     : 0x%p\n",darr[2]);
	printf("&darr[0][0] : 0x%p\n",&darr[0][0]);
	printf("&darr[0][1] : 0x%p\n",&darr[0][1]);
}


void main()
{
	int data_arr[3][5] =	{	{1,2,3,4,5,},
								{6,7,8,9,10},
								{11,12,13,14,15}	};
	display(data_arr);	//data_arr, data_arr+1 �� �ǹ��ϴ°� 20byte�� ũ�⸦ ���� �迭�� ���� ����Ŵ
						//���࿡ �迭�� ���� 1���� �����ͷ� ��������
						//�Ű����� = int* dprr, �������� data_arr[0] ���� �ϸ� �����ּҷ� ���ٰ���
	printf("data_arr        : 0x%p\n",data_arr);
	printf("data_arr[0]     : 0x%p\n",data_arr[0]);
	printf("data_arr+1      : 0x%p\n",data_arr+1);
	printf("data_arr[1]     : 0x%p\n",data_arr[1]);
	printf("data_arr[2]     : 0x%p\n",data_arr[2]);
	printf("&data_arr[0][0] : 0x%p\n",&data_arr[0][0]);
	printf("&data_arr[0][1] : 0x%p\n",&data_arr[0][1]);
}
#endif


#if 0
////////////////main�Լ��� ����� 2���� �迭�� �����Ͽ� �ѻ���� �̸�,�ּҸ� ���
void inform_insert(char (*inperson)[50])
{
	printf("�̸��� �Է��غ��Ŷ� : ");
	scanf("%s",inperson[0]);
	printf("�ּҸ� �Է��غ��Ŷ� : ");
	scanf("%s",inperson[1]);
}

void inform_display(char (*inperson)[50])
{
	printf("�״��� �̸��� : %s\n",inperson[0]);
	printf("�״��� �ּ��� : %s\n",inperson[1]);
}

void main()
{
	char person[2][50];

	inform_insert(person);	//�̸�, �ּ� �Է�
	inform_display(person);	//�̸�, �ּ� ���
}
#endif


#if 0
/*
	Fill_array()�� double�� ������ �迭 �̸��� �迭 ũ�⸦ �Ű������� ����
		*�迭�� ������ double�� ������ �Է��Ͽ� �����ų� ���ڰ� �ƴҰ�� break, �Է¹������� return
	Show_array()�� double�� ������ �迭 �̸��� �迭 ũ�⸦ �Ű������� ���ϰ� ���
	Reverse_array()�� double�� ������ �迭 �̸��� �迭 ũ�⸦ �Ű������� ���ϰ� ����� ������ ������
	
	�� �Լ��� ����Ͽ�
		1. �迭�� ä���	2. �迭�� ����ϰ�		3. �迭�� ��������� ������		4. �迭�� ���
		���� : ù��°���ҿ� ���������Ҹ� ������ ������ ���Ҹ��� ������ ������ ��!
*/

void Fill_array(double (*Farr)[5], int* Fcount);
void Show_array(double (*Sarr)[5], int* Scount);
void Reverse_array(double (*Rarr)[5], int* Rcount);
void main()
{
	double arr[5][5]={0};
	int count = 0;
	Fill_array(arr,&count);
	Show_array(arr,&count);
	Reverse_array(arr, &count);
	Show_array(arr,&count);
}

void Fill_array(double (*Farr)[5], int* Fcount)
{
	int cnt1,cnt2;
	printf("Fill_array ���� \n");
	for(cnt1 = 0; cnt1<5; ++cnt1)
	{
		for(cnt2 = 0; cnt2<5; ++cnt2)
		{
			printf("[%d][%d]�迭�� ��� �Է� : ",cnt1,cnt2);
			scanf("%lf",&Farr[cnt1][cnt2]);
			if(Farr[cnt1][cnt2]<0)
			{
				Farr[cnt1][cnt2] = 0; //scanf���� �Էµ� ���� �ʱ�ȭ
				printf("Fill �Լ����� ������ count : %d\n",*Fcount);
				return;		// void�Լ��� ����� return;
			}
			else
				(*Fcount)++;
		}
	}
	printf("Fill �Լ����� ������ count : %d\n",*Fcount);
	return;
}

void Show_array(double (*Sarr)[5], int* Scount)
{
	int cnt1;
	printf("Show_array ���� \n");
	for(cnt1 = 0; cnt1<*Scount; ++cnt1)
	{
		printf("�迭�� ���� ��� : %lf\n",*((*Sarr)+cnt1));
	}
	printf("[5][5]ũ�� �迭�� �Էµ� ���� �� : %d\n",*Scount);
	return;
}

void Reverse_array(double (*Rarr)[5], int* Rcount)
{
	int cnt1,cnt2;
	double temp;
	printf("Reverse_array ���� \n");
	cnt2 = *Rcount-2;
	for(cnt1 = 0; cnt1<(*Rcount-2)/2; ++cnt1)
	{
		temp = *((*Rarr)+cnt1+1);
		*((*Rarr)+cnt1+1) = *((*Rarr)+cnt2);
		*((*Rarr)+cnt2) = temp;
		cnt2--;
	}
}
#endif


#if 0
////////////////////////������
void gooprint(int (*pgoo)[9]);
void main()
{
	int googoo[8][9] = {	{2,4,6,8,10,12,14,16,18},
							{3,6,9,12,15,18,21,24,27},
							{4,8,12,16,20,24,28,32,36},
							{5,10,15,20,25,30,35,40,45},
							{6,12,18,24,30,36,42,48,54},
							{7,14,21,28,35,42,49,56,63},
							{8,16,24,32,40,48,56,64,72},
							{9,18,27,36,45,54,63,72,81}	};
	gooprint(googoo);
}

void gooprint(int (*pgoo)[9])
{
	int cnt1,cnt2;
	for(cnt1=1; cnt1<10; ++cnt1)
	{
		for(cnt2=1; cnt2<5; ++cnt2)
			printf("%d x %d = %2d\t",cnt2+1,cnt1,pgoo[cnt2-1][cnt1-1]);
		printf("\n");
	}
	for(cnt1=1; cnt1<10; ++cnt1)
	{
		for(cnt2=5; cnt2<9; ++cnt2)
			printf("%d x %d = %2d\t",cnt2+1,cnt1,pgoo[cnt2-1][cnt1-1]);
		printf("\n");
	}
}

#endif


#if 0
////////////////1�Ⱓ ���� �ǸŵǴ� å�� ���� �Է¹޴´�.
void accrue(char** Amonth,int* Asale,int* Asales);
void main()
{
	char* month[12] = {	"1��","2��","3��","4��","5��",
						"6��","7��","8��","9��","10��","11��","12��"};
	int saleArr[12];
	int sales=0;
	accrue(month,saleArr,&sales);
	printf("�� �Ǹŷ� : %d\n",sales);
}
void accrue(char** Amonth,int* AsaleArr,int* Asales)
{
	int cnt;
	for(cnt = 0; cnt<12; ++cnt)
	{
		printf("%s�� �Ǹŵ� å�� �� : ",*(Amonth+cnt));	//Amonth�� �����ϰ� �����͹迭month�� �ּҸ� �ҷ����� ������
													//month�ּҿ� ��� "1��"�� �ּҸ� �ҷ������� *�����ڰ� �ʿ���
		scanf("%d",&AsaleArr[cnt]);
		*Asales+=AsaleArr[cnt];
	}
}	
#endif


#if 1
///////////////3�Ⱓ ���� �ǸŵǴ� å�� ���� �ų� �����Ͽ� ���(2�����迭���)
void accrue(char** Amonth,int (*AsaleArr)[12],int* Asales);
void main()
{
	char* month[12] = {	"1��","2��","3��","4��","5��",
						"6��","7��","8��","9��","10��","11��","12��"};
	int saleArr[3][12];
	int sales=0;
	accrue(month,saleArr,&sales);
	printf("3�Ⱓ �� �Ǹŷ� : %d\n",sales);
}
void accrue(char** Amonth,int (*AsaleArr)[12],int* Asales)
{
	int cnt1,cnt2;
	int year[3]={0};
	for(cnt1 = 0; cnt1 < 3; ++cnt1)
	{
		for(cnt2 = 0; cnt2<12; ++cnt2)
		{
			printf("%s�� �Ǹŵ� å�� �� : ",*(Amonth+cnt2));	//Amonth�� �����ϰ� �����͹迭month�� �ּҸ� �ҷ����� ������
														//month�ּҿ� ��� "1��"�� �ּҸ� �ҷ������� *�����ڰ� �ʿ���
			scanf("%d",&AsaleArr[cnt1][cnt2]);
			year[cnt1]+=AsaleArr[cnt1][cnt2];
		}
	}
	printf("1�Ⱓ �����Ǹż� : %d\n",year[0]);
	printf("2�Ⱓ �����Ǹż� : %d\n",year[0]+year[1]);
	printf("3�Ⱓ �����Ǹż� : %d\n",year[0]+year[1]+year[2]);
	*Asales = year[0]+year[1]+year[2];
}

#endif
















