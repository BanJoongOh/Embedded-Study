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
	//push()는 스택이 가득 차 있으면 false, 아니면 true를 리턴
	bool push(const CUSTOMER& item);
	//pop()은 스택이 비어 있으면 false, 아니면 true를 리턴
	bool pop(CUSTOMER& item);
};
#endif