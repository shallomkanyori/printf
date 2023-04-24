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

/**
 * print_int - writes an integer to stdout
 * @args: The argument list
 * @buffer: The buffer that holds what to print
 *
 * Return: The number of characters written.
 */
int print_int(va_list args, char buffer[])
{
	int n = va_args(args, int);
	unsigned int num;
	int is_negative = 0;
	int i = BUFFER_SIZE - 2;

	buffer[BUFFER_SIZE - 1] = '\0';
	
	if (n < 0)
	{
		is_negative = 1;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}
	if (n == 0)
		buffer[i--] = '0';
	
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	if (is_negative)
		buffer[i] = '-';
	else
		i++
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
