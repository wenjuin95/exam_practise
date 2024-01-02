// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);

int ft_atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;
	if(str[0] == '-' || str[0] == '+')
	{
		if(str[0] == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return(result * sign); 
}

#include <stdio.h>
int main()
{
	char *str = "-2345";
	int i = ft_atoi(str);
	printf("%d", i);
}