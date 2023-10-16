#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


int _printf(char *format, ...)
{
	int printed = 0; 
	char *i = format, *tmp;
	char c;
	va_list args;
	int n = 0;

	va_start (args, format);

	while (*i != '\0')
	{
		if (*i != '%')
		{
			putchar(*i), printed++;
		}
		else
		{
			/* to get the place holder */
			i++;

			if (*i == 's')
			{
				tmp = va_arg(args, char *);
				while (*tmp != '\0')
				{
					putchar(*tmp);
					printed++, tmp++;
				}
			}
			else if (*i == 'c')
			{
				putchar(va_arg(args, int));
				printed++;
			}
			else if (*i == '%')
			{
				printed++, putchar('%');
			}
		}
		i++;
	}
}
