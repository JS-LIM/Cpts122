/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program bubble sorts a list of names                                   *
*******************************************************************************************/

#include "Driver_1.h"

void testBubbleSortAscend(void)
{
	char *listPtrs[10] = { "fred", "austin", "andy", "julie", "jake" };
	const int size = 5, order = 0; 
	int index = 0;

	print_list(listPtrs, size);

	bubbleSort(listPtrs, size, order);

	print_list(listPtrs, size);
}