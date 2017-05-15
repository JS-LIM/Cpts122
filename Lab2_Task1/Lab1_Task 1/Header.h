#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

//typedef struct pokemon 
//{
//	char name[100]; 
//} Pokemon;
//
//
//typedef struct node 
//{
//	Pokemon data;
//	struct node *pNext;
//} Node;
//
//Node * makeNode(Pokemon newData);
//int insertFront(Node **pList, Pokemon newData);

typedef struct contact
{
	int id;
	int num;
	char *name;
} Contact;

typedef struct node
{
	Contact data;
	struct node *next;
} Node;

Node *makeNode(Contact data);
int insert_front(Node **pHead, Contact data);
void print_list(Node *pList);

