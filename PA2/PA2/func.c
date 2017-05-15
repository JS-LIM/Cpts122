/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA2                                                              *
* Date: 9/14/16                                                                            *
* Description: This program isn't finished, will be for PA3                                *
*******************************************************************************************/

#include "Header.h"

int display_menu()
{
	int menu_choice;

	do
	{
		printf("Hello, welcome to your Digital Music Manager\nEnter in the number of your choice\n1. Load\n2. Store\n3. Display\n4. Insert\n5. Delete\n6. Edit\n7. Sort\n8. Rate\n9. Exit\n");
		scanf("%d", &menu_choice);
	} while (menu_choice == NULL);

	return menu_choice;
}

Node *makeNode(Record newData, FILE *infile)
{
	char line[200] = "", *token = NULL, *temp = NULL;
	Node *pMem = NULL;

	pMem = (Node *)malloc (sizeof(Node));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		pMem->data = newData;
	}
	

	if (infile != NULL)
	{
		fgets(line, 200, infile);

		if (line[0] == '\"')
		{
			token = strtok(line, ",");
			strcpy(pMem->data.artist, token);

			temp = token;

			temp = strtok(NULL, ",");
			strcat(pMem->data.artist, ",");
			strcat(pMem->data.artist, temp);
			
			token = strtok(NULL, ",");
			strcpy(pMem->data.album_title, token);

			token = strtok(NULL, ",");
			strcpy(pMem->data.song_title, token);

			token = strtok(NULL, ",");
			strcpy(pMem->data.genre, token);

			token = strtok(NULL, ":");
			pMem->data.time.minutes = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.time.seconds = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.times_played = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.rating = atoi(token);
		}

		else
		{
			token = strtok(line, ",");
			strcpy(pMem->data.artist, token);

			token = strtok(NULL, ",");
			strcpy(pMem->data.album_title, token);

			token = strtok(NULL, ",");
			strcpy(pMem->data.song_title, token);

			token = strtok(NULL, ",");
			strcpy(pMem->data.genre, token);

			token = strtok(NULL, ":");
			pMem->data.time.minutes = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.time.seconds = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.times_played = atoi(token);

			token = strtok(NULL, ",");
			pMem->data.rating = atoi(token);
		}
	}

	return pMem;
}

int insertFront(Node **pList, Record newData, FILE *infile)
{
	Node *pMem = NULL, *pCur = NULL;
	int success = 0;

	pMem = makeNode(newData, infile);

	if (pMem != NULL)
	{
		success = 1;

		if (*pList == NULL)
			*pList = pMem;

		else
		{
			pCur = *pList;
			pMem->pNext = *pList;
			pCur->pPrev = pMem;
			*pList = pMem;
		}
	}

	return success;
}

void printList(Node *pHead)
{
	while (pHead != NULL)
	{
		printf("artist: %s\n", pHead->data.artist);
		printf("album_title: %s\n", pHead->data.album_title);
		printf("song_title: %s\n", pHead->data.song_title);
		printf("genre: %s\n", pHead->data.genre);
		printf("minutes: %d\n", pHead->data.time.minutes);
		printf("seconds: %d\n", pHead->data.time.seconds);
		printf("times_played: %d\n", pHead->data.times_played);
		printf("rating: %d\n", pHead->data.rating);
		//printf("pPrev %d\n", pHead->pPrev);
		//printf("pHead %d\n", pHead);
		//printf("pNext %d\n\n", pHead->pNext);
		pHead = pHead->pNext;
	}
}

int count_file_lines(FILE *infile)
{
	int count = 0;
	char line[200] = "", line_prev[200] = "";

	fgets(line, 200, infile);

	while (strcmp(line, line_prev) != 0)
	{
		strcpy(line_prev, line);
		fgets(line, 200, infile);
		count++;
	}

	return count;
}

void choice_three(Node *pHead)
{
	//needs fixing

	int choice = 0, count = 1;

	do
	{
		printf("Enter in the number of your choice\n1. Print all records\n2. Print all records that match an artist\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	
	if (choice == 1)
	{
		if (pHead == NULL)
			printf("List is empty\n");
		
		else
			printList(pHead);
	}

	else 
	{
		if (pHead == NULL)
			printf("List is empty\n");

		else
		{
			/*printf("Which artist would you like?\nEnter in the number of the artist\n");
			while (pHead != NULL)
			{
				printf("%d: %s\n", count, pHead->data.artist);
				pHead = pHead->pNext;
				count++;
			}

			scanf("%d", &count);*/
		}
	}
}

int choose_option()
{
	int menu_choice;

	do
	{
		menu_choice = display_menu();
		system("cls");
	} while (menu_choice < 1 || menu_choice > 9);

	return menu_choice;
}

void write_to_file(FILE *infile, Node *pHead)
{
	printf("File has stored successfully\n");

	while (pHead != NULL)
	{
		fprintf(infile, "%s,", pHead->data.artist);
		fprintf(infile, "%s,", pHead->data.album_title);
		fprintf(infile, "%s,", pHead->data.song_title);
		fprintf(infile, "%s,", pHead->data.genre);
		fprintf(infile, "%d:", pHead->data.time.minutes);
		fprintf(infile, "%d,", pHead->data.time.seconds);
		fprintf(infile, "%d,", pHead->data.times_played);
		fprintf(infile, "%d\n", pHead->data.rating);
		pHead = pHead->pNext;
	}
}

void choice_eight(Node *pHead, int count)
{
	// Needs fixing

	int inc = 0, choice = 0, rating = 0;
	printf("Which song would you like to rate?\nEnter in the number of your choice\n");

	for (inc = 1; inc < count; inc++)
	{
		printf("%d. ", inc);
		printf("%s,", pHead->data.artist);
		printf("%s,", pHead->data.album_title);
		printf("%s,", pHead->data.song_title);
		printf("%s,", pHead->data.genre);
		printf("%d:", pHead->data.time.minutes);
		printf("%d,", pHead->data.time.seconds);
		printf("%d,", pHead->data.times_played);
		printf("%d\n", pHead->data.rating);
		pHead = pHead->pNext;
	}

	do
	{
		printf("Enter a valid number\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > count);
	
	do
	{
		printf("What would you like to rate it?\nEnter in a number 1-5\n");
		scanf("%d", &rating);
	} while (rating < 1 || rating > 6);
}