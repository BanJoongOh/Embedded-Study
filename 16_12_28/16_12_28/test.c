/*

CPU���� ALU�� register(cache)
ALU -> �������, ��(T/F�Ǵ�)

�䱸���� -> Flow Chart(����) -> �ڵ屸�� -> �����

�������� - �޸𸮿� �Ҵ�
�������� - �����̸�, �����ּҰ�
���� - �迭(1����) - �Լ� - ������(�迭�� �ּҿ� �����ϱ� ����) - �����͹迭 - �Լ� - ����������
������ = �ּҿ� ��������

<�������� ũ�� ���ϱ�>
2�Ǻ��� = 1�Ǻ��� + 1

	1000 0000�� 1�Ǻ��� = 0111 1111 + 1 = 1000 0000
	1000 0000 = -128��

�����Ҵ��� heap ������ ����ϴµ� �����ּҸ����� ����ϱ⶧���� �����Ͱ� �ʼ�

<<����Q & link the list>>
<<�����ε�>>

*/

#include <stdio.h>

#if 0
void main()
{
	char ch;

	printf("���ϴ� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c",&ch);
	printf("�Է��� ���ڴ� %c�̰� ������ �ּҴ� %p�̰� 0x%x�̰� %x. \n",ch,&ch,&ch,&ch);
	*((char*)0x12ff2b)='k';
	printf("������ ���ڴ� %c\n",ch);
	printf("%d",3+5<<2|7);
}
#endif

#if 0
void main()
{
	int lat,min,sec;
	printf("������ ��, ��, �� ������ �Է��ض� : \n");
	printf("������ : ");
	scanf("%d",&lat);
	printf("�а��� : ");
	scanf("%d",&min);
	printf("�ʰ��� : ");
	scanf("%d",&sec);
	printf("%d��, %d��, %d��",lat,min,sec);
}
#endif




/*

buffer����
1. fan out�� �ø��� ����!(��������)
2. delay �ð����� �ֱ� ����

not gate(inverter)

Atmega128 ���ͷ�Ʈ Ȱ��ȭ�ÿ� SREG |= 0x80; �� ������ ��(7���� ������ ��Ʈ�� �ǵ�� �ȵ�!)

for(count=0; count<5; ++count);
while(count<5);
		for���� �޸� ���� while���� ���ѷ����� ���� �� �ֱ� ������ �ݺ��������� while�����ٴ� for���� ��ȣ��

*/


#if 0
void main()
{
	int count;
	for(count=0; count<5; ++count);	//Non operation! ���ǰ˻� �� ������ �ݺ���
		printf("count�� ���簪�� : %d\n",count);
}
#endif






////////////////Ex1 ���ϴ� �������� ���
#if 0
void main()
{
	int num,count;
	printf("�Է��� ���� : ");
	scanf("%d",&num);
	for(count=1; count<10; ++count)
		printf("%d�� %d X %d = %d\n",num,num,count,num*count);
}
#endif


////////////////Ex2 �Է��� ������ ���̸�ŭ *�� ���ﰢ�� ���
#if 1
void main()
{
	int star,space,keyin,count,spacecount,starcount;
	printf("���̸� �Է� : ");
	scanf("%d",&keyin);
	
	spacecount=keyin-1;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<spacecount; ++space)
			printf(" ");
		for(star=0; star<(count+1)*2-1; ++star)
			printf("*");
		printf("\n");
		spacecount--;
	}
	printf("\n");


	starcount=keyin;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<count; ++space)
			printf(" ");
		for(star=0; star<(starcount)*2-1; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
	printf("\n");


	starcount=1;
	for(count=0;count<keyin;++count)
	{
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount++;
	}
	starcount-=2;
	for(count=0;count<keyin;++count)
	{
		
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
	printf("\n");


	spacecount=keyin;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<spacecount-1; ++space)
			printf(" ");
		for(star=0; star<count+1; ++star)
			printf("*");
		printf("\n");
		spacecount--;
	}
	starcount=keyin-1;
	for(count=0;count<keyin;++count)
	{
		for(space=0; space<count+1; ++space)
			printf(" ");
		for(star=0; star<starcount; ++star)
			printf("*");
		printf("\n");
		starcount--;
	}
}
#endif















