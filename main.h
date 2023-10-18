#ifndef _HEADER_
#define _HEADER_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)

int _printf(char *format, ...);
char *itoa(int num, int base);
void reverse(char str[], int length);
int ps(char *s);
int pt_s(va_list args);
int get_op(va_list args, char c);
int print_percent(va_list args);
int print_d(va_list args);
int print_ch(va_list args);


typedef struct op
{
	char op;
	int (*f)(va_list);
} op_t;


#endif
