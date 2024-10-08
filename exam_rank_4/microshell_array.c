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

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define WRITEFD 1
#define READFD 0

void err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int cd(char **argv, int i)
{
	//if position is not 2 then print error and return 1 (because the argument is not correct)
	if (i != 2)
		return err("error: cd: bad arguments\n"), 1;
	//if chdir is equal to -1 then print error and return 1 (mean change directory failed)
	if (chdir(argv[i]) == -1)
		return err("error: cd: cannot change directory to "), err(argv[i]), err("\n"), 1;
	return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
	//if has_pipe is 1(true) and dup2 is equal to -1 or close is equal to -1 then print error and exit
	if (has_pipe == TRUE && (dup2(fd[end], end) == -1 || close(fd[WRITEFD]) == -1 || close(fd[READFD]) == -1))
		err("error: fatal\n"), exit(1);
}

int	exec(char **argv, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;

	//if argument is not null and is equal to "|" then has_pipe is 1(true)
	if (argv[i] != NULL && !strcmp(argv[i], "|"))
		has_pipe = TRUE;
	else
		has_pipe = FALSE;

	//if has_pipe is 0(false) and the first argument is equal to "cd" then return the cd function
	if (has_pipe == FALSE && !strcmp(argv[0], "cd"))
		return (cd(argv, i));

	//if has_pipe is 1(ture) and pipe is equal to -1 then print error and exit	
	if (has_pipe == TRUE && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);

	//if pid is equal to -1 then print error and exit
	if ((pid = fork()) == -1)
		err("error: fatal\n"), exit(1);

	//if pid is equal to 0 
	if (pid == 0)
	{
		argv[i] = 0; //set the argument to 0
		set_pipe(has_pipe, fd, WRITEFD); //set the pipe to write
		if (!strcmp(argv[0], "cd")) //if the argument is equal to "cd" then exit
			exit(cd(argv, i));
		execve(argv[0], argv, envp); //execute the argument
		err("error: cannot execute "), err(argv[0]), err("\n"), exit(1); //print error and exit if the execution failed
	}
	waitpid(pid, &status, 0); //wait for the child process to finish
	set_pipe(has_pipe, fd, READFD); //set the pipe to read

	//if the status is between 0 and 255 then return the status
	if (status >= 0 && status <= 255)
		return status;
	else
		return 1;
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0;
	int status = 0;

	while (argv[i])
	{
		argv = argv + i + 1; //increament the pointer
		i = 0; //reset 0 is the index

		//if the argument is not | or ; then increment the index
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		//if i is not 0 mean is not the first argument
		if (i != 0)
			status = exec(argv, i, envp);
	}
	return status;
}