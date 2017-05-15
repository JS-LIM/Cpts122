/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA1 Task1                                                        *
* Date: 9/4/16                                                                             *
* Description: This program decrypts and encrypts messages with the Caesar Shift Cipher.   *
*******************************************************************************************/

#include <stdio.h>

void capitalize_quote(char quote[]);
void shift_quote(char quote[], int shift);
void decapitalize_quote(char quote[]);
int unshift(int shift);