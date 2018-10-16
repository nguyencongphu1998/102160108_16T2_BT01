#include<string>
#include<iostream>
using namespace std;

class CongTrinhKhoaHoc
{
private:
	string ProduceNo;
	int ProduceYear;
	bool ProduceArea;
public:
	CongTrinhKhoaHoc(string = "test", int = 0, bool = true);
	~CongTrinhKhoaHoc();
	void setProduceNo(string);
	string getProduceNo();
	void setProduceYear(int);
	int getProduceYear();
	void setProduceArea(bool);
	bool getProduceArea();
	friend ostream &operator<<(ostream &, CongTrinhKhoaHoc &);
	friend istream &operator>>(istream &, CongTrinhKhoaHoc &);
};

