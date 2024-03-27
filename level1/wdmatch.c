/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int j = 0;
		int i = 0;
		while (av[2][j])
		{
			if (av[2][j] == av[1][i])
				i++;
			j++;
		}
		if (av[1][i] == '\0')
		{
			int k = 0;
			while (av[1][k])
			{
				write(1, &av[1][k], 1);
				k++;
			}
		}
	}
	write(1, "\n", 1);
}