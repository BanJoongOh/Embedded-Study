#include <iostream>
#include "monster.h"
using namespace std;

Pica::Pica()
{
	cout << "피카츄 생성" << endl;
	hp = 100;
	exp = 0;
	level = 1;
}

void Pica::eat()
{
	Demon::eat();
	hp += 4;
}

void Pica::sleep()
{
	Demon::sleep();
	hp += 10;
}

bool Pica::exercise()
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

bool Pica::play()
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

void Pica::levelUp()
{
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Pica::electronic()
{
	cout << "피카츄 백만볼트 공격!" << endl;
	exp += 50;
	hp -= 20;
	levelUp();
	if (hp <= 0)
		return false;
	else
		return true;
}