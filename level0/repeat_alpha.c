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
*	1. outter loop through the string and write out
*	2. it get alphabet position and convert into the number of alphabet by "- a" and "- A"
*	3. inner loop will loop the number of alphabet that count and write out
*/
int main(int ac, char **av)
{
        if (ac == 2)
        {
                int i = 0;
                while (av[1][i])
                {
                        write(1, &av[1][i], 1);
                        int k = 0;
                        if (av[1][i] >= 'a' && av[1][i] <= 'z')
                                k = av[1][i] - 'a';
                        if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                                k = av[1][i] - 'A';
                        while (0 < k)
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
*	  [loop will print]
*	  (nothing)
*	  [then the original]
*	  a
*	  [loop will print]
*	  ab
*	  [then the original]
*	  abb
*	  [loop will print]
*	  abbcc
*	  [then the original]
*	  abbccc
*/
