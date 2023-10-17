#include "main.h"
#include <unistd.h>
#include <stdio.h>


int _printf(char *format, ...)
{
	int printed = 0;
	char *i = format;
	va_list args;
	int n = 0;

	va_start(args, format);

	while (*i != '\0')
	{
		i += ps(i);

		if (*i == '%')
		{
			n += get_op(args, *(++i));
			i++;
		}
	}
	return (n + i - format);
}

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

int get_op(va_list args, char c)
{
	int i = 0;
	char *s;

	if (c == 's')
	{
		s = va_arg(args, char *);
		i = pt_s(s);
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
