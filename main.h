#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



/**
 * struct option - building a stucture for Option.
 * @flage: String.
 * @func: a pointrt to a function.
 * Description: Define a new type struct opt whit flage and func.
 */

 
 
typedef struct option
{
    char *flage;
	int (*func)(va_list, char *, unsigned int);
} opt;
/*functions_Prototypes */
int (*print_handler(const char *sp, int idx))(va_list, char *, unsigned int);
int _printf(const char *format, ...);
int char_handler(va_list arg, char *buffer, unsigned int buffer_size);
int di_handler(va_list arg, char *buffer, unsigned int buffer_size);
int string_handler(va_list arg, char *buffer, unsigned int buffer_size);
int per_handler(va_list ar __attribute__((unused)), char *b, unsigned int bus);
int binary_handler(va_list arg, char *buffer, unsigned int buffer_size);
char *to_binary(char *binary_handler, long int input, int negative, int last);
int octal_handler(va_list arg, char *buffer, unsigned int buffer_size);
char *to_octal(char *octal_handler, char *binary_handler);
int hexadecimal_handler(va_list arg, char *buffer, unsigned int buffer_size);
char *to_hexadecimal(char *hex, char *bin, int s, int l);
int upper_hexa_handler(va_list arg, char *buffer, unsigned int buffer_size);
int unsigned_handler(va_list arg, char *buffer, unsigned int buffer_size);
int ascii_handler(va_list arg, char *buffer, unsigned int buffer_size);
int address_handler(va_list arg, char *buffer, unsigned int buffer_size);
int reverse_handler(va_list arg, char *buffer, unsigned int buffer_size);
int rot13_handler(va_list arg, char *buffer, unsigned int buffer_size);
/*buffer_handlers*/
unsigned int buffer_handler(char *buffer, char ch, unsigned int buffer_size);
int _putchar(char *buffer, int buffersize);
int flags(const char *s, int idx);
/*helper functions prototypes */
int char_len(char *c);
#endif


