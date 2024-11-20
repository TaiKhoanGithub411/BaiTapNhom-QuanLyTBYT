#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
#include"Header.h";
#include"Thuvien.h"
#include"Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	BSTree root;
	CreatRoot(root);
	int menu;
	do
	{
		system("CLS");
		MenuChinh();
		menu = ChonMenu(6);
		XulyMenuChinh(menu, root);
		system("PAUSE");
	} while (menu>0);
}
