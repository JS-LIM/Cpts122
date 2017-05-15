#pragma once

#include <iostream>
#include "Node.h"

class BST
{
public:
	BST();
	BST(const BST &rhs);
	~BST();

	Node *getRoot() const;
	void setRoot(Node * const newRoot);

	void insert(const string &newData);
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

private:
	Node *mpRoot;

	void insert(Node *& pTree, const string &newData);
	void inOrderTraversal(Node *pTree);
	void preOrderTraversal(Node *pTree);
	void postOrderTraversal(Node *pTree);
	void destroyTree(Node *pTree);
};