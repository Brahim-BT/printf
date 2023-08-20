#include "main.h"
/**
 * print_handler - pointer to function
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
                {NULL, NULL}
};
	int i = 0, j = 0, f_indx;

	f_indx = indx;
	while (con[i].flage && sp)
	{
		if (sp[indx] == con[i].flage[j])
		{
			if (con[i].flage[j + 1] != 0)
			{
				indx++;
				j++;
			}
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			indx = f_indx;
		}
	}
	return (con[i].func);
}

