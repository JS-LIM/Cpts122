#include "BST.h"

int main()
{
	BST a;

	a.insert("What");
	a.insert("In");
	a.insert("The");
	a.insert("Actual");
	a.insert("Fuck");

	cout << "In order Traversal" << endl;
	a.inOrderTraversal();
	cout << endl;

	cout << "Preorder Traversal" << endl;
	a.preOrderTraversal();
	cout << endl;

	cout << "Postorder Traversal" << endl;
	a.postOrderTraversal();
	cout << endl;

	return 0;
}
