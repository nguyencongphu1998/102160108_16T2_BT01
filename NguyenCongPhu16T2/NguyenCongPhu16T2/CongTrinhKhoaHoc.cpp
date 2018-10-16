#include "CongTrinhKhoaHoc.h"

CongTrinhKhoaHoc::CongTrinhKhoaHoc(string produceNo,int produceYear,bool produceArea)
{
	this->ProduceNo = produceNo;
	this->ProduceYear = produceYear;
	this->ProduceArea = produceArea;
}


CongTrinhKhoaHoc::~CongTrinhKhoaHoc()
{
}

void CongTrinhKhoaHoc::setProduceArea(bool produceArea)
{
	this->ProduceArea = produceArea;
}

bool CongTrinhKhoaHoc::getProduceArea()
{
	return this->ProduceArea;
}

void CongTrinhKhoaHoc::setProduceYear(int produceYear)
{
	this->ProduceYear = produceYear;
}

int CongTrinhKhoaHoc::getProduceYear()
{
	return this->ProduceYear;
}

void CongTrinhKhoaHoc::setProduceNo(string produceNo)
{
	this->ProduceNo = produceNo;
}

string CongTrinhKhoaHoc::getProduceNo()
{
	return this->ProduceNo;
}

istream &operator>>(istream &i, CongTrinhKhoaHoc &ctkh)
{
	ctkh.setProduceYear(0);
	while (ctkh.getProduceYear() < 1900 || ctkh.getProduceYear() > 2018)
	{
		cout << "Nam san xuat gioi han tu 1900 tro ve sau" << endl;
		cout << "Nam san xuat = ";
		i >> ctkh.ProduceYear;
	}
	
	cout << "Ma san pham = ";
	i >> ctkh.ProduceNo;	

	cout << "Khu vuc = ";
	i >> ctkh.ProduceArea;

	return cin;
}

ostream &operator<<(ostream &o, CongTrinhKhoaHoc &ctkh)
{
	o << "Khu vuc : " << ctkh.getProduceArea() << endl;
	o << "Ma san pham : " << ctkh.getProduceNo() << endl;
	o << "Nam san xuat : " << ctkh.getProduceYear() << endl;
	return o;
}
