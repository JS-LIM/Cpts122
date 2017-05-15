/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA2                                                              *
* Date: 9/14/16                                                                            *
* Description: This program isn't finished, will be for PA3                                *
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

//"Swift, Taylor", 1989, Shake it Off, Pop, 3:35, 12, 3
//Drake, NOTHING WAS THE SAME, Own it, Rap, 3 : 23, 3, 3
//Drake, YOU WELCOME, The Motto, Rap, 4 : 13, 7, 4
//"Perri, Christina", HEAD OF HEART, Trust, Pop, 2 : 35, 3, 5
//"Bieber, Justin", PURPOSE, No Sense, Pop, 4 : 12, 6, 1
//Eminem, SHADYXV, Vegas, Rap, 3 : 37, 8, 3
//Adele, 25, Remedy, Pop, 4 : 11, 24, 4
//"Swift, Taylor", RED, Stay Stay Stay, Pop, 4 : 42, 5, 1
//"Brooks, Garth", FRESH HORSES, The Old Stuff, Country, 2 : 57, 11, 2
