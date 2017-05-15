#include "Header.h"

void find_max(int *max_size, char str[20])
{
	int i = 0;

	for (i = 0; i < 20; i++)
	{
		if (str[i] == NULL)
		{
			*max_size = i;
		}
	}

	*max_size--;
}

void reverse_string(char str[20], char rstr[20], int max_size, int count)
{
	if (count < max_size)
	{
		rstr[(max_size - 1) - count] = str[count];
		reverse_string(str, rstr, max_size, count + 1);
	}
}

void print_rstring(char rstr[20], int max_size)
{
	int i = 0;

	printf("rstr: ");
	for (i = 0; i < (max_size); i++)
	{
	printf("%c", rstr[i]);
	}
	printf("\n");
}