// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>

int main(int ac, char **av)
{
	if(ac == 3)
	{
		/*example: ./inter abac abcdef
  		* count av[2] and set them to 1
    		* example: abcdef
      		*          111111	
    		* count av[1] and found 1 in the loop will return the alpahbet
      		*example: abac
		*         11 1
		* chg it to 2 to prevent return again
  		*example: abac
    		*	  1121
      		* return: abc
    		*/
		int tab[127] = {0}; //127 is the ascii table total 
		int i =0;
		char *s1 = av[1];
		char *s2 = av[2];
		while(s2[i])
			//is important to chg to int
			tab[(int)s2[i++]] = 1;
		i = 0;
		while(s1[i])
		{
			if(tab[(int)s1[i]] == 1) 
			{
				write(1, &s1[i], 1);
				tab[(int)s1[i]] = 2;
			}
			i++;
		}

	}
	write(1, "\n", 1);
}

//ver2
int main(int ac, char **av)
{
        if (ac == 3)
        {
                int i = 0;
                int tab[127] = {0};
                while (av[2][i])
                {
                        tab[(int)av[2][i]] = 1;
                        i++;
                }
                i = 0;
                while (av[1][i])
                {
                        if (tab[(int)av[1][i]] == 1)
                        {
                                write(1, &av[1][i], 1);
                                tab[(int)av[1][i]] = 2;
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
}
