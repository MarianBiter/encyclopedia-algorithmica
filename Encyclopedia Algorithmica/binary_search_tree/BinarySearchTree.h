#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

class BinarySearchTree
{
public:
	struct TreeNode
	{
		int key;
		TreeNode* left;
		TreeNode* right;
	};

	BinarySearchTree();
	~BinarySearchTree();
	//TreeNode* Search(int key);
	//TreeNode* Maximum();
	//TreeNode* Minimum();
	//int MaximumValue();
	//int MinimumValue();
	//TreeNode* Successor(TreeNode* x);
	//TreeNode* Predecessor(TreeNode* x);
	TreeNode* Insert(int key);
	bool checkIsBinarySearch();
	int treeHeight();
	//void Delete(TreeNode*);
private:
	TreeNode* m_root;
};

#endif