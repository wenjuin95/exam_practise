/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

int nbr_len(int nbr)
{
	int i = 1;
	while (nbr /= 10)
		i++;
	return i;
}

char *ft_itoa(int nbr)
{
	char *result;
	int len;

	long num = nbr;
	len = nbr_len(num);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = num % 10 + '0';
		num = num / 10;
	}
	if (nbr < 0) //use ori nbr to know is "-" number
		result[0] = '-';
	return (result);
}