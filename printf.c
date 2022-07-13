#include "main.h"
#include <stdio.h>

/**
 * Allowed functions:
 *
 * write (man 2 write)
 * malloc (man 3 malloc)
 * free (man 3 free)
 * va_start (man 3 va_start)
 * va_end (man 3 va_end)
 * va_copy (man 3 va_copy)
 * va_arg (man 3 va_arg)
 */

int _printf(const char *format, ...)
{
	unsigned long int i, n;
	va_list arg_ptr;
	int j;
	fn_print params[] =
	{
		{'d', print_d},
		{'i', print_d},
		{0, 0}
	};

	/* format is the last required argument */
	va_start(arg_ptr, format);

	for (i = 0, n = 0; format[i] != '\0'; i++, n++)
	{
		if (format[i] == '%')
		{
			for (j = 0; params[j].c; j++)
			{
				if (params[j].c == format[i + 1])
				{
					params[j].fp(&arg_ptr);
					i += 2;
					n += 2;
				}
			}

			if (format[i + 1] == '%')
			{
				print_char('%');
				i += 2;
				n++;
			}
		}
		print_char(format[i]);
	}

	return (n);
}

void _puts(const char *s)
{
	unsigned long int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		print_char(s[i]);
	}
}

void print_char(char c)
{
	write(1, &c, 1);
}
