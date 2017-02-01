#include <iostream>
#include "monster.h"
using namespace std;

Gobu::Gobu()
{
	cout << "���α� ����" << endl;
	hp = 300;
	exp = 0;
	level = 1;
}

void Gobu::eat()
{
	Demon::eat();
	hp += 4;
}

void Gobu::sleep()
{
	Demon::sleep();
	hp += 10;
}

bool Gobu::exercise()
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

bool Gobu::play()
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

void Gobu::levelUp()
{
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Gobu::water()
{
	cout << "���α� ������ ����!" << endl;
	exp += 50;
	hp -= 20;
	levelUp();
	if (hp <= 0)
		return false;
	else
		return true;
}
