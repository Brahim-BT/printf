#include "main.h"




/**
 * binary_handler - Convert INteger to binary
 * @arge: arguments
 * @bffr: String
 * @buffer_size: Intger
 * Return: Intger
 */
 
 
 
int binary_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	int input = va_arg(arge, int);
	int first_bit = 0, i = 0, counter = 0;
	unsigned int negative = 0;
	char *binary_handler;

	if (input == 0)
	{
		buffer_size = buffer_handler(bffr, '0', buffer_size);
		return (1);
	}
	if (input < 0)
	{
		input = (-1 * input) - 1;
		negative = 1;
	}

	binary_handler = malloc(sizeof(char) * (32 + 1));
	binary_handler = to_binary(binary_handler, input, negative, 32);

	while (binary_handler[i])
	{
		if (first_bit == 0 && binary_handler[i] == '1')
			first_bit = 1;
		if (first_bit == 1)
		{
			buffer_size = buffer_handler(bffr, *(binary_handler + i), buffer_size);
			counter++;
		}
		i++;
	}
	free(binary_handler);
	return (counter);
}

