/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/


/*
*	1. use i to loop the string
*	2. if is alphabet "- a - 1" to get the length of each alphabet and assign to j
*	3. use j to write out each alphabet length
*/
int main(int ac, char **av)
{
        if (ac == 2)
        {
                int i = 0; // for string loop
                while (av[1][i])
                {
                        int k = 1; //get the length
                        if (av[1][i] >= 'a' && av[1][i] <= 'z')
                                k = av[1][i] - ('a' - 1); //this will get number of length for each character to print
                        else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                                k = av[1][i] - ('A' - 1);
                        while (1 <= k)
                        {
                                write(1, &av[1][i], 1);
                                k--;
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
}

/*
*example: ./a.out abc
*	  j = a - (a - 1)
          j = 1; // 1 is the length for the first letter
          output = a

          j = b - (a - 1)
          j = 2
          output = abb

          j = c - (a - 1)
          j = 3
          output = abbccc
*/
