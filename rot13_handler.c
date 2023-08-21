#include "main.h"
/**
 * rot13_handler - this function will apply ROT13 encryption to the input string and adds the encrypted characters to the buffer.
 * @arge: type for va_list
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */

int rot13_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	unsigned int m = 0, n = 0, o = 0;
	char alph_1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char alph_2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char nul_val[] = "(null)";
	char *val;

	val = va_arg(arge, char *);
	if (val == 0)
	{
		for (m = 0; nul_val[m]; m++)
		{
			buffer_size = buffer_handler(bffr, nul_val[m], buffer_size);
		}
		return (6);
	}
	for (m = 0; *(val + m); m++)
	{
		for (o = n = 0; alph_1[n] != 0; n++)
		{
			if (*(val + m) == alph_1[n])
			{
				o = 1;
				buffer_size = buffer_handler(bffr, alph_2[n], buffer_size);
				break;
			}
		}
		if (o == 0)
			buffer_size = buffer_handler(bffr, *(val + m), buffer_size);
	}
	return (m);
}