#include "main.h"
/**
 * ascii_handler - this function will onvert value ascii < 32 or > 127 to hexadecimal for us.
 * @arge: the arguments to be given to the fucntion
 * @bffr: String
 * @buffer_size: int
 * Return: int
 */
int ascii_handler(va_list arge, char *bffr, unsigned int buffer_size)
{
	unsigned int i = 0, con, sum = 0;
	char *hex_d, *bin_buf;
	unsigned char *input = va_arg(arge, unsigned char *);

	bin_buf = malloc(sizeof(char) * (32 + 1));
	hex_d = malloc(sizeof(char) * (8 + 1));

	for (; input[i]; i++)
	{
		if (input[i] < 32 || input[i] >= 127)
		{
			buffer_size = buffer_handler(bffr, '\\', buffer_size);
			buffer_size = buffer_handler(bffr, 'x', buffer_size);
			con = input[i];
			bin_buf = to_binary(bin_buf, con, 0, 32);
			hex_d = to_hexadecimal(bin_buf, hex_d, 1, 8);

			buffer_size = buffer_handler(bffr, hex_d[6], buffer_size);
			buffer_size = buffer_handler(bffr, hex_d[7], buffer_size);
			sum += 3;
		}
		else
			buffer_size = buffer_handler(bffr, input[i], buffer_size);
	}
	free(hex_d);
	return (i + sum);
}
