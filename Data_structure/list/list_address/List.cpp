#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	m_pList = new Node;
	//m_pList->data = 0;
	m_pList->Next = NULL;
	m_iLenth = 0;
}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	Node *currentNode = m_pList->Next;
	while (currentNode != NULL)
	{
		Node *temp = currentNode->Next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->Next = NULL;
}

bool List::ListEmpty()
{
	return m_iLenth == 0 ? true : false;
}


int List::ListLength()
{
	return m_iLenth;
}

bool List::GetElem(int i, Node *pNode)
{
	if (i > m_iLenth - 1 || i < 0)
		return false;
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) //i的下一个
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->Next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node *pNode)
{
	int count = 0;
	Node *temp = m_pList;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
		if (temp->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1; //代表没有找到
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *temp = m_pList;
	Node *tempBefore = NULL;
	while (temp->Next != NULL)
	{
		tempBefore = temp;
		temp = temp->Next;
		if (temp->data == pCurrentNode->data)
		{
			if (tempBefore == m_pList)
			{
				return false;
			}
			pPreNode->data = tempBefore->data;
			return true;
		}
	}
	return false; //代表没有找到
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *temp = m_pList;

	while (temp->Next != NULL)
	{
		temp = temp->Next;
		if (temp->data == pCurrentNode->data)
		{
			if (temp->Next == NULL)
				return false;
			pNextNode->data = temp->Next->data;
			return true;
		}
	}

	return false;

}

void List::ListTraverse()
{
	Node * currentNode = m_pList;
	while (currentNode->Next != NULL)
	{
		currentNode = currentNode->Next;
		currentNode->printNode();
	}
}

bool List::ListInsert(int i, Node *pNode)
{
	if (i < 0 || i > m_iLenth)
		return false;
	Node *current = m_pList;
	for (int k = 0; k < i; k++)
	{
		current = current->Next;
	}
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->Next = current->Next;
	current->Next = newNode;
	m_iLenth++;
	return true;

}

bool List::ListDelete(int i, Node *pNode)
{
	if (i > m_iLenth - 1 || i < 0)
		return false;
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) //i的下一个
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->Next;
	}
	currentNodeBefore->Next = currentNode->Next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLenth--;
	return false;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->Next;
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->Next = newNode;
	newNode->Next = temp;
	m_iLenth++; //
	return true;

}

bool List::ListInsertTail(Node *pNode)
{
	Node *temp = m_pList;
	while (temp->Next != NULL)
	{
		temp = temp->Next;
	}

	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->Next = NULL;
	temp->Next = newNode;
	m_iLenth++; //
	return true;
}

