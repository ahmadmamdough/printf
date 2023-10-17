#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - entry point
 * @format: the format string
 * Return: no. of printed chars
 */
int _printf(char *format, ...)
{
	char *i = format;
	va_list args;
	int n = 0;

	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);

	va_start(args, format);

	while (*i != '\0')
	{
		i += ps(i);

		if (*i == '%')
		{
			n -= 2;
			n += get_op(args, *(++i));
			i++;
		}
	}

	va_end(args);

	return (n + i - format);
}

/**
 * ps - prints until it meets % or NULL
 * @s: the string to print
 * Return: number of printed items
 */

int ps(char *s)
{
	int i = 0;

	while (*s != '\0' && *s != '%')
	{
		putchar(*s);
		s++, i++;
	}
	return (i);
}

/**
 * pt_s - prints the whole string
 * @s: the string to print
 * Return: no. of printed items
 */
int pt_s(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		putchar(*s);
		n++;
		s++;
	}
	return (n);
}
/**
 * get_op - calls function
 * @args: the args list
 * @c: the place holder
 * Return: the printed items
 */
int get_op(va_list args, char c)
{
	int i = 0;
	char *s;

	if (c == 's')
	{
		s = va_arg(args, char *);
		i = pt_s(s);
		return (i);
	}
	else if (c == 'c')
	{
		i = va_arg(args, int);
		putchar(i);
		return (1);
	}
	else if (c == '%')
	{
		putchar('%');
		return (1);
	}
	return (0);
}
