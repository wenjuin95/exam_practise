/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int j;

	if (ac >= 2)
	{
		//search for space and move the position
		while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		j = i; //this is the position to starting the word
		while(av[1][i])
		{
			//find the next word
			while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				i++;
			//find the next word
			while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			// print the word till it reaches last word
			while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i-1] == ' ' || av[1][i-1] == '\t'))
			{
				while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				{
					write(1, &av[1][i], 1);
					i++;
				}
				write(1, " ",  1);
				i++;
			}
		}
		//print the first word
		while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t'))
		{
			write(1, &av[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}