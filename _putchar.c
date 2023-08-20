#include "main.h"

/**
 *_putchar - Function printing character
 *@buffersiz: String
 *@buffer: String
 *Return: Integer
 */

int _putchar(char *buffer, int buffersiz)
{
	return (write(1, buffer, buffersiz));
}


