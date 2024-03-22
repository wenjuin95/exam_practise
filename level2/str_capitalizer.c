/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/

#include <unistd.h>

void str_cap(char *str)
{
	while(*str)
	{
		while(*str && (*str == ' ' || *str == '\t'))
		{
			write(1, str, 1);
			str++;
		}
		if (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - 32;
			write(1, str, 1);
			str++;
		}
		while(*str && *str != ' ' && *str != '\t')
		{
			if(*str >= 'A' && *str <= 'Z')
				*str = *str + 32;
			write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1;
		while (i < ac)
		{
			str_cap(av[i]);
			i++;
		}
	}
}

//ver 2
int main(int ac, char **av)
{
	if (ac != 1)
	{
		int i = 1;
		while (i < ac)
		{
			int j = 0;
			char c;
			int flag = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					c = av[i][j] + 32;
				else
					c = av[i][j];
				if (c == ' ' || av[i][j] == '\t')
						flag = 1;
				if (c >= 'a' && c <= 'z' && (flag == 1 || j == 0))
				{
					c = c - 32;
					flag = 0;
				}	
				write(1, &c, 1);
				j++;
			}
			i++;
			write(1,"\n", 1);
		}
	}
	else
		write(1, "\n", 1);
}
