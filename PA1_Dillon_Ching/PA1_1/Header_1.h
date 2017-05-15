/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program bubble sorts a list of names                                   *
*******************************************************************************************/

#include <stdio.h>
#include <string.h>

void bubbleSort(char *listPtrs[], int numItems, int order);
void print_list(char *listPtrs[], const int size);