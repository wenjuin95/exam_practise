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

/*
*	0. check if empty
*	1. loop the pointer of s1 (not string)
*	2. loop the s2 string and compare with *s1
*	3. if found return the pointer position s1(typecast to char *)
*	4. if not return 0;
*/
char *ft_strpbrk(const char *s1, const char *s2)
{
	if (s1 == 0 || s2 == 0)
		return 0;
	int j = 0;
	while (s1[j])
	{
		i = 0;
		while (s2[i])
		{
			if (s1[j] == s2[i])
				return (char *)s1;
			i++;
		}
		j++;
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
