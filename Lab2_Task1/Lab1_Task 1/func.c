#include "Header.h"

//Node * makeNode(Pokemon newData)
//{
//	Node *pMem = NULL;
//
//	pMem = (Node *)malloc(sizeof(Node));
//
//	(*pMem).pNext = NULL;
//	pMem->data = newData;
//
//	return pMem;
//}
//
//int insertFront(Node **pList, Pokemon newData)
//{
//	Node *pMem = NULL;
//	int success = 0; 
//
//	pMem = makeNode(newData);
//
//	if (pMem != NULL)
//	{
//		success = 1;
//
//		if (*pList == NULL)
//		{
//			*pList = pMem;
//		}
//		else 
//		{
//			pMem->pNext = *pList;
//			*pList = pMem;
//		}
//	}
//
//	return success;
//}

Node* makeNode(Contact data)
{
	Node *pMem = (Node*) malloc(sizeof(Node));
	if (pMem != NULL)
	{
		pMem->next = NULL;
		pMem->data.id = data.id;
		pMem->data.num = data.num;
		return pMem;
	}

	else
		return NULL;
}

int insert_front(Node **pList, Contact data)
{
	Node *pMem = makeNode(data);
	int success = 0;

	if (pMem != NULL)
	{
		success = 1;

		if (*pList == NULL)
		{
			*pList = pMem;
		}

		else
		{
			pMem->next = *pList;
			*pList = pMem;
		}
	}

	return success;
}

void print_list(Node *pList)
{
	Node *pMem = pList;
	while (pMem != NULL)
	{
		printf("%d\n", pMem->data.id);
		printf("%d\n", pMem->data.num);
		printf("%s\n", pMem->data.name);
		pMem = pMem->next;
	}
}