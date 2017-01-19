#include <iostream>
#include "cow.h"

using namespace std;

Cow::Cow()
{
	cout<<"叼弃飘 积己磊 积己"<<endl;
}

Cow::Cow(const char* name, const char* hobby, double weight)
{
	cout<<"积己磊 积己"<<endl;
	strcpy(m_name,name);

	m_hobby = new char[strlen(hobby)+1];
	strcpy(m_hobby,hobby);

	m_weight = weight;
}
Cow::Cow(const Cow &temp)
{
	cout<<"汗荤积己磊 积己"<<endl;
	strcpy(m_name, temp.m_name);

	m_hobby = new char[strlen(temp.m_hobby)+1];
	strcpy(m_hobby, temp.m_hobby);

	m_weight = temp.m_weight;
}
Cow::~Cow()
{
	cout<<"家戈磊 悼累!"<<endl;
	delete []m_hobby;
}
void Cow::ShowCow() const
{
	cout<<"  name : "<<m_name<<endl;
	cout<<" hobby : "<<m_hobby<<endl;
	cout<<"weight : "<<m_weight<<endl;
}