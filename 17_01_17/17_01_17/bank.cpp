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
		cout<<name[temp]<<"님의 "<<"계좌금액은 음수가 될 수 없으므로, "
			<<"잔액을 0으로 초기화합니다.\n";
		money = 0;
	}
	else
		money = Tmoney;
}


void Bank::Plus(int Tplus)
{
	if(Tplus<0)
	{
		cout<<"입금액은 음수가 될 수 없으므로, "
			<<"거래가 취소되었습니다.\n";
	}
	else
		money+=Tplus;
}

void Bank::Minus(int Tminus)
{
	if(Tminus<0)
	{
		cout<<"입금액은 음수가 될 수 없으므로, "
			<<"거래가 취소되었습니다.\n";
	}
	else
		money-=Tminus;
}

void Bank::Show()
{
	cout<<"고객명 : "<<name<<"\t"
		<<"계좌명 : "<<acount<<endl
		<<"잔액 : "<<money<<"\\"<<endl;
}
