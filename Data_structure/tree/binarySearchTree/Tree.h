#ifndef _TREE_H_
#define _TREE_H_


#include <iostream>
using namespace std;

enum ORDER_MODE
{
	ORDER_MODE_PREV,
	ORDER_MODE_MID,
	ORDER_MODE_POST
};


/************Node********************/
template<typename T>
class BinaryNode
{
public:
	BinaryNode(const T &elem, BinaryNode *lf, BinaryNode *rg):
		element(elem), left(lf), right(rg){}
public:
	T element;
	BinaryNode* left;
	BinaryNode* right;
};
/************Node********************/

/************Tree********************/
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();
	const T findMin() const;
	const T findMax() const;
	bool contains(const T& x) const;
	void printTree(ORDER_MODE eOrderMode = ORDER_MODE_PREV) const;
	void makeEmpty();
	void insert(const T& x);
	void remove(const T& x);
private:
	BinaryNode<T>* m_root;
	void insert(const T& x, BinaryNode<T>* &t);
	void remove(const T& x, BinaryNode<T>* &t);
	BinaryNode<T>* findMin(BinaryNode<T>* t) const;
	BinaryNode<T>* findMax(BinaryNode<T>* t) const;
	bool contains(const T& x, const BinaryNode<T>* t) const;
	void makeEmpty(BinaryNode<T>* &t);
	void printTreeInPrev(BinaryNode<T>* t) const;
	void printTreeInMid(BinaryNode<T>* t)const;
	void printTreeInPost(BinaryNode<T>* t)const;
};


template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = NULL;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& rhs)
{
	m_root = rhs.m_root;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	makeEmpty();
}

template<typename T>
void BinarySearchTree<T>::makeEmpty()
{
	makeEmpty(m_root);
}

template<typename T>
void BinarySearchTree<T>::makeEmpty(BinaryNode<T>* &t) // makeEmpty的参数是一个指针的引用：BinaryNode<T>* &t 
{
	if (t)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template<typename T>
const T BinarySearchTree<T>::findMin() const
{
	BinaryNode<T>* temp = findMin(m_root);
	if (temp == NULL)
	{
		cerr << "树不存在" << endl;
		return 0;
	}
	else
		return temp->element;
	//return findMin(m_root)->element;
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* t) const
{
	if (!t)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

template<typename T>
const T BinarySearchTree<T>::findMax() const
{
	BinaryNode<T>* temp = findMax(m_root);
	if (temp == NULL)
	{
		cerr << "树不存在" << endl;
		return 0;
	}
	else
		return temp->element;
	//return findMax(m_root)->element;
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::findMax(BinaryNode<T>* t) const
{
	if (!t)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}


// return true if the x is found in the tree 
template <class T>
bool  BinarySearchTree<T>::contains(const T& x) const
{
	return contains(x, m_root);
}
template <class T>
bool BinarySearchTree<T>::contains(const T& x, const BinaryNode<T>* t) const
{
	if (!t)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (x > t->element)
		return contains(x, t->right);
	else
		return true;
}

template <class T>
void BinarySearchTree<T>::insert(const T& x)
{
	insert(x, m_root);
}

template <class T>
void BinarySearchTree<T>::insert(const T& x, BinaryNode<T>* &t)
{
	if (t == NULL)
		t = new BinaryNode<T>(x, NULL, NULL);//注意这个指针参数是引用 
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->element)
		insert(x, t->right);
	else
		;//do nothing 
}


template <class T>
void BinarySearchTree<T>::remove(const T& x)
{
	remove(x, m_root);
}

template <class T>
void BinarySearchTree<T>::remove(const T& x, BinaryNode<T>* &t)
{
	if (t == NULL)
		return;
	if (x < t->element)
		remove(x, t->left);
	else if (x > t->element)
		remove(x, t->right);
	else // now == 
	{
		if (t->left != NULL && t->right != NULL)//two child 
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else
		{
			BinaryNode<T> *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}
}


//Print tree
template <class T>
void BinarySearchTree<T>::printTree(ORDER_MODE eOrderMode /*= ORDER_MODE_PREV*/) const
{
	if (ORDER_MODE_PREV == eOrderMode)
		printTreeInPrev(m_root);
	else if (ORDER_MODE_MID == eOrderMode)
		printTreeInMid(m_root);
	else if (ORDER_MODE_POST == eOrderMode)
		printTreeInPost(m_root);
	else
		;//do nothing
}
template <class T>
void BinarySearchTree<T>::printTreeInPrev(BinaryNode<T>* t) const
{
	if (t)
	{
		cout << t->element;
		printTreeInPrev(t->left);
		printTreeInPrev(t->right);
	}
}
template <class T>
void BinarySearchTree<T>::printTreeInMid(BinaryNode<T>* t) const
{
	if (t)
	{
		printTreeInMid(t->left);
		cout << t->element;
		printTreeInMid(t->right);
	}
}
template <class T>
void BinarySearchTree<T>::printTreeInPost(BinaryNode<T>* t) const
{
	if (t)
	{
		printTreeInPost(t->left);
		printTreeInPost(t->right);
		cout << t->element;
	}
}


/************Tree********************/

#endif