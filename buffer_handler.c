#include "main.h"


/**
 * buffer_handler - this function will concatinating for us
 * @bffr: String
 * @ch: char
 * @buffer_size: unsigned int
 * Return: unsigned int
 */
 
 
unsigned int buffer_handler(char *bffr, char ch, unsigned int buffer_size)
{
	if (buffer_size == 1024)
	{
		_putchar(bffr, buffer_size);
		buffer_size = 0;
	}
	bffr[buffer_size] = ch;
	buffer_size++;
	return (buffer_size);
}

