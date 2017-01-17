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
	cout<<"현재 문의 상태 : "<<state<<endl;
}
