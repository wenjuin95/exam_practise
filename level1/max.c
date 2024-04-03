/*
	Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/


/*
*	1. initialize the size with 0
*	2. assign the array with giveng size for result
*	3. loop the total len with i and compare result and array
*	4. if array found the bigger then assign to rest
*	5. return the result
*/
int max(int *tab, unsigned int len)
{
	if(len == 0)
		return 0;
	unsigned int i = 0;
	int result = tab[i]; // initialize an array of i
	//loop in the size given
	while(i < len) //until 1 not 0
	{
		//if the first array is highest assign it to result
		//next compare the result with the array's
		if(result < tab[i])
			result = tab[i];
		i++;
	}
	return result;
}
#include <stdio.h>
int main()
{
	int tab[] = {44, 23, 3, 4};
	int len = 4;
	printf("%d\n", max (tab, len));
}
