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

/*
*	1. loop through the whole argument
*	2. loop through each of the word
*	3. check if is big make it small letter
*	4. after the word check is space or tab then open flag
*	5. if the flag is on the next word should be chg (if is small chg big)
*	note: "j=0" mean first letter of the word
*	6. handle each argument to next line
*/
int main(int ac, char **av)
{
	if (ac >= 1)
	{
		//loop through the argc for the sentence
		int i = 1;
		while (i < ac)
		{
			//loop through the word
			int j = 0;
			int flag = 0; //make flag for found the first word
			while (av[i][j])
			{
				//check is 'A' to 'Z'
				if (av[i][j] >= 'A' && av[i][j] <= 'Z')
					av[i][j] = av[i][j] + 32; //chg to 'a' to 'z'
				else
					av[i][j] = av[i][j]; //maintain
				//when next word is space
				if (av[i][j] == ' ' || av[i][j] == '\t')
						flag = 1; //open flag
				//check the flag is true and the next word is 'a' to 'z' 
				if (av[i][j] >= 'a' && av[i][j] <= 'z' && (flag == 1 || j == 0))
				{
					av[i][j] = av[i][j] - 32; //chg to 'A' to 'Z'
					flag = 0; //close flag
				}	
				write(1, &av[i][j], 1); //write out
				j++;
			}
			write(1,"\n", 1); //if have more argument make it line by line
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
