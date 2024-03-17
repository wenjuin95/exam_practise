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
int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		char n;
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10; 
		else  
		 	break;  
		if (n >= str_base) 
			break;  
		res = res * str_base + n; 
		i++; 
	}
	return (sign * result);
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
