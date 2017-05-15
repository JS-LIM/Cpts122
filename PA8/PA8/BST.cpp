/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA8                                                              *
* Date: 11/15/16                                                                           *
* Description: This Program takes data from a csv file and places them in order in two     *
*			   different trees based off of the third data value. Then it returns stats    *
*			   based off of the minimum and maximum values.								   *
*******************************************************************************************/

#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::setRoot(Node *newData)
{
	this->mpRoot = newData;
}

Node *& BST::getRoot()
{
	return this->mpRoot;
}

void BST::insert(int &newData, string &newData1)
{
	insert(mpRoot, newData, newData1);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

TransactionNode & BST::findSmallest(Node *pTree)
{
	if (pTree->getLeft() == nullptr)
	{
		cout << "Units: " << dynamic_cast <TransactionNode *> (pTree)->getUnits() << " Type: " << pTree->getData() << endl;
		return dynamic_cast <TransactionNode &> (*pTree);
	}

	else
		findSmallest(pTree->getLeft());
}

TransactionNode & BST::findLargest(Node *pTree)
{
	if (pTree->getRight() == nullptr)
	{
		dynamic_cast <TransactionNode *> (pTree)->printData();
		return dynamic_cast <TransactionNode &> (*pTree);
	}

	else
		findLargest(pTree->getRight());
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

void BST::insert(Node *& pTree, int &newData, string &newData1)
{
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(newData, newData1);
	}

	else if (newData >  dynamic_cast <TransactionNode *> (pTree)->getUnits())
	{
		insert(pTree->getRight(), newData, newData1);
	}

	else if (newData < dynamic_cast <TransactionNode *> (pTree)->getUnits())
	{
		insert(pTree->getLeft(), newData, newData1);
	}

	else
	{
		cout << "Tried to insert a duplicate" << endl;
	}
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
		cout << "Units: " << dynamic_cast <TransactionNode *> (pTree)->getUnits() << " Type: " << pTree->getData() << endl;
		inOrderTraversal(pTree->getRight());
	}
}