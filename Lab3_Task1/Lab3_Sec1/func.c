#include "Header.h"

int is_Empty(Stack *s)
{
	if (s->pTop == NULL)
	{
		printf("Stack is empty\n");
		return TRUE;
	}

	else
	{
		printf("Stack is not empty\n");
		return FALSE;
	}
		
}

Node * make_node(Node data)
{
	Node * temp = (Node*)malloc(sizeof(Node));

	if (temp != NULL)
	{
		temp->next = NULL;
		//temp->data = data;

		return temp;
	}

	else
	{
		return NULL;
	}
		
}

void push(Stack *s, Node data)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	
	if (temp != NULL)
	{
		s = temp;
		temp->next = s;

		/*temp->next = s;
		s = temp;*/
		
	}
}

void print_stack(Stack *s)
{
	Node *temp = s;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}