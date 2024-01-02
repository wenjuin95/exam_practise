/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp);
		rev = NULL;
		len--; //remove the '\0'
		while (tmp[len])
		{
			if (tmp[len - 1] == ' ')// if before is ' '
			{
				rev = &tmp[len]; //rev will point at the tmp[len]
				while(*rev && *rev != ' ')
				{
					write(1, rev, 1);
					rev++;
				}
				write(1, " ", 1);
			}
			else if (len == 0) //if the len is 0
			{
				rev = &tmp[len]; //rev will point at the tmp[len]
				while(*rev && *rev != ' ')
				{
					write(1, rev, 1);
					rev++;
				}
			}
			len--;
		}

	}
	write(1, "\n", 1);
}