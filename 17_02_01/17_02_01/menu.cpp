
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
		//fputs("\n", fp);	����ؼ� �ٳѱ��� �����ǹǷ� �ּ�
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
	puts("������ �� ��ȣ : ");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL)
	{
		puts("���ο� ���� �Է� : ");
		scanf("%s", buf);
		strcpy(cur->buf, buf);
		//fputs("\n", cur->buf);
		strcat(cur->buf, "\n");	//���� �� ���� �߰�
	}
	else
		printf("not found\n");
}

void del()
{
	Data *cur = NULL;
	int num;
	char buf[255];
	puts("������ �� ��ȣ : ");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL)
	{
		puts("�����մϴ�.\n");
		if (cur->prev == NULL)	//ù ��° ���� prev�� NULL��!
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
		else if (cur->next == NULL)	// �� ������ ���
		{
			tail = tail->prev;
			tail->next = NULL;
			free(cur);
		}
		else // �߰� ���
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
		printf("%d �޸� ����\n", temp1->num);
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