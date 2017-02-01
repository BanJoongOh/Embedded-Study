#include <iostream>
#include "monster.h"

using namespace std;
void Demon::eat()	//상속할 것이기 때문에 간단하게만 선언함
{
	cout << "밥 먹는다." << endl;
}
void Demon::sleep()	//상속할 것이기 때문에 간단하게만 선언함
{
	cout << "잠잔다." << endl;
}
bool Demon::exercise()	//상속할 것이기 때문에 간단하게만 선언함
{
	cout << "운동한다." << endl;
	return true;
}
bool Demon::play()	//상속할 것이기 때문에 간단하게만 선언함
{
	cout << "논다." << endl;
	return true;
}
void Demon::levelUp()	//상속할 것이기 때문에 간단하게만 선언함
{
	cout << "레벨업이다." << endl;
}
void Demon::printInfo()
{
	cout << "   hp : " << hp << endl;
	cout << "  exp : " << exp << endl;
	cout << "level : " << level << endl;
}
