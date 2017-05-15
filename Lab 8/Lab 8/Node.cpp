#include "Node.h"

Node::Node(string newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node()
{
	cout << "Inside Node's destructor" << endl;
	cout << "Deleting Node with data: " << getData() << endl;
}

void Node::setData(const string newData)
{
	this->mData = newData;
}

void Node::setLeft(Node * const newLeft)
{
	this->mpLeft = newLeft;
}

void Node::setRight(Node * const newRight)
{
	this->mpRight = newRight;
}

string Node::getData() const
{
	return this->mData;
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}

ostream & operator << (ostream &lhs, Node rhs[])
{
	lhs << rhs;

	return lhs;
}
