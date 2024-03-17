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

int *ft_range(int start, int end)
{
	int size = 1 + abs(end - start);
	int *res = malloc(sizeof(int) * size);
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
