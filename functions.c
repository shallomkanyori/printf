#include "main.h"

/**
 * print_char - writes a character to stdout
 * @c: the character to print
 *
 * Return: 1 on succes, -1 on error
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - writes a string to stdout
 * @str: the string to print
 *
 * Return: the numbers of characters written
 */
int print_str(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		print_char(str[i]);

	return (i);
}
