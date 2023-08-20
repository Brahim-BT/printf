#include "main.h"


/**
 * _printf - function for printing
 * @frmt: String
 * Return: Integer
 */



int _printf(const char *frmt, ...)
{
	unsigned int i = 0, len = 0, buffer_size = 0;
	va_list arg;
	int (*handler)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arg, frmt), buffer = malloc(sizeof(char) * 1024);
	if (!frmt || !buffer || (frmt[i] == '%' && !frmt[i + 1]))
		return (-1);
	if (!frmt[i])
		return (0);
	for (i = 0; frmt && frmt[i]; i++)
	{
		if (frmt[i] == '%')
		{
			if (frmt[i + 1] == '\0')
			{
				_putchar(buffer, buffer_size), free(buffer), va_end(arg);
				return (-1);
			}
			else
			{	handler = print_handler(frmt, i + 1);
				if (handler == NULL)
				{
					if (frmt[i + 1] == ' ' && !frmt[i + 2])
						return (-1);
					buffer_handler(buffer, frmt[i], buffer_size), len++, i--;
				}
				else
					len += handler(arg, buffer, buffer_size), i += flags(frmt, i + 1);
			} i++;
		}
		else
			buffer_handler(buffer, frmt[i], buffer_size), len++;
		for (buffer_size = len; buffer_size > 1024; buffer_size -= 1024)
			;
	}
	_putchar(buffer, buffer_size), free(buffer), va_end(arg);
	return (len);
}

