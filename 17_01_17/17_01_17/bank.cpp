#include <iostream>
#include "bank.h"
using namespace std;


void Bank::Acount(const char* Tname, const char* Tacount, int Tmoney)
{
	int temp;
	for(temp = 0; Tname[temp]!='\0'; ++temp)
		name[temp] = Tname[temp];
	name[temp] = '\0';
	for(temp = 0; Tacount[temp]!='\0'; ++temp)
		acount[temp] = Tacount[temp];
	acount[temp] = '\0';
	if(Tmoney<0)
	{
		cout<<name[temp]<<"���� "<<"���±ݾ��� ������ �� �� �����Ƿ�, "
			<<"�ܾ��� 0���� �ʱ�ȭ�մϴ�.\n";
		money = 0;
	}
	else
		money = Tmoney;
}


void Bank::Plus(int Tplus)
{
	if(Tplus<0)
	{
		cout<<"�Աݾ��� ������ �� �� �����Ƿ�, "
			<<"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else
		money+=Tplus;
}

void Bank::Minus(int Tminus)
{
	if(Tminus<0)
	{
		cout<<"�Աݾ��� ������ �� �� �����Ƿ�, "
			<<"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else
		money-=Tminus;
}

void Bank::Show()
{
	cout<<"���� : "<<name<<"\t"
		<<"���¸� : "<<acount<<endl
		<<"�ܾ� : "<<money<<"\\"<<endl;
}
