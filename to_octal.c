#include "main.h"

/**
 * to_octal - this function will convert the binary form of to its octal representation.
 * @binary_handler: table
 * @octal_handler: octal table
 * Return: octal_handler
 */

char *to_octal(char *octal_handler, char *binary_handler)
{
	int m = 0, oct_sz, oct, n, last;
	octal_handler[11] = 0;
	for (m = 31, oct_sz = 10; m >= 0; m--, oct_sz--)
	{
		if (m > 1)
			last = 4;
		else
			last = 2;
		for (oct = 0, n = 1; n <= last; n *= 2, m--)
			oct = ((*(binary_handler + m) - 48) * n) + oct;
		m++;
		octal_handler[oct_sz] = oct + '0';
	}
	return (octal_handler);
}