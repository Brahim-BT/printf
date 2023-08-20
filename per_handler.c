#include "main.h"
/**
 * per_handler - Function for character %
 * @ar: arguments
 * @b: String
 * @bs: Integer
 * Return: Always 1
 */



int per_handler(va_list ar __attribute__((unused)), char *b, unsigned int bs)
{
	buffer_handler(b, '%', bs);


	return (1);
}

