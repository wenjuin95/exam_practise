/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

/*
*	1. make a string copy with limit
*	2. loop the string
*		a. skip the whitespace
*		b. check if the string not finish the increase 1 means found the word
*		c. loop through the current word
*	3. malloc the total word that you found
*	4. loop through the string again
*		a. skip the whitspace
*		b. assign a starting index
*		c. loop trough the current word
*		d. compare the length of current word and index
*		e. malloc the total length of current word
*		f. copy to and array
*	5. assign a null terminator
*/
#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (s2[i] && i < n) //loop s2 andlimit the size
	{
		s1[i] = s2[i]; //it sopy to s1 with size given
		i++;
	}
	s1[i] = '\0'; //assign null to it
	return s1;
}

char **ft_split(char *str)
{
	int i = 0;
	int wc = 0;
	int j = 0;
	int arr = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) //skip front if found those
			i++;
		if (str[i]) //found the first word then increment
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')) //loop trough the word and found those
			i++;
	}
	char **res = malloc(sizeof(char *) * wc + 1); //malloc the wc
	if (res == NULL)
		return NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) //get whitespace position
			i++;
		j = i; //whitespace position assign j
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')) //get word position
			i++;
		if (i > j) //check the word position is bigger then space
		{
			res[arr] = malloc(sizeof(char) * (i - j) + 1); //i - j to get the length of the word
			ft_strncpy(res[arr], &str[j], i - j); //coppy word to arr
			arr++; //move to the next word to copy
		}
	}
	return res;
}

#include <stdio.h>
#include <limits.h>

int main() {
  	char *input_string = "Hello World This Is A Test";
   char **result = ft_split(input_string);

   // Print the split substrings
   for (int i = 0; result[i] != NULL; i++) {
       printf("Substring %d: %s\n", i, result[i]);
       free(result[i]);  // Free the memory allocated for each substring
   }

   // Free the array of strings
   free(result);

   return 0;
}
