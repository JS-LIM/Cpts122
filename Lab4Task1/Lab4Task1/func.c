#include "Header.h"

Node *makeNode(Data newData)
{
	Node *pMem = (Node *)malloc(sizeof(Node));
	
	if (pMem != NULL)
	{
		pMem->item.pData = (char *)malloc(sizeof(char) * strlen(newData.pData) + 1);
		if (pMem->item.pData != NULL)
		{
			strcpy(pMem->item.pData, newData.pData);
		}

		pMem->pNext = NULL;
	}
	
	return pMem;
}

Boolean isEmpty(Queue *q)
{
	if (q->pHead == NULL)
	{
		printf("List is empty\n");
		return TRUE;
	}

	else
	{
		printf("List is not empty\n");
		return FALSE;
	}
}

Boolean enqueue(Queue *q, Data newData)
{
	Node *pMem = makeNode(newData);
	Boolean success = FALSE;

	if (pMem != NULL)
	{
		success = TRUE;

		if (q->pTail != NULL)
		{
			q->pTail->pNext = pMem;
			q->pTail = pMem;
		}

		else
			q->pHead = q->pTail = pMem;
	}

	return success;
}

void printQueue(Node *a)
{
	if (a != NULL)
	{
		printf("%s\n", a->item.pData);
		a = a->pNext;
		printQueue(a);
	}
}

void dequeue(Queue *q, Data newData, char returned)
{
	Node *pMem = makeNode(newData);
	
	if (pMem != NULL)
	{
		if (q->pHead != NULL)
		{
			pMem = q->pHead;
			//strcpy(returned, pMem->item.pData);
			q->pHead = q->pHead->pNext;
			printf("print: %s\n", pMem->item.pData);
			free(pMem);
		}

		else
			printf("Nothing in list to dequeue\n");
	}
}