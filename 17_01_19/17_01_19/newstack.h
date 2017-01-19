#ifndef STACK_H_
#define STACK_H_
#define MAX 10
typedef unsigned long Ulong;


typedef struct
{
	char fullname[35];
	double payment;
}CUSTOMER;


class Stack
{
private:
	CUSTOMER items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	//push()�� ������ ���� �� ������ false, �ƴϸ� true�� ����
	bool push(const CUSTOMER& item);
	//pop()�� ������ ��� ������ false, �ƴϸ� true�� ����
	bool pop(CUSTOMER& item);
};
#endif