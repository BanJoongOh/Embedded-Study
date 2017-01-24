#ifndef COMPANY
#define COMPANY

class Employee
{
	char name[30];
	//int flag;
public:
	Employee();
	char* GetName(char* Tname);
};

class Permanent : public Employee
{
	int salary;
public:
	Permanent(char* name = "None", int money = 0);
	int GetPay();
};

class Temp : public Employee
{
	int time;
	int pay;
public:
	Temp(char* name = "None", int time = 0, int pay = 0);
	int GetPay();
};

class Department
{
	Employee* emplist[10];
	int idx;
	int money;
public:
	Department();
	void AddEmployee(Employee* tmp);
	void ShowPayList();
};

#endif