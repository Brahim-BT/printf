#include "main.h"

/**
 * to_hexadecimal - this function will converts the binary representation into a hexadecimal representation for us.
 * @binary_buffer: table of binary_buffer
 * @hex: octal table
 * @s: int
 * @l: int
 * Return: hexadecimal_handler
 */

char *to_hexadecimal(char *binary_buffer, char *hexa, int s, int l)
{
	int m, n, lst, op;

	hexa[l] = '\0';
	if (s)
		lst = 55;
	else
		lst = 87;
	for (m = (l * 4) - 1; m >= 0; m--)
	{
		for (op = 0, n = 1; n <= 8; n *= 2, m--)
			op = ((*(binary_buffer + m) - '0') * n) + op;
		m++;
		if (op < 10)
			hexa[m / 4] = op + 48;
		else
			hexa[m / 4] = op + lst;
	}
	return (hexa);
}