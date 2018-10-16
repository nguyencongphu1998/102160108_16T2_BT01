#include "List.h"
void(*compare)(List *, CongTrinhKhoaHoc &key, int &left, int &right);

void Increase(List *list, CongTrinhKhoaHoc &key, int &left, int &right)
{
	while ((*list).ElementAt(left).getProduceYear() < key.getProduceYear())
	{
		left++;
	}

	while ((*list).ElementAt(right).getProduceYear() > key.getProduceYear())
	{
		right--;
	}
}

void Decrease(List *list, CongTrinhKhoaHoc &key, int &left, int &right)
{
	while ((*list).ElementAt(left).getProduceYear() > key.getProduceYear())
	{
		left++;
	}

	while ((*list).ElementAt(right).getProduceYear() < key.getProduceYear())
	{
		right--;
	}
}

List::List(int size)
{
	this->size = size;
	this->data = new CongTrinhKhoaHoc[this->size];
}


List::~List()
{
	delete[] this->data;
}


void List::Display()
{
	cout << *this;
}

void List::AddFirst(CongTrinhKhoaHoc &congTrinhKhoaHoc)
{
	this->size++;
	CongTrinhKhoaHoc *p = this->data;
	this->data = new CongTrinhKhoaHoc[this->size];

	for(int i = this->size - 1; i > 0 ; i--)
	{
		*(this->data + i) = *(p + i - 1);
	}

	*(this->data) = congTrinhKhoaHoc;
}

void List::AddLast(CongTrinhKhoaHoc &congTrinhKhoaHoc)
{
	this->size++;
	CongTrinhKhoaHoc *p = this->data;
	this->data = new CongTrinhKhoaHoc[this->size];

	for (int i = 0; i < this->size - 1; i++)
	{
		*(this->data + i) = *(p + i);
	}

	*(this->data + size - 1) = congTrinhKhoaHoc;
}

void List::Add(int k,CongTrinhKhoaHoc &congTrinhKhoaHoc)
{
	if (k > this->size)
	{
		cout << "Vị trí không hợp lệ";
	}
	else
	{
		this->size++;
		CongTrinhKhoaHoc *p = this->data;
		this->data = new CongTrinhKhoaHoc[this->size];

		for (int i = 0 ; i < this->size; i++)
		{
			if (i < k - 1)
			{
				*(this->data + i) = *(p + i);
			}

			if (i == k - 1)
			{
				*(this->data + i) = congTrinhKhoaHoc;
			}

			if(i > k - 1)
			{
				*(this->data + i) = *(p + i - 1);
			}
		}
	}
}

void List::Update(CongTrinhKhoaHoc &ctkh)
{
	int k = 0;
	for(int i = 0 ; i < this->size ; i++)
	{
		if (this->data[i].getProduceNo() == ctkh.getProduceNo())
		{
			this->data[i].setProduceArea(ctkh.getProduceArea());
			this->data[i].setProduceYear(ctkh.getProduceYear());
			k++;
		}
	}

	if(k == 0)
	{
		cout << "Khong tim thay doi tuong can cap nhat";
	}
}

void List::DeleteFirst()
{
	this->size--;
	CongTrinhKhoaHoc *p = this->data;
	this->data = new CongTrinhKhoaHoc[this->size];

	for(int i = 0; i < this->size; i++)
	{
		*(this->data + i) = *(p + i + 1);
	}
}

void List::DeleteLast()
{
	this->size--;
	CongTrinhKhoaHoc *p = this->data;
	this->data = new CongTrinhKhoaHoc[this->size];
	for (int i = 0; i < this->size; i++)
	{
		*(this->data + i) = *(p + i);
	}
}

void List::Delete(int k)
{
	if (k > this->size)
	{
		cout << "Vị trí không hợp lệ";
	}
	else
	{
		this->size--;
		CongTrinhKhoaHoc *p = this->data;
		this->data = new CongTrinhKhoaHoc[this->size];
		for (int i = 0; i < this->size; i++)
		{
			if (i >= k - 1)
			{
				*(this->data + i) = *(p + i + 1);
			}
			else
			{
				*(this->data + i) = *(p + i);
			}
		}
	}
}

List* List::BinarySearch(int produceYear)
{
	List* listSearch = new List(0);
	int left = 0;
	int right = this->getSize() - 1;

	while (left <= right)
	{
		int middle = left + (right - left) / 2;
		if (produceYear > this->data[middle].getProduceYear())
		{
			left = middle + 1;
		}
		if (produceYear < this->data[middle].getProduceYear())
		{
			right = middle - 1;
		}
		if (this->data[middle].getProduceYear() == produceYear)
		{
			(*listSearch).AddFirst(this->data[middle]);
			int newleft = middle - 1;
			int newright = middle + 1;
			bool check = true;

			while (check)
			{
				check = false;
				if (newleft >= 0)
				{
					if (this->data[newleft].getProduceYear() == produceYear)
					{
						(*listSearch).AddFirst(this->data[newleft]);
					}
					newleft--;
					check = true;
				}
				if (newright < this->getSize())
				{
					if (this->data[newright].getProduceYear() == produceYear)
					{
						(*listSearch).AddFirst(this->data[newright]);
					}
					newright++;
					check = true;
				}
			}
			return listSearch;
		}
	}
	return listSearch;
}

void List::Sort(int &i)
{
	switch (i)
	{
	case 1:
		compare = Increase; break;
	case 2:
		compare = Decrease; break;
	}

	this->QuickSort(0, this->size - 1, compare);

}

void List::QuickSort(int left, int right,void (*compare)(List *, CongTrinhKhoaHoc &, int &, int &))
{
	if (this->size == 0)
	{
		return;
	}

	if (left >= right)
	{
		return;
	}

	CongTrinhKhoaHoc key = this->data[left + (right - left) / 2];
	int i = left, j = right;

	while (i <= j)
	{		
		compare(this, key, i, j);	
		/*while (this->data[i].getProduceYear() > key.getProduceYear())
		{
			i++;
		}

		while (this->data[j].getProduceYear() < key.getProduceYear())
		{
			j--;
		}*/

		if (i <= j)
		{
			if (i < j)
			{
				CongTrinhKhoaHoc temp = this->data[i];
				this->data[i] = this->data[j];
				this->data[j] = temp;
			}

			i++;
			j--;
		}
	}

	if (left < j) QuickSort(left, j, compare);
	if (i < right) QuickSort(i, right, compare);
}

CongTrinhKhoaHoc& List::operator[](const int &i)
{
	CongTrinhKhoaHoc temp;
	return (i >= 0 && i < this->size) ? *(this->data + i) : temp;
}

istream &operator>>(istream &i, List &list)
{
	cout << "Nhap so luong can nhap" << endl;
	cin >> list.size;
	CongTrinhKhoaHoc ctkh;
	list.data = new CongTrinhKhoaHoc[list.size];
	for (int i = 0; i < list.size; i++)
	{
		cout << "Nhap ctkh " << (i + 1) << endl;
		cin >> ctkh;
		list.data[i] = ctkh;
	}
	return cin;
}

ostream &operator<<(ostream &o, List &list)
{
	if (list.size == 0) 
	{
		cout << "Khong tim thay" << endl;
		return cout;
	}

	for (int i = 0; i < list.size; i++) 
	{
		cout << list[i];
	}

	return cout;
}

CongTrinhKhoaHoc List::ElementAt(const int &i)
{
	return this->data[i];
}

List &List::operator=(const List &list)
{
	this->size = list.size;
	this->data = new CongTrinhKhoaHoc[this->size];
	for (int i = 0; i < this->size; i++) 
	{
		this->data[i] = list.data[i];
	}
	return *this;
}
