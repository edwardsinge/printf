#include <unistd.h> 		/* write(2) */
#include <stdarg.h>		/* va_arg(3) */

int _printf(const char *format, ...);
void _puts(const char *s);
void print_char(char c);
void print_number(int n);
int count_digits(int n);
void print_d(va_list *arg_ptr);

typedef struct fn_print
{
	char c;
	void (*fp)();
} fn_print;
