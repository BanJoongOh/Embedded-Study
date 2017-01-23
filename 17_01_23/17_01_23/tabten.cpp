#include "tabten.h"
#include <iostream>
using namespace std;

TableTennis::TableTennis(const string &fn, const string &ln, bool ta)
:firstname(fn), lastname(ln), table(ta) {}

void TableTennis::Name() const
{
	cout<<lastname<<", "<<firstname;
}


///////////////RatedPlayer ¸Þ¼­µå
RatedPlayer::RatedPlayer(unsigned int r, const std::string &fn, const std::string &ln, bool ht)
: TableTennis(fn,ln,ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennis& tp)
: TableTennis(tp), rating(r)
{}