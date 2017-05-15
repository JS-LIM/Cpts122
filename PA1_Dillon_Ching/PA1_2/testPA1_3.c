/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program decrypts and encrypts messages with the Caesar Shift Cipher.   *
*******************************************************************************************/

#include "Driver_3.h"

void testPA1_3(void)
{
	int i = 0, shift = 4;
	char quote[] = { "The path of the righteous man is beset on all sides by the inequities of the selfish and the tyranny of evil men. Blessed is he who, in the name of charity and good will, shepherds the weak through the valley of the darkness. For he is truly his brother's keeper and the finder of lost children. And I will strike down upon thee with great vengeance and furious anger those who attempt to poison and destroy my brothers. And you will know I am the Lord when I lay my vengeance upon you." };

	printf("%s\n\n", quote);

	capitalize_quote(quote);
	shift_quote(quote, shift);
	decapitalize_quote(quote);
	printf("%s\n\n", quote);

	capitalize_quote(quote);
	shift = unshift(shift);
	shift_quote(quote, shift);
	decapitalize_quote(quote);
	printf("%s\n\n", quote);


	return 0;
}