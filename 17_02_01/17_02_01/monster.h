#pragma once
class Demon	//����� �������� ���� Ŭ����
{
protected:	//private�� �޸� ��ӿ����� ������ �����
	int hp;
	int exp;
	int level;
public:
	virtual void eat();
	virtual void sleep();
	virtual bool exercise();
	virtual bool play();
	virtual void levelUp();
	void printInfo();
};

class Pica : public Demon
{
public:
	Pica();
	void eat();
	void sleep();
	bool exercise();
	bool play();
	void levelUp();
	bool electronic();
};

class Pi : public Demon
{
public:
	Pi();
	void eat();
	void sleep();
	bool exercise();
	bool play();
	void levelUp();
	bool fire();
};

class Gobu : public Demon
{
public:
	Gobu();
	void eat();
	void sleep();
	bool exercise();
	bool play();
	void levelUp();
	bool water();
};