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
	//push()는 스택이 가득 차 있으면 false, 아니면 true를 리턴
	bool push(const Ulong& item);
	//pop()은 스택이 비어 있으면 false, 아니면 true를 리턴
	bool pop(Ulong& item);
};
#endif