#include "main.h"


/**
 * upper_hexa_handler - Convert upper INteger to hexadecimal
 * @arge: arguments
 * @bffr: String
 * @buffer_size: Intger
 * Return: Intger
 */



int upper_hexa_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	int input = va_arg(arge, int);
	int first_hexa_dadecimal = 0, i = 0, cntr = 0;
	unsigned int negative = 0;
	char *hexa_d, *binary_buffer;

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
	binary_buffer = malloc(sizeof(char) * (32 + 1));
	binary_buffer = to_binary(binary_buffer, input, negative, 32);
	hexa_d = malloc(sizeof(char) * (8 + 1));
	hexa_d = to_hexadecimal(binary_buffer, hexa_d, 1, 8);
	while (hexa_d[i])
	{
		if (first_hexa_dadecimal == 0 && hexa_d[i] != 48)
			first_hexa_dadecimal = 1;
		if (first_hexa_dadecimal)
		{
			buffer_size = buffer_handler(bffr, hexa_d[i], buffer_size);
			cntr++;
		}
		i++;
	}

	free(hexa_d);

return (cntr);

}

