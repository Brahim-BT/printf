#include "main.h"
/**
 * rot13_handler - function for rot13 string
 * @arge: type for va_list
 * @bffr: String
 * @buffer_size: Integer positive
 * Return: Integer
 */



int rot13_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	char *value;
	unsigned int i = 0, j = 0, k = 0;
	char null_value[] = "(null)";
	char tab1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char tab2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	value = va_arg(arge, char *);
	if (value == 0)
{
		for (i = 0; null_value[i]; i++)
		{
			buffer_size = buffer_handler(bffr, null_value[i], buffer_size);
		}


		return (6);

}
	for (i = 0; *(value + i); i++)
{
		for (k = j = 0; tab1[j] != 0; j++)
		{
			if (*(value + i) == tab1[j])
			{
				k = 1;
				buffer_size = buffer_handler(bffr, tab2[j], buffer_size);
				break;
			}
		}
		if (k == 0)
			 buffer_size = buffer_handler(bffr, *(value + i), buffer_size);
}


	return (i);
}

