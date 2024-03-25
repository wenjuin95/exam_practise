/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>

/*
*	1. loop through the string and skip the space or tab
*	2. loop again
*	3. while loop check if found space or tab then open flag
*	4. check if found word then check again the flag is on or off
*	5. if on write 1 space
*	6. reset flag off and write out
*/
int main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int flag;
		
		//skip the front space
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;

		//here start the function
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				flag = 1;
			if ((av[1][i] != ' ' && av[1][i] != '\t'))
			{
				if (flag == 1)
					write(1, " ", 1);
				flag = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
