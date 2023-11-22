#include "ProcessStr.h"

void PrintListCus(list<string> ListCus)
{
	string s = ListCus.front();
	int n = atoi(s.c_str());
	cout << "-------------Danh sach khach VIP------------" << endl << endl;

	cout << "Tong so co " << n << " khach!-----------------" << endl << endl;
	ListCus.pop_front();
	for (list<string>::iterator i = ListCus.begin(); i != ListCus.end(); i++)
	{
		cout << *i << endl;
	}

}
void PrintBill (list<string> Bill)
{
	string s = Bill.front();
	int n = atoi(s.c_str());

	for (list<string>::iterator i = Bill.begin(); i != Bill.end(); i++)
	{
		cout << *i << endl;
	}

}
void PrintDoanhThu(list<string> DoanhThu)
{
	string s = DoanhThu.front();
	int n = atoi(s.c_str());

	for (list<string>::iterator i = DoanhThu.begin(); i != DoanhThu.end(); i++)
	{
		cout << *i << endl;
	}

}
