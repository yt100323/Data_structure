#include <iostream>
#include <stdlib.h>
#include "List.h"
#include "Coordinate.h"

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
	Coordinate e1(3, 5);
	Coordinate e2(5, 7);
	Coordinate e3(6, 8);

	Coordinate temp(0, 0);

	List *list1 = new List(10);

	list1->ListInsert(0, &e1);
	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);
	

	list1->ListTraverse();

	/*list1->GetElem(0, &temp);
	cout << "temp: " << temp << endl;

	temp = 5;
	cout << "temp地址： " << list1->LocateElem(&temp) << endl;
	*/
	/*list1->PriorElem(&e2, &temp);
	cout << "temp: " << temp << endl;
	list1->NextElem(&e6, &temp);
	cout << "temp: " << temp << endl;*/




	/*list1->ListDelete(0, &temp);

	if (!list1->ListEmpty())
	{
	cout << "not empty" << endl;
	}

	list1->ClearList();

	if (list1->ListEmpty())
	{
	cout << "empty" << endl;
	}

	list1->ListTraverse();*/

	/*cout << "#" << temp << endl;
	cout << list1->ListLength() << endl;*/

	delete list1;
	list1 = NULL;
	system("pause");
	return 0;
}