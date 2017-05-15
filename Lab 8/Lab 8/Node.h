#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;
using std::endl;

class Node
{
	friend class BST;

public:
	Node(string mData = "");
	~Node();

	string getData() const;

	void setData(const string newData);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);

private:
	string mData;

	Node *mpLeft;
	Node *mpRight;

	Node *& getLeft();
	Node *& getRight();
};

ostream & operator << (ostream &lhs, Node rhs[]);