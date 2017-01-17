#include <iostream>

class Bank
{
private:
	char name[30];
	char acount[30];
	int money;
//	int temp;
/*	void plus()
	{
		money+=temp;
	}
	void minus()
	{
		money+=temp;
	}
*/
public:
	void Acount(const char* Tname, const char* Tacount, int Tmoney);
	void Plus(int Tplus);
	void Minus(int Tminus);
	void Show();
};