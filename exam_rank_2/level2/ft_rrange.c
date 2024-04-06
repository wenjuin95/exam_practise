/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

/*
*	1. check which is bigger then take the bigger minus smaller to get size
*	2. malloc the size
*	//in this part we need reverse
*	3. check if start bigger then end
*	   ex: end will be assign to malloc with increament
*	4. end bigger then start
*	   ex: end will assign to malloc with decreament
*/
int *ft_range(int start, int end)
{
	int size;
	if (star > end)
		size = (start - end);
	else
		size = (end - start);
	int *res = malloc(sizeof(int) * size + 1);
	if (!res)
		return NULL;
	int i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = end;
			end --;
			i++;
		}
	}
	else 
	{
		while (start >= end)
		{
			res[i] = end;
			end++;
			i++;
		}
	}
	return res;
}

#include <stdio.h>
int main()
{
	int *arr = ft_rrange(1, 3);
	int len = abs((3) - (1));
	int i = 0;
	while (i <= len)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}
