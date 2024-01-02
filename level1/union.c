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

int main(int ac, char **av)
{
	char tab[256] = {0};
	int i = 0;
	int j = 1;
	if (ac == 3)
	{
		//check both string
		while (j < 3)
		{
			while(av[j][i])
				tab[(int)av[j][i++]] = 1; //in the first string set all to 1
			i = 0; //set i to the first to get to the next string
			j++; //increament j to next string
		}

		//print both string
		j = 1;
		while (j < 3)
		{
			while (av[j][i]) 
			{
				if (tab[(int)av[j][i]] == 1) //if the string found 1
				{
					write(1, &av[j][i], 1); // print it out
					tab[(int)av[j][i]] = 2; //if fount the repeated character it not print out
				}
				i++;
			
			i = 0; //set i to the first to get to the next string
			j++; //increament j to next string
		}
	}
	write(1, "\n", 1);
}