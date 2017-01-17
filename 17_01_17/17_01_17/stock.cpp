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
		cout<< "�ֽ� ���� ������ �� �� �����Ƿ�, "<<company
			<<" shares�� 0���� �ʱ�ȭ�մϴ�.\n";
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
		cout<<"���� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<<"�ŷ��� ��ҵǾ����ϴ�.\n";
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
		cout<<"�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<<"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else if(num>shares)
	{
		cout<<"���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, "
			<<"�ŷ��� ��ҵǾ����ϴ�.\n";
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
	cout<<"ȸ��� : "<<company
		<<"�ֽ� �� : "<<shares<<endl
		<<"�ְ� : $"<<share_val
		<<"�ֽ� �� ��ġ : $"<<total_val<<endl;
}
