/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program bubble sorts a list of names                                   *
*******************************************************************************************/

#include "Header_1.h"

void bubbleSort(char *listPtrs[], int numItems, int order)
{
	int index = 0, passes = 0;
	char *pTemp = NULL;

	for (passes = 1; passes < numItems; ++passes)
	{
		for (index = 0; index < numItems - passes; ++index)
		{
			if (order == 0)
			{
				if (strcmp (listPtrs[index], listPtrs[index + 1]) > 0)
				{
					pTemp = listPtrs[index]; 
					listPtrs[index] = listPtrs[index + 1];
					listPtrs[index + 1] = pTemp;
				}
			}
		}
	}
}

void print_list(char *listPtrs[], const int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		puts(listPtrs[index]);
	}

	printf("\n");
}