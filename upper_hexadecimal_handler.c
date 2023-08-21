#include "main.h"

/**
 * upper_hexa_handler - this function will convert an int into its corresponding uppercase hexadecimal representation and add it to a buffer for us.
 * @arge: arguments
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */

int upper_hexa_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	unsigned int neg = 0;
	int input = va_arg(arge, int);
	char *hex_d, *bin_bfr;
	int frst_hex_dcml = 0, m = 0, c = 0;

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
	bin_bfr = malloc(sizeof(char) * (32 + 1));
	bin_bfr = to_binary(bin_bfr, input, neg, 32);
	hex_d = malloc(sizeof(char) * (8 + 1));
	hex_d = to_hexadecimal(bin_bfr, hex_d, 1, 8);
	for (; hex_d[m]; m++)
	{
		if (frst_hex_dcml == 0 && hex_d[m] != 48)
			frst_hex_dcml = 1;
		if (frst_hex_dcml)
		{
			buffer_size = buffer_handler(bffr, hex_d[m], buffer_size);
			c++;
		}
	}
	free(hex_d);
	return (c);
}