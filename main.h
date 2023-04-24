#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/**
 * struct fmt - A format struct
 * @spec: the character that is the conversion specifier
 * @fnc: the function that handles the conversion
 *
 * Description: A struct that maps a conversion specifier to the function that
 * handles that conversion
 */
typedef struct fmt
{
	char spec;
	int (*fnc)(va_list, char[]);
} fmt_t;

int _printf(const char *format, ...);

int print_char(va_list args, char buffer[]);
int print_str(va_list args, char buffer[]);
int print_percent(va_list args, char buffer[]);
int print_int (va_list args, char buffer[]);

#endif /* MAIN_H */
