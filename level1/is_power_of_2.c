/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

2^n not n^2

int	    is_power_of_2(unsigned int n);
*/

/*i
*	0. this is to look for those that can be multiple only 2 with 2 and get the number
*	1. loop the number from 1
*	2. check the number modulo 2 result is return 0
*	3. if is then divide it
*	if is not then return 0
*/
int	is_power_of_2(unsigned int n)
{
	/*
	    example: 1. 16 % 2 == 0
	 		16 / 2 = 8 (8 will return to the loop and recursive)
	   	     2. 8 % 2 == 0
			8 / 2 = 4
	  	     3. 4 % 2 == 0
		        4 / 2 = 2
		     4. 2 % 2 == 0
	                2 / 2 = 0 (0 is less then 1, it stop the loop)
		1. n enter the loop
  		2. if the n can't be divide by 2 return 0 
    		3. if can be divided wil go to the loop again until it touch less then or equal to 0
	    		
	*/
	while (n > 1)
	{
		if (n % 2 == 0) //if the number modulo is 0
			n = n / 2; //divide it until it less then 1
		else 
			return 0; 
	}
	return 1;
}

#include <stdio.h>
int main()
{
	printf("%d\n", is_power_of_2(16));
}
