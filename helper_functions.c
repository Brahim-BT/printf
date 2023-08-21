#include "main.h"
/**
 * char_len - this function will calculate chars lenght for us.
 * @c: character or string
 * Return: lenght of string
 */
int char_len(char *c)
{
	int i = 0;

	while (c[i])
		i++;
	return (i);
}
