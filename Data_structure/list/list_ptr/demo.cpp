#include <iostream>
#include <stdlib.h>
#include "List.h"

using namespace std;

int main()
{
	/*Node node1;
	node1.data = 3;*/
	Node *node1 = new Node;
	node1->data = 3;

	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;
	Node node6;
	node6.data = 8;
	Node node7;
	node7.data = 9;

	Node temp;

	List *pList = new List;

	pList->ListInsertHead(node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);

	pList->ListInsertTail(&node5);
	pList->ListInsertTail(&node6);

	pList->ListInsert(1, &node7);

	//pList->ListDelete(1, &temp);
	//pList->GetElem(1, &temp);
	pList->NextElem(&node5, &temp);




	pList->ListTraverse();

	cout << "temp " << temp.data << endl;

	delete node1;
	node1 = NULL;
	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}