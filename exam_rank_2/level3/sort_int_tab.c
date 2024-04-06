/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

/*
*	1.loop the i with size given
*		a. loop the j with + 1 (assign the next array to loop)
*		b. compare the i and j
* 		c. use swap
*/
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	while (i < size)
	{
		unsigned int j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>
int main()
{
	int arr[] = {2, 5, 3, 1, 4, 6};
	int size = 6;
	int i = 0;
	while (i < size)
	{
		printf("%d: %d\n", i, arr[i]);
		i++;
	}
	printf("\n");
	sort_int_tab(arr, size);
	i = 0;
	while (i < size)
	{
		printf("%d: %d\n", i, arr[i]);
		i++;
	}
}
