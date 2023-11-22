
#include<iostream>
#include<fstream>
#include<string.h>
#include<istream>
using namespace std;
//Sử dụng class để lưu trữ thông tin và đăng nhập của khách hàng 
class NhanVien
{
public:
	char first_name[20];
	char last_name[20];
	char email[40];
	char password[20];
public:
	static void Regester(NhanVien& kh);
	static void Login(NhanVien& kh);
	static void Forgot(NhanVien& kh);
	static void Start();
	static void StartQuanLy();
	static void StartNhanVien();
	static void Show(NhanVien& kh);
};