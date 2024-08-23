// Assignment name  : microshell
// Expected files   : microshell.c
// Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
// --------------------------------------------------------------------------------------

// Write a program that will behave like executing a shell command
// - The command line to execute will be the arguments of this program
// - Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)
// - You must implement "|" and ";" like in bash
// 	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"
// - Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
// 	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
// 	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
// 	- a cd command will never be immediately followed or preceded by a "|"
// - You don't need to manage any type of wildcards (*, ~ etc...)
// - You don't need to manage environment variables ($BLA ...)
// - If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit
// - If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)
// - Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

// for example this should work:
// $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
// microshell
// i love my microshell
// $>

// Hints:
// Don't forget to pass the environment variable to execve

// Hints:
// Do not leak file descriptors!

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define WRITEFD 1
#define READFD 0

# define TRUE 1
# define FALSE 0

/**
 * @brief print error message
 * @param str error message
*/
void error_msg(char *str)
{
	while(*str)
		write(2, str++, 1);
}

/**
 * @brief change the directory
 * @param av command line arguments
 * @param i index of the command
 * @return 0 if success else 1
*/
int cd(char **av, int i)
{
	if (i != 2)
		return error_msg("error: cd: bad arguments\n"), 1;
	else if (chdir(av[1]) == -1)
		return error_msg("error: cd: cannot change directory to "), error_msg(av[1]), error_msg("\n"), 1;
	return 0;
}

/**
 * @brief initialize fd
 * @param has_pipe boolean to ehck pipe
 * @param fd file descripter
 * @param fd_type is either WRITE or READ
*/
void set_pipe(int has_pipe, int fd[2], int fd_type)
{
	//if has_pipe is 1 and if dup2 is failed or close is failed then print error message and exit
	if(has_pipe == TRUE && (dup2(fd[fd_type], fd_type) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		error_msg("error: fatal\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief execute the command
 * @param av command line arguments
 * @param i index of the command
 * @param env environment variable
 * @return 0 if success else 1
*/
int execute(char **av, int i, char **env)
{
	int has_pipe, fd[2], pid, status;

	//if av[i] is not null and av[i] is pipe then has_pipe is 1
	//1 is true and 0 is false
	has_pipe = av[i] != NULL && strcmp(av[i], "|") == 0;

	//if pipe is true and av[i] is cd then return cd function
	if (has_pipe == TRUE && strcmp(*av, "cd") == 0)
		return cd(av, i);

	//if pipe is true and pipe is failed then print error message and exit
	if (has_pipe == TRUE && pipe(fd) == -1)
	{
		error_msg("error: fatal\n");
		exit(EXIT_FAILURE);
	}

	//fork the process for pipe is true and pipe is successful
	pid = fork();
	if (pid == 0)
	{
		av[i] = NULL; //is separate the command from left and right side of the pipe

		set_pipe(has_pipe, fd, WRITEFD); //duplicate the write file descriptor and close the file descriptor

		//if av is cd then return cd function
		if (strcmp(*av, "cd") == 0)
			return cd(av, i);

		//if not then execute the command
		execve(*av, av, env);
		
		//if execve is failed then print error message
		error_msg("error: cannot execute "), error_msg(*av), error_msg("\n");
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, READFD); //duplicate the read file descriptor and close the file descriptor
	return WIFEXITED(status) && WEXITSTATUS(status); //return the exit status
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	int i = 1;
	int status = 0;

	while (av[i])
	{
		av += i; //move the pointer to the next command. This skips over the already processed arguments.

		//counts the length of the current command by incrementing i until it encounters a NULL, |, or ;.
		i = 0;
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		
		//if the length of the command is not 0 (mean programe name) then execute the command 
		if (i != 0) 
			status = execute(av, i, env);

		//if the command is not NULL or | or ; then increment i
		i += (av[i] != NULL);
	}
	return status;
}