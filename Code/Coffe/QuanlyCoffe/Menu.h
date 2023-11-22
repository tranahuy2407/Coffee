#ifndef __MENU_H__
#define __MENU_H__
#define _CRT_SECURE_NO_WARNINGS
//
#include <iostream>
using namespace std;

int fMenuDrink();

int fMenuMain();
//menu con 01
int fMenuPay();
//menu cháu; con của menu con 01
int  fMenuBill();
//menu con 02
int fMenuListVIP();
//Hàm lựa chọn chức năng trong từng menu
int fSelectMenu(int NumberOfMenu);
//
void fRunMenuMain(int& Command, bool& Check);
//
int fRunMenuDrink(int& CommandSub, int& CommandMain, bool& Check);
//
int fRunMenuPay(int& CommandSub, int& CommandMain, bool& Check);
//
int fRunMenuBill(int& CommandSub, int& CommandMain, bool& Check);
//
int fRunMenuListVip(int& CommandSub, int& CommandMain, bool& Check);
//

#endif // !__MENU_H__

