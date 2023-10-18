#include <limits.h>

/**
 * itoa - return string of int value
 *
 * @val: the value to be converted
 * @base: the base of the conversion
 * Return: the string value
 */

char *itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;

	if (val == INT_MIN)
		return ("2147483648");
	if (val == 0)
		return ("0");

	for (; val && i ; --i, val /= base)
	{
		buf[i] = "0123456789abcdef"[val % base];
	}

	return (&buf[i + 1]);

}
