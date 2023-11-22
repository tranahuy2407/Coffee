#include "Menu.h"
#include "Files.h"
#include"ProcessStr.h"
#include"Thucuong.h"
#include"NhanVien.h"
#include"Voucher.h"

double tiennhan;
double tienallsp;
double tienthua;
double slvc;
//Xây dựng menu đa cấp chứa các thông tin chức năng của cửa hàng 
int fMenuMain()
{
	system("cls");
	cout << "********************* MAIN MENU ************************" << endl;
	cout << "**                                                    **" << endl;
	cout << "**         1.Menu thuc uong.                          **" << endl;
	cout << "**         2.ThanhToan.                               **" << endl;
	cout << "**         3.Danh sach khach hang than thiet.         **" << endl;
	cout << "**         4.Quay lai trang login.                    **" << endl;
	cout << "**         5.Thoat.                                   **" << endl;
	cout << "**                                                    **" << endl;
	cout << "************ Cam on va hen gap lai quy khach ***********" << endl;
	return 5;
}
int fMenuDrink() {
	system("cls");
	cout << "************************ MENU DRINK *******************************" << endl;
	cout << "**                                                               **" << endl;
	cout << "**        1.Tat ca thuc uong.                                    **" << endl;
	cout << "**        2.Sap xep cac loai thuc uong thap gia tu thap den cao  **" << endl;
	//cout << "**        3.Tim thuc uong theo ten.                              **" << endl;
	cout << "**        3.Tro ve MainMenu.                                     **" << endl;
	cout << "**                                                               **" << endl;
	cout << "*********** Cam on va hen gap lai quy khach ***********************" << endl;
	return 3;
}
int fMenuPay()
{
	system("cls");
	cout << "********************* MENU PAY *************************" << endl;
	cout << "**                                                    **" << endl;
	cout << "**       1.Tao Hoa Don.                               **" << endl;
	cout << "**       2. Quay ve menu chinh.                       **" << endl;
	cout << "**                                                    **" << endl;
	cout << "************ Cam on va hen gap lai quy khach ***********" << endl << endl;
	return 2;
}
int fMenuBill()
{
	system("cls");
	cout << "*********************** MENU BILL **********************" << endl;
	cout << "**                                                    **" << endl;
	cout << "**      1. Xem hoa don va thanh toan.                 **" << endl;
	cout << "**      2. Quay ve Menu Pay.                          **" << endl;
	cout << "**      3. Quay ve Main Menu.                         **" << endl;
	cout << "**                                                    **" << endl;
	cout << "************ Cam on va hen gap lai quy khach! **********" << endl << endl;
	return 4;
}
int fMenuListVIP()
{
	system("cls");
	cout << "******************** MENU VIP **************************" << endl;
	cout << "**                                                    **" << endl;
	cout << "**       1. Xem Danh sach VIP.                        **" << endl;
	cout << "**       2. In danh sach VIP.                         **" << endl;
	cout << "**       3. Quy ve menu chinh                         **" << endl;
	cout << "**                                                    **" << endl;
	cout << "************ Cam on va hen gap lai quy khach ***********" << endl << endl;
	return 2;
}



int fSelectMenu(int NumberOfMenu)
{
	int command;
	bool check;
	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "--------------------" << endl;
		cout << "Lua chon trong khoang 1 - " << NumberOfMenu << ":";
		cin >> command;
		check = cin.fail();
		cin.clear();
	} while (check && (command < 1 || command > NumberOfMenu));
	return command;
}

void fRunMenuMain(int& Command, bool& Check)
{
	if (Command == 1)
	{
		int com = fSelectMenu(fMenuDrink());
		fRunMenuDrink(com, Command, Check);
	
	}
	else if (Command == 2)
	{
		int com = fSelectMenu(fMenuPay());	
		fRunMenuPay(com, Command, Check);
		//Ghi vao cuoi file
		/*string str = "";
		cout << "nhap thong tin khach hang:";
		_flushall();
		getline(cin, str, '$');
		WiriteEndOfFile("ListCus.txt", str);
		int n = atoi(ReadFirstLine("ListCus.txt").c_str());
		ReplaceFirstLineOfFile("ListCus.txt", to_string(n + 1), to_string(n));
		*/
	}
	else if(Command==3)
	{
		int com = fSelectMenu(fMenuListVIP());
		fRunMenuListVip(com, Command, Check);
	}
	else if (Command == 4)
	{
		// trở lại trang đăng nhập
		NhanVien::Start();
	}
	else {
		exit(0);
	}
}

int fRunMenuDrink(int& CommandSub, int& CommandMain, bool& Check)
{
	if (CommandSub == 1)
	{//Tiến hành mở file chứa thông tin món lên để đọc và in ra màn hình cho khách hàng thấy và sẽ cho khách hàng oder tên món theo mã nếu khách hàng chọn mã món trùng với mã món 
		//có sẵn trong cửa hàng thì tiến hành mở 1 file mới và lưu thông tin khách hàng oder vào đó.
		ifstream filein;
		filein.open("ListMenu.txt", ios_base::in);
		vector<MENU>ds_menu;
		system("cls");
		MENU::readMenu(filein, ds_menu);
		MENU::printMenu(ds_menu);
		filein.close();
		ofstream fileout;
		fileout.open("Bill.txt", ios_base::out);
		double thanhtien = 0;
		int m;
		double sl;
		slvc = 0;
		tienallsp = 0;
		fileout << "\n--------------------------GROUP FIVE COFFE SHOP------------------------------";
		fileout << "\n--------------------------180 Cao Lo, Quan 8, TPHCM--------------------------";
		fileout << "\n-------------------------------09xxxxxxxx-03xxxxxxx--------------------------";
		fileout << "\n---------------------------------HOA DON-------------------------------------";
		do {
			cout << "\nMoi quy khach nhap ma tu 0 - 14 tren menu de goi thuc uong:";
			cin >> m;
		
			if (m == -1) {
				break;
			}
			do {
				cout << "Nhap so luong muon oder: ";
				cin >> sl;
			} while (sl < 1 );
			thanhtien += (ds_menu[m].gia * sl);
			tienallsp += (ds_menu[m].gia * sl);
			MENU::luuFileThanhToan(fileout, ds_menu, m);
			fileout << "\n\tSo luong: " << sl;
			slvc += sl;
			cout << "\nThong tin da duoc luu vao danh sach thanh toan!";
			cout << "\nNhan -1 neu hoan thanh order!";
		} while (m != -1);
		fileout << "\nThanh  tien:" << thanhtien << "VND";
		fileout << "\nChuc quy khach ngon mieng!";
		fileout << "\nPass wifi: tranahuy247";
		fileout << "\n\n\n-------------Cam on va hen gap lai quy khach!----------------------------" << endl << endl;
		fileout.close();

		system("pause");

	}
    if(CommandSub==2)
	{
		//Sắp xếp theo giá tử thấp đến cao và cũng sẽ tiến hành như trên 
		ifstream fileinsort;
		fileinsort.open("ListMenu.txt", ios_base::in);
		vector<MENU>ds_menusort;
		system("cls");
		MENU::readMenu(fileinsort, ds_menusort);
		MENU::Sort(ds_menusort);
		fileinsort.close();
		ofstream fileoutsort;
		fileoutsort.open("Bill.txt", ios_base::out);
		int n;
		double slsort;
		double thanhtien = 0;
		tienallsp = 0;
		fileoutsort << "\n--------------------------GROUP FIVE COFFE SHOP------------------------------";
		fileoutsort << "\n--------------------------180 Cao Lo, Quan 8, TPHCM--------------------------";
		fileoutsort << "\n-------------------------------09xxxxxxxx-03xxxxxxx--------------------------";
		fileoutsort << "\n---------------------------------HOA DON-------------------------------------";
		do {
			cout << "\n\n\nMoi quy khach nhap ma tu 1 - 15 tren menu de goi thuc uong:";
			cin >> n;
			fileoutsort << endl;
			if (n == -1) {
				break;
			}
			do {
				cout << "\nNhap so luong muon oder: ";
				cin >> slsort;
			} while (slsort < 1);
			MENU::luuFileThanhToan(fileoutsort, ds_menusort, n);
			fileoutsort <<"\n\tSo luong: "<< slsort;
			fileoutsort << "\n--------------------------------";
			thanhtien += (ds_menusort[n].gia * slsort);
			tienallsp += (ds_menusort[n].gia * slsort);
			cout << "Thong tin da duoc luu vao danh sach thanh toan!";
			cout << "\nNhan -1 neu hoan thanh order!";
		} while (n!=-1);
		fileoutsort << "\nThanh  tien:"<<(size_t)thanhtien <<" VND";
		fileoutsort << "\nChuc quy khach ngon mieng!";
		fileoutsort << "\nPass wifi: tranahuy247";
		fileoutsort << "\n\n\n-------------Cam on va hen gap lai quy khach!---------------------------" << endl << endl;
		fileoutsort.close();
		system("pause");
	}
	else {
		return 0;
	}

}
int fRunMenuPay(int& CommandSub, int& CommandMain, bool& Check)
{
	if (CommandSub == 1)
	{
		int com = fSelectMenu(fMenuBill());
		fRunMenuBill(com, CommandMain, Check);
	}
	else
	{
		return 0;
	}

}
int fRunMenuBill(int& CommandSub, int& CommandMain, bool& Check)
{

    if (CommandSub == 1)
	{
		//Tiến hành đọc file thanh toán và in ra cho khách hàng khi khách hàng xem hóa đơn và thanh toán.
		//Nhập vào số tiền cần thanh toán và nếu thừa sẽ hiện ra số tiền thừa 
		system("cls");
		PrintBill(ReadFile("Bill.txt"));
		string ten, sdt;
		fstream fin;
		fin.open("Voucher.txt",ios_base::app|ios_base::in);
		vector<VOUCHER>dskh_vc;
			cout << "\nNhap ten khach hang:";
			getline(cin, ten);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nNhap sdt: ";
			getline(cin, sdt);
			VOUCHER::readvoucher(fin, dskh_vc);
			for (unsigned int i = 0; i < dskh_vc.size(); i++) {
				if (dskh_vc[i].tenKH == ten && dskh_vc[i].SDT == sdt) {
					dskh_vc[i].sl += slvc;
					if (dskh_vc[i].sl>=20)
					{
						cout << "\nQuy khach duoc tang 1 ly ngau nhien free theo chinh sach voucher cua quan";
					}
				}
				else
				{
					fin << ten << " ," << sdt << " ," << slvc;

				}
			}
			/*VOUCHER::kiemTraVoucher(fin, dskh_vc, ten, sdt, slvc);*/
		fin.close();
		do
		{
		cout << "\nNhap so tien thanh toan: ";
		cin >> tiennhan;
		if (tiennhan < tienallsp) {
			cout << "\nSo tien cua quy khach khong dung!";
			cout << "\nVui long nhap lai so tien can thanh toan!";
		}
		} while (tiennhan < tienallsp);
		tienthua = tiennhan - tienallsp;
		cout << "\nThanh toan thanh cong!";
		cout << "\nSo tien thua lai: " << tienthua << endl;
		ofstream fout;
		fout.open("doanhthu.txt", ios_base::app);
		time_t now = time(0);
		char* dt = ctime(&now);
		fout << "Thoi gian:" << dt << "\tTien nhan duoc la: " << tienallsp << endl;
		
		fout.close();
		if (tiennhan > 100000) {
			cout << "\nBan da tro thanh thanh vien VIP cua quan!";
			cout << "\nBan nhap thong tin cua minh de quan luu lai!";
			string str = "";
		cout << "Nhap thong tin cua ban bao gom ten va SDT:";
		_flushall();
		getline(cin, str, '$');
		cout << "\nNhan $ de ket thuc dien thong tin";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		WiriteEndOfFile("ListCus.txt", str);
		int n = atoi(ReadFirstLine("ListCus.txt").c_str());
		ReplaceFirstLineOfFile("ListCus.txt", to_string(n + 1), to_string(n));
		cout << "Thong tin cua ban da duoc luu vao thanh vien VIP";
		}
		cout << "\nCam on va hen gap lai quy khach! ";
		system("pause");
		exit(0);
	
	}
	else if (CommandSub == 2)
	{
		int com = fSelectMenu(fMenuPay());
		fRunMenuPay(com, CommandMain, Check);
		
	}
	else
	{

		return 0;// fix
	}
	
}

int fRunMenuListVip(int& CommandSub, int& CommandMain, bool& Check)
{
	if (CommandSub == 1)
	{
		//In ra file thanh vien vip 
		system("cls");
		PrintListCus(ReadFile("ListCus.txt"));
		system("pause");
	}
	else if (CommandSub == 2)
	{
	}
	else
	{
		return 0;
	}
}





