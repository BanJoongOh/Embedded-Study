#include <cstring>
#include "stringbad.h"

using namespace std;

StringBad::StringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	cout<<"��ü ����\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy(str, "C++");
	cout<<"����Ʈ ��ü ����\n";
}

StringBad::~StringBad()
{
	cout<<"\""<<str<<"\"��ü �Ҹ�, \n";
	delete []str;
}

/*
ostream & operator<<(ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
*/