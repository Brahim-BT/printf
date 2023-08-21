#include "main.h"

/**
 * unsigned_handler - this function will takes an unsigned integer and converts it to its decimal representation for us.
 * @arge: argumerts for type va_list
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */

int unsigned_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	int m;
	char div;
	unsigned int current_int, div_n = 1, integer;
	unsigned int value = va_arg(arge, unsigned int);
	integer = value;
	current_int = integer;
	for (; current_int > 9; div_n *= 10, current_int /= 10)
	{
		div_n *= 10;
		current_int /= 10;
	}
	for (m = 0; div_n > 0; m++)
	{
		div = ((integer / div_n) % 10) + '0';
		buffer_size = buffer_handler(bffr, div, buffer_size);
		div_n /= 10;
	}
	return (m);
}