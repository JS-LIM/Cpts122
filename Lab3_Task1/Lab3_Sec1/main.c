#include "Header.h"

int main()
{
	Stack s;
	Node a, b;
	int success = 0;

	success = is_Empty(&s);

	a.data = 4;
	b.data = 2;

	push(&s, a);
	push(&s, b);
	
	printf("%d\n", a.data);
	printf("%d\n", b.data);

	success = is_Empty(&s);
	print_stack(s.pTop);

	//s.pTop = NULL;
	
	return 0;
}