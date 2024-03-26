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
*	1. count the total length
*	2. loop the total length
*	3. decrement the length if found whitespace or is NULL terminator
*	4. assign the position to "end"
*	5. if is word keep decrement 
*	6. assign the decrement word ad start + 1 (+1 is to got to the current position to start)
*	7. also assign it to flag
*	8. loop through within start and end and write out
*	9. check if the flag is not 0 also write " 
*/
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i]) // count the total length
			i++;
		while (0 <= i)
		{
			while (av[1][i] == ' ' || av[1][i] == '\0' || av[1][i] == '\t') //skip the whitespace and null terminator
				i--;
			int end = i; //assing it as end
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') //if is word keep decrease
				i--;
			int start = i + 1; //after that iterate +1 to the current word
			int flag = start; //assign as flag
			while (start <= end) //go through the loop
			{
				write(1, &av[1][start], 1); //write out
				start++;
			}
			if (flag != 0) //the the flag if is not equal 0 keep write out " "
				write(1, " ", 1)
		}

	}
	write(1, "\n", 1);
}
