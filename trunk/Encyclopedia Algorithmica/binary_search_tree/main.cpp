#include <iostream>
#include "BinarySearchTree.h"
#include <random>

void main()
{
	BinarySearchTree bst;

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

	for (int n=0; n<128; ++n)
	{
		bst.Insert(dis(gen));
	}

	bool check = bst.checkIsBinarySearch();
	int height = bst.treeHeight();

}