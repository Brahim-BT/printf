#include "main.h"
/**
 * per_handler - this function is maid for the character %.
 * @ar: arguments
 * @b: String
 * @bs: int
 * Return: Always 1
 */



int per_handler(va_list ar __attribute__((unused)), char *b, unsigned int bs)
{
	buffer_handler(b, '%', bs);
	return (1);
}