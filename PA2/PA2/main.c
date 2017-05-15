/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA2                                                              *
* Date: 9/14/16                                                                            *
* Description: This program isn't finished, will be for PA3                                *
*******************************************************************************************/

#include "Header.h"

int main()
{
	FILE *infile = fopen("music.csv", "r");
	int menu_choice = 0, success = 0, count = 0;
	Record r = { "" };
	Node *pHead = NULL;

	menu_choice = choose_option();

	do
	{
		switch (menu_choice)
		{
		case 1:
			count = count_file_lines(infile);
			infile = fopen("music.csv", "r");
			for (int i = 0; i < count; i++)
				success = insertFront(&pHead, r, infile);
			printf("file loaded successfully\n");
			menu_choice = choose_option();
			system("cls");
			break;
		case 2:
			infile = fopen("music.csv", "w");
			write_to_file(infile, pHead);
			menu_choice = choose_option();
			system("cls");
			break;
		case 3:
			choice_three(pHead);
			menu_choice = choose_option();
			system("cls");
			break;
		case 4:
			menu_choice = choose_option();
			system("cls");
			break;
		case 5:
			menu_choice = choose_option();
			system("cls");
			break;
		case 6:
			menu_choice = choose_option();
			system("cls");
			break;
		case 7:
			menu_choice = choose_option();
			system("cls");
			break;
		case 8:
			choice_eight(pHead, count);
			menu_choice = choose_option();
			system("cls");
			break;
		}
	} while (menu_choice != 9);
	
	printf("You have exited the program\n");

	return 0;
}