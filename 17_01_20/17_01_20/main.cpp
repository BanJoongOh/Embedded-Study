/*

- 클래스 생성시 자동생성
	1. 디폴트 생성자
	2. 디폴트 소멸자
	3. 디폴트 복사생성자(객체생성시에) : 멤버변수 : 멤버변수 간의 복사(얕은 복사)	// Person p1(p2)
	4. 디폴트 대입연산자(생성자호출후) : 멤버변수 : 멤버변수 간의 복사(얕은 복사)	// p1 = p2;
	5. this 포인터 : 객체의 주소를 가리킴

	Person(int _x = 0, int _y = ):x(_x),y(_y){}	== Person(int _x = 0, int _y = ){x = _x; y = _y;}
			MFC에서의 멤버변수 초기화							일반적인 멤버변수 초기화
	
- 연산자 오버로딩
	ex)
		void operator+(int val);

		void Point::operator+(int val)
		{
			x+=val;
			y+=val;
		}

		Point p;
		p+10	// 각 멤버변수에 10이 더해짐

	




*/
#include <iostream>
using namespace std;


#if 0
class Point
{
private:
	int x,y;
public:
	Point(int _x = 0, int _y = 0) : x(_x),y(_y) { }
	void showPosition();
	void operator+(int val);
};

void Point::showPosition()
{
	cout<<x<<' '<<y<<endl;
}

void Point::operator+(int val)
{
	x+=val;
//	y+=val;
}

void main()
{
	Point temp(10,20);
	temp.showPosition();

	temp+1000;	//p.operator+(10);
	temp.showPosition();
}
#endif



#if 0
#include "mytime.h"

void main()
{
	Time planning;
	Time coding(2, 40);
	Time fixing(5.55);
	Time total1,total2;

	cout<<"planning time = ";
	planning.Show();
	cout<<endl;
	
	cout<<"coding time = ";
	coding.Show();
	cout<<endl;

	cout<<"fixing time = ";
	fixing.Show();
	cout<<endl;
	
	total1 = coding.Sum(fixing);
	cout<<"coding.Sum(fixing) = ";
	total1.Show();
	cout<<endl;

	total2 = coding+fixing;
	cout<<"coding.Sum(fixing) = ";
	total1.Show();
	cout<<endl;
}
#endif



////////////////////////연산자 오버로딩 예제
#if 0
class Point
{
	int m_x,m_y;
public:
	Point(int x = 0, int y = 0):m_x(x),m_y(y){}
	void ShowPoint();
	Point operator-(const Point& temp1) const
	{
		Point temp;
		temp.m_x = m_x - temp1.m_x;
		temp.m_y = m_y - temp1.m_y;
		return temp;
	}
};

void Point::ShowPoint()
{
	cout<<m_x<<' '<<m_y<<endl;
}

void main()
{
	Point p1(2,3);
	Point p2(4,8);

	Point p3 = p2-p1;

	p3.ShowPoint();
}
#endif



////////////////////////연산자 오버로딩 예제
#if 0
class Point
{
	int m_x,m_y;
public:
	Point(int x = 0, int y = 0):m_x(x),m_y(y){}
	void ShowPoint();
	int operator!=(const Point& temp1) const
	{
		int flag;
		flag = 0;
		if(m_x!=temp1.m_x)
			flag++;
		else if(m_y!=temp1.m_y)
			flag++;

		if(flag!=0)
			return 1;
		else
			return 0;
	}
};

void Point::ShowPoint()
{
	cout<<m_x<<' '<<m_y<<endl;
}

void main()
{
	Point p1(2,3);
	Point p2(4,8);
	Point p3(4,8);

	if(p1!=p2)
		cout<<"다르구나"<<endl;
	else
		cout<<"같구나!"<<endl;
	
	if(p3!=p2)
		cout<<"다르구나"<<endl;
	else
		cout<<"같구나!"<<endl;

	p3.ShowPoint();
}
#endif



#if 0
class Point
{
private:
	int x,y;
public:
	Point(int _x=0, int _y=0):x(_x),y(_y){}
	void ShowPoint();
	friend Point operator+(const Point& p1, const Point& p2);	//전역함수가 멤버에 접근하기 위한 선언
	/*{
		Point temp(p1.x+p2.x, p1.y+p2.y);
		return temp;
	}*/
};

void Point::ShowPoint()
{
	cout<<x<<' '<<y<<endl;
}


Point operator+(const Point& p1, const Point& p2)	//Point 클래스 멤버함수가 아닌 전역함수임
{
		Point temp(p1.x+p2.x, p1.y+p2.y);
		return temp;
}


void main()
{
	Point p1(11,11);
	Point p2(55,33);
	Point p3 = p1+p2;
	p3.ShowPoint();
}
#endif


/////////////////////////전역함수는 멤버함수와 다르게 operator가 피연산자들을 모두 매개변수로 받을 수 있음
using std::ostream;
class Person
{
	char* name;
public:
	Person(char* _name)
	{
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	Person(const Person& p)
	{
		name = new char[strlen(p.name)+1];
		strcpy(name, p.name);
	}
	~Person()
	{
		delete []name;
	}
	friend ostream& operator<<(ostream& os, Person& p);
	char* getName()
	{
		return name;
	}
	Person& operator=(const Person& p);
};	//안에서 동작 = 인라인함수로 동작(잘 안쓰는게 좋음)

//밖에서의 함수는 일반 함수
Person& Person::operator=(const Person& p)
{
	delete []name;
	name = new char[strlen(p.name)+1];
	strcpy(name, p.name);
	return *this;
}

ostream& operator<<(ostream& os, Person& p)	//ostream은 output stream, cout을 받기 위함
{
	os<<p.getName();	//os는 cout과 동일
	return os;
}

void main()
{
	Person p1("Mr.Ban");
	Person p2("Mr.Kim");

	cout<<p1;		//전역함수이기 때문에(피연산자들을 모두 매개변수를 받음)&os가 cout, &p가 p1이 되는거임!
	cout<<endl;

	cout<<p2<<endl;	//ostream&의 전역함수는 os를 리턴하기 때문
	p1 = p2;
	cout<<p1<<endl;
}
	
	
	
	
	



	
	



	
	




