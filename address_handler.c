
#include "main.h"
/**
 * address_handler - handle address
 * @arge: argument de type va_list
 * @bffr: String
 * @buffer_size: INteger
 * Return: len of add
 */
int address_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	long int input;
	int i = 0, c, first_adrs = 0, neg = 0;
	char *hexa, *binary;
	void *adrs;
	char null_value[] = "(nil)";
	adrs = va_arg(arge, void *);
	if (adrs == 0)
	{
		for (; null_value[i]; i++)
			buffer_size = buffer_handler(bffr, null_value[i], buffer_size);
		return (buffer_size);
	}
	input = (intptr_t)adrs;
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = to_binary(binary, input, neg, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = to_hexadecimal(binary, hexa, 0, 16);
	buffer_size = buffer_handler(bffr, 48, buffer_size);
	buffer_size = buffer_handler(bffr, 120, buffer_size);
	c = 2;
	for (; hexa[i]; i++)
	{
		if (hexa[i] != '0' && !first_adrs)
			first_adrs = 1;
		if (first_adrs == 1)
			buffer_size = buffer_handler(bffr, hexa[i], buffer_size), c++;
	}
	return (c);
}