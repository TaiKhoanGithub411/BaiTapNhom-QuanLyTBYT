//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma, BSTree& rootparent);
BSTree Search_TenTB(BSTree root, char ten[30], BSTree& parent);
BSTree Search_PhongSD(BSTree root, char phong[30]);
Date TaoNgayThangNam(int ngay, int thang, int nam);
BSTree Search_NgayThanhNamNhap(BSTree root, Date nhap);
BSTree Search_NgayThangNamSD(BSTree root, Date nhap);
void Xuat_TatCaTB(BSTree root, char ten[30]);
//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma,BSTree& rootparent)
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
void Xuat_TatCaTB(BSTree root, char ten[30])
{
    if (root != NULL)
    {
        if (strcmp(root->infor.TenTB, ten) == 0)
            XuatTB(root->infor);
        Xuat_TatCaTB(root->left, ten);
        Xuat_TatCaTB(root->right, ten);
    }
}

BSTree Search_PhongSD(BSTree root, char phong[30])
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (strcmp(root->infor.PhongSD, phong) == 0)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree left = Search_PhongSD(root->left, phong);
            if(left!=NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_PhongSD(root->right, phong);
            if(right!=NULL)
                InsertNode(result, right->infor);
        }
    }
    return result;
}
Date TaoNgayThangNam(int ngay, int thang, int nam)
{
    Date x;
    x.ngay = ngay;
    x.thang = thang;
    x.nam = nam;
    return x;
}
BSTree Search_NgayThanhNamNhap(BSTree root, Date nhap)
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (root->infor.ngayNhap.ngay == nhap.ngay && root->infor.ngayNhap.thang == nhap.thang && root->infor.ngayNhap.nam == nhap.nam)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree left = Search_NgayThanhNamNhap(root->left, nhap);
            if (left != NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_NgayThanhNamNhap(root->right, nhap);
            if (right != NULL)
                InsertNode(result, right->infor);
        }
    }
    return result;
}
BSTree Search_NgayThangNamSD(BSTree root, Date nhap)
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (root->infor.ngaySD.ngay == nhap.ngay && root->infor.ngaySD.thang == nhap.thang && root->infor.ngaySD.nam == nhap.nam)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree left = Search_NgayThanhNamNhap(root->left, nhap);
            if (left != NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_NgayThanhNamNhap(root->right, nhap);
            if (right != NULL)
                InsertNode(result, right->infor);
        }
    }
    return result;
}