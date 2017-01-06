/*

�Լ�
	1) void main(void)  : �Ű�����+�������� X, return X
	2) void main(int a) : �Ű�����+�������� O, return X
	3)  int main(void)  : �Ű�����+�������� X, return 0
	4)  int main(int a) : �Ű�����+�������� O, return O

�Լ����� - �Ű��������ٴ� �ڷ����� �ξ� �� �߿���



- ��������(������ ����)
	ex) temp = 8;
- ��������(�޸� �ּ�)
	������ ���� : �޸� �ּҰ��� �����ϱ� ���� ����
	ex) int *ptr = &temp;
		**�Ϲ������� ������ ������ ����� ���ÿ� �ʱ�ȭ(�ּ� �Ǵ� NULL)
		**������ �������� *ptr�� �ƴ϶� ptr��
			�޸� ���������Ҷ� *ptr�� �� // ptr�� &������(�����ּ�)�� ����Ŵ
			<	*ptr == temp // ptr == &temp	>
				*(&temp) == temp -> *�� &�� ����
		**������ ������ �ڷ��� ũ��� 4bytes(32bits�ü��)
		**������ ������ �ڷ����� �������ٽ� �����ּҺ��� ��byte�� ����������
			�����ϴ� ������ ��.

	<<0x12345678�ϰ��>>
		ARM, Intel - Little Endian(������Ʈ~������Ʈ������ ���� 0x5000-78)
		����ζ�迭 - Big Endian(������Ʈ-������Ʈ������ ���� 0x5000-12)

	�ѹ��� ����!! ��� ������ ����(�ڷ�������)�� 4Byte = �ּҸ� ����Ű�� ����

- ������ ����
	*������ +,-�� ����� ��!(x����� overflow����)
	ptr+1 -> !�ڷ����� ũ��!��ŭ ���� ���� ����Ŵ(char�ϰ�� 1byte���� int�ϰ�� 4byte����)
	ptr++ -> ���� �ּҰ� !�ڷ����� ũ��!��ŭ���� ������

*/


#include <stdio.h>

#if 0
////////////////temp�� ���������ؼ� 20�����
void main()
{
	int temp = 8;
	int* ptr = &temp;

	printf("temp : %d\n",temp);
	printf("*ptr : %d\n",*ptr);
	printf("temp Address : 0x%x\n",&temp);
	printf("ptr : 0x%x\n",ptr);

	*ptr = 20;
	printf("temp : %d\n",temp);
}
#endif


#if 0
void reverse(int* num1, int* num2)	//call by address
{
	int rtemp = *num1;	// rtemp = &temp
	*num1 = *num2;		// &temp = &val
	*num2 = rtemp;		// &val = rtemp
}

void main()
{
	int temp = 8;
	int val = 5;
	printf("temp : %d, val = %d\n",temp,val);
	reverse(&temp, &val);
	printf("temp : %d, val = %d\n",temp,val);
}
#endif


#if 0
void main()
{
	int temp = 0x12345678;			
	char* ptr = (char*)&temp;		//endian�� �Ǵ��ϱ� ���� 1byte�� ���� char������ ����.(ĳ���ÿ���)
	printf("temp : %x\n",temp);
	printf("*ptr : %x\n",*ptr);
	if(*ptr==0x78)
		printf("ù�ּ��� ���� : %x �̰� little endian�Դϴ�.\n",*ptr);	//Intel & ARM
	else
		printf("ù�ּ��� ���� : %x �̰� big endian�Դϴ�.\n",*ptr);
	printf("*ptr�� ����° �� : %x\n",*(ptr+3));
}
#endif


#if 0
void mystringcopy(char* string1, char* string2) //char* string1 = src
{
		printf("src�ּ�(p) : %p\n",string1);
		printf("src�ּ�(s) : %s\n",string1);
		printf("src�ּ�(s) : %c\n",*string1);
	while(*string1!='\0')
		*string2++ = *string1++;
	*string2 = '\0';
}

void main()
{
	char src[50];
	char dest[50];
	char* ptr = src;
	printf("���ڸ� �Է��غ��� : ");
	scanf("%s",src);
	fflush(stdin);
		printf("ptr�ּ�(p) : %p\n",ptr);
		printf("ptr�ּ�(s) : %s\n",ptr);
		printf("ptr�ּ�(s) : %c\n",*ptr);
	mystringcopy(src,dest);
	printf(" src : %s.\n",src);
	printf("dest : %s.\n",dest);
}
#endif



//sec �迭�� ������, ����, Ư�����ڵ��� �Է¹���
//modify()�Լ� ȣ���Ŀ��� dest�� ���� ��ҹ��ڸ� ����
//apha_counting()�Լ� ȣ���Ŀ��� dest�� �ִ� ���ĺ� 'a'�� ������ �޴´�.(�ڷ��� int)
void modify(char* str1, char* str2);
int alpha_counting(char* alpha);
void main()
{
	char src[50];
	char dest[50];

	printf("������ ���ڸ� �Է��ϰŶ� : ");
	scanf("%s",src);
	modify(src,dest);
	printf("src : %s, dest : %s, a�� ���� : %d\n",src,dest,alpha_counting(dest));
}

void modify(char* str1, char* str2)
{
	while(*str1!='\0')
	{
		if((*str1>64 && *str1<91) || (*str1>96 && *str1<123))
			*str2++ = *str1;
		*str1++;
	}
	*str2 = '\0';
	
}

int alpha_counting(char* alpha)
{
	int temp = 0;
	while(*alpha!='\0')
	{
		if(*alpha=='a')
			temp++;
		*alpha++;
	}
	return temp;
}

























