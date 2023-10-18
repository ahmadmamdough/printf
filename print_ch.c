#include "main.h"
/**
 * print_ch - enrty point
 * @args: the args list
 * Return: always 1
 */
int print_ch(va_list args)
{
	int c = va_arg(args, int);

	putchar(c);
	return (1);
}
