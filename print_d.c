#include "main.h"

void print_d(va_list *arg_ptr)
{
	int d;
	d = va_arg(*arg_ptr, int);

	print_number(d);
}

void print_number(int n)
{
	int aux1, i, count, x;	/* declaring variables */
	if (n<0)
		print_char('-');	/* if negative, insert negative sign */

	/* handles special case of extreme negative */
	if (n==-2147483648)
	{
		print_char(50);
		n = -147483648;
	}

	if (n<0)
		n=-n;		/* if negative, go into positive world */

	count = count_digits(n);
	x = 1;

	for (i=1;i<count;i++)	/* make x big */
		x=x*10;

	print_char((n/x)+48);

	if (x>1)
	{
		aux1= n - ((int) n/x) * x; /* store magic formula */
		/* if there's any zero's, don't miss them */
		for (i=1;i<count_digits(n)-count_digits(aux1);i++)
		{
			print_char(48);
		}
		print_number(n - ((int) n/x) * x); /* recursive protocol */
	}
}

int count_digits(int n)
{
	int i=0, x=1;

	if (n==0)
		return 1;
	else if (n>=1000000000) /* modify this to suit other than 32-bit */
		return 10;
	while (x<=n)
	{
		i++;
		x=x*10;
	}
	return i;
}
