//======================================================
BSTree Search_MaTB(BSTree root, KeyType ma);
BSTree Search_TenTB(BSTree root, char ten[30]);
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
	if (root == NULL)
		return NULL;
	if (strcmp(root->infor.TenTB, ten) == 0)
		return root;
	BSTree result = Search_TenTB(root->left, ten);
	if (result == NULL)
		result = Search_TenTB(root->right, ten);
	return result;
}