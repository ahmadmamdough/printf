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
	unsigned int j = 0;
	int res;
	char *i = format;
	va_list args;
	int n = 0;

	if (!format || (format[j] == '%' && !format[j + 1]))
		return (-1);

	va_start(args, format);

	while (*i != '\0')
	{
		i += ps(i);

		if (*i == '%')
		{
			n -= 2;
			res = get_op(args, *(++i));
			if (res == -1)
				return (-1);
			n += res;
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
 * @args: the string to print
 * Return: no. of printed items
 */
int pt_s(va_list args)
{
	char *s = va_arg(args, char *);
	int n = 0;

	if (!s)
	{
		s = "(null)";
	}
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
	op_t ops[] = {
		{'c', print_ch},
		{'s', pt_s},
		{'d', print_d},
		{'i', print_d},
		{'%', print_percent}
	};
	int i = 0;

	UNUSED(args);
	while (ops[i].op != c && i < 5)
		i++;

	if (i == 5)
	{
		putchar('%'), putchar(c);
		return (2);
	}
	return (ops[i].f(args));

}
