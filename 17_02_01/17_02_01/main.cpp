/*

data,bss - object���� �̹� ����
stack,heap - ���α׷� ���� ��
text - ���α׷� code, ��� ���� ����� // ���� �Ұ���

�������� : bss�� �Ҵ�(��Ÿ�Ϳ��� 0���� �ʱ�ȭ��)

for loop���� �������� ������ ����ϸ� �ӵ����� ����!(r0, r1...)
	��, �������ʹ� �ּҰ� ���� ������ stack ������ ������ ���� �Ұ���������
		�����Ϸ��� �������ͺ����� stack�� �� �Ҵ��Ͽ� ������ ��Ÿ������ ����(�ӵ�����ȿ���� ������)

Q ��ü���� ���α׷����� ����?
	��ü�� ���Ǽ��迡 �ִ� ���� ���α׷��� �𵨸� �ϴ� ��
	���α׷��� �ʿ��� ���, �繰 ���� ��ü�� ǥ���Ͽ� ���α׷��� �ǹ̸� �ο�

���� �˰��� �׽�Ʈ�� ���� �߼�...

�̹� object ������ �����Ǹ� �ּ�ó���� ������ ������ �߻�
-> �������� �ʿ� ���� �ڵ�� �������ܸ� �ؾ���

*/

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
Data *head = NULL;
Data *tail = NULL;
char *path = "a.txt";

void main()
{
	init();
	puts("�߰���");
	printA();
	add("aaa\n");
	add("bbb\n");
	add("ccc\n");
	puts("add �Լ��� ���ڿ� �߰�\n");
	printA();
	//printB();	//���� ���
	printf("edit�Լ��� ���ڿ� ����\n");
	edit();
	printA();
	fileWrite();
	stop();
}
#endif


#if 0
#include <iostream>
using namespace std;

class A
{
public:
	virtual void func1()	//���� ����(�������̵�)
	{
		cout << "A : func1" << endl;
	}
};
 
class B : public A
{
public:
	void func1()
	{
		cout << "B : func1" << endl;
	}
};

void main()
{
	A a;
	B b;
	a.func1();
	b.func1();

	A *pa = &b;	//������������ �Լ��� ȣ���Ϸ��� �����͸� �����
	B *pb = &b;
	pa->func1();
	pb->func1();
}
#endif



//////////////////////ĳ������ �̿��� ������ �ٸ�����
#include <iostream>
#include <typeinfo>	//�ش� Ŭ������ �������� Ȯ���ϱ� ���� ���
#include "monster.h"

using namespace std;

void main()
{
	Demon *d;	//��ĳ������ �ϱ� ����
	bool flag = false;
	char select=0;
	puts("�ɸ��� ����");
	
	while (!flag)
	{
		puts("1. ��ī��, 2. ���α�, 3. ���̸�");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			d = new Pica;
			flag = true;
			break;
		case 2:
			d = new Gobu;
			flag = true;
			break;
		case 3:
			d = new Pi;
			flag = true;
			break;
		default:
			puts("1-3 �� �ϳ��� �Է��Ͻÿ�");
			flag = false;
			break;
		}
	}

	while (flag)
	{
		puts("1. ��Ա� 2. ���ڱ� 3. ��ϱ� 4. ��� 5. ����Ȯ�� 6. Ư�� ����");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			d->eat();
			break;
		case 2:
			d->sleep();
			break;
		case 3:
			flag = d->exercise();
			break;
		case 4:
			flag = d->play();
			break;
		case 5:
			d->printInfo();
			break;
		case 6:
			if (typeid(*d) == typeid(Pica))
				flag = ((Pica*)d)->electronic();
			else if (typeid(*d) == typeid(Gobu))
				flag = ((Gobu*)d)->water();
			else if (typeid(*d) == typeid(Pi))
				flag = ((Pi*)d)->fire();
			break;
		default :
			puts("�� �ܿ��� �� �������");
			flag = false;
			break;
		}
	}
	delete d;
}




