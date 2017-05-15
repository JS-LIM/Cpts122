#include "Header.h"

int main()
{
	Data n = { "sup" }, o = { "hi" }, p = { "wazzup" };
	Queue q = { NULL, NULL };
	Boolean result = { FALSE };
	char *data = { "" };

	result = isEmpty(&q);
	enqueue(&q, n);
	enqueue(&q, o);
	enqueue(&q, p);
	printQueue(q);
	dequeue(&q, n, data);
	dequeue(&q, n, data);
	dequeue(&q, n, data);
	dequeue(&q, n, data);

	//printf("data: %s\n", data);






	return 0;
}