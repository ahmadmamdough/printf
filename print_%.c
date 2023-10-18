#include "main.h"
/**
 * print_percent - prints %
 * @args: arg_list
 * @s: the string
 * Return: number of printed items
 */
int print_percent(va_list args)
{
	putchar('%');
	
	UNUSED(args);

	return (1);
}
