#include "main.h"
/**
* to_binary - fill table with binary chars
* @binary_handler: table
* @inpt: integer input
* @negative: check if input negative
* @laste: presents the limit (32 for integrs)
* Return: binary_handler
*/



char *to_binary(char *binary_handler, long int inpt, int negative, int laste)
{
	int i = 0;

	while (i < laste)
	{
		binary_handler[i] = '0';
		i++;
	}

	binary_handler[laste] = 0;

	for (i = laste - 1; inpt > 1; i--)
	{
		if (inpt == 2)
			binary_handler[i] = '0';
		else
			binary_handler[i] = (inpt % 2) + 48;
		inpt = inpt / 2;
	}
	if (inpt != 0)
		binary_handler[i] = 49;
	if (negative)
	{
		for (i = 0; *(binary_handler + i); i++)
			if (*(binary_handler + i) == 49)
				binary_handler[i] = 48;
			else
				*(binary_handler + i) = 49;
	}


return (binary_handler);
}

