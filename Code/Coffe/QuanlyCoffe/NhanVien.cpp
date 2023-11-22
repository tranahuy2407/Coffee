#include"NhanVien.h"
#include"Menu.h"
#include"Files.h"
#include"ProcessStr.h"

void NhanVien::Regester(NhanVien &nv) {
	   
		cout << "Nhap Ho: ";
		cin >> nv.first_name;
		cout << "Nhap Ten: ";
		cin >> nv.last_name;
		cout << "Nhap tai khoan email: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> nv.email;
		cout << "Nhap mat khau: ";
		cin >> nv.password;
		cout << "\nTai khoan cua nhan vien da duoc dang ky thanh cong!\n  ";
}

void NhanVien::Show(NhanVien& nv) {
		cout << nv.first_name << " " << nv.last_name << endl;
		cout << "Email : " << nv.email << endl;
		cout << "Password: " << nv.password << endl;
		cout << "----------------------------------------" << endl;

}
 
void NhanVien::Login(NhanVien& nv) {
		cout << "Xin chao! " << nv.first_name << " " << nv.last_name << 
			" tai khoan cua ban da duoc dang nhap thanh cong!" << endl;
		cout << "Email cua ban la : " << nv.email << endl;
		cout << "Nhan ENTER de tiep tuc!" << endl;
}

void NhanVien::Forgot(NhanVien& nv) {
		system("cls");
		cout << "Hi " << nv.first_name << " " << nv.last_name <<
			"Mat khau cua ban la :" <<nv.password<< endl;
}

	void NhanVien:: StartQuanLy() {
		NhanVien nv;
		int chon, c;
		cout << "********************** LOGIN ***************************" << endl;
		cout << "**                                                    **" << endl;
		cout << "**        1.Them nhan vien                            **" << endl;
		cout << "**        2.Xem doanh thu                             **" << endl;
		cout << "**        3.Xem cac tai khoan nhan vien               **" << endl;
		cout << "**                                                    **" << endl;
		cout << "********************************************************" << endl;

		cout << "\nNhap lua chon cua ban: "; 
		cin >> chon;

		switch(chon)
		{
		case 1:
		{
			system("cls");
			ofstream out("Login.txt", ios::binary | ios::app);
			if (!out) {
				cout << "File khong ton tai\n";
			}
			else
			{
				nv.Regester(nv);
				out.write((char*)&nv, sizeof(nv));
				out.close();
			}
			cout << "Nhan 1 de quay lai meunu lua chon: ";
			cin >> c;
			if (c == 1) {
				StartQuanLy();
			}
		}
			break;
		case 2: 
		{
			system("cls");
			PrintDoanhThu(ReadFile("doanhthu.txt"));
			system("pause");
	
		}
			  break;
		
		case 3	: {
			system("cls");
			ifstream in("Login.txt", ios::binary | ios::in);
			if (!in) {
				cout << "File khong ton tai! \n";
			}
			else
			{
				
				char srh_email[40];
				char srh_password[20];
				bool search = false;
				cout << "Nhap tai khoan email cua admin: ";
				cin >> srh_email;
				cout << "Nhap mat khau cua admin: ";
				cin >> srh_password;
				while (in.read((char*)&nv, sizeof(nv))) {
					if (strcmp(srh_email, "admin") == 0 && strcmp(srh_password, "admin") == 0) {
						nv.Show(nv);
						search = true;
					}
					if (search == false) {
						cout << "Xin loi! Tai khoan hoac mat khau cua ban khong phai cua admin!\n";

					}
				}
			}
			in.close();
			cout << "Nhan 1 de quay ve menu lua chon \n";
			cin >> c;
			if (c == 1) {
				StartQuanLy();
			}
		}
			  break;
		default:
		{
			cout << "Lua chon cua ban khong dung";
		}
    }
 }
 void NhanVien::StartNhanVien() {

	 NhanVien nv;
	 int chonlua, b;
	 cout << "********************** LOGIN ***************************" << endl;
	 cout << "**                                                    **" << endl;
	 cout << "**        1.Dang nhap de vao ca                       **" << endl;
	 cout << "**        2.Quen mat khau                             **" << endl;
	 cout << "**                                                    **" << endl;
	 cout << "********************************************************" << endl;
	 cout << "\nNhap chon lua cua ban: ";
	 cin >> chonlua;
	 switch (chonlua)
	 {
	 case 1: {
		 system("cls");
		 ifstream in("Login.txt", ios::binary | ios::in);
		 if (!in) {
			 cout << "File khong ton tai \n";
		 }
		 else
		 {
			 
			 char srh_email[40];
			 char srh_password[20];
			 bool search = false;
			 cout << "Nhap tai khoan email cua ban: ";
			 cin >> srh_email;
			 cout << "Nhap mat khau cua ban: ";
			 cin >> srh_password;
			 while (in.read((char*)&nv, sizeof(nv)))
			 {
				 if (strcmp(srh_email, nv.email) == 0 && strcmp(srh_password, nv.password) == 0) {

					 nv.Login(nv);
					 search = true;
					 system("pause");
					 int command;
					 bool check = 0;
					 do
					 {

						 if (check == 1)
						 {
							 fRunMenuMain(command, check);
							 check = 0;
						 }
						 else
						 {
							 command = fSelectMenu(fMenuMain());
							 fRunMenuMain(command, check);
						 }


					 } while (command != 3);
				 }
			 }
			 in.close();
			 if (search == false) {
				 cout << "Xin loi! Tai khoan hoac mat khau cua ban khong dung!\n";

			 }

		 }

	 }
		   break;
	 case 2: {
		 system("cls");
		 ifstream in("Login.txt", ios::binary | ios::in);
		 if (!in) {
			 cout << "File khong ton tai \n";
		 }
		 else
		 {
			 char srh_email[40];
			 bool search = false;
			 cout << "Nhap tai khoan email cua ban: ";
			 cin >> srh_email;
			 while (in.read((char*)&nv, sizeof(nv)))
			 {
				 if (strcmp(srh_email, nv.email) == 0) {
					 nv.Forgot(nv);
					 search = true;
				 }
			 }
			 in.close();
			 if (search == false) {
				 cout << "Xin loi! Email cua ban khong dung!";
			 }
		 }
		 cout << "Nhan 1 de quay lai menu lua chon \n";
		 cin >> b;
		 if (b == 1) {
			 StartQuanLy();
		 }
	 }
		   break;
	 default:
	 {
		 cout << "Lua chon cua ban khong dung";
	 }
    }
 }


 void NhanVien::Start()
 {
	 NhanVien nv;
	 int luachon,a;
	 cout << "********************** LOGIN ***************************" << endl;
	 cout << "**                                                    **" << endl;
	 cout << "**        1.Nhan Vien                                 **" << endl;
	 cout << "**        2.Quan Ly                                   **" << endl;
	 cout << "**                                                    **" << endl;
	 cout << "********************************************************" << endl;
	 cout << "\nNhap chon lua cua ban: ";
	 cin >> luachon;
	 switch (luachon) {
	 case 1:
	 {
		 system("cls");
		 NhanVien::StartNhanVien();
	 }
	 break;
	 case 2:
	 {
		 system("cls");
		 ifstream in("Login.txt", ios::binary | ios::in);
		 if (!in) {
			 cout << "File khong ton tai! \n";
		 }
		 else
		 {
			 
			 char srh_email[40];
			 char srh_password[20];
			 bool search = false;
			 cout << "Nhap tai khoan email cua admin: ";
			 cin >> srh_email;
			 cout << "Nhap mat khau cua admin: ";
			 cin >> srh_password;
			 while (in.read((char*)& nv, sizeof(nv))) {
				 if (strcmp(srh_email, "admin") == 0 && strcmp(srh_password, "admin") == 0) {
					 NhanVien::StartQuanLy();
					 search = true;
				 }
				 if (search == false) {
					 cout << "Xin loi! Tai khoan hoac mat khau cua ban khong phai cua admin!\n";

				 }
			 }
		 }
		 in.close();
		 cout << "Nhan 1 de quay ve menu lua chon \n";
		 cin >> a;
		 if (a == 1) {
			 Start();
		 }
		
	 }
	 break;
	 default:
	 {
		 cout << "Lua chon cua ban khong dung!";
	 }

	 }
 }