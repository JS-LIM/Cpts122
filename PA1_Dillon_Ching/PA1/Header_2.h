/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program recursively finds a path through a maze.                       *
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_maze(char maze[8][8]);
void generate_maze(char maze[8][8]);
void place_maze_runner(char maze[8][8]);
void place_maze_runner2(char maze[8][8]);
int move_maze_runner(char maze[8][8]);
int recur_maze_runner(char maze[8][8]);
