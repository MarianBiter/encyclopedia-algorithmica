#include "BinarySearchTree.h"
#include <stack>
#include <queue>

BinarySearchTree::BinarySearchTree()
{
	m_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	std::stack<TreeNode*> nodeStack;
	nodeStack.push(m_root);

	while(!nodeStack.empty())
	{
		TreeNode* currentNode = nodeStack.top();
		nodeStack.pop();
		if(currentNode->left != nullptr)
		{
			nodeStack.push(currentNode->left);
		}
		if(currentNode->right !=nullptr)
		{
			nodeStack.push(currentNode->right);
		}

		//free node
		if(currentNode !=nullptr)
		{
			delete currentNode;
			currentNode = nullptr;
		}
	}
}

BinarySearchTree::TreeNode* BinarySearchTree::Insert(int key)
{
	TreeNode* nodeToInsert = new TreeNode();
	nodeToInsert->key = key;
	nodeToInsert->left = nullptr;
	nodeToInsert->right = nullptr;

	TreeNode* trailingNode = nullptr;
	TreeNode* node = m_root;

	while(node!=nullptr)
	{
		trailingNode = node;
		if(key<node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	if(trailingNode == nullptr) //the tree has no nodes
	{
		m_root = nodeToInsert;
	}
	else if(key<trailingNode->key) // the tree has at least one node and trailingNode is the parent of nodeToInsert
	{
		trailingNode->left = nodeToInsert;
	}
	else
	{
		trailingNode->right = nodeToInsert;
	}

	return nodeToInsert;
}


bool BinarySearchTree::checkIsBinarySearch()
{
	bool isBinarySearchTree = true;
	std::stack<TreeNode*> nodeStack;
	nodeStack.push(m_root);

	while(!nodeStack.empty())
	{
		TreeNode* currentNode = nodeStack.top();
		nodeStack.pop();
		if(currentNode != nullptr)
		{
			if(currentNode->left != nullptr)
			{
				if(currentNode->left->key>currentNode->key)
				{
					isBinarySearchTree = false;
					break;
				}
				nodeStack.push(currentNode->left);
			}
			if(currentNode->right !=nullptr)
			{
				if(currentNode->right->key<currentNode->key)
				{
					isBinarySearchTree = false;
					break;
				}
				nodeStack.push(currentNode->right);
			}
		}
	}
	return isBinarySearchTree;
}

int BinarySearchTree::treeHeight()
{
	int treeHeightValue = 0;
	if(m_root == nullptr)
	{
		return treeHeightValue;
	}
	std::queue<TreeNode*> nodeQueue;
	nodeQueue.push(m_root);

	while(!nodeQueue.empty())
	{
		int nodeCount = nodeQueue.size();
		treeHeightValue++;
		while(nodeCount > 0)
		{
			TreeNode* node = nodeQueue.front();
			nodeQueue.pop();
			if(node->left != nullptr)
			{
				nodeQueue.push(node->left);
			}
			if(node->right != nullptr)
			{
				nodeQueue.push(node->right);
			}
			nodeCount--;
		}
	}

	return treeHeightValue;
}