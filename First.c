/*

���α׷� �޸� = Rom -> Flash�� ����(Rom Writer�� ��ΰ� �����͸� ���� �����ϱ⶧��)
  ������ �޸� = Ram
Q1 : ��ü ������ Ư¡�� �����Ͻÿ�,
	*�������� CPU���� �޶� �̽ļ��� ��������

*/

/*
#include <stdio.h>	// std : ǥ��, io : ��/��� 
					// Header : �Լ������� ����
					// stdio.h = iostream.h = iostream

void main() // main : ���α׷��� ����(�����) -> main �Լ��� �ü���� ȣ��(0:����/-1:������)
{
	printf("C++�� ����� \n��ȸ \n"); // Body : �Լ��� ����(����)���� ����
}
*/

/*

�Լ�ȣ��(��������), �Լ�����(�Ű�����)
"���ڿ�", '���ڻ��'
���Ĺ��� : %p : ������(�ּ�)

*/



#include <stdio.h>	//# : ��ó����(����������)
  
void main()
{
	char age = 25;
	float score = 3.000;
	double *pw;
	printf("�̸� : ���߿� \n");
	printf("�ּ� : �������\n");
	printf("���� : %d\n",age);
	printf("���� : %.2f\n",score);	//.2f = �Ҽ��� 2�ڸ�����!
	printf("double size = %d\n",sizeof(pw));
}


/*
���� : ������ �����͸� �����ϱ����� �Ҵ��� �޸� ����
�ڷ��� char(1), short(2), int(4), long(4), float(4), double(8) ##intel PC ����
sizeof������ : sizeof(�ڷ���)

* ������ ���� : bit - nibble - byte - word - long


*/











































































