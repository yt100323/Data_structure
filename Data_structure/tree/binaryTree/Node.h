#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
public:
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	int index;
	int data;
	Node *pRChild;
	Node *pLChild;
	Node *pParent;

};


#endif