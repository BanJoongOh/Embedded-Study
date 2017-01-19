class Cow
{
private:
	char m_name[20];
	char* m_hobby;
	double m_weight;
public:
	Cow();
	Cow(const char* name, const char* hobby, double weight);
	Cow(const Cow& temp);
	~Cow();
	//Cow & operator = (const Cow& c);
	void ShowCow() const;	// 함수의 상수화(함수내에서는 수정 불가능)
};



