//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma);
BSTree Search_TenTB(BSTree root, char ten[30]);
BSTree Search_PhongSD(BSTree root, char phong[30]);
Date TaoNgayThangNam(int ngay, int thang, int nam);
BSTree Search_NgayThangNamNhap(BSTree root, Date nhap);
BSTree Search_NgayThangNamSD(BSTree root, Date nhap);
BSTree Search_Parent_MaTB(BSTree root, KeyType ma);
BSTree Search_Parent_TenTB(BSTree root, char ten[30]);
BSTree FindMinRight(BSTree root);
BSTree DeleteNode(BSTree root, BSTree Node);
BSTree DeleteMaTB(BSTree root, KeyType ma);
//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma)
{
    if (root == NULL) return NULL;
    BSTree parent = Search_Parent_MaTB(root, ma);
    if (parent == NULL) 
    {
        if (_stricmp(root->infor.maTB, ma) == 0) 
            return root;
        else 
            return NULL;
    }
    if (_stricmp(root->infor.maTB, ma) < 0)
        return Search_MaTB(root->right, ma);
    else 
        return Search_MaTB(root->left, ma);
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
BSTree Search_Parent_MaTB(BSTree root, KeyType ma)
{
    BSTree parent = NULL, current = root;
    while (current != NULL)
    {
        if (_stricmp(current->infor.maTB, ma)==0)
            return parent;
        if (_stricmp(current->infor.maTB, ma) < 0)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            parent = current;
            current = current->left;
        }
    }
}
BSTree Search_Parent_TenTB(BSTree root, char ten[30])
{
    BSTree parent = NULL, current = root;
    while (current!=NULL)
    {
        if (_stricmp(current->infor.TenTB, ten) == 0)
            return parent;
        if (_stricmp(current->infor.TenTB, ten) < 0)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            parent = current;
            current = current->left;
        }
    }
}
BSTree Search_Parent_PhongSD(BSTree root, char phong[30])
{
    BSTree parent = NULL, current = root;
    while (current!=NULL)
    {
        if (_stricmp(current->infor.PhongSD, phong) == 0)
            return parent;
        if (_stricmp(current->infor.PhongSD, phong) < 0)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            parent = current;
            current = current->left;
        }
    }
}
BSTree FindMinRight(BSTree root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
BSTree DeleteNode(BSTree root, BSTree Node)
{
    if (root == NULL || Node == NULL)
        return root;
    if (Node->left == NULL && Node->right == NULL)
    {
        free(Node);
        return NULL;
    }
    if (Node->left == NULL)
    {
        BSTree temp = Node->right;
        free(Node);
        return temp;
    }
    if (Node->right == NULL)
    {
        BSTree temp = Node->left;
        free(Node);
        return temp;
    }
    BSTree temp = FindMinRight(Node->right);
    Node->infor = temp->infor;
    Node->right = DeleteNode(Node->right, temp);
    return root;
}
BSTree DeleteMaTB(BSTree root, KeyType ma)
{
    BSTree parent = Search_Parent_MaTB(root, ma);
    if (parent == NULL)
        return root;
    BSTree Node = NULL;
    if (_stricmp(parent->infor.maTB, ma) == 0)
        Node = parent;
    else
    {
        if (_stricmp(parent->infor.maTB, ma) < 0)
            Node = parent->right;
        else
            Node = parent->left;
    }
    return DeleteNode(root, Node);
}