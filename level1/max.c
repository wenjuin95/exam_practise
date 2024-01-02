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

int max(int *tab, unsigned int len)
{
	int result = tab[0];
	unsigned int i = 0;
	while(i < len)
	{
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