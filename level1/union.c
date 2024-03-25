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
*	1. make and array that take 127 storage and assign all to 0
*	//loop the argument to check each of the argument does it found repeat alphabet
*	2. outside loop will loop the argument (start form 1 not 0)
*	3. inside loop forthe string and found the alphabet and assign to the array to 1
*	4. outside loop reset the string to 0 and repeat
*	//loop the argument and write if found and check does it repeat
*	1. outside loop will loop the argument (start from 1 not 0)
*	3. inside loop for the string and check if the array that assign 1 found then write and assign to 2 (prevent to reuse)
*	4. outside loop reset the string to 0 and repeat
*/
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
