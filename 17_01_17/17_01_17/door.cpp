#include "door.h"

void Door::Open()
{
	state = OPEN;
}

void Door::Close()
{
	state = CLOSE;
}

void Door::ShowState()
{
	cout<<"���� ���� ���� : "<<state<<endl;
}
