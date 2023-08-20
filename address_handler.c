
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
	void *address;
	int i = 0, counter, first_address = 0, negative = 0;
	long int input;
	char *hexa, *binary;
	char null_value[] = "(nil)";
	address = va_arg(arge, void *);
	if (address == 0)
	{
		while (null_value[i])
			buffer_size = buffer_handler(bffr, null_value[i], buffer_size), i++;
		return (buffer_size);
	}
	input = (intptr_t)address;
	if (input < 0)
	{
		input = (input * -1) - 1;
		negative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = to_binary(binary, input, negative, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = to_hexadecimal(binary, hexa, 0, 16);
	buffer_size = buffer_handler(bffr, 48, buffer_size);
	buffer_size = buffer_handler(bffr, 120, buffer_size);
	counter = 2;
	while (hexa[i])
	{
		if (hexa[i] != '0' && !first_address)
			first_address = 1;
		if (first_address == 1)
			buffer_size = buffer_handler(bffr, hexa[i], buffer_size), counter++;
		i++;
	}

	return (counter);

}

