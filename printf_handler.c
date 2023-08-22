#include "main.h"

/**
 * print_handler - this is a pointer to function
 * @sp: String
 * @indx: Integer
 * Return: Integer
 */

int (*print_handler(const char *sp, int indx))(va_list, char *, unsigned int)
{
	opt con[] = {
		{"c", char_handler},
		{"s", string_handler},
		{"d", di_handler},
		{"i", di_handler},
		{"b", binary_handler},
		{"o", octal_handler},
		{"u", unsigned_handler},
		{"x", hexadecimal_handler},
		{"X", upper_hexa_handler},
		{"S", ascii_handler},
		{"p", address_handler},
		{"%", per_handler},
		{"r", reverse_handler},
		{"R", rot13_handler},
		{NULL, NULL}};
	int m = 0, n = 0, f_indx;

	f_indx = indx;
	while (con[m].flage && sp)
	{
		if (sp[indx] == con[m].flage[n])
		{
			if (con[m].flage[n + 1] != 0)
			{
				indx++;
				n++;
			}
			else
				break;
		}
		else
		{
			n = 0;
			m++;
			indx = f_indx;
		}
	}
	return (con[m].func);
}