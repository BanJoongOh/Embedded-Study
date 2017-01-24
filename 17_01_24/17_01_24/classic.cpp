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
	cout<<"\t#Cd Report 함수 진입"<<endl;
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
:Cd(s1,s2,n,x)		//멤버 초기화 리스트 문법이라서 생성자만 해당됨!
{
	int count;
	for(count = 0; s3[count]!='\0'; ++count)
		present[count] = s3[count];
	present[count] = '\0';
}

void Classic::Report() const
{
	Cd::Report();		// 부모 class에 있는 Report 함수를 강제로 호출하는 문법
	cout<<"\t#Classic Report 함수 진입"<<endl;
	cout<<"present : "<<present<<endl;
	cout<<endl;
}

Classic& Classic::operator=(const Classic& d)
{
	Cd::operator=(d);	// 기초 클래스 부분을 복사함.
	int count;
	for(count = 0; d.present[count]!='\0'; ++count)
		present[count] = d.present[count];
	present[count] = '\0';
	return *this;
}