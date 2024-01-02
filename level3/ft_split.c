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

#include <stdlib.h>

//count the word character length
int count_len(char *str)
{
	int i = 0;
	while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++; //count is word
	return i;
}

//duplicate word
char *dup_word(char *str)
{
	int i = 0;
	int len = count_len(str);
	char *result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

//fill each of word
void fill_word(char **array, char *str)
{
	int word_index = 0;
	while(*str == ' ' || *str == '\t' || *str == '\n')
		str++; //move pointer
	while(*str)
	{
		array[word_index] = dup_word(str);
		word_index++;
		while(*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++; //move pointer
		while(*str == ' ' || *str == '\t' || *str == '\n')
			str++; //move pointer
	}
}

//count how many word
int count_word(char *str)
{
	int word_index = 0;
	while(*str == ' ' || *str == '\t' || *str == '\n')
		str++; //move pointer
	while(*str)
	{
		word_index++;
		while(*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++; //move pointer
		while(*str == ' ' || *str == '\t' || *str == '\n')
			str++; //move pointer
	}
	return (word_index);
}

char **ft_split(char *str)
{
	int num_word = count_word(str);
	char **split = malloc(sizeof(char *) * (num_word + 1));
	split[num_word] = 0;
	fill_word(split, str);
	return split;
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