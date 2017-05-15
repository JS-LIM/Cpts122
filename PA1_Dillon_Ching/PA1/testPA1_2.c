/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program recursively finds a path through a maze.                       *
*******************************************************************************************/

#include "Driver_2.h"

void testPA1_2(void)
{
	char maze[8][8] = { "" };
	int end_program;

	generate_maze(maze);
	place_maze_runner(maze);
	place_maze_runner2(maze);
	print_maze(maze);

	end_program = recur_maze_runner(maze);
	if (end_program == 1)
	{
		printf("No possible route\n\n");
		print_maze(maze);
		return 0;
	}

	if (end_program == 2)
	{
		printf("Possible route exists!\n\n");
		print_maze(maze);
	}

	return 0;
}