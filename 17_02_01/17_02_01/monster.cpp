#include <iostream>
#include "monster.h"

using namespace std;
void Demon::eat()	//����� ���̱� ������ �����ϰԸ� ������
{
	cout << "�� �Դ´�." << endl;
}
void Demon::sleep()	//����� ���̱� ������ �����ϰԸ� ������
{
	cout << "���ܴ�." << endl;
}
bool Demon::exercise()	//����� ���̱� ������ �����ϰԸ� ������
{
	cout << "��Ѵ�." << endl;
	return true;
}
bool Demon::play()	//����� ���̱� ������ �����ϰԸ� ������
{
	cout << "���." << endl;
	return true;
}
void Demon::levelUp()	//����� ���̱� ������ �����ϰԸ� ������
{
	cout << "�������̴�." << endl;
}
void Demon::printInfo()
{
	cout << "   hp : " << hp << endl;
	cout << "  exp : " << exp << endl;
	cout << "level : " << level << endl;
}
