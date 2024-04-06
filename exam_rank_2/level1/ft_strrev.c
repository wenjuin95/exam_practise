// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that reverses (in-place) a string.
//
// It must return its parameter.
//
// Your function must be declared as follows:
//
// char    *ft_strrev(char *str);

/*
*	1. count the length of the string
*	2. minus 1 for remove null terminator
*	3. compare with 0 and the total length
* 	4. swap with smaller and bigger
*	5.increase the 0 and decrease the length
*/
char *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	int tmp;
	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	return str;
}

#include <stdio.h>
int main()
{
	char str[] = "hello";
	ft_strrev(str);
	printf("%s\n", str);
}
