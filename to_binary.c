#include "main.h"

/**
 * to_binary - this function will convert a given decimal integer to its binary representation for us.
 * @binary_handler: table
 * @inpt: int input
 * @negative: checks if input is negative or not
 * @laste: presents the limit (32 for int)
 * Return: binary_handler
 */

char *to_binary(char *binary_handler, long int inpt, int negative, int laste)
{
	int m = 0;

	for (; m < laste; m++)
	{
		binary_handler[m] = '0';
	}
	binary_handler[laste] = 0;
	for (m = laste - 1; inpt > 1; m--)
	{
		if (inpt == 2)
			binary_handler[m] = '0';
		else
			binary_handler[m] = (inpt % 2) + 48;
		inpt = inpt / 2;
	}
	if (inpt != 0)
		binary_handler[m] = 49;
	if (negative)
	{
		for (m = 0; *(binary_handler + m); m++)
			if (*(binary_handler + m) == 49)
				binary_handler[m] = 48;
			else
				*(binary_handler + m) = 49;
	}
	return (binary_handler);
}