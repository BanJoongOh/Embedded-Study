#pragma once
class Demon	//상속을 목적으로 만든 클래스
{
protected:	//private과 달리 상속에서는 접근을 허용함
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