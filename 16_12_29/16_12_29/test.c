

#include <stdio.h>

#if 0
////////////Ex ����5�� �Է� �� ��,��� ���
void main()
{
	int count,keyin;
	double sum=0;
	for(count = 0; count<5; ++count)
	{
		printf("���� �Է� : ");
		scanf("%d",&keyin);
		sum+=keyin;
	}
	printf("�Է��� �� : %.0f, �Է��� ��� : %.2f\n",sum,sum/5);//���� ����ȯ -> (double)sum/5
	// ���Կ����ڸ� ������ ������ �ڷ����� �����ϰ� �� ��!
}
#endif


#if 0
/////////////Ex �� ������ �� ������ ��
void main()
{
	int keyin1,keyin2,count;
	int sum = 0;
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d",&keyin1);
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d",&keyin2);

	for(count = 0; count<keyin2-keyin1+1; ++count)
		sum+=keyin1+count;

	printf("%d�� %d������ ���� : %d\n",keyin1, keyin2, sum);
}
#endif


#if 0
void main()
{
	char ch;
	int space = 0;
	int total = 0;

	scanf("%c",&ch);
	while(ch!='.')
	{
		if(ch==' ')
			space++;
		total++;
		scanf("%c",&ch);	//scanf�� �ּҸ� �����ؼ� ���� �ֱ⶧���� ������ ������ �� ����!
	}
	printf("�Է��� ������ �� : %d\n",total);
	printf("�Է��� ��ĭ�� �� : %d\n",space);
}
#endif


#if 0
void main()
{
	int keyin;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf("%d",&keyin);
	while(keyin!=0)
	{
		if(keyin%2==0)
			printf("\t���� �Է��� %d�� ¦���Դϴ�.\n",keyin);
		else
			printf("\t���� �Է��� %d�� Ȧ���Դϴ�.\n",keyin);
		printf("���ڸ� �Է��Ͻÿ� : ");
		scanf("%d",&keyin);
	}
}
#endif

#if 0
// 65~90 �빮��, 97~122 �ҹ���
void main()
{
	char keyin;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf("%c",&keyin);
	fflush(stdin);
	if(keyin>64 && keyin<91)
		keyin+=32;
	else if(keyin>96 && keyin<123)
		keyin-=32;

	while(keyin!='.')
	{
		printf("��ҹ��� ��ȯ��� : %c\n\n",keyin);
		printf("���ڸ� �Է��Ͻÿ� : ");
		scanf("%c",&keyin);
		fflush(stdin);
		if(keyin>64 && keyin<91)
			keyin+=32;
		else if(keyin>96 && keyin<123)
			keyin-=32;
	}
}
#endif


#if 0
void main()
{
	char choice;
	scanf("%c",&choice);
	fflush(stdin);
	while(choice!='Q' && choice!='q')
	{
		switch(choice)
		{
			case 'a' :
			case 'A' : printf("a�� �Է��߱�\n");
						break;
			case 'r' :
			case 'R' : printf("reportȣ��\n");
						break;
			case 'l' :
			case 'L' : printf("������� ȸ�簬��\n");
						break;

			case 'c' :
			case 'C' : printf("comfortȣ��\n");
						break;

			default : printf("�ٸ� ���� �Է��ϰŶ� \n");
		}
		scanf("%c",&choice);
		fflush(stdin);
	}
}
#endif


#if 1
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
#endif


#if 0
void main()
{
	int kor,eng,math,aver;
	printf("ö���� ������ �Է��غ��� \n");
	printf("���� ���� : ");
	scanf("%d",&kor);
	printf("���� ���� : ");
	scanf("%d",&eng);
	printf("���� ���� : ");
	scanf("%d",&math);
	aver = (kor+eng+math)/3;
	if(aver>89)
		printf("ö���� ������ ����� : %d�̸�, ���´� ����մϴ�\n",aver);
	else if(aver>59 && aver<90)
		printf("ö���� ������ ����� : %d�̸�, ���´� ��ȣ�մϴ�\n",aver);
	else
		printf("ö���� ������ ����� : %d�̸�, ���´� ������Դϴ�\n",aver);
}
#endif
































