//=============================================================================
void MenuChinh();
int ChonMenu(int somenu);
void XulyMenuChinh(int menu, BSTree& root);
void MenuTK();
void XuLyMenuTK(int menu, BSTree root);
void MenuSapXep();
void XuLyMenuSX(int menu, BSTree& root);
void MenuXoa();
void XuLyMenuXoa(int menu, BSTree& root);
void MenuThem_ChinhSua();
void XuLyMenuThem_ChinhSua(int menu, BSTree& root);
//=============================================================================
void MenuChinh()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao du lieu thiet bi";
	cout << "\n2. Xem du lieu thiet bi";
	cout << "\n3. Chuyen sang chuc nang tim kiem";
	cout << "\n4. Chuyen sang chuc nang sap xep";
	cout << "\n5. Chuyen sang chuc nang xoa";
	cout << "\n6. Chuyen sang chuc nang them - chinh sua";
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
		cout << "\n0. Thoat chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao du lieu thiet bi\n";
		DocFile(root, (char*)"TBYT.txt");
		cout << "\nDanh sach du lieu moi tao la:\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem du lieu thiet bi\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << endl;
		break;
	case 3:
		do
		{
			system("CLS");
			MenuTK();
			chonmenu = ChonMenu(5);
			XuLyMenuTK(chonmenu, root);
			system("PAUSE");
		} while (chonmenu > 0);
	case 4:
		do
		{
			system("CLS");
			MenuSapXep();
			chonmenu = ChonMenu(5);
			XuLyMenuSX(chonmenu, root);
			system("PAUSE");
		} while (chonmenu > 0);
		break;
	case 5:
		do
		{
			system("CLS");
			MenuXoa();
			chonmenu = ChonMenu(5);
			XuLyMenuXoa(chonmenu, root);
			system("PAUSE");
		} while (chonmenu > 0);
		break;
	case 6:
		do
		{
			system("CLS");
			MenuThem_ChinhSua();
			chonmenu = ChonMenu(5);
			XuLyMenuThem_ChinhSua(chonmenu, root);
			system("PAUSE");
		} while (chonmenu > 0);
		break;
	}
}
void MenuTK()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0. Tro ve chuong trinh chinh";
	cout << "\n1. Tim kiem theo ma";
	cout << "\n2. Tim kiem theo ten";
	cout << "\n3. Tim kiem theo ngay/thang/nam nhap";
	cout << "\n4. Tim kiem theo ngay/thang/nam su dung";
	cout << "\n5. Tim kiem theo phong su dung";

}
void XuLyMenuTK(int menu, BSTree root)
{
	int kq, ngay, thang, nam;
	KeyType ma;
	BSTree p, q;
	CreatRoot(p); CreatRoot(q);
	char x[30];
	switch (menu)
	{
	case 0:
		cout << "\n0. Tro ve chuong trinh chinh";
		return;
	case 1:
		cout << "\n1. Tim kiem theo ma";
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
		cout << "\n2. Tim kiem theo ten\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ten thiet bi can tim: ";
		cin >> x;
		p = Search_TenTB(root, x);
		if (p != NULL)
		{
			cout << "\nThiet bi co ten " << x << "la\n";
			XuatTieuDe();
			Xuat_LNR(p);
		}
		break;
	case 3:
		cout << "\n3. Tim kiem theo ngay/thang/nam nhap\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ngay: "; cin >> ngay;
		cout << "\nNhap thang: "; cin >> thang;
		cout << "\nNhap nam: "; cin >> nam;
		p = Search_NgayThangNamNhap(root, TaoNgayThangNam(ngay, thang, nam));
		if (p != NULL)
		{
			cout << "\Thiet bi co ngay nhap " << ngay << "/" << thang << "/" << nam << "\n";
			XuatTieuDe();
			Xuat_LNR(p);
		}
		else
			cout << "\Khong co thiet bi co ngay nhap " << ngay << "/" << thang << "/" << nam << "\n";
		break;
	case 4:
		cout << "\n4. Tim kiem theo ngay/thang/nam su dung\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ngay: "; cin >> ngay;
		cout << "\nNhap thang: "; cin >> thang;
		cout << "\nNhap nam: "; cin >> nam;
		p = Search_NgayThangNamSD(root, TaoNgayThangNam(ngay, thang, nam));
		if (p != NULL)
		{
			cout << "\Thiet bi co ngay su dung " << ngay << "/" << thang << "/" << nam << "\n";
			XuatTieuDe();
			Xuat_LNR(p);
		}
		else
			cout << "\Khong co thiet bi co ngay su dung " << ngay << "/" << thang << "/" << nam << "\n";
		break;
	case 5:
		cout << "\n4. Tim kiem theo phong su dung\n";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap phong su dung thiet bi can tim: ";
		cin >> x;
		p = Search_PhongSD(root, x);
		if (p != NULL)
		{
			cout << "\nPhong su dung thiet bi co ten " << x << "\n";
			XuatTieuDe();
			Xuat_LNR(p);
		}
		else
			cout << "\nKhong co phong " << x << " trong danh sach";
		break;
	}
	
}
void MenuSapXep()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0. Tro ve chuong trinh chinh";
	cout << "\n1. Sap xep theo ma thiet bi";
	cout << "\n2. Sap xep theo ten";
	cout << "\n3. Sap xep theo phong su dung";
}
void XuLyMenuSX(int menu, BSTree& root)
{
	switch (menu)
	{
	case 0:
		cout << "\n0. Tro ve chuong trinh chinh\n";
		break;
	case 1:
		cout << "\n1. Sap xep theo ma thiet bi\n";
		XuatTieuDe();
		break;
	case 2:
		cout << "\n2. Sap xep theo ten\n";
		XuatTieuDe();
		break;
	case 3:
		cout << "\n3. Sap xep theo phong su dung\n";
		XuatTieuDe();
		break;
		
	}
}
void MenuXoa()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0. Tro ve chuong trinh chinh";
	cout << "\n1. Xoa theo ma thiet bi";
	cout << "\n2. Xoa theo ten";
	cout << "\n3. Xoa theo ngay thang nam nhap";
	cout << "\n4. Xoa theo phong su dung";
}
void XuLyMenuXoa(int menu, BSTree& root)
{
	int kq, ngay, thang, nam;
	KeyType ma;
	BSTree p, q;
	CreatRoot(p); CreatRoot(q);
	char x[30];
	switch (menu)
	{
	case 0:
		cout << "\n0. Tro ve chuong trinh chinh\n";
		break;
	case 1:
		cout << "\n1. Xoa theo ma thiet bi";
		XuatTieuDe();
		Xuat_NLR(root);
		cout << "\nNhap ma thiet bi can xoa: ";
		cin >> ma;
		cout << "\nDanh sach sau khi xoa thiet bi co ma " << ma << " la\n";
		DeleteMaTB(root, ma);
		XuatTieuDe();
		Xuat_NLR(root);
		break;
	case 2:
		cout << "\n2. Xoa theo ten";
		XuatTieuDe();
		break;
	case 3:
		cout << "\n3. Xoa theo ngay thang nam nhap";
		XuatTieuDe();
		break;
	case 4:
		cout << "\n4. Xoa theo phong su dung";
		XuatTieuDe();
		break;
	}
}
void MenuThem_ChinhSua()
{
	cout << "======================== MENU QUAN LY THIET BI Y TE ==================================";
	cout << "\n0. Tro ve chuong trinh chinh";
	cout << "\n1. Them mot thiet bi";
	cout << "\n2. Chinh sua ten thiet bi";
	cout << "\n3. Chinh sua ma thiet bi";
	cout << "\n4. Chinh sua ngay thang nam nhap";
}
void XuLyMenuThem_ChinhSua(int menu, BSTree& root)
{
	switch (menu)
	{
	case 0:
		cout << "\n0. Tro ve chuong trinh chinh\n";
		break;
	case 1:
		cout << "\n1. Them mot thiet bi";
		XuatTieuDe();
		break;
	case 2:
		cout << "\n2. Chinh sua ten thiet bi";
		XuatTieuDe();
		break;
	case 3:
		cout << "\n3. Chinh sua ma thiet bi";
		XuatTieuDe();
		break;
	case 4:
		cout << "\n4. Chinh sua ngay thang nam nhap";
		XuatTieuDe();
		break;
	}
}