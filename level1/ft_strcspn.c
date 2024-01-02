// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while(s[i])
	{
		size_t j = 0;
		while(reject[j])
		{
			if(s[i] == reject[j]) //if found the first one straight return
				return i;
			j++;
		}
		i++;
	}
	i = 0;
	while(s[i])
		i++;
	return i;
}


#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%ld\n", ft_strcspn("test", "es"));
	printf("%ld\n", strcspn("test", "es"));
printf("%ld\n", ft_strcspn("test", "f"));
	printf("%ld\n", strcspn("test", "f"));
}