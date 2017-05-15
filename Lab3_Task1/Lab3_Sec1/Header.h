#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

typedef struct node
{
	int data;
	struct node *next;
} Node;

typedef struct stack
{
	Node *pTop;
} Stack;

int is_Empty(Stack *s);
Node * make_node(Node data);
void push(Stack *s, Node data);
void print_stack(Stack *s);