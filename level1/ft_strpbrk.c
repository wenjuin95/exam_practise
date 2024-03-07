// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------
//
// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).
//
// The function should be prototyped as follows:
//
// char	*ft_strpbrk(const char *s1, const char *s2);

//similar to ft_strchr
char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return (char *)s1;
			i++;
		}
		s1++;
	}
	return 0;
}

// #include <stdio.h>
// int main()
// {
// 	char s1[] = "hello world";
// 	char s2[] = "el";
// 	char *str = ft_strpbrk(s1, s2);
// 	printf("%s\n", str);
// }
