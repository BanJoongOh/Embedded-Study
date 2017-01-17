#include <iostream>
using std::cout;
using std::endl;

#define OPEN 1
#define CLOSE 2

class Door
{
private:
	int state;

public:
	void Open();
	void Close();
	void ShowState();
};