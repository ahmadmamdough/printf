#ifndef _HEADER_
#define _HEADER_

#include <stdlib.h>
#include <stdarg.h>


int _printf(char *format, ...);
char *itoa(int val, int base);
int ps(char *s);
int pt_s(char *s);
int get_op(va_list args, char c); 

#endif
