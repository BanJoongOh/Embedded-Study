#include <iostream>
#include "company.h"

using namespace std;

Employee::Employee(){}

char* Employee::GetName(char* Tname)
{
	strcpy(name, Tname);
	return Tname;
}

Permanent::Permanent(char* name, int money)
{
	Employee::GetName(name);
	salary = money;
}

int Permanent::GetPay()
{
	return salary;
}

Temp::Temp(char* name,int time, int pay){}

int Temp::GetPay()
{
	return time*pay;
}

Department::Department()
{
	money = 0;
	idx = 0;
}

void Department::AddEmployee(Employee *tmp)
{
	//money+=tmp->GetPay();
	emplist[idx] = tmp;
	idx++;
}

void Department::ShowPayList()
{
	for(int count = 0; count<<idx; ++count)
	{
		cout<<count<<"��° �ٷ��� ����"<<endl;
		//cout<<"�̸� : "<<emplist[count]->GetName<<endl;
		//cout<<"�ӱ� : "<<emplist[count]->
	}
	cout<<"�� �ӱ� : "<<money<<endl;
}
