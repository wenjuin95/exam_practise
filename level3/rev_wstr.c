/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

/*
*	1. count the total length of the string
*	2. minus the length if found whitespace or NULL terminator and assign to end
*	3. minus the lenght if found word then +1 and assign to start
*	4. assign the start to flag
*	4. check if end is bigger then start then print the start string
	5. use the flag to check if the start string not 0 to keep print space after the start string
*/
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i]) // count the total length
			i++;
		while (0 <= i) //[from 0 <= i]
		{
			while (av[1][i] == ' ' || av[1][i] == '\0' || av[1][i] == '\t') //decrease the position if found whitesapce or NULL
				i--;
			int end = i; //assign the position to end
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') //decrease the position if is the word
				i--;
			int start = i + 1; //thios to prevent the last word no found (it minus until the first word if no +1 it will come -1 not 0)
			int flag = start; //assign it to flag
			while (start <= end) //if the end is bigger then start [from start <= end]
			{
				write(1, &av[1][start], 1); //write the start word
				start++;
			}
			if (flag != 0) //check if the start is not 0 
				write(1, " ", 1) //make a space for it 
		}

	}
	write(1, "\n", 1);
}
