typedef char KeyType[10];
struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct TBYT
{
	KeyType maTB;
	char TenTB[30];
	Date ngayNhap;
	Date ngaySD;
	int soLuong;
	char LoaiTB[30];
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
		if (_stricmp(root->infor.maTB, x.maTB) == 0)
			return 0;
		if (_stricmp(root->infor.maTB, x.maTB) > 0)
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
		in >> x.maTB;
		in >> x.TenTB;
		in >> x.ngayNhap.ngay;
		in >> x.ngayNhap.thang;
		in >> x.ngayNhap.nam;
		in >> x.ngaySD.ngay;
		in >> x.ngaySD.thang;
		in >> x.ngaySD.nam;
		in >> x.soLuong;
		in >> x.LoaiTB;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	cout << setiosflags(ios::left)
		<< setw(10) << "MaTB"
		<< setw(30) << "Ten Thiet Bi"
		<< setw(30) << "Ngay Nhap"
		<< setw(30) << "Ngay Su Dung"
		<< setw(10) << "So luong"
		<< setw(30) << "Loai Thiet Bi";
	cout << endl;
}
void XuatTB(TBYT x)
{
	cout << setiosflags(ios::left)
		<< setw(10) << x.maTB
		<< setw(30) << x.TenTB
		<< setw(10)
		<< setw(2) << x.ngayNhap.ngay << '/'
		<< setw(2) << x.ngayNhap.thang << '/'
		<< setw(4) << x.ngayNhap.nam
		<< setw(10)
		<< setw(2) << x.ngaySD.ngay << '/'
		<< setw(2) << x.ngaySD.thang << '/'
		<< setw(4) << x.ngaySD.nam
		<< setw(10) << x.soLuong
		<< setw(30) << x.LoaiTB;
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