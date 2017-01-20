/*

- Ŭ���� ������ �ڵ�����
	1. ����Ʈ ������
	2. ����Ʈ �Ҹ���
	3. ����Ʈ ���������(��ü�����ÿ�) : ������� : ������� ���� ����(���� ����)	// Person p1(p2)
	4. ����Ʈ ���Կ�����(������ȣ����) : ������� : ������� ���� ����(���� ����)	// p1 = p2;
	5. this ������ : ��ü�� �ּҸ� ����Ŵ

	Person(int _x = 0, int _y = ):x(_x),y(_y){}	== Person(int _x = 0, int _y = ){x = _x; y = _y;}
			MFC������ ������� �ʱ�ȭ							�Ϲ����� ������� �ʱ�ȭ
	
- ������ �����ε�
	ex)
		void operator+(int val);

		void Point::operator+(int val)
		{
			x+=val;
			y+=val;
		}

		Point p;
		p+10	// �� ��������� 10�� ������

	




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



////////////////////////������ �����ε� ����
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



////////////////////////������ �����ε� ����
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
		cout<<"�ٸ�����"<<endl;
	else
		cout<<"������!"<<endl;
	
	if(p3!=p2)
		cout<<"�ٸ�����"<<endl;
	else
		cout<<"������!"<<endl;

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
	friend Point operator+(const Point& p1, const Point& p2);	//�����Լ��� ����� �����ϱ� ���� ����
	/*{
		Point temp(p1.x+p2.x, p1.y+p2.y);
		return temp;
	}*/
};

void Point::ShowPoint()
{
	cout<<x<<' '<<y<<endl;
}


Point operator+(const Point& p1, const Point& p2)	//Point Ŭ���� ����Լ��� �ƴ� �����Լ���
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


/////////////////////////�����Լ��� ����Լ��� �ٸ��� operator�� �ǿ����ڵ��� ��� �Ű������� ���� �� ����
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
};	//�ȿ��� ���� = �ζ����Լ��� ����(�� �Ⱦ��°� ����)

//�ۿ����� �Լ��� �Ϲ� �Լ�
Person& Person::operator=(const Person& p)
{
	delete []name;
	name = new char[strlen(p.name)+1];
	strcpy(name, p.name);
	return *this;
}

ostream& operator<<(ostream& os, Person& p)	//ostream�� output stream, cout�� �ޱ� ����
{
	os<<p.getName();	//os�� cout�� ����
	return os;
}

void main()
{
	Person p1("Mr.Ban");
	Person p2("Mr.Kim");

	cout<<p1;		//�����Լ��̱� ������(�ǿ����ڵ��� ��� �Ű������� ����)&os�� cout, &p�� p1�� �Ǵ°���!
	cout<<endl;

	cout<<p2<<endl;	//ostream&�� �����Լ��� os�� �����ϱ� ����
	p1 = p2;
	cout<<p1<<endl;
}
	
	
	
	
	



	
	



	
	




