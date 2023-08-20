#include "main.h"
/**
 * char_handler - handle charachters
 * @arge: args counter
 * @bffr: String
 * @buffer_size: unsigned integer
 * Return: Always 1
 */
int char_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char value;
	value = va_arg(arge, int);
	buffer_handler(bffr, value, buffer_size);


	return (1);
}

