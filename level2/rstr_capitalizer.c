/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

/*
*	1. loop through the argument
*	2. loop through the word
*	3. check if is big letter just convert to small
*	4. check if after the word is space, tab or null
*	5. go back and check if is small letter then make big letter
*	6. printf out
*	7. print line by line if a lot of argument
*/

int main(int ac, char **av)
{
	if (ac != 1)
	{
		//loop through the argument
		int i = 1;
		while (i < ac)
		{
			//loop through the word
			int j = 0;
			while (av[i][j])
			{
				//check if is 'A' to 'Z'
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					av[i][j] = av[i][j] + 32; //chg to 'a' to 'z'
				else
					av[i][j] = av[i][j]; //remain
				//check the word after is space, tab or null
				if (av[i][j+1] == ' ' || av[i][j+1] == '\t' || av[i][j+1] == '\0')
				{
					// check the word is small letter
					if (av[i][j] >= 'a' && av[i][j] <= 'z')
						av[i][j] = av[i][j] - 32; //chg to big
				}
				write(1, &av[i][j], 1); //write out
				j++;
			}
			i++;
			write(1,"\n", 1); //make it line by line
		}
	}
	else
		write(1, "\n", 1);
}
