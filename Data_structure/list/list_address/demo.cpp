#include <iostream>
#include <stdlib.h>
#include "List.h"

using namespace std;
int meau()
{
	//��ʾ���ܲ˵�
	cout << "���ܲ˵�" << endl;
	cout << "1.�½���ϵ��" << endl;
	cout << "2.ɾ����ϵ��" << endl;
	cout << "3.���ͨѶ¼" << endl;
	cout << "4.�˳�ͨѶ¼" << endl;
	cout << "�����룺";

	int order = 0;
	cin >> order;
	return order;
}

void createPerson(List *list)
{
	Node node; //��ʱ��
	cout << "������������" << endl;
	cin >> node.data.name;
	cout << "������绰��" << endl;
	cin >> node.data.phone;

	/*Person person;
	cout << "������������" << endl;
	cin >> person.name;
	cout << "������绰��" << endl;
	cin >> person.phone;
	node.data = person;*/ //��һ�ַ���

	list->ListInsertTail(&node);
}

void deletePerson(List *list)
{
	Node temp;
	Node node; //��ʱ��
	int position = -1;
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	cin >> node.data.name;
	cout << "������Ҫɾ����ϵ�˵ĵ绰��" << endl;
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
			cout << "�û�ָ��----->>�½���ϵ��" << endl;
			createPerson(plist);
			break;
		case 2:
			cout << "�û�ָ��----->>ɾ����ϵ��" << endl;
			deletePerson(plist);
			break;
		case 3:
			cout << "�û�ָ��----->>���ͨѶ¼" << endl;
			plist->ListTraverse();
			break;
		case 4:
			cout << "�û�ָ��----->>�˳�ͨѶ¼" << endl;
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