#include "main.h"

/**
 * _printf - this function will print anything for us.
 * @frmt: String
 * Return: int
 */

int _printf(const char *frmt, ...)
{
	va_list arg;
	int (*handler)(va_list, char *, unsigned int);
	char *bfr;
	unsigned int m = 0, l = 0, bfr_sz = 0;

	va_start(arg, frmt), bfr = malloc(sizeof(char) * 1024);
	if (!frmt || !bfr || (frmt[m] == '%' && !frmt[m + 1]))
		return (-1);
	if (!frmt[m])
		return (0);
	for (m = 0; frmt && frmt[m]; m++)
	{
		if (frmt[m] == '%')
		{
			if (frmt[m + 1] == '\0')
			{
				_putchar(bfr, bfr_sz), free(bfr), va_end(arg);
				return (-1);
			}
			else
			{
				handler = print_handler(frmt, m + 1);
				if (handler == NULL)
				{
					if (frmt[m + 1] == ' ' && !frmt[m + 2])
						return (-1);
					buffer_handler(bfr, frmt[m], bfr_sz), l++, m--;
				}
				else
					l += handler(arg, bfr, bfr_sz), m += flags(frmt, m + 1);
			}
			m++;
		}
		else
			buffer_handler(bfr, frmt[m], bfr_sz), l++;
		for (bfr_sz = l; bfr_sz > 1024; bfr_sz -= 1024)
			;
	}
	_putchar(bfr, bfr_sz), free(bfr), va_end(arg);
	return (l);
}