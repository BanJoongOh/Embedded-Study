#ifndef STACK_H_
#define STACK_H_
#define MAX 10
typedef unsigned long Ulong;

class Stack
{
private:
	Ulong items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	//push()�� ������ ���� �� ������ false, �ƴϸ� true�� ����
	bool push(const Ulong& item);
	//pop()�� ������ ��� ������ false, �ƴϸ� true�� ����
	bool pop(Ulong& item);
};
#endif