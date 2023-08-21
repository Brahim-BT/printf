#include "main.h"
/**
 * string_handler - this function will be responsible for formatting and printing strings for us.
 * @arge: type for va_list
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */
int string_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char *val;
	unsigned int m = 0;
	char nul_val[] = "(null)";

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
	{
		buffer_size = buffer_handler(bffr, val[m], buffer_size);
	}
	return (m);
}