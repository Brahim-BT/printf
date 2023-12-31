#include "main.h"
/**
 * hexadecimal_handler - this funciton will convert integers to hexadecimals for us.
 * @arge: arguments
 * @buffer: String
 * @buffer_size: int
 * Return: int
 */
int hexadecimal_handler(va_list arge, char *buffer, unsigned int buffer_size)
{
	int input = va_arg(arge, int);
	int first_hex_d = 0, m = 0, c = 0;
	unsigned int neg = 0;
	char *hex_d, *bin_buf;

	if (input == 0)
	{
		buffer_size = buffer_handler(buffer, '0', buffer_size);
		return (1);
	}
	if (input < 0)
	{
		input = (-1 * input) - 1;
		neg = 1;
	}
	bin_buf = malloc(sizeof(char) * (32 + 1));
	bin_buf = to_binary(bin_buf, input, neg, 32);
	hex_d = malloc(sizeof(char) * (8 + 1));
	hex_d = to_hexadecimal(bin_buf, hex_d, 0, 8);
	for (; hex_d[m]; m++)
	{
		if (first_hex_d == 0 && hex_d[m] != 48)
			first_hex_d = 1;
		if (first_hex_d)
		{
			buffer_size = buffer_handler(buffer, hex_d[m], buffer_size);
			c++;
		}
	}
	free(hex_d);
	return (c);
}