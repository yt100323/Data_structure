#include "Tree.h"

Tree::Tree()
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	DeleteNode(0, NULL);

}

Node *Tree::SearchNode(int nodeIndex)          //不明白,原先的有问题，后来改了递归
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	Node *newNode = new Node();
	if (newNode == NULL)
		return false;

	newNode->index = pNode->index;
	newNode->data = pNode->data;
	newNode->pParent = temp;

	if (direction == 0)
	{
		temp->pLChild = newNode;
	}
	if (direction == 1)
	{
		temp->pRChild = newNode;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;
	

}


void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}


void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}