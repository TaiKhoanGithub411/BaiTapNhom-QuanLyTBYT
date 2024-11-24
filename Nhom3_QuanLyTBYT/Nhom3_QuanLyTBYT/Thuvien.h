//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma);
BSTree Search_TenTB(BSTree root, char ten[30]);
BSTree Search_PhongSD(BSTree root, char phong[30]);
Date TaoNgayThangNam(int ngay, int thang, int nam);
BSTree Search_NgayThangNamNhap(BSTree root, Date nhap);
BSTree Search_NgayThangNamSD(BSTree root, Date nhap);
BSTree FindMinRight(BSTree root);
void DeleteNode(BSTree& root, BSTree node);
void DeleteMaTB(BSTree& root, KeyType ma);
void DeleteTen(BSTree& root, char x[30]);
void DeletePhongSD(BSTree& root, char x[30]);
//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma)
{
    BSTree current = root;
    while (current != NULL)
    {
        int comparison = _stricmp(current->infor.maTB, ma);
        if (comparison == 0)
            return current;
        else if (comparison < 0)
            current = current->right;
        else
            current = current->left;
    }
    return NULL;
}
BSTree Search_TenTB(BSTree root, char ten[30])
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (_stricmp(root->infor.TenTB, ten) == 0)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree leftResult = Search_TenTB(root->left, ten);
            if (leftResult != NULL)
                InsertNode(result, leftResult->infor);
        }
        if (root->right != NULL)
        {
            BSTree rightResult = Search_TenTB(root->right, ten);
            if (rightResult != NULL)
                InsertNode(result, rightResult->infor);
        }
    }
    return result;
}
BSTree Search_PhongSD(BSTree root, char phong[30])
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (_stricmp(root->infor.PhongSD, phong) == 0)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree left = Search_PhongSD(root->left, phong);
            if (left != NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_PhongSD(root->right, phong);
            if (right != NULL)
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
BSTree Search_NgayThangNamNhap(BSTree root, Date nhap)
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (root->infor.ngayNhap.ngay == nhap.ngay && root->infor.ngayNhap.thang == nhap.thang && root->infor.ngayNhap.nam == nhap.nam)
            InsertNode(result, root->infor);
        if (root->left != NULL)
        {
            BSTree left = Search_NgayThangNamNhap(root->left, nhap);
            if (left != NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_NgayThangNamNhap(root->right, nhap);
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
            BSTree left = Search_NgayThangNamSD(root->left, nhap);
            if (left != NULL)
                InsertNode(result, left->infor);
        }
        if (root->right != NULL)
        {
            BSTree right = Search_NgayThangNamSD(root->right, nhap);
            if (right != NULL)
                InsertNode(result, right->infor);
        }
    }
    return result;
}
BSTree FindMinRight(BSTree root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;
    return root;
}
void DeleteNode(BSTree& root, BSTree nodetoDelete)
{
    if (nodetoDelete == NULL)
        return;
    if (nodetoDelete->left == NULL && nodetoDelete->right == NULL)
    {
        delete nodetoDelete;
        root = NULL;
    }
    else if (nodetoDelete->left == NULL)
    {
        BSTree temp = nodetoDelete->right;
        delete nodetoDelete;
        root = temp;
    }
    else if (nodetoDelete->right == NULL)
    {
        BSTree temp = nodetoDelete->left;
        delete nodetoDelete;
        root = temp;
    }
    else
    {
        BSTree minRight = FindMinRight(nodetoDelete->right);
        nodetoDelete->infor = minRight->infor;
        DeleteNode(nodetoDelete->right, minRight);
    }
}
void DeleteMaTB(BSTree& root, KeyType ma)
{
    if (root == NULL)
        return;
    if (_stricmp(root->infor.maTB, ma) == 0)
    {
        BSTree nodeToDelete = root;
        DeleteNode(root, nodeToDelete);
        return;
    }
    if (root->left != NULL)
        DeleteMaTB(root->left, ma);
    if (root->right != NULL)
        DeleteMaTB(root->right, ma);
}
void DeleteTen(BSTree& root, char x[30])
{
    if (root == NULL)
        return;
    if (_stricmp(root->infor.TenTB, x) == 0)
    {
        BSTree nodeToDelete = root;
        DeleteNode(root, nodeToDelete);
        return;
    }
    if (root->left != NULL)
        DeleteTen(root->left, x);
    if (root->right != NULL)
        DeleteTen(root->right, x);
}
void DeleteAllByTen(BSTree& root, char x[30])
{
    if (root == NULL)
        return;
    DeleteTen(root, x);
    if (root->left != NULL)
        DeleteAllByTen(root->left, x);
    if (root->right != NULL)
        DeleteAllByTen(root->right, x);
}
void DeletePhong(BSTree& root, char x[30])
{
    if (root == NULL)
        return;
    if (_stricmp(root->infor.PhongSD, x) == 0)
    {
        BSTree nodeToDelete = root;
        DeleteNode(root, nodeToDelete);
        return;
    }
    if (root->left != NULL)
        DeletePhong(root->left, x);
    if (root->right != NULL)
        DeletePhong(root->right, x);
}
void DeleteAllPhong(BSTree& root, char x[30])
{
    if (root == NULL)
        return;
    DeletePhong(root, x);
    if (root->left != NULL)
        DeleteAllPhong(root->left, x);
    if (root->right != NULL)
        DeleteAllPhong(root->right, x);
}