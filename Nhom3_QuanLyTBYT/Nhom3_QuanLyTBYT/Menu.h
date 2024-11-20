//=============================================================================
void MenuChinh();
int ChonMenu(int somenu);
void XulyMenuChinh(int menu, BSTree& root);
void MenuTK();
void XuLyMenuTK(int menu, BSTree root);
//=============================================================================
void MenuChinh()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu thiet bi";
	cout << "\n2.Xem du lieu thiet bi";
	cout << "\n3.Chuyen sang chuc nang tim kiem";
	cout << "\n4.Chuyen sang chuc nang sap xep";
	cout << "\n5.Chuyen sang chuc nang xoa";
	cout << "\n6.Chuyen sang chuc nang them";
	cout << "\n6.Chuyen sang chuc nang thong ke";
}
int ChonMenu(int somenu)
{
	int chon;
	for (;;)
	{
		cout << "\nNhap chon so menu: ";
		cin >> chon;
		if (0 <= chon && chon <= somenu)
			break;
	}
	return chon;
}
void XulyMenuChinh(int menu, BSTree& root)
{
	int chonmenu;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh\n";
		break;
	case 1:
		cout << "\n1.Tao du lieu thiet bi\n";
		DocFile(root, (char*)"TBYT.txt");
		cout << "\nDanh sach du lieu moi tao la:\n";
		XuatTieuDe();
		Xuat_NLR(root);
		break;
	case 2:
		cout << "\n2.Xem du lieu thiet bi\n";
		XuatTieuDe();
		Xuat_NLR(root);
		break;
	case 3:
		do
		{
			system("CLS");
			MenuTK();
			chonmenu = ChonMenu(5);
			XuLyMenuTK(chonmenu, root);
			system("PAUSE");
		} while (chonmenu>0);
	}
}
void MenuTK()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0.Tro ve chuong trinh chinh";
	cout << "\n1.Tim kiem theo ma";
	cout << "\n2.Tim kiem theo ten";
	cout << "\n3.Tim kiem theo ngay nhap";
	cout << "\n4.Tim kiem theo thang nhap";
	cout << "\n5.Tim kiem theo phong su dung";

}
void XuLyMenuTK(int menu, BSTree root)
{
	int kq;
	KeyType ma;
	BSTree p;
	char tentb[30];
	switch (menu)
	{
	case 0:
		cout << "\n0.Tro ve chuong trinh chinh";
		return;
	case 1:
		cout << "\n1.Tim kiem theo ma";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ma thiet bi can tim: ";
		cin >> ma;
		p = Search_MaTB(root, ma);
		if (p != NULL)
		{
			cout << "\nThiet bi co ma " << ma << "la\n";
			XuatTieuDe();
			XuatTB(p->infor);
		}
		else
			cout << "\nKhong co ma " << ma << " trong danh sach";
		break;
	case 2:
		cout << "\n2.Tim kiem theo ten\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ten thiet bi can tim: ";
		cin >> tentb;
		p = Search_TenTB(root, tentb);
		if (p != NULL)
		{
			cout << "\nThiet bi co ten " <<tentb << "la\n";
			XuatTieuDe();
			XuatTB(p->infor);
		}
		else
			cout << "\nKhong co ten " << tentb << " trong danh sach";
		break;
	}
}