#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char *pData;
} Data;

typedef struct node
{
	Data item;
	struct node *pNext;
} Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
} Queue;

typedef enum boolean
{
	FALSE, TRUE
} Boolean;

Node *makeNode(Data newData);
Boolean isEmpty(Queue *q);
Boolean enqueue(Queue *q, Data newData);
void printQueue(Queue a);
void dequeue(Queue *q, Data newData, char returned);

