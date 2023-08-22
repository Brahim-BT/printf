
#include "main.h"
/**
 * address_handler - this function will handle addresses for us.
 * @arge: argument de type va_list
 * @bffr: String
 * @buffer_size: int
 * Return: len of add
 */
int address_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	long int input;
	int m = 0, c, first_adrs = 0, neg = 0;
	char *hex, *bin;
	void *adrs;
	char nul_val[] = "(nil)";
	adrs = va_arg(arge, void *);
	if (adrs == 0)
	{
		for (; nul_val[m]; m++)
			buffer_size = buffer_handler(bffr, nul_val[m], buffer_size);
		return (buffer_size);
	}
	input = (intptr_t)adrs;
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = to_binary(bin, input, neg, 64);
	hex = malloc(sizeof(char) * (16 + 1));
	hex = to_hexadecimal(bin, hex, 0, 16);
	buffer_size = buffer_handler(bffr, 48, buffer_size);
	buffer_size = buffer_handler(bffr, 120, buffer_size);
	c = 2;
	for (; hex[m]; m++)
	{
		if (hex[m] != '0' && !first_adrs)
			first_adrs = 1;
		if (first_adrs == 1)
			buffer_size = buffer_handler(bffr, hex[m], buffer_size), c++;
	}
	return (c);
}