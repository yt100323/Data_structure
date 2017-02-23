#include "List.h"
#include <iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	m_pList = new int[m_iSize];
	m_iLenth = 0;
}

List::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	m_iLenth = 0;
}

bool List::ListEmpty()
{
	return m_iLenth == 0 ? true:false;
}


int List::ListLength()
{
	return m_iLenth;
}

bool List::GetElem(int i, int *e)
{
	if (i < 0 || i >= m_iSize)
		return false;

	*e = m_pList[i];
	return true;
}

int List::LocateElem(int *e)
{
	for (int i = 0; i < m_iLenth; i++)
	{
		if (m_pList[i] == *e)
			return i;
	}
	return -1; //代表没有找到
}

bool List::PriorElem(int *currentElem, int *preElem)
{
	int  temp = LocateElem(currentElem);
	if (0 == temp || -1 == temp)
	{
		return false;
	}
	else
	{
		*preElem = m_pList[temp - 1];
		return true;
	}
}

bool List::NextElem(int *currentElem, int *nextElem)
{
	int temp = LocateElem(currentElem);
	if ((m_iLenth - 1) == temp || -1 == temp)  //temp-1
	{
		return false;
	}
	else
	{
		*nextElem = m_pList[temp + 1];
		return true;
	}
}

void List::ListTraverse()
{
	for (int i = 0; i < m_iLenth; i++)
	{
		cout << m_pList[i] << endl;
	}
}

bool List::ListInsert(int i, int *e)
{
	if (i > m_iLenth || i < 0)
		return false;
	for (int k = m_iLenth - 1; k >= i; k--) //最后一个元素m_iLenth-1 和 >=
	{
		m_pList[k + 1] = m_pList[k];
	}

	m_pList[i] = *e;
	m_iLenth++;
	return true;
}

bool List::ListDelete(int i, int *e)
{
	if (i > m_iLenth - 1 || i < 0)
		return false;

	*e = m_pList[i];
	for (int k = i; k < m_iLenth; k++)
	{
		m_pList[k] = m_pList[k+1];
	}
	m_iLenth--;
	return false;
}

