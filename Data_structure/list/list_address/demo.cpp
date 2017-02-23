#include <iostream>
#include <stdlib.h>
#include "List.h"

using namespace std;
int meau()
{
	//显示功能菜单
	cout << "功能菜单" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;
	cout << "请输入：";

	int order = 0;
	cin >> order;
	return order;
}

void createPerson(List *list)
{
	Node node; //临时的
	cout << "请输入姓名：" << endl;
	cin >> node.data.name;
	cout << "请输入电话：" << endl;
	cin >> node.data.phone;

	/*Person person;
	cout << "请输入姓名：" << endl;
	cin >> person.name;
	cout << "请输入电话：" << endl;
	cin >> person.phone;
	node.data = person;*/ //另一种方法

	list->ListInsertTail(&node);
}

void deletePerson(List *list)
{
	Node temp;
	Node node; //临时的
	int position = -1;
	cout << "请输入要删除联系人的姓名：" << endl;
	cin >> node.data.name;
	cout << "请输入要删除联系人的电话：" << endl;
	cin >> node.data.phone;
	position = list->LocateElem(&node);
	list->ListDelete(position,&temp);

}

int main()
{
	List *plist = new List;

	int userOrser = 0;
	while (userOrser != 4)
	{
		userOrser = meau();
		switch (userOrser)
		{
		case 1:
			cout << "用户指令----->>新建联系人" << endl;
			createPerson(plist);
			break;
		case 2:
			cout << "用户指令----->>删除联系人" << endl;
			deletePerson(plist);
			break;
		case 3:
			cout << "用户指令----->>浏览通讯录" << endl;
			plist->ListTraverse();
			break;
		case 4:
			cout << "用户指令----->>退出通讯录" << endl;
			break;
		default:
			break;
		}

	}
	delete plist;
	plist = NULL;
	/*List *plist1 = new List;
	Node node1;
	node1.data.name = "tester1";
	node1.data.phone = "123456";

	Node node2;
	node2.data.name = "tester2";
	node2.data.phone = "234567";

	plist1->ListInsertHead(&node1);
	plist1->ListInsertHead(&node2);

	plist1->ListTraverse();

	delete plist1;
	plist1 = NULL;*/

	system("pause");
	return 0;
}