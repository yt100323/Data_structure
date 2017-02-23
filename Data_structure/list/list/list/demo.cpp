#include <iostream>
#include <stdlib.h>
#include "List.h"

using namespace std;

/******************************************/
/*
BOOL InitList(List **list);    //创建线性表  ->  构造函数
void DestroyList(List *list);  //销毁线性表  ->  析构函数
void ClearList(List *list);
BOOL ListEmpty(List *list);
int ListLength(List *list);
BOOL GetElem(List *list, int i, Elem *e);
int LocateElem(List *list, Elem *e);
BOOL PriorElem(List *list, Elem *currentElem, Elem *preElem);
BOOL NextElem(List *list, Elem *currentElem, Elem *nextElem);
BOOL ListInsert(List *list, int i, Elem *e);
BOOL ListDelete(List *list, int i, Elem *e);
void ListTraverse(List *list);
*/
/********************************************/
int main()
{  
	//3572918
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;

	int temp;

	List *list1 = new List(10);

	list1->ListInsert(0, &e1);
	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);
	list1->ListInsert(3, &e4);
	list1->ListInsert(4, &e5);
	list1->ListInsert(5, &e6);
	list1->ListInsert(3, &e7);

	list1->ListDelete(0, &temp);
	

	list1->ListTraverse();
	cout << "#" << temp << endl;

	delete list1;
	list1 = NULL;
	system("pause");
	return 0;
}