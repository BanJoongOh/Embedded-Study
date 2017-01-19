#include <cstring>
#include "stringbad.h"

using namespace std;

StringBad::StringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	cout<<"按眉 积己\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy(str, "C++");
	cout<<"叼弃飘 按眉 积己\n";
}

StringBad::~StringBad()
{
	cout<<"\""<<str<<"\"按眉 家戈, \n";
	delete []str;
}

/*
ostream & operator<<(ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
*/