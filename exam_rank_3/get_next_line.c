/*
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);

Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
*/

/*
*	1. understand
*	.ft_strlen
*	.ft_strchr
*	.ft_strdup
*	.ft_strcpy
*	.ft_strjoin
*
*/
 #include <unistd.h>
 #include <stdlib.h>

 #define BUFFER_SIZE 32

 int ft_strlen(char *str)
 {
	int i = 0;
	while (str[i])
		i++;
	return i;
 }

 char *ft_strcpy(char *dest, char *src)
 {
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
 }

 char *ft_strchr(char *s, int c)
 {
	int i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	return NULL;
 }

 char *ft_strdup(char *s)
 {
	int size = ft_strlen(s);
	char *str = malloc(size + 1);
	if (str == NULL)
		return NULL;
	ft_strcpy(str, s);
	return str;
 }

 char *ft_strjoin(char *s1, char *s2)
 {
	if (s1 == NULL || s2 == NULL)
		return NULL;
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char *res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return NULL;
	ft_strcpy(res, s1);
	ft_strcpy(res + s1_len, s2);
	free(s1);
	return res;
 }

 char *get_next_line(int fd)
 {
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int read_byte;
	int to_copy;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return NULL;
	line = ft_strdup(buffer); //the first if buffer had nothing it copy "\0" to line
	while (!(newline = ft_strchr(line, '\n')) && (read_byte = read(fd, buffer, BUFFER_SIZE))) //buffer will get the number of BUFFER_SIZE given word and newline will get the line after "\n"
	{
		buffer[read_byte] = '\0'; //buffer then readed will put "\0"
		line = ft_strjoin(line, buffer); //they will join and make a line
	}
	if (ft_strlen(line) == 0) //if the line doesn't have anything just return and free
	{
		free(line);
		return NULL;
	}
	if (newline != NULL) //if the newline found something
	{
		to_copy = newline - line + 1; //calculate the length of newline
		ft_strcpy(buffer, newline + 1); // copy the content newline to the buffer
	}
	else
	{
		to_copy = ft_strlen(line); //calsulate the whole length
		buffer[0] = '\0'; //assign \0
	}
	line[to_copy] = '\0'; //the buffer will copy to line
	return (line);
 }

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);

// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return 0;
// }
