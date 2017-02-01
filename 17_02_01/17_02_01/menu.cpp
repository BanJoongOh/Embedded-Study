
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void init()
{
	char buf[255];
	FILE *fp = fopen(path, "r");	//read only
	while (fgets(buf, 255, fp) != NULL)
	{
		add(buf);
	}
	fclose(fp);
}

void fileWrite()
{
	FILE *fp = fopen(path, "w");
	Data *cur = head;
	while (cur != NULL)
	{
		fputs(cur->buf, fp);
		//fputs("\n", fp);	계속해서 줄넘김이 누적되므로 주석
		cur = cur->next;
	}
	fclose(fp);
}

void add(char *str)
{
	Data *bmp = (Data*)malloc(sizeof(Data));
	strcpy(bmp->buf, str);
	if (head == NULL)
	{
		bmp->num = 1;
		head = bmp;
		bmp->prev = NULL;
	}else
	{
		bmp->num = tail->num + 1;
		tail->next = bmp;
		bmp->prev = tail;
	}
	tail = bmp;
	tail->next = NULL;
}

void edit()
{
	Data *cur = NULL;
	int num;
	char buf[255];
	puts("수정할 줄 번호 : ");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL)
	{
		puts("새로운 문장 입력 : ");
		scanf("%s", buf);
		strcpy(cur->buf, buf);
		//fputs("\n", cur->buf);
		strcat(cur->buf, "\n");	//수정 후 개행 추가
	}
	else
		printf("not found\n");
}

void del()
{
	Data *cur = NULL;
	int num;
	char buf[255];
	puts("삭제할 줄 번호 : ");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL)
	{
		puts("삭제합니다.\n");
		if (cur->prev == NULL)	//첫 번째 노드는 prev가 NULL임!
		{
			if (cur->next == NULL)
			{
				free(cur);
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
				free(cur);
			}
		}
		else if (cur->next == NULL)	// 맨 마지막 노드
		{
			tail = tail->prev;
			tail->next = NULL;
			free(cur);
		}
		else // 중간 노드
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
		}
	}
}

void stop()
{
	Data *temp1 = head;
	Data *temp2 = head->next;
	int count = 0;
	while(1)
	{
		printf("%d 메모리 해제\n", temp1->num);
		free(temp1);
		if (temp2==NULL)
			break;
		temp1 = temp2;	// temp = head->next
		temp2 = temp1->next;	
		++count;
	}
}


void printA()
{
	Data *cur = NULL;
	cur = head;
	while (cur != NULL)
	{
		printf("%d\t%s", cur->num, cur->buf);
		cur = cur->next;
	}
}

void printB()
{
	Data *cur = NULL;
	cur = tail;
	while (cur != NULL)
	{
		printf("%d\t%s", cur->num, cur->buf);
		cur = cur->prev;
	}
}

Data* search(int num)
{
	Data *cur = head;
	while (cur != NULL)
	{
		if (num == cur->num)
			return cur;
		cur = cur->next;
	}
	return NULL;
}