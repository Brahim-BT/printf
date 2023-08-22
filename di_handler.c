#include "main.h"

/**
 * di_handler - this function will be responsible for formatting and printing signed integer values for us.
 * @arge: argumerts for type va_list
 * @bffr: String
 * @buffer_size: unsigned int
 * Return: int
 */

int di_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	int input, i;
	char div;
	unsigned int neg, current_int, div_num = 1, integer;
	int value = va_arg(arge, int);

	neg = 0;
	input = value;
	if (input < 0)
	{
		integer = -1 * value;
		buffer_size = buffer_handler(bffr, '-', buffer_size);
		neg = 1;
	}
	else
		integer = value;
	current_int = integer;
	while (current_int > 9)
	{
		div_num *= 10;
		current_int /= 10;
	}
	for (i = 0; div_num > 0; i++)
	{
		div = ((integer / div_num) % 10) + '0';
		buffer_size = buffer_handler(bffr, div, buffer_size);
		div_num /= 10;
	}
	return (i + neg);
}