
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<filesystem>
using namespace std;
//
//sử dụng vector để lưu trữ thông tin của thưcs uống bao gồm mã, tên món và giá của món đó 
class MENU : public vector<MENU> 
{
public:
	int ma = 0;
    string tenMon; 
	double gia = 0;
public:
	static void read1sp(ifstream &filein,MENU &m);
	static void print1sp(MENU m);
	static void readMenu(ifstream& filein, vector<MENU> &ds_menu);
	static void printMenu(vector<MENU> ds);
	static void ghiThongTinBill(ofstream& fileout, MENU m);
	static void luuFileThanhToan(ofstream& fileout, vector<MENU>ds,int n);
	static bool comp(MENU m, MENU n);
	static void Sort(vector<MENU>ds);
	static void print1spSort(MENU  m);
	/*static  MENU TimViTriPhanTuTrongVector(vector<MENU> ds, MENU m,string ten);*/
};

