/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

/*
*	1. check the number is 1 then print 1
*	2. else loop the n
*	3. check the prime
*	4. if found prime the i will print out the number
*	5. n divide by i for next search
*	6. check if n is less then equal 2 then print *
*	7. i - 1 for the loop to add 1 become 2(to prevent infinite loop)
*/
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 2;
		int n = atoi(av[1]);
		if (n == 1)
			printf("1"); //check if only 1 then write 1
		else
		{
			while (2 <= n) //loop the n
			{
				if (n % i == 0) //check for prime number
				{
					printf("%d", i); //print the prime
					n /= i; //divide the n for the next search
					if (n >= 2) //if the n still bigger then 1 then write *
						printf("*");
					i--; //this to reuse back te number
				}
				i++;
			}
		}
	}
	printf("\n");
}

/*
*	1. 42 % 2 == 0
*		print 2
*		42 / 2 = 21
* 		21 >= 2
*    			print *
*      		2 - 1 = 1
*  	2. 21 % (1+1) != 0
*	3. 21 % 3 = 0
*		print 3
*		21 / 3 = 7
*  		7 >= 2
*    			print *
*      		3 - 1 = 2 	
*	4. 7 % (2 + 1) != 0
*	5. 7 % 4 != 0
*	6. 7 % 5 != 0
*	7. 7 % 6 != 0
*	8. 7 % 7 == 0
*		print 7
*		7 / 7 = 1
*  		1 >= 2
*    			no print *
*      		7 - 1 = 6
*	9. 1 is not bigger then 2 so stop
*/

