/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.
*/

#include <unistd.h>
#include <stdarg.h>

int ft_putstr(char *str)
{
	int i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
}

int ft_puthex(long long nb, int base)
{
	int len = 0;
	char *base_str = "0123456789abcdef";
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base)
		len += ft_puthex((nb / base), base);
	len += write(1, &base_str[nb % base], 1);
	return (len);
}

int ft_printf(const char *format, ...)
{
	int len = 0;

	va_list ptr;
	va_start(ptr, format);

	int i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			
			if (format[i+1] == 's')
				len += ft_putstr(va_arg(ptr, char *));
			else if (format[i+1] == 'd')
				len += ft_puthex((long long)va_arg(ptr, int), 10);
			else if (format[i+1] == 'x')
				len += ft_puthex((long long)va_arg(ptr, unsigned int), 16);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}

// #include <stdio.h>

// int main()
// {
// 	int len = 0;
// 	int len2 = 0;
// 	int i = 2147483647;
// 	len += (ft_printf("%d\n", i));
// 	ft_printf("%d\n", len);
// 	len2 += (printf("%d\n", i));
// 	printf("%d\n", len);
// }
