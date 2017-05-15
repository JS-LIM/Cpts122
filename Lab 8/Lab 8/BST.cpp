#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::BST(const BST &rhs)
{
	this->mpRoot = rhs.mpRoot;
}

BST::~BST()
{
	cout << "Inside BST destructor" << endl;
	this->destroyTree(this->mpRoot);
}

Node * BST::getRoot() const
{
	return this->mpRoot;
}

void BST::setRoot(Node * const newRoot)
{
	this->mpRoot = newRoot;
}

void BST::insert(Node *& pTree, const string &newData)
{
	if (pTree == nullptr)
	{
		pTree = new Node(newData);
	}

	else if (newData > pTree->getData())
	{
		insert(pTree->getRight(), newData);
	}

	else if (newData < pTree->getData())
	{
		insert(pTree->getLeft(), newData);
	}

	else
	{
		cout << "Tried to insert a duplicate" << endl;
	}
}

void BST::insert(const string &newData)
{
	insert(this->mpRoot, newData);
}

void BST::inOrderTraversal(Node *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		inOrderTraversal(pTree->getLeft());
		cout << pTree->getData() << endl;
		inOrderTraversal(pTree->getRight());
	}
}

void BST::preOrderTraversal(Node *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		cout << pTree->getData() << endl;
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
	}
}

void BST::postOrderTraversal(Node *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		postOrderTraversal(pTree->getLeft());
		postOrderTraversal(pTree->getRight());
		cout << pTree->getData() << endl;
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

void BST::preOrderTraversal()
{
	preOrderTraversal(this->mpRoot);
}

void BST::postOrderTraversal()
{
	postOrderTraversal(this->mpRoot);
}

void BST::destroyTree(Node *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}