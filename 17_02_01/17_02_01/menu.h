#pragma once	//헤더를 한번만 불러오게함

typedef struct abc {
	int num;
	char buf[255];
	struct abc *next;
	struct abc *prev;
}Data;

extern char *path;
extern Data *head;	// 다른 파일에서 선언된 변수를 접근 가능할 수 있게 해줌!
extern Data *tail;

void init();
void fileWrite();
void add(char *str);
void edit();
void del();
void stop();
void printA();
void printB();
Data* search(int num);


