#include "main.h"

/**
 * binary_handler - this function will convert integer to binary for us.
 * @arge: arguments
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */

int binary_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	int input = va_arg(arge, int);
	int first_bit = 0, m = 0, c = 0;
	unsigned int neg = 0;
	char *bin_handler;

	if (input == 0)
	{
		buffer_size = buffer_handler(bffr, '0', buffer_size);
		return (1);
	}
	if (input < 0)
	{
		input = (-1 * input) - 1;
		neg = 1;
	}

	bin_handler = malloc(sizeof(char) * (32 + 1));
	bin_handler = to_binary(bin_handler, input, neg, 32);

	for (; bin_handler[m]; m++)
	{
		if (first_bit == 0 && bin_handler[m] == '1')
			first_bit = 1;
		if (first_bit == 1)
		{
			buffer_size = buffer_handler(bffr, *(bin_handler + m), buffer_size);
			c++;
		}
	}
	free(bin_handler);
	return (c);
}