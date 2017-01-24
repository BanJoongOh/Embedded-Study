#ifndef CLASSIC
#define CLASSIC

class Cd
{
private:
	char performer[30];
	char label[30];
	int select;			//수록곡수
	double playtime;	//분 단위 연주 시간
public:
	Cd(char* s1, char* s2, int n, double x);
	Cd(const Cd& d);
	Cd(){}
	~Cd(){}
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	char present[30];
public:
	Classic(char* s1, char* s2, char* s3, int n, double x);
	Classic(){}
	~Classic(){}
	void Report() const;
	Classic& operator=(const Classic& d);
};
#endif

