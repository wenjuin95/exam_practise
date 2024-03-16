/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int size;
	int *result;
	int i = 0;

	size = abs(end - start); // abs to control the negative and positive
	result = malloc(sizeof(int) * size + 1);
	if (!result)
		return NULL;
	if (start < end)
	{
		while (start <= end)
		{
			result[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			result[i] = start;
			start--;
			i++;
		}
	}
	return result;
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	int	arr_len;
	int	*arr;

	arr_len = abs(atoi(argv[2]) - atoi(argv[1]));
	arr = ft_range(atoi(argv[1]), atoi(argv[2]));
	for (int i = 0; i <= arr_len; i += 1)
		printf("%d\n", arr[i]);
	free(arr);
	return (EXIT_SUCCESS);
}
