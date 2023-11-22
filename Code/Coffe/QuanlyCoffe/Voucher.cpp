#include "Voucher.h"

void VOUCHER::read1voucher(fstream& filein, VOUCHER& v) {
	getline(filein, v.tenKH, ',');
	filein.seekg(1, 1);
	getline(filein, v.SDT, ',');
	filein.seekg(1, 1);
	filein >> v.sl;
}
void VOUCHER::readvoucher(fstream& filein, vector<VOUCHER>& ds_voucher) {
	while (filein.eof() == false)
	{
		VOUCHER v;
		read1voucher(filein, v);
		ds_voucher.push_back(v);	
	}
}
//void VOUCHER::kiemTraVoucher(fstream& filein,vector<VOUCHER> ds, string ten,string sdt,double soluongvc) {
//
//	for (unsigned int i = 0; i < ds.size(); i++) {
//		if (ds[i].tenKH == ten && ds[i].SDT == sdt) {
//			ds.erase(ds.begin() + i);
//			filein << ten << " ," << sdt << " ," << soluongvc;
//		}
//		if (soluongvc >= 20) {
//			cout << "\nQuy khach duoc tang 1 ly ngau nhien free theo chinh sach voucher cua quan";
//		}
//	}
//
//}