#include "main.h"
/**
 * octal_handler - thsi function will convert integers values to octals for us.
 * @arge: arguments
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */
int octal_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char *bin_handler;
	int input = va_arg(arge, int);
	int first_octal = 0, m = 0, c = 0;
	unsigned int neg = 0;
	char *oct_handler;
	if (input < 0)
	{
		input = (-1 * input) - 1;
		neg = 1;
	}
	if (input == 0)
	{
		buffer_size = buffer_handler(bffr, '0', buffer_size);
		return (1);
	}
	bin_handler = malloc(sizeof(char) * (32 + 1));
	bin_handler = to_binary(bin_handler, input, neg, 32);
	oct_handler = malloc(sizeof(char) * (11 + 1));
	oct_handler = to_octal(oct_handler, bin_handler);
	for (; oct_handler[m]; m++)
	{
		if (first_octal == 0 && oct_handler[m] != 48)
			first_octal = 1;
		if (first_octal == 1)
		{
			buffer_size = buffer_handler(bffr, *(oct_handler + m), buffer_size);
			c++;
		}
	}
	free(oct_handler);
	return (c);
}