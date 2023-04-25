#include "main.h"

/**
 * print_unsigned - writes an unsigned integer to stdout
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: the number of characters printed
 */
int print_unsigned(va_list args, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	int i = BUFFER_SIZE - 2;

	buffer[BUFFER_SIZE - 1] = '\0';

	if (num == 0)
		buffer[i--] = '0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}

/**
 * print_octal - writes an unsigned int to stdout in octal
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: the number of characters printed
 */
int print_octal(va_list args, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	int i = BUFFER_SIZE - 2;

	buffer[BUFFER_SIZE - 1] = '\0';

	if (num == 0)
		buffer[i--] = '0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	i++;
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}

/**
 * print_hex_lower - writes an unsigned int to stdout in lowercase hexadecimal
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: the number of characters printed
 */
int print_hex_lower(va_list args, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char char_set[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f'};

	return (print_hex(num, buffer, char_set));
}

/**
 * print_hex_upper - writes an unsigned int to stdout in uppercase hexadecimal
 * @args: the argument list
 * @buffer: the buffer that holds what to print
 *
 * Return: the number of characters printed
 */
int print_hex_upper(va_list args, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char char_set[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F'};

	return (print_hex(num, buffer, char_set));
}

/**
 * print_hex - writes an unsigned int to stdout in hexadecimal
 * @num: the integer to print
 * @buffer: the buffer that holds what to print
 * @char_set: the character set for hexadecimal digits
 *
 * Return: the number of characters printed
 */
int print_hex(unsigned int num, char buffer[], char char_set[])
{
	int i = BUFFER_SIZE - 2;

	buffer[BUFFER_SIZE - 1] = '\0';

	if (num == 0)
		buffer[i--] = '0';

	while (num > 0)
	{
		buffer[i--] = char_set[num % 16];
		num /= 16;
	}

	i++;
	return (write(1, &buffer[i], BUFFER_SIZE - i - 1));
}
