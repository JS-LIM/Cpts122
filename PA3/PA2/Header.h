/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA3                                                              *
* Date: 9/23/16                                                                            *
* Description: This program makes a music player that reads in a music.csv file            *
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct duration
{
	int minutes;
	int seconds;
} Duration;

typedef struct record
{
	char artist[30];
	char album_title[30];
	char song_title[30];
	char genre[30];
	struct duration time;
	int times_played;
	int rating;
} Record;

typedef struct node
{
	Record data;
	struct node *pNext, *pPrev;
} Node;

int display_menu();
Node *makeNode(Record newData, FILE *infile);
int insertFront(Node **pList, Record newData, FILE *infile);
void printList(Node *pHead);
int count_file_lines(FILE *infile);
void choice_three(Node *pHead);
int choose_option();
void write_to_file(FILE *infile, Node *pHead);
void choice_eight(Node *pHead, int count);
void choice_six(Node *pHead);
Node *choice_four();
int scanned_insertFront(Node **pList, FILE *infile);
void choice_five(Node **pList);
void choice_seven(Node **pList);
void swap(Node *pCur, Node *pNext);