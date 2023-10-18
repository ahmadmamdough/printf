#include "main.h"

int print_ch(va_list args)
{
	int c = va_arg(args, int);
	
	putchar(c);
	return (1);
}
