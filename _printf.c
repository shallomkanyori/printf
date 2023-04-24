#include "main.h"
#include <stdlib.h>

void print_buffer(char buffer[], int *buffer_ind);
int _print(const char *format, int *i, va_list args, char buffer[]);

/**
 * _printf - produces output according to format
 * @format: the format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int printed;
	int b_ind = 0;
	int chars_written = 0;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[b_ind++] = format[i];

			if (b_ind == BUFFER_SIZE)
				print_buffer(buffer, &b_ind);

			chars_written++;
			continue;
		}

		print_buffer(buffer, &b_ind);

		i++;
		printed = _print(format, &i, args, buffer);

		if (printed == -1)
			return (-1);

		chars_written += printed;
	}

	print_buffer(buffer, &b_ind);
	va_end(args);

	return (chars_written);
}

/**
 * print_buffer - prints a buffer
 * @buffer: the buffer
 * @b_ind: a pointer to the index after the last added character
 *
 * Return: Nothing.
 */
void print_buffer(char buffer[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, buffer, *b_ind);

	*b_ind = 0;
}

/**
 * _print - prints formatted output
 * @format: the format string
 * @i: the current index of the format string
 * @args: the argument list
 * @buffer: the local buffer that holds what to print
 *
 * Return: The number of characters printed.
 */
int _print(const char *format, int *i, va_list args, char buffer[])
{
	int ind;
	int chars_written = -1;
	fmt_t formatters[] = {{'c', print_char}, {'s', print_str},
		{'%', print_percent}, {'d', print_int}, {'i', print_int},
		{'\0', NULL}};

	for (ind = 0; formatters[ind].spec; ind++)
		if (formatters[ind].spec == format[*i])
			return (formatters[ind].fnc(args, buffer));

	if (formatters[ind].spec == '\0')
	{
		if (format[*i] == '\0')
			return (-1);

		if (write(1, "%%", 1) == -1)
			return (-1);

		if (write(1, &format[*i], 1) == -1)
			return (-1);

		return (2);
	}

	return (chars_written);
}
