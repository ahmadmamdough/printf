#include "main.h"
/**
 * print_d - entry
 * @args: the arg list
 * Return: the printed chars
 */
int print_d(va_list args)
{
	int val = va_arg(args, unsigned int), printed = 0;
	char *str;

	if (val < 0)
	{
		putchar('-');
		printed++;
		val *= -1;
	}
	str = itoa(val, 10);

	while (*str)
	{
		putchar(*str);
		printed++;
		str++;
	}
	return (printed);
}
