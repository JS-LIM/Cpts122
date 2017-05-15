/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program recursively finds a path through a maze.                       *
*******************************************************************************************/

#include "Header_2.h"

void print_maze(char maze[8][8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("[%c] ", maze[i][j]);
		}
		printf("\n\n");
	}
}

void generate_maze(char maze[8][8])
{
	int i, j, rnum;

	srand(time(NULL));
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			rnum = (rand() % 3);
			if (rnum == 0)
				maze[i][j] = 'X';
			
			else
				maze[i][j] = ' ';
		}
	}
}

void place_maze_runner(char maze[8][8])
{
	maze[0][1] = '~';
}

void place_maze_runner2(char maze[8][8])
{
	maze[7][7] = '-';
}

int move_maze_runner(char maze[8][8])
{
	int i, j, a = 10, b = 10;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (maze[i][j] == '~')
			{
				a = i;
				b = j;
			}
		}
	}

	if (a == 10 && b == 10)
		return 1;

	else if (maze[a + 1][b] == '-' && a != 7)
		return 2;

	else if (maze[a][b + 1] == '-' && b != 7)
		return 2;

	else if (maze[a - 1][b] == '-' && a != 0)
		return 2;

	else if (maze[a][b - 1] == '-' && b != 0)
		return 2;

	if (maze[a][b + 1] == ' ')
	{
		if (b != 7)
		{
			maze[a][b + 1] = '~';
		}
	}

	if (maze[a + 1][b] == ' ')
	{
		if (a != 7)
		{
			maze[a + 1][b] = '~';
		}
	}

	if (maze[a - 1][b] == ' ')
	{
		if (a != 0)
		{
			maze[a - 1][b] = '~';
		}
	}

	if (maze[a][b - 1] == ' ')
	{
		if (b != 0)
		{
			maze[a][b - 1] = '~';
		}
	}

	
	maze[a][b] = 'O';

	return 0;
}

int recur_maze_runner(char maze[8][8])
{
	int end_program = 0, maze_runner = 0;

	maze_runner = move_maze_runner(maze);
	if (maze_runner == 1)
		end_program = 1;
	else if (maze_runner)
		end_program = 2;

	if (end_program == 1)
		return 1;

	if (end_program == 2)
		return 2;

	else
		recur_maze_runner(maze);
}