//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma, BSTree& rootparent);
BSTree Search_TenTB(BSTree root, char ten[30], BSTree& parent);
BSTree Search_PhongSD(BSTree root, char phong[30], BSTree& parent);
Date TaoNgayThangNam(int ngay, int thang, int nam);
BSTree Search_NgayThangNamNhap(BSTree root, Date nhap, BSTree& parent);
//BSTree Search_NgayThangNamSD(BSTree root, Date nhap);
void Xuat_TatCaTB_TheoTen(BSTree root, char ten[30]);
void Xuat_TatCaTB_TheoPhongSD(BSTree root, char phong[30], BSTree& parent);
void Xuat_TatCaTB_TheoNgayNhap(BSTree root, Date nhap, BSTree& parent);
//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma, BSTree& rootparent)
{
    CreatRoot(rootparent);
    BSTree current = root;
    int dk;
    while (current != NULL)
    {
        dk = strcmp(current->infor.maTB, ma);
        if (dk == 0)
            return current;
        rootparent = current;
        if (dk < 0)
            current = current->right;
        else
            current = current->left;
    }
    return NULL;
}
BSTree Search_TenTB(BSTree root, char ten[30], BSTree& parent)
{
    if (root == NULL)
        return NULL;
    int dk = strcmp(root->infor.TenTB, ten);
    if (dk == 0)
        return parent;
    if (dk < 0)
    {
        parent = root;
        return Search_TenTB(root->right, ten, parent);
    }
    else
    {
        parent = root;
        return Search_TenTB(root->left, ten, parent);
    }
}
BSTree Search_PhongSD(BSTree root, char phong[30], BSTree& parent)
{
    while (root != NULL)
    {
        int dk = strcmp(root->infor.PhongSD, phong);
        if (dk == 0)
            return parent;
        if (dk < 0)
        {
            parent = root;
            return Search_PhongSD(root->right, phong, parent);
        }
        else
        {
            parent = root;
            return Search_PhongSD(root->left, phong, parent);
        }
    }
    return NULL;
}
Date TaoNgayThangNam(int ngay, int thang, int nam)
{
    Date x;
    x.ngay = ngay;
    x.thang = thang;
    x.nam = nam;
    return x;
}
BSTree Search_NgayThangNamNhap(BSTree root, Date nhap, BSTree& parent)
{
    parent = NULL;
    while (root != NULL)
    {
        bool dk = (root->infor.ngayNhap.ngay == nhap.ngay &&
            root->infor.ngayNhap.thang == nhap.thang &&
            root->infor.ngayNhap.nam == nhap.nam);

        if (dk)
            return root;
        parent = root;
        if (nhap.nam < root->infor.ngayNhap.nam ||
            (nhap.nam == root->infor.ngayNhap.nam && nhap.thang < root->infor.ngayNhap.thang) ||
            (nhap.nam == root->infor.ngayNhap.nam && nhap.thang == root->infor.ngayNhap.thang && nhap.ngay < root->infor.ngayNhap.ngay))
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
void Xuat_TatCaTB_TheoTen(BSTree root, char ten[30])
{
    if (root != NULL)
    {
        if (strcmp(root->infor.TenTB, ten) == 0)
            XuatTB(root->infor);
        Xuat_TatCaTB_TheoTen(root->left, ten);
        Xuat_TatCaTB_TheoTen(root->right, ten);
    }
}
void Xuat_TatCaTB_TheoPhongSD(BSTree root, char phong[30],BSTree&parent)
{
    if (root != NULL)
    {
        if (strcmp(root->infor.PhongSD, phong) == 0)
            XuatTB(root->infor);
        Xuat_TatCaTB_TheoPhongSD(root->left, phong, parent);
        Xuat_TatCaTB_TheoPhongSD(root->right, phong, parent);
    }
}
void Xuat_TatCaTB_TheoNgayNhap(BSTree root, Date nhap,BSTree&parent)
{
    BSTree p = Search_NgayThangNamNhap(root, nhap, parent);
    if (p != NULL)
    {
        if (root != NULL)
        {
            if (root->infor.ngayNhap.ngay == nhap.ngay &&
                root->infor.ngayNhap.thang == nhap.thang &&
                root->infor.ngayNhap.nam == nhap.nam)
                XuatTB(root->infor);
            Xuat_TatCaTB_TheoNgayNhap(root->left, nhap, parent);
            Xuat_TatCaTB_TheoNgayNhap(root->right, nhap, parent);
        }
    }
    else
        cout << "\nKhong tim thay\n";
}