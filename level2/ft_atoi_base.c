/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

//check the front
char	is_space(char c)
{
	if (c <= 32)
		return 1;
	return 0;
}

int	get_number(char c, int base)
{
	int	nb;

	//check base is less or more then 10
	if (base <= 10)
		nb = base + '0';
	else
		nb = base - 10 + 'a';

	//convert number
	if (c >= '0' && c <= '9' && c <= nb)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= nb)
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F' && c <= nb)
		return (c - 'A' + 10);
	else
		return (-1); //act as an error
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int i;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((i = get_number(*str), str_base)) >= 0)
	{
		result = result * str_base + (i * sign);
		str++;
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
	//                            ff           16            = 255
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
    }
    return (0);
}
