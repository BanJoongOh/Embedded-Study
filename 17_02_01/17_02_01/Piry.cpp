#include <iostream>
#include "monster.h"
using namespace std;

Pi::Pi()
{
	cout << "파이리 생성" << endl;
	hp = 200;
	exp = 0;
	level = 1;
}

void Pi::eat()
{
	Demon::eat();
	hp += 4;
}

void Pi::sleep()
{
	Demon::sleep();
	hp += 10;
}

bool Pi::exercise()
{
	Demon::exercise();
	hp -= 20;
	exp += 15;
	levelUp();
	if (hp <= 0)
		return false;
	else
		return true;
}

bool Pi::play()
{
	Demon::play();
	hp -= 5;
	exp += 5;
	levelUp();
	if (hp <= 0)
		return false;
	else
		return true;
}

void Pi::levelUp()
{
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Pi::fire()
{
	cout << "파이리 불꽃 발사!" << endl;
	exp += 50;
	hp -= 20;
	levelUp();
	if (hp <= 0)
		return false;
	else
		return true;
}
