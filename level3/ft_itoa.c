/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/


/*
*	1. get the length of the number
*	2. if found negative number increase the number length
*	3. malloc the number length
*	4. put the null terminator at the back
*	5. check if is 0 then store 0 and return
*	6. if is negative number store "-" and make it positive
*	7. make a loop to store the number from back
*	8. return the string
*/
int nbr_len(int n) //get the number length
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}

char *ft_itoa(int nbr)
{
	long n = nbr;
	int len = nbr_len(n);
	if (n <= 0) //check if is negative increase the length
		len++;
	char *res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return NULL;
	res[len - 1] = '\0'; //it put null terminator to the end of the length
	if (n == 0) //if number is 0 just assign 0 and return 0
	{
		res[0] = '0';
		return res;
	}
	if (n < 0) //if is negative assign "-" and make it positive number
	{
		res[0] = '-';
		n *= -1;
	}
	while (n) //loop the n
	{
		len--;
		res[len] = n % 10 + '0'; // this get the end one by one and store
		n /= 10; //this will delete end one by one
	}
	return res;
}
