/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void ft_putnbr(int nb)
{
	if(nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	char c = (nb % 10) + '0';
	write(1, &c, 1);
}

int prime_nb(int n)
{
	int i = 2;
	while(i < n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int add_prime(int n)
{
	int sum = 0;
	int i = 2;
	while (i <= n)
	{
		if (prime_nb(i) == 1)
			sum += i;
		i++;
	}
	return sum;
}

int main (int ac, char **av)
{
	int n;
	if (ac == 2 && (n = ft_atoi(av[1])))
		ft_putnbr(add_prime(n));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return 0;
}