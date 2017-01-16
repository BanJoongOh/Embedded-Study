/*
Header - ��ó�� ���� ���� : main�Լ��� �� ȭ�鿡 ���̰� �ϱ� ����

	�̸����� : program�� size�� Ŀ���鼭 ���� �̸��� ���� �Լ��� ������ �з��ؼ� �����.
		ex) using namespace std;(using namespace�� �����)

		printf("���ڿ� ���");	//���ڿ� ����� �����ּҸ� ��ȯ��
		printf(const char* ps);	//�Լ�

- C++������ cin, cout ��ü��  ���
	�ڷ����� ���� ���Ĺ��ڸ� �� �ʿ� ����.

	\n(0x0A) = �ٹٲ�
	\r(0x0D) = �ٹٲ����� Ŀ���� �� ������
		\n�� \r�� ���� ��!

	cout<<"test program\n"; == count<<"test program"<<endl;

- ������ �켱����
	�򰥸���� ��ȣ�Ĺ������

- �����ε�: �����ڿ� �߰����� ����� �ο�	//ex) 3*5�� *temp ���� '*'
	OOP(��ü����)�� Ư¡: ĸ��ȭ/������/���/��������/��Ʈ��Ȱ��(ǥ�����ø�-stl)
	*�Լ� �����ε� : C++������ �Լ����� ���Ƶ� �Ű������� �ٸ��� ������ �� ����
		**return type�� ������

- ����Ʈ �Ű�����(����) : �Լ� ȣ�⿡�� �������ڸ� ���� �ʾ����� �⺻������ ó���ϴ� �Ű������� ��
	�������� ���� ���� : * ���Ǻκ��� �״��, �Լ� ����(main��)���� �����!(����Ʈ �Ű����� ����)
	�Ű������� �������ϰ�� ��� ä���� �� ��!

cin.get -> �Ű������� ���� ���ڿ����̸� �ѰԵǸ� ©�����

- C++������ �����Ҵ� : new, delete(�������Լ��� ȣ������ : ��ü����)
	char* name = new char[30]; // == (char*)malloc(sizeof(char)*30);
	delete []name;	// == free(name)

- #if,#else,#endif : ���Ǻ� ������






*/



#include <iostream>
#include <cstring>	//strlen(), strcpy()�� ����ϱ� ����
using namespace std;
#if 0
void main()
{
	int carrots;

	carrots = 25;

	cout<<"���� ����� ";
	cout<< carrots;
	cout<<"�� ������ �ִ�.";
	cout<<endl;
	carrots = carrots-1;
	cout<<"�ƻ�ƻ�, ���� ����� "<<carrots<<"���̴�."<<endl;
}
#endif



#if 0
void main()
{
	int carrots;

	cout<<"����� �� �� ������ �ִ�? ";
	cin>>carrots;
	cout<<"���� ����� "<<carrots<<"�� ������ �־��"<<endl;
}
#endif



#if 0
void main()
{
	char name[30];
	char address[50];
	
	cout<<"�̸��� �Է��ϼ��� : ";
	cin>>name;
	cout<<"�ּҸ� �Է��ϼ��� : ";
	cin>>address;
	cout<<"����� �̸��� : "<<name<<endl;
	cout<<"����� �ּҴ� : "<<address<<endl;
}
#endif



#if 0
void changetemp(double* temp)
{
	*temp = (1.8 * (*temp))+32.0;
}

void main()
{
	double temp;
	
	cout<<"���� �µ��� �Է��ϼ��� : ";
	cin>>temp;
	cout<<"���� "<<temp<<"���� ȭ�� ";
	changetemp(&temp);
	cout<<temp<<"�� �Դϴ�."<<endl;
}
#endif




#if 0
#define ArSize 20
void main()
{
	char name[ArSize];
	char dessert[ArSize];
	cout<<"�̸��� �Է��Ͻÿ� : ";
	cin.getline(name,ArSize);
	cout<<"����Ʈ�� �Է��Ͻÿ� : ";
	cin.getline(dessert,ArSize);
	cout<<"���ִ� "<<dessert<<"�� �غ��ϰڽ��ϴ�.\n";
	cout<<name<<"��\n";
}
#endif



#if 0
/////////////////////�ڵ��� ������ŭ �����Ҵ��Ͽ� main���� ���
typedef struct
{
	char name[30];
	int years;
}CAR;

void carlist(CAR** Ftemp, int* Fcount);
void main()
{
	int count;
	CAR* temp = NULL;
	cout<<"�� ���� ���� ������� �����Ͻðڽ��ϱ�? ";
	cin>>count;
	carlist(&temp,&count);	//�����Ͱ� ����Ű�� ���� �ٲٱ� ���� �ּҸ� �޾ƾ���!
	cout<<"���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�.\n";
	for(int num = 0; num<count; ++num)
		cout<<temp[num].years<<"���� "<<temp[num].name<<endl;
	delete []temp;
}

void carlist(CAR** Ftemp, int* Fcount)
{
	CAR* Fcar = new CAR[*Fcount];
	for(int num = 0; num<(*Fcount); ++num)
	{
		cout<<"�ڵ��� #"<<num+1<<endl;
		cout<<"���۾�ü: ";
		cin>>Fcar[num].name;
		cout<<"���۳⵵: ";
		cin>>Fcar[num].years;
	}
	*Ftemp = Fcar;
}
#endif




typedef struct
{
	char* str;	//���ڿ��� ����
	int ct;		//���ڿ��� ����
}TEST;
void set(TEST& set, char* temp);
void show(TEST show, int count = 1);	//count�� ����Ʈ �Ű�����
void show(char* show, int count = 1);
void main()
{
	TEST beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);	
	
	cout<<"\t�Լ� �ѹ� ���\n";
	show(beany);		// ���ڿ� ����� �� �� ���
	cout<<"\t�Լ� �ι� ���\n";
	show(beany, 2);	// ���ڿ� ����� �� �� ���
	testing[0] = 'D';
	testing[1] = 'u';
	
	cout<<"\ttesting �ѹ� ���\n";
	show(testing);	//���ڿ� 1ȸ ���
	cout<<"\ttesting ���� ���\n";
	show(testing, 3);	//���ڿ� 3ȸ ���
	show("Done");
	printf("�����Ҵ� �ּ� : %p",beany.str);
	delete beany.str;
}

void set(TEST& set, char* temp)
{
	set.ct = strlen(temp);	//���ڿ��� ���̸� beany ����ü�� ����
	char* strtemp = new char[(set.ct)+1];	//���ڿ��� ����+1��ŭ �����Ҵ�
	printf("�����Ҵ� �ּ� : %p",strtemp);
	strcpy(strtemp, temp);	//�Ҵ��� heap������ ���ڱ��� ����
	set.str = strtemp;		//beany����ü�� str�� heap�� �ּҸ� ����Ŵ
}

void show(TEST show, int count)
{
	for(int temp = 0; temp<count; ++temp)
		cout<<"str : "<<show.str<<endl<<"length : "<<show.ct<<endl;
}

void show(char* show, int count)
{
	for(int temp = 0; temp<count; ++temp)
		cout<<"testing : "<<show<<endl;
}










