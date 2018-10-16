#include<iostream>
#include<iomanip>
#include"List.h"
using namespace std;

int main() {
	List ctkhs;
	List *search;
	CongTrinhKhoaHoc ctkh;
	int i;
	int k;
	int size;

	do 
	{
		cout << "-------------------------" << endl;
		cout << "Chuong trinh quan ly CTKH" << endl;
		cout << "-------------------------" << endl;
		cout << "1. Nhap 1 mang doi tuong" << endl;
		cout << "2. Hien thi danh sach doi tuong" << endl;
		cout << "3. Them moi 1 doi tuong o dau danh sach" << endl;
		cout << "4. Them moi 1 doi tuong o cuoi danh sach" << endl;
		cout << "5. Them moi 1 doi tuong o vi tri bat ki" << endl;
		cout << "6. Cap nhat 1 doi tuong" << endl;
		cout << "7. Xoa doi tuong o dau danh sach" << endl;
		cout << "8. Xoa doi tuong o cuoi danh sach" << endl;
		cout << "9. Xoa doi tuong o vi tri bat ki" << endl;
		cout << "10. Tim kiem theo nam san xuat" << endl;
		cout << "11. Sap xep theo nam san xuat" << endl;
		cout << "-------------------------" << endl;
		cout << "Nhap lenh:" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			cin >> ctkhs;
			break;
		case 2:
			ctkhs.Display();
			break;
		case 3:
			cin >> ctkh;
			ctkhs.AddFirst(ctkh);
			break;
		case 4:
			cin >> ctkh;
			ctkhs.AddLast(ctkh);
			break;
		case 5:
			cout << "Nhap vi tri can them moi" << endl;
			cin >> k;
			cin >> ctkh;
			ctkhs.Add(k, ctkh);
			break;		
		case 6:
			cin >> ctkh;
			ctkhs.Update(ctkh);
			break;
		case 7:
			ctkhs.DeleteFirst();
			break;
		case 8:
			ctkhs.DeleteLast();
			break;
		case 9:
			cout << "Nhap vi tri can xoa" << endl;
			cin >> k;
			ctkhs.Delete(k);
			break;
		case 10:
			i = 1;
			ctkhs.Sort(i);
			cout << "Nhap nam can tim kiem" << endl;
			cin >> k;
			search = ctkhs.BinarySearch(k);
			if((*search).getSize() == 0)
			{
				cout << "--------------" << endl;
				cout << "Khong tim thay" << endl;
				cout << "--------------" << endl;
			}
			else
			{
				cout << "--------------" << endl;
				cout << *search;
				cout << "--------------" << endl;
			}
			break;
		case 11:
			do
			{
				cout << "-------------" << endl;
				cout << "Chon cach sap xep" << endl;
				cout << "1.Sap xep tang dan" << endl;
				cout << "2.Sap xep giam dan" << endl;
				cin >> i;
			} 
			while (i !=2 && i != 1);
			ctkhs.Sort(i);
			ctkhs.Display();
			break;
		default:
			cout << "Vui long nhap dung lenh" << endl;
			break;
		}
	} 
	while (i != 0);
	
	system("pause");
	return 0;
}
