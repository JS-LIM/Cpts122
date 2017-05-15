#include "List.h"
#include "ListNode.h"

int main()
{
	List<int> list;

	list.insertAtFront(42);
	list.insertAtFront(3);
	list.insertAtFront(99);
	list.insertAtFront(76);
	list.print();


	return 0;
}