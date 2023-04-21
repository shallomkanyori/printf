#include "main.h"

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
	int chars_written = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			print_char(format[i]);
			chars_written++;
			continue;
		}

		i++;
		switch (format[i])
		{
		case 'c':
			print_char((char) va_arg(args, int));
			chars_written++;
			break;
		case 's':
			chars_written += print_str(va_arg(args, char *));
			break;
		case '%':
			print_char('%');
			chars_written++;
			break;
		default:
			print_char('%');
			print_char(format[i]);
			chars_written += 2;
			break;
		}
	}

	return (chars_written);
}
