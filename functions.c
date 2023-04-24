#include "main.h"

/**
 * print_char - writes a character to stdout
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: 1 on succes, -1 on error
 */
int print_char(va_list args, char buffer[])
{
	char c = (char)va_arg(args, int);

	UNUSED(buffer);

	return (write(1, &c, 1));
}

/**
 * print_str - writes a string to stdout
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: the numbers of characters written
 */
int print_str(va_list args, char buffer[])
{
	int i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		;

	return (write(1, str, i));
}

/**
 * print_percent - writes a percent sign to stdout
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: 1 on success, -1 on error
 */
int print_percent(va_list args, char buffer[])
{
	UNUSED(args); /* declared argument */
	UNUSED(buffer);

	return (write(1, "%%", 1));
}
