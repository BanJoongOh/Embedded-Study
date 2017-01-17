#include <iostream>
#include "stock.h"
using namespace std;

void Stock::acquire(const char* co, int n, double pr)
{
	int temp;
	for(temp = 0; co[temp]!='\0'; ++temp)
		company[temp] = co[temp];
	company[temp] = '\0';
	if(n<0)
	{
		cout<< "주식 수는 음수가 될 수 없으므로, "<<company
			<<" shares를 0으로 초기화합니다.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

void Stock::buy(int num, double price)
{
	if(num<0)
	{
		cout<<"매입 주식 수는 음수가 될 수 없으므로, "
			<<"거래가 취소되었습니다.\n";
	}
	else
	{
		shares+=num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	if(num<0)
	{
		cout<<"매도 주식 수는 음수가 될 수 없으므로, "
			<<"거래가 취소되었습니다.\n";
	}
	else if(num>shares)
	{
		cout<<"보유 주식보다 많은 주식을 매도할 수 없으므로, "
			<<"거래가 취소되었습니다.\n";
	}
	else
	{
		shares-=num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	cout<<"회사명 : "<<company
		<<"주식 수 : "<<shares<<endl
		<<"주가 : $"<<share_val
		<<"주식 총 가치 : $"<<total_val<<endl;
}
