#include "main.h"

/**
 * char_handler - this function will handle charachters for us.
 * @arge: args counter
 * @bffr: String
 * @buffer_size: unsigned int
 * Return: Always 1
 */

int char_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char val;
	val = va_arg(arge, int);
	buffer_handler(bffr, val, buffer_size);
	return (1);
}