#ifndef TABTEN
#define TABTEN

#include <string>

using std::string;

class TableTennis
{
private:
	string firstname;
	string lastname;
	bool table;
public:
	TableTennis(const string& fn = "default first",
				const string& ln = "default last", bool ta = false);
	void Name() const;
	bool Table() const
	{
		return table;
	}
	void ResetTable(bool v)
	{
		table = v;
	}
};


///////////////RatedPlayer Class ¼±¾ð

class RatedPlayer : public TableTennis
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string& fn = "None",
				const string& ln = "None", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennis& tp);
	unsigned int Rating()
	{
		return rating;
	}
	void ResetRating(unsigned int r)
	{
		rating = r;
	}
};
#endif