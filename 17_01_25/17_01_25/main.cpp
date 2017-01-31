/*

- 표준 템플릿 라이브러리(STL)
컨테이너 단위로 어떤 데이터든 넣을 수 있는데 이를 가리키는 포인터를 이터레이터 라고함!
vector : 컨테이너를 배열화함
  list : 컨테이너안의 데이터

기존의 배열은 데이터가 늘어날경우 재할당을 해야하는데 vector를 사용하면 내부적으로 처리가 됨!


*/



#include <iostream>
using namespace std;


#if 0
////////////////////////////////////템플릿 예제
template <typename co>
void Swap(co& num1, co& num2);

template <typename eco>
eco Add(eco num1, eco num2);

void main()
{
	int i = 10;
	int j = 20;
	cout<<"i, j = "<<i<<", "<<j<<endl;
	cout<<"template을 사용한 Swap"<<endl;
	Swap(i,j);
	cout<<"바뀐 결과  i, j = "<<i<<", "<<j<<endl;
	cout<<"더하자 "<<Add(i,j)<<endl<<endl;

	double x = 24.4;
	double y = 77.11;
	cout<<"x, y = "<<x<<", "<<y<<endl;
	cout<<"template을 사용한 Swap"<<endl;
	Swap(x,y);
	cout<<"바뀐 결과  x, y = "<<x<<", "<<y<<endl;
	cout<<"더하자 "<<Add(x,y)<<endl<<endl;
}

template <typename co>
void Swap(co& num1, co& num2)
{
	co temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

template <typename eco>
eco Add(eco num1, eco num2)
{
	return num1+num2;
}
#endif



#if 0
#include <string>
#include <cctype>
#include "stack.h"

void main()
{
	Stack<string> st;	//Stack 클래스에 string형 데이터를 담은 st 객체를 선언
	char ch;
	string po;
	cout<<"주문서를 추가하려면 A, 주문서를 처리하려면 P, \n";
	cout<<"종료하려면 Q를 입력하시오,\n";

	while(cin >> ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')	//fflush(stdin)과 동일하게 버퍼를 비워줌
			continue;
		if(!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch(ch)
		{
		case 'A' :
		case 'a' :	cout<<"추가할 주문서의 번호를 입력하시오 : ";
					cin>>po;
					if(st.isfull())
						cout<<"스택이 가득 차 있음!\n";
					else
						st.push(po);
					break;
		case 'P' :
		case 'p' :	if(st.isempty())
						cout<<"스택이 비어 있음!\n";
					else
					{
						st.pop(po);
						cout<<"#"<<po<<"주문서를 처리 했음!\n";
					}
					break;
		}
		cout<<"주문서를 추가하려면 A, 주문서를 처리하면 P, \n";
		cout<<"종료하려면 Q를 입력하시오,\n";
	}
	cout<<"프로그램을 종료함!\n";
}
					
#endif



#if 0
#include <vector>

void main()
{
	vector<int> V1;
	//vector<int> V1(4);	//정수 4개의 메모리 확보
	//vector<int> V1(4,10);	//정수 4개를 10으로 초기화
	V1.push_back(20);
	V1.push_back(30);
	V1.push_back(40);
	V1.push_back(50);
	V1.push_back(60);

	cout<<"V1.capacity() = "<<V1.capacity()<<endl;

	cout<<"for : "<<endl;
	for(int k = 0; k < V1.size(); ++k)
		cout<<V1[k]<<endl;

	V1.erase(V1.begin() + 2);

	cout<<endl<<"iterator : "<<endl;
	vector<int>::iterator it1;

	for(it1 = V1.begin(); it1 != V1.end(); ++it1)
		cout<<*it1<<endl;

	cout<<endl<<"reverse_iterator : "<<endl;

	V1.insert(V1.begin() + 2, 77);

	vector<int>::reverse_iterator it2;

	for(it2 = V1.rbegin(); it2 != V1.rend(); ++it2)
		cout<<*it2<<endl;

	V1.clear();
}
#endif




#if 0
#include <list>

void main()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_front(20);
	L1.push_back(30);
	L1.push_back(40);

	L1.insert(L1.begin(), 50);
	cout<<"L1.size() = "<<L1.size()<<endl;

	list<int>::iterator it1;
	for(it1 = L1.begin(); it1 != L1.end(); ++it1)
		cout<<*it1<<endl;

	cout<<endl<<"L1.fornt() = "<<L1.front()<<endl;
	L1.pop_front();

	for(it1 = L1.begin(); it1 != L1.end(); ++it1)
		cout<<*it1<<endl;
	cout<<endl;

	L1.clear();
}
#endif



#include <list>

class Point
{
	int x,y;
public:
	Point(int x = 0, int y = 0);
	Point(const Point& pt);
	~Point(){cout<<"Destructor\n";}
	void SetPt(int x, int y);
	int GetX(){return x;}
	int GetY(){return y;}
	Point& operator=(const Point& pt);
	friend ostream& operator << (ostream& out, Point& pt);
};

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& pt)
{
	cout<<"Copy Constructor"<<endl;
	x = pt.x;
	y = pt.y;
}

void Point::SetPt(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point& Point::operator=(const Point& pt)
{
	this->x = pt.x;
	this->y = pt.y;
	return *this;
}

ostream& operator<<(ostream& out, Point& pt)
{
	out<<"("<<pt.x<<", "<<pt.y<<") "<<endl;
	return out;
}

void main()
{
	list<Point> L1;
	Point pt1(10,20);

	L1.push_back(pt1);

	pt1.SetPt(10, 20);
	L1.push_back(pt1);

	pt1.SetPt(30, 40);
	L1.push_back(pt1);

	list<Point>::iterator it1;
	cout<<"Using (*it).GetX(), (*it).GetY()"<<endl;
	for(it1 = L1.begin(); it1 != L1.end(); ++it1)
		cout<<"("<<(*it1).GetX()<<", "<<(*it1).GetY()<<") "<<endl;
	cout<<endl;

	cout<<endl<<"operator << friend function!" << endl;
	for(it1 = L1.begin(); it1 != L1.end(); ++it1)
		cout<<*it1<<endl;
}

















