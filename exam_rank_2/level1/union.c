/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include <unistd.h>

/*
*	1. check av[1] and av[2] have any double alphabet with flag (tab)
*	2. loop through each of the argument(start from 1) to print if the flag is on
*/
int main(int ac, char **av)
{
	if (ac == 3)
	{
		int arg = 1; //argument start from the second
		int tab[127] = {0}; //flag
		//loop all the argument and check each of the rgument had double
		while(arg <= 2)
		{
			int i = 0;
			while (av[arg][i])
				tab[(int)av[arg][i++]] = 1; //flag on to skip the similar alphabet
			arg++;
		}
		//loop and print if no double
		arg = 1;
		while (arg <= 2)
		{
			int j = 0;
			while (av[arg][j])
			{
				if (tab[(int)av[arg][j]] == 1) //if flag on
				{
					write(1, &av[arg][j], 1); //print the flag
					tab[(int)av[arg][j]] = 2; //to not printf the same flag
				}
				j++;
			}
			arg++;
		}
	}
	write(1, "\n", 1);
}
