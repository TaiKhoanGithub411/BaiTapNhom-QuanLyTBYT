//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma);
BSTree Search_TenTB(BSTree root, char ten[30]);
BSTree Search_PhongSD(BSTree root, char phong[30]);
Date TaoNgayThangNam(int ngay, int thang, int nam);
BSTree Search_NgayThanhNamNhap(BSTree root, Date nhap);
BSTree Search_NgayThangNamSD(BSTree root, Date nhap);
//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma)
{
	if (root != NULL)
	{
		if (strcmp(root->infor.maTB, ma) == 0)
			return root;
		else
			if (strcmp(root->infor.maTB, ma) < 0)
				return Search_MaTB(root->right, ma);
			else
				return Search_MaTB(root->left, ma);
	}
	return NULL;
}
BSTree Search_TenTB(BSTree root, char ten[30])
{
    BSTree result;
    CreatRoot(result);
    if (root != NULL)
    {
        if (strcmp(root->infor.TenTB, ten) == 0)
        {
            InsertNode(result, root->infor);
        }
        if (root->left != NULL)
        {
            BSTree leftResult = Search_TenTB(root->left, ten);
            if(leftResult!=NULL)
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