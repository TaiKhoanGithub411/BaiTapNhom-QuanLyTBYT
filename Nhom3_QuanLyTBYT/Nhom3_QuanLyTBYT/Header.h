typedef char KeyType[10];
struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct TBYT
{
	KeyType ma;
	char TenTB[30];
	Date ngayNhap;
	Date ngaySD;
	int soLuong;
	char PhongSD[30];
	int DonGia;
};
typedef TBYT Data;
struct BSNode
{
	Data infor;
	BSNode* left;
	BSNode* right;
};
typedef BSNode* BSTree;
//================================================================
BSNode* CreatNode(TBYT x);
void CreatRoot(BSTree& root);
int InsertNode(BSTree& root, TBYT x);
int DocFile(BSTree& root, char* filename);
void XuatTieuDe();
void XuatTB(TBYT x);
void Xuat_NLR(BSTree root);
void Xuat_LNR(BSTree root);
void Xuat_RNL(BSTree root);
//================================================================
BSNode* CreatNode(TBYT x)
{
	BSNode* p = new BSNode();
	if (p != NULL) {
		p->infor = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void CreatRoot(BSTree& root)
{
	root = NULL;
}
int InsertNode(BSTree& root, TBYT x)
{
	if (root != NULL)
	{
		if (_stricmp(root->infor.ma, x.ma) == 0)
			return 0;
		if (_stricmp(root->infor.ma, x.ma) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreatNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
int DocFile(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maTB;
	int kq;
	CreatRoot(root);
	TBYT x;
	while (!in.eof())
	{
		in >> x.ma;
		in >> x.TenTB;
		in >> x.ngayNhap.ngay;
		in >> x.ngayNhap.thang;
		in >> x.ngayNhap.nam;
		in >> x.ngaySD.ngay;
		in >> x.ngaySD.thang;
		in >> x.ngaySD.nam;
		in >> x.soLuong;
		in >> x.PhongSD;
		in >> x.DonGia;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	int i;
	cout << endl<<".";
	for (i = 1; i <= 116; i++)
		cout << '_';
	cout  <<"." << endl;
	cout << setiosflags(ios::left);
	cout << '|'
		<< setw(8) << "Ma nhap "
		<< '|'
		<< setw(30) << "Ten Thiet Bi"
		<< '|'
		<< setw(15) << "Ngay Nhap"
		<< '|'
		<< setw(15) << "Ngay Su Dung"
		<< '|'
		<< setw(12) << "So luong"
		<< '|'
		<< setw(15) << "Phong SD"
		<< '|' << setw(15) << "Don Gia Nhap"
		<< '|';
	cout << endl << '|';
	for (i = 1; i <= 116; i++)
		cout << '_';
	cout << '|';

}
void XuatCuoi()
{
	int i;
	cout << endl << "|";
	for (i = 1; i <= 116; i++)
		cout << '_';
	cout << "|" << endl;
	
	
}
void XuatTB(TBYT x)
{
	cout << endl << '|';
	cout << setiosflags(ios::left)
		<< setw(8) << x.ma
		<< '|' << setw(30) << x.TenTB
		<< '|' << setw(15)
		<< setw(2) << x.ngayNhap.ngay << '/'
		<< setw(2) << x.ngayNhap.thang << '/'
		<< setw(9) << x.ngayNhap.nam
		<< '|' << setw(15)
		<< setw(2) << x.ngaySD.ngay << '/'
		<< setw(2) << x.ngaySD.thang << '/'
		<< setw(9) << x.ngaySD.nam
		<< '|' << setw(12) << x.soLuong
		<< '|' << setw(15) << x.PhongSD
		<< '|' << setw(15) << x.DonGia
		<< '|';

}
void Xuat_NLR(BSTree root)
{
	if (root != NULL)
	{
		XuatTB(root->infor);
		Xuat_NLR(root->left);
		Xuat_NLR(root->right);
	}
}
void Xuat_LNR(BSTree root)
{
	if (root != NULL)
	{
		Xuat_LNR(root->left);
		XuatTB(root->infor);
		Xuat_LNR(root->right);
	}
}
void Xuat_RNL(BSTree root)
{
	if (root != NULL)
	{
		Xuat_RNL(root->right);
		XuatTB(root->infor);
		Xuat_RNL(root->left);
	}
}