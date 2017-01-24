#include <iostream>
#include <string>
#include "classic.h"
using namespace std;


Cd::Cd(char *s1, char *s2, int n, double x)
{
	int count;
	for(count = 0; s1[count]!='\0'; ++count)
		performer[count] = s1[count];
	performer[count] = '\0';

	for(count = 0; s2[count]!='\0'; ++count)
		label[count] = s2[count];
	label[count] = '\0';

	select = n;
	playtime = x;
}

Cd::Cd(const Cd &d)
{
	int count;
	for(count = 0; d.performer[count]!='\0'; ++count)
		performer[count] = d.performer[count];
	performer[count] = '\0';

	for(count = 0; d.label[count]!='\0'; ++count)
		label[count] = d.label[count];
	label[count] = '\0';

	select = d.select;
	playtime = d.playtime;
}

void Cd::Report() const
{
	cout<<"\t#Cd Report �Լ� ����"<<endl;
	cout<<"performer : "<<performer<<endl;
	cout<<"    label : "<<label<<endl;
	cout<<"   select : "<<select<<endl;
	cout<<" playtime : "<<playtime<<endl;
}

Cd& Cd::operator=(const Cd& d)
{
	int count;
	for(count = 0; d.performer[count]!='\0'; ++count)
		performer[count] = d.performer[count];
	performer[count] = '\0';

	for(count = 0; d.label[count]!='\0'; ++count)
		label[count] = d.label[count];
	label[count] = '\0';

	select = d.select;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(char* s1, char* s2, char* s3, int n, double x)
:Cd(s1,s2,n,x)		//��� �ʱ�ȭ ����Ʈ �����̶� �����ڸ� �ش��!
{
	int count;
	for(count = 0; s3[count]!='\0'; ++count)
		present[count] = s3[count];
	present[count] = '\0';
}

void Classic::Report() const
{
	Cd::Report();		// �θ� class�� �ִ� Report �Լ��� ������ ȣ���ϴ� ����
	cout<<"\t#Classic Report �Լ� ����"<<endl;
	cout<<"present : "<<present<<endl;
	cout<<endl;
}

Classic& Classic::operator=(const Classic& d)
{
	Cd::operator=(d);	// ���� Ŭ���� �κ��� ������.
	int count;
	for(count = 0; d.present[count]!='\0'; ++count)
		present[count] = d.present[count];
	present[count] = '\0';
	return *this;
}