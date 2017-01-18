#ifndef NUM
#define NUM 4

class Sales
{
private:
	double sales[NUM];
	double average;
	double max;
	double min;
public:
	Sales(const double* ar, int n);
	void setSales();
	void showSales();
};
#endif