#include "main.h"


/**
 * buffer_handler - concatinating function
 * @bffr: String
 * @ch: char
 * @buffer_size: unsigned Intger
 * Return: unsigned Intger
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

