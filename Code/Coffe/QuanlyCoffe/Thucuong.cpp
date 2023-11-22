#include"Thucuong.h"

//Đọc 1 sản phẩm bao gồm mã dấu cách giữa các thôgn tin có trong file món
void MENU::read1sp(ifstream& filein, MENU& m) {
	filein >> m.ma;
	filein.seekg(1, 1);
	getline(filein, m.tenMon, ',');
	filein.seekg(1, 1);
	filein >> m.gia;
}
//Hàm in ra thông tin của 1 loại đồ uống 
void MENU::print1sp(MENU  m) {
	cout << m.ma << "." << m.tenMon << endl;
	cout << "Gia" << ":";
	cout << m.gia << endl;
	cout << "-------------------";
}
//Hàm đọc toàn bộ thông tin của tất cả món có trong file sử dụng vòng lặp nếu chưa hết file thì khai báo 1 Menu gọi lại hàm đọc 1 và tiến hành lấy thông tin đã đọc đưa vào trong Menu 
 void MENU::readMenu(ifstream& filein, vector<MENU> &ds_menu){
	while(filein.eof()==false)
	{
		MENU m;
		read1sp(filein, m);
		ds_menu.push_back(m);
	}
	
}
 // In ra danh sách món bằng cách sử dụng vòng lặp duyệt từ đầu đến cuối và gọi lại hàm in 1 món để in ra tất cả thông tin của món được lưu trong Menu
 void MENU::printMenu(vector<MENU> ds) {
	 cout << "----------------------------------------------------------" << endl;
	 cout << "\t\tTen loai thuc uong" << endl;
	 for (unsigned int i = 0; i < ds.size(); i++)
	 {

		 print1sp(ds[i]);
		 cout << endl;
	 }
	 cout << "\n\n\n-------------Cam on va hen gap lai quy khach!------------" << endl << endl;
 }
 //Hàm ghi thông tin của món vào file thanh toán 
 void MENU::ghiThongTinBill(ofstream& fileout, MENU m) {
	 
	 fileout <<endl<<"\t" << m.ma << "." << m.tenMon << endl << "\t" << "Gia: " << m.gia;
	

 }
 //Hàm lưu tất cả thôgn tin của món vào file thanh toán  sử dụng vòng lặp và so sánh nếu khách hàng nhập vào đúng như mã đó thì gọi lại hàm ghi thông tin và ghi thông tin vào file 
 void MENU::luuFileThanhToan(ofstream& fileout, vector<MENU> ds, int n) {
	
	 for (unsigned int i = 0; i < ds.size(); i++) {
		 if (ds[i].ma == n) {
			 ghiThongTinBill(fileout, ds[i]);
		 }
		 cout << endl;
	 }

 }
 //hàm so sánh giá tiền 
 bool MENU::comp(MENU m, MENU n) {
	 return (m.gia < n.gia);
 }
 //sử dụng vòng lặp duyệt qua hết toàn bộ thức uống có trong danh sách và tiến hành sắp xếp bàng hàm Sort có sẵn trong vector và gọi hàm so sánh giá để sắp xếp từ thấp đến cao
 void MENU::Sort(vector<MENU> ds) {
	 cout << "--------------------------------------------------------------------------------" << endl;
	 cout << "\t\tTen loai thuc uong theo gia tu thap den cao" << endl;
	 for (unsigned i = 0; i < ds.size(); i++) {
		 sort(ds.begin(), ds.end(), comp);
		 print1spSort(ds[i]);
		 cout << endl;
	 }
	 cout << "\n\n\n-------------Cam on va hen gap lai quy khach!------------" << endl << endl;
 }
 //hàm in 1 sản phẩm được gọi lên hàm sắp xếp để in ra thông tin của món đó sau khi sắp xếp 
 void MENU::print1spSort(MENU  m) {
	 cout << m.ma;
	 cout << "." << m.tenMon << endl;
	 cout << "Gia" << ":"; 
	 cout << m.gia << endl;
	 cout << "-------------------";
 }
 //
 //MENU MENU::TimViTriPhanTuTrongVector(vector<MENU> ds, MENU m,string ten)
 //{
	// vector<MENU>::iterator vitri;
	// vitri = find(m.begin(), m.end(), ten);
	// return *vitri;
 //}
 