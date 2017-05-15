/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA3                                                              *
* Date: 9/23/16                                                                            *
* Description: This program makes a music player that reads in a music.csv file            *
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
		printf("rating: %d\n\n", pHead->data.rating);
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
	Node *pCur = pHead, *pPrev = pHead, *pTemp = pHead;
	int choice = 0, count = 1, option = 0, success = 0, check = 0;
	char artist[30] = "";


	if (pCur == NULL)
	{
		printf("Please load a file\n");
		return;
	}
		
	do
	{
		printf("Enter in the number of your choice\n1. Print all records\n2. Print all records that match an artist\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);

	while (success != 1)
	{
		success = 1;
		pTemp = pHead;

		while (pTemp->pNext != NULL)
		{
			if (strcmp(pTemp->data.artist, pTemp->pNext->data.artist) > 0)
			{
				swap(pTemp, pTemp->pNext);

				pTemp = pTemp->pNext;
				success = 0;
			}

			else
			{
				pTemp = pTemp->pNext;
			}
		}
	}
	
	if (choice == 1)
	{
		printList(pCur);
	}

	else
	{
		printf("Which artist would you like?\nEnter in the number of the artist\n");
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.artist, pPrev->data.artist) == 0 && count != 1)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			else
			{
				printf("%d: %s\n", count, pCur->data.artist);
				pPrev = pCur;
				pCur = pCur->pNext;
				count++;
			}
		}

		do
		{
			printf("Enter in a number\n");
			scanf("%d", &option);
		} while (option < 1 || option > (count - 1));
			
		pCur = pHead;
		pPrev = pHead;
		count = 1;

		while (check != 1)
		{
			if (pCur == NULL)
			{
				strcpy(artist, pPrev->data.artist);
				check = 1;
			}
			
			else
			{
				if (strcmp(pCur->data.artist, pPrev->data.artist) == 0)
				{
					pPrev = pCur;
					pCur = pCur->pNext;
				}

				else
				{
					if (option == count)
					{
						strcpy(artist, pPrev->data.artist);
						check = 1;
					}

					pPrev = pCur;
					pCur = pCur->pNext;
					count++;
				}
			}
		}

		pCur = pHead;

		while (pCur != NULL)
		{
			if (strcmp(artist, pCur->data.artist) == 0)
			{
				printf("%s,", pCur->data.artist);
				printf("%s,", pCur->data.album_title);
				printf("%s,", pCur->data.song_title);
				printf("%s,", pCur->data.genre);
				printf(" %d:", pCur->data.time.minutes);
				printf(" %d,", pCur->data.time.seconds);
				printf(" %d,", pCur->data.times_played);
				printf(" %d\n", pCur->data.rating);
				pCur = pCur->pNext;
			}

			else
				pCur = pCur->pNext;
		}
		printf("\n");
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
		fprintf(infile, " %d:", pHead->data.time.minutes);
		fprintf(infile, " %d,", pHead->data.time.seconds);
		fprintf(infile, " %d,", pHead->data.times_played);
		fprintf(infile, " %d\n", pHead->data.rating);
		pHead = pHead->pNext;
	}
}

void choice_eight(Node *pHead, int count)
{
	Node *pCur = pHead, *pCur2 = pHead;
	int inc = 0, inc2 = 0, choice = 0, rating = 0;
	char artist[30] = "";

	if (pCur == NULL)
	{
		printf("Please load a file\n");
		return;
	}

	printf("Which song would you like to edit?\nEnter in the number of your choice\n");

	for (inc = 1; inc < count; inc++)
	{
		printf("%d. ", inc);
		printf("%s,", pCur->data.artist);
		printf("%s,", pCur->data.album_title);
		printf("%s,", pCur->data.song_title);
		printf("%s,", pCur->data.genre);
		printf(" %d:", pCur->data.time.minutes);
		printf(" %d,", pCur->data.time.seconds);
		printf(" %d,", pCur->data.times_played);
		printf(" %d\n", pCur->data.rating);
		pCur = pCur->pNext;
	}

	scanf("%d", &choice);

	do
	{
		printf("What would you like to rate it?\nEnter in a number 1-5\n");
		scanf("%d", &rating);
	} while (rating < 1 || rating > 6);

	inc = 1;
	while (pCur2 != NULL)
	{
		if (choice == inc)
		{
			pCur2->data.rating = rating;
		}

		inc++;
		pCur2 = pCur2->pNext;
	}
}

void choice_six(Node *pHead)
{
	Node *pCur = pHead, *pPrev = pHead;
	int count = 1, option = 0, choice = 0, rating, inc2 = 0, times_played, minutes, seconds, success = 0;
	char artist[30] = "", album_title[30] = "", song_title[30] = "", genre[30] = "";

	if (pCur == NULL)
	{
		printf("Please load file\n");
		return;
	}
		

	while (success != 1)
	{
		success = 1;
		pCur = pHead;

		while (pCur->pNext != NULL)
		{
			if (strcmp(pCur->data.artist, pCur->pNext->data.artist) > 0)
			{
				swap(pCur, pCur->pNext);

				pCur = pCur->pNext;
				success = 0;
			}

			else
			{
				pCur = pCur->pNext;
			}
		}
	}

	pCur = pHead;
	printf("Which artist would you like to edit?\nEnter in the number of the artist\n");
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, pPrev->data.artist) == 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		else
		{
			printf("%d: %s\n", count, pCur->data.artist);
			pPrev = pCur;
			pCur = pCur->pNext;
			count++;
		}
	}

	do
	{
		printf("Enter in a number\n");
		scanf("%d", &option);
	} while (option < 1 || option >(count - 1));

	pCur = pHead;
	pPrev = pHead;
	count = 1;

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, pPrev->data.artist) == 0)
		{
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		else
		{
			if (option == count)
				strcpy(artist, pCur->data.artist);

			pPrev = pCur;
			pCur = pCur->pNext;
			count++;
		}
	}

	pCur = pHead;

	while (pCur != NULL)
	{
		if (strcmp(artist, pCur->data.artist) == 0)
		{
			printf("%s,", pCur->data.artist);
			printf("%s,", pCur->data.album_title);
			printf("%s,", pCur->data.song_title);
			printf("%s,", pCur->data.genre);
			printf(" %d:", pCur->data.time.minutes);
			printf(" %d,", pCur->data.time.seconds);
			printf(" %d,", pCur->data.times_played);
			printf(" %d\n", pCur->data.rating);

			strcpy(artist, pCur->data.artist);
			strcpy(album_title, pCur->data.album_title);
			strcpy(song_title, pCur->data.song_title);
			strcpy(genre, pCur->data.genre);
			minutes = pCur->data.time.minutes;
			seconds = pCur->data.time.seconds;
			times_played = pCur->data.times_played;
			rating = pCur->data.rating;

			printf("Enter in the option to edit\n1. artist\n2. album title\n3. song title\n4. genre\n5. time (minutes)\n6. time (seconds)\n7. times played\n8. rating\n9. exit\n");

			do
			{
				printf("Enter a valid number\n");
				scanf("%d", &choice);
			} while (choice < 1 || choice > 9);

			switch (choice)
			{
			case 1:
				printf("What is the new artist?\nEnter in a name\n");
				scanf(" %[^\n]s", &artist);
				break;
			case 2:
				printf("What is the new album title?\nEnter in a name\n");
				scanf(" %[^\n]s", &album_title);
				break;
			case 3:
				printf("What is the new song title?\nEnter in a name\n");
				scanf(" %[^\n]s", &song_title);
				break;
			case 4:
				printf("What is the new genre?\nEnter in a genre\n");
				scanf(" %[^\n]s", &genre);
				break;
			case 5:
				do
				{
					printf("How many minutes long is it?\nEnter in a number\n");
					scanf("%d", &minutes);
				} while (minutes < 0);
				break;
			case 6:
				do
				{
					printf("How many seconds long is it?\nEnter in a number\n");
					scanf("%d", &seconds);
				} while (seconds < 0 || seconds > 59);
				break;
			case 7:
				do
				{
					printf("How many times has it been played?\nEnter in a number\n");
					scanf("%d", &times_played);
				} while (times_played < 0);
				break;
			case 8:
				do
				{
					printf("What would you like to rate it?\nEnter in a number 1-5\n");
					scanf("%d", &rating);
				} while (rating < 1 || rating > 6);
				break;
			case 9:
				break;
			}
			pPrev = pCur;
				
			strcpy(pPrev->data.artist, artist);
			strcpy(pPrev->data.album_title, album_title);
			strcpy(pPrev->data.song_title, song_title);
			strcpy(pPrev->data.genre, genre);
			pPrev->data.time.minutes = minutes;
			pPrev->data.time.seconds = seconds;
			pPrev->data.times_played = times_played;
			pPrev->data.rating = rating;

			printf("Edited: %s,", pPrev->data.artist);
			printf("%s,", pPrev->data.album_title);
			printf("%s,", pPrev->data.song_title);
			printf("%s,", pPrev->data.genre);
			printf(" %d:", pPrev->data.time.minutes);
			printf(" %d,", pPrev->data.time.seconds);
			printf(" %d,", pPrev->data.times_played);
			printf(" %d\n\n", pPrev->data.rating);

			pPrev = pPrev->pNext;

			pCur = pCur->pNext;
		}

		else
			pCur = pCur->pNext;
	}
	
}

Node *choice_four()
{
	char artist[30] = "", album_title[30] = "", song_title[30] = "", genre[30] = "";
	int minutes, seconds, times_played, rating;
	Node *pMem = (Node *)malloc(sizeof(Node));

	pMem->pPrev = NULL;

	printf("Making new record\n");
	
	printf("Enter in the Artist\n");
	scanf(" %[^\n]s", &artist);
	strcpy(pMem->data.artist, artist);

	printf("Enter in the Album Title\n");
	scanf(" %[^\n]s", &album_title);
	strcpy(pMem->data.album_title, album_title);

	printf("Enter in the Song Title\n");
	scanf(" %[^\n]s", &song_title);
	strcpy(pMem->data.song_title, song_title);

	printf("Enter in the Genre\n");
	scanf(" %[^\n]s", &genre);
	strcpy(pMem->data.genre, genre);

	do
	{
		printf("Enter in the time (Minutes)\n");
		scanf("%d", &minutes);
	} while (minutes < 0);
	pMem->data.time.minutes = minutes;

	do
	{
		printf("Enter in the time (Seconds)\n");
		scanf("%d", &seconds);
	} while (seconds < 0 || seconds > 59);
	pMem->data.time.seconds = seconds;

	do
	{
		printf("Enter in the amount of Times Played\n");
		scanf("%d", &times_played);
	} while (times_played < 0);
	pMem->data.times_played = times_played;

	do
	{
		printf("Enter in the Rating\n");
		scanf("%d", &rating);
	} while (rating < 1 || rating > 6);
	pMem->data.rating = rating;

	return pMem;
}

int scanned_insertFront(Node **pList, FILE *infile)
{
	Node *pMem = NULL, *pCur = NULL;
	int success = 0;

	if (*pList == NULL)
	{
		printf("Please load file\n");
		return;
	}

	pMem = choice_four();

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

void choice_five(Node **pList)
{
	int i = 0;
	char song[30] = "", song2[30] = "", temp = '\0';
	Node *pTemp = *pList, *pCur = *pList, *pPrev = NULL;

	if (*pList == NULL)
	{
		printf("Please load file\n");
		return;
	}

	printf("What song would you like to remove?\n");

	while (pTemp != NULL)
	{
		printf("%s\n", pTemp->data.song_title);
		pTemp = pTemp->pNext;
	}

	printf("Enter in the song for deletion\n");
	scanf(" %[^\n]s", &song);

	for (i = 0; i < 29; i++)
	{
		song2[i + 1] = song[i];
	}

	song2[0] = ' ';

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.song_title, song2) == 0)
		{
			if (pPrev == NULL)
			{
				(*pList) = pCur->pNext;
				(*pList)->pPrev = NULL;
				free(pCur);
				return;
			}

			else
			{
				pPrev->pNext = pCur->pNext;
				pCur->pPrev = pPrev->pPrev;
				free(pCur);
				return;
			}
		}
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	printf("Could not find record\n");
}

void choice_seven(Node **pList)
{
	Node *pCur = *pList, *pPrev = NULL, *pMem = NULL;
	int choice, success = 0;

	if (*pList == NULL)
	{
		printf("Please load file\n");
		return;
	}

	pMem = (Node *)malloc(sizeof(Node));

	printf("Would you like to sort by\n1. Artist\n2. Album Title\n3. Rating\n4. Times Played\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		while (success != 1)
		{
			success = 1;
			pCur = *pList;

			while (pCur->pNext != NULL)
			{
				if (strcmp(pCur->data.artist,pCur->pNext->data.artist) > 0)
				{
					swap(pCur, pCur->pNext);

					pCur = pCur->pNext;
					success = 0;
				}

				else
				{
					pCur = pCur->pNext;
				}
			}
		}
		break;
	case 2:
		while (success != 1)
		{
			success = 1;
			pCur = *pList;

			while (pCur->pNext != NULL)
			{
				if (strcmp(pCur->data.album_title, pCur->pNext->data.album_title) > 0)
				{
					swap(pCur, pCur->pNext);

					pCur = pCur->pNext;
					success = 0;
				}

				else
				{
					pCur = pCur->pNext;
				}
			}
		}
		break;
	case 3:
		while (success != 1)
		{
			success = 1;
			pCur = *pList;

			while (pCur->pNext != NULL)
			{
				if (pCur->data.rating > pCur->pNext->data.rating)
				{
					swap(pCur, pCur->pNext);

					pCur = pCur->pNext;
					success = 0;
				}

				else
				{
					pCur = pCur->pNext;
				}
			}
		}
		break;
	case 4:
		while (success != 1)
		{
			success = 1;
			pCur = *pList;

			while (pCur->pNext != NULL)
			{
				if (pCur->data.times_played > pCur->pNext->data.times_played)
				{
					swap(pCur, pCur->pNext);

					pCur = pCur->pNext;
					success = 0;
				}

				else
				{
					pCur = pCur->pNext;
				}
			}
		}
		break;
	}
}

void swap(Node *pCur, Node *pNext)
{
	Node *pMem = (Node *)malloc(sizeof(Node));

	strcpy(pMem->data.artist, pCur->data.artist);
	strcpy(pCur->data.artist, pNext->data.artist);
	strcpy(pNext->data.artist, pMem->data.artist);

	strcpy(pMem->data.album_title, pCur->data.album_title);
	strcpy(pCur->data.album_title, pNext->data.album_title);
	strcpy(pNext->data.album_title, pMem->data.album_title);

	strcpy(pMem->data.song_title, pCur->data.song_title);
	strcpy(pCur->data.song_title, pNext->data.song_title);
	strcpy(pNext->data.song_title, pMem->data.song_title);

	strcpy(pMem->data.genre, pCur->data.genre);
	strcpy(pCur->data.genre, pNext->data.genre);
	strcpy(pNext->data.genre, pMem->data.genre);

	pMem->data.time.minutes = pCur->data.time.minutes;
	pCur->data.time.minutes = pNext->data.time.minutes;
	pNext->data.time.minutes = pMem->data.time.minutes;

	pMem->data.time.seconds = pCur->data.time.seconds;
	pCur->data.time.seconds = pNext->data.time.seconds;
	pNext->data.time.seconds = pMem->data.time.seconds;

	pMem->data.times_played = pCur->data.times_played;
	pCur->data.times_played = pNext->data.times_played;
	pNext->data.times_played = pMem->data.times_played;

	pMem->data.rating = pCur->data.rating;
	pCur->data.rating = pNext->data.rating;
	pNext->data.rating = pMem->data.rating;
}