#include "Tree.h"
#include <stdlib.h>


int main()
{
	BinarySearchTree<int> binaryTree;
	binaryTree.insert(5);
	binaryTree.insert(1);
	binaryTree.insert(2);
	binaryTree.insert(3);
	binaryTree.insert(6);
	binaryTree.insert(8);
	binaryTree.insert(7);
	bool b = binaryTree.contains(1);
	cout << b << endl;
	int x = binaryTree.findMin();
	cout << x << endl;
	x = binaryTree.findMax();
	cout << x << endl;
	binaryTree.remove(0);
	binaryTree.printTree(ORDER_MODE_PREV);
	cout << endl;
	//binaryTree.makeEmpty();
	binaryTree.printTree(ORDER_MODE_MID);
	cout << endl;
	binaryTree.printTree(ORDER_MODE_POST);
	cout << endl;
	system("pause");
	return 0;
}