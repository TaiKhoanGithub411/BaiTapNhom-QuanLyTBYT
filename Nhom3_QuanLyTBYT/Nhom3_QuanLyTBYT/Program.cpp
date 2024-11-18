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
	BSTree root;
	DocFile(root, (char*)"TBYT.txt");
	XuatTieuDe();
	Xuat_NLR(root);
	system("PAUSE");
	return 1;
}
