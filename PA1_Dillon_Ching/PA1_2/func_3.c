/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program decrypts and encrypts messages with the Caesar Shift Cipher.   *
*******************************************************************************************/

#include "Header_3.h"

void capitalize_quote(char quote[])
{
	int i = 0, ascii = 0;

	while (quote[i] != NULL)
	{
		ascii = (int)quote[i];
		if (ascii >= 97 && ascii <= 122)
		{
			ascii -= 32;
			quote[i] = (char)ascii;
		}
		i++;
	}
}

void shift_quote(char quote[], int shift)
{
	int i = 0, ascii = 0;

	while (quote[i] != NULL)
	{
		ascii = (int)quote[i];
		if (ascii >= 65 && ascii <= 90)
		{
			if (shift >= 0)
			{
				if ((ascii - 90) + shift > 0)
				{
					ascii = (ascii - 26) + shift;
					quote[i] = (char)ascii;
				}

				else
				{
					ascii += shift;
					quote[i] = (char)ascii;
				}
			}
			
			else
			{
				if ((ascii - 65) + shift < 0)
				{
					ascii = (ascii + 26) + shift;
					quote[i] = (char)ascii;
				}

				else
				{
					ascii += shift;
					quote[i] = (char)ascii;
				}
			}
		}
		i++;
	}
}

void decapitalize_quote(char quote[])
{
	int i = 0, ascii = 0;

	while (quote[i] != NULL)
	{
		ascii = (int)quote[i];

		if (ascii >= 65 && ascii <= 90)
		{
			if (quote[i - 2] != 46)
			{
				ascii += 32;
				quote[i] = (char)ascii;
			}
		}

		i++;
	}

	ascii = (int)quote[0];
	ascii -= 32;
	quote[0] = (char)ascii;
}

int unshift(int shift)
{
	shift *= -1;

	return shift;
}