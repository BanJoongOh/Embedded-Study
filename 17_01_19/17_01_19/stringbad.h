#include <iostream>
using namespace std;
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
class StringBad
{
private:
	char* str;
	int len;
public:
	StringBad(const char* s);
	StringBad();
	~StringBad();
	void display()
	{
		cout<<"\tdisplay�Լ� ����\t"<<str<<endl;
	}
};
#endif
