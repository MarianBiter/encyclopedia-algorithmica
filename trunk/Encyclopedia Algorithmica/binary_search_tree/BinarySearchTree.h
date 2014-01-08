#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

class BinarySearchTree
{
	struct TreeNode
	{
		int key;
		TreeNode* left;
		TreeNode* right;
	};
public:
	BinarySearchTree();
	~BinarySearchTree();
	TreeNode* Search(int key);
	TreeNode* Maximum();
	TreeNode* Minimum();
	int MaximumValue();
	int MinimumValue();
	TreeNode* Successor(TreeNode* x);
	TreeNode* Predecessor(TreeNode* x);
	void Insert();
	void Delete(TreeNode*);
private:
	TreeNode* m_root;
};

#endif