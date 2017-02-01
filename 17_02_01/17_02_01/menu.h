#pragma once	//����� �ѹ��� �ҷ�������

typedef struct abc {
	int num;
	char buf[255];
	struct abc *next;
	struct abc *prev;
}Data;

extern char *path;
extern Data *head;	// �ٸ� ���Ͽ��� ����� ������ ���� ������ �� �ְ� ����!
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


