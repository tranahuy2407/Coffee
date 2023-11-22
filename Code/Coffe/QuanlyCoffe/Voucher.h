#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<filesystem>
using namespace std;


class VOUCHER:public vector<VOUCHER> {
public:
	string tenKH;
	string SDT;
	int sl=0;
public:
	static void read1voucher(fstream& filein, VOUCHER& v);
	static void readvoucher(fstream& filein, vector<VOUCHER>& ds_voucher);
	//static void kiemTraVoucher(fstream& filein,vector<VOUCHER> ds, string ten, string sdt, double soluongvc);
};
