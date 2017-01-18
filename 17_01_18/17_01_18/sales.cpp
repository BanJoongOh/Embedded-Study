#include "sales.h"
#include <iostream>
using namespace std;

Sales::Sales(const double* ar, int n)
{
	double temp = 0;
	int num;
	for(num = 0; num<n; ++num)
	{
		sales[num] = ar[num];
		temp+=ar[num];
	}
	average = temp/4;
	max=min=sales[0];	
	for(num = 0; num<n-1; ++num)
	{
		if(sales[num]>sales[num+1])
			max = sales[num];
		if(sales[num]<sales[num+1])
			min = sales[num];
	}
}
void Sales::setSales()
{
	double temp = 0;
	for(int temp = 1; temp<5; ++temp)
	{
		cout<<temp<<"분기 판매액 입력 : ";
		cin>>sales[temp-1];
	}
	average = temp/4;
	max=min=sales[0];
	for(int num = 0; num<3; ++num)
	{
		if(sales[num]>sales[num+1])
			max = sales[num];
		if(sales[num]<sales[num+1])
			min = sales[num];
	}
}
void Sales::showSales()
{
	cout<<"판매액 평균 : "<<average<<endl;
	cout<<"판매액 MAX  : "<<max<<endl;
	cout<<"판매액 MIN  : "<<min<<endl;
}

