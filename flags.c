#include "main.h"
/**
 * flags - this function will be for flags
 * @s: String
 * @indx: int
 * Return: int
 */
int flags(const char *s, int indx)
{
	opt pr[] = {
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
	int m = 0, c = 0, f_indx;
	f_indx = indx;
	for (; pr[m].flage;)
	{
		if (s[indx] == pr[m].flage[c])
		{
			if (pr[m].flage[c + 1] != '\0')
			{
				indx++;
				c++;
			}
			else
				break;
		}
		else
		{
			c = 0;
			m++;
			indx = f_indx;
		}
	}
	return (c);
}