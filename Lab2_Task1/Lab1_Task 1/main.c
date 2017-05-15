#include "Header.h"

//int main(void)
//{
//	struct pokemon pok;
//	Pokemon pok2 = { "Charizard" };
//	int success = 0;
//
//	Node *pHead = NULL; 
//	success = insertFront(&pHead, pok2); 
//	printf("Name: %s\n", pHead->data.name);
//
//	return 0;
//}

int main()
{
	Contact contact1, contact2;
	int success = 0;

	contact1.id = 42;
	contact1.num = 1;
	//contact1.name = "";

	contact2.id = 43;
	contact2.num = 2;

	Node *pHead = NULL;

	success = insert_front(&pHead, contact1);
	success = insert_front(&pHead, contact2);

	print_list(pHead);
	
	

	return 0;
}






