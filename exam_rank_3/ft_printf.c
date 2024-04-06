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

int ft_putnbr(int n)
{
	int len = 0;
	long nb = n;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	char c = nb % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}

int ft_puthex(unsigned int nb)
{
	int len = 0;
	char *base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16);
	len += write(1, &base[nb % 16], 1);
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
				len += ft_putnbr(va_arg(ptr, int));
			else if (format[i+1] == 'x')
				len += ft_puthex(va_arg(ptr, unsigned int));
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}