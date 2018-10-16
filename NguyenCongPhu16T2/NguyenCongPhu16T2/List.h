#include"CongTrinhKhoaHoc.h"
#pragma once
class List
{
private :
	CongTrinhKhoaHoc *data;
	int size;
public:
	List(int = 0);
	~List();
	void Display();
	void AddFirst(CongTrinhKhoaHoc &);
	void AddLast(CongTrinhKhoaHoc &);
	void Add(int,CongTrinhKhoaHoc &);
	void Update(CongTrinhKhoaHoc &);
	void DeleteFirst();
	void DeleteLast();
	void Delete(int);
	List* BinarySearch(int);
	void Sort(int &);
	void QuickSort(int,int,void (*compare)(List *, CongTrinhKhoaHoc &, int &, int &));
	CongTrinhKhoaHoc& operator[](const int&);
	int getSize() {
		return size;
	};
	CongTrinhKhoaHoc ElementAt(const int&);
	friend istream &operator>>(istream &, List &);
	friend ostream &operator<<(ostream &, List &);
	List &operator=(const List &);

};

