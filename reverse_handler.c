#include "main.h"

/**
 * reverse_handler - this function will reverse a string for us.
 * @arge: type for va_list
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */

int reverse_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char nul_val[] = "(null)";
	char *val;
	int n = 0;
	unsigned int m = 0;

	val = va_arg(arge, char *);
	if (val == 0)
	{
		for (m = 0; nul_val[m]; m++)
		{
			buffer_size = buffer_handler(bffr, nul_val[m], buffer_size);
		}
		return (6);
	}
	for (m = 0; *(val + m); m++)
		;
	n = m - 1;
	for (; n >= 0; n--)
	{
		buffer_size = buffer_handler(bffr, val[n], buffer_size);
	}
	return (m);
}