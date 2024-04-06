/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include <unistd.h>

/*
*	1. count the length of the string and minus the null terminator
*	2. check the length from back if found space or tab then minus
*	3. check the length from back if found a word then minus
*	3. check if is space or tab then +1 for the length
*	4. loop the string and skip the space or tab and start to write out
*/
int main(int ac, char **av)
{
	int i = 0;
	if(ac == 2)
	{
		//count the total string
		while(av[1][i])
			i++;
		i--; //cut the '\0' in the whole sentence
		while((av[1][i] == ' ' || av[1][i] == '\t') && i != 0) //check got space/tab at the back
			i--;
		while((av[1][i] != ' ' && av[1][i] != '\t') && i != 0) //check it is a character
			i--;
		if (av[1][i] == ' ' || av[1][i] == '\t') //if is space/tab increment it
			i++;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') //start print the string (it ignore the front)
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
/*
*example: ./a.out "hello world"
*	 1. total length 12 (inc "\0")
*	 [hello world|\0] (12)
		     start
*	 2. remove the \0
*	 [hello world] (11)
*	 3. not space then skip, count character until found space
*	 [hello| world] (5)
	       start
*	 4. founnd space increase 1
*	 [hello |world] (6)
	        start
*	 5. count and print
*	 [world] 
*/
