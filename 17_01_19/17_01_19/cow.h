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
	void ShowCow() const;	// �Լ��� ���ȭ(�Լ��������� ���� �Ұ���)
};



