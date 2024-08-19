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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TYPE_END 3
# define TYPE_PIPE 4
# define TYPE_BREAK 5

typedef struct s_command
{
	char	**av;
	int		size;
	int		type;
	int		fd[2];
	struct s_command	*next;
	struct s_command	*prev;
} t_command;

int ft_strlen(char *str)
{
	int i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// char *ft_strdup(char *str)
// {
// 	int size = ft_strlen(str);

// 	if (str == NULL)
// 		return (NULL);
// 	char *new = malloc(sizeof(char) * size + 1);
// 	if (new == NULL)
// 		return (NULL);
// 	new[size] = '\0';
// 	while (0 <= size)
// 	{
// 		new[size] = str[size];
// 		size--;
// 	}
// 	return (new);
// }
char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	char *dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	int i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}


/**
 * @param ptr head pointer of the list
 * @param new_node new node
*/
void lstadd_back(t_command **ptr, t_command *new_node)
{
	t_command *tmp; //tmp node

	if (!(*ptr))// if the head pointer was nothing
		*ptr = new_node; //first node will be the new node
	else // if head pointer was something
	{
		tmp = *ptr; //first node will be the tmp node
		while (tmp->next) //look for the last node
			tmp = tmp->next;
		tmp->next = new_node; //last node will bew the new node
		new_node->prev = tmp; //new node's prev will be the last node
	}
}

/**
 * @brief count the length of command without pipe and break
 * @note if the command has pipe or break, it will stop counting
 * @note (example: "ls -la | grep main.c" is 2 argument then after pipe it will stop counting)
*/
int length_argv(char **av)
{
	int i = 0;
	while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	return (i);
}

int check_type(char *av)
{
	if (av == NULL)
		return (TYPE_END);
	if (strcmp(av, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(av, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

int parser(t_command **ptr, char **av)
{
	int size = length_argv(av); //get the length of the command
	t_command *new = malloc(sizeof(t_command)); //allocate memory for new node
	if (new == NULL)
		exit_fatal();
	new->av = malloc(sizeof(char *) * (size + 1)); //allocate memory for command
	if (new->av == NULL)
		exit_fatal();
	new->size = size; //set the size of the command
	new->next = NULL; //set the next node to NULL
	new->prev = NULL; //set the prev node to NULL
	new->av[size] = NULL; //set the last index to NULL
	size--;	// Decrease the size for copying arguments mean decrease the pipe or break
	while (0 <= size) //copy the command to the new node
	{
		new->av[size] = ft_strdup(av[size]);
		size--;
	}
	new->type = check_type(av[new->size]); //check the type of the command
	lstadd_back(ptr, new); //add the new node to the list
	return(new->size); //return the size of the command
}

void execute(t_command *tmp, char **env)
{
	pid_t pid;
	int status;
	int pipe_open = 0; //initialize the pipe_open to 0 mean close

	//if this type is pipe or previous pipe is not null and the previous type is pipe
	if (tmp->type == TYPE_PIPE || (tmp->prev != NULL && tmp->prev->type == TYPE_PIPE)) 
	{
		pipe_open = 1; //if has, set the pipe_open to 1 mean open
		if (pipe(tmp->fd) == -1) //make a pipe
			exit_fatal();
	}
	pid = fork(); 
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		//if type is pipe and the dup2 is failed
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) == -1)
			exit_fatal();
		//if previous is not null and type is pipe and the dup2 is failed
		if (tmp->prev != NULL && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[STDIN], STDIN) == -1)
			exit_fatal();
		//if the execute command failed
		if ((execve(tmp->av[0], tmp->av, env)) == -1)
			exit_execve(tmp->av[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		//if the pipe is open
		if (pipe_open)
		{
			close(tmp->fd[STDOUT]); //close the read pipe
			if (tmp->next == NULL || tmp->type == TYPE_BREAK) //if the next is null or type is break 
				close(tmp->fd[STDIN]); //close the write pipe
		}
		//if the previous is not null and the type is pipe
		if (tmp->prev != NULL && tmp->prev->type == TYPE_PIPE) 
			close(tmp->prev->fd[STDIN]); //close the write pipe
	}
}

void check_cmd(t_command *ptr, char **env)
{
	t_command *tmp;

	tmp = ptr;
	while (tmp != NULL)
	{
		if (strcmp(tmp->av[0], "cd") == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir(tmp->av[1]) == -1)
				exit_cd_2(tmp->av[1]);
		}
		else
			execute(tmp, env);
		tmp = tmp->next;
	}
}

void free_cmd(t_command *ptr)
{
	t_command *tmp;
	int i;

	while (ptr != NULL)
	{
		tmp = ptr->next;
		i = 0;
		while ( i < ptr->size)
		{
			free(ptr->av[i]);
			i++;
		}
		free(ptr->av);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}

int main(int ac, char **av, char **env)
{
	t_command *ptr = NULL;
	int i = 1;

	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue;
			}
			i += parser(&ptr, &av[i]);
			if (av[i] == NULL)
				break;
			else
				i++;
		}
		if (ptr != NULL)
			check_cmd(ptr, env);
		free_cmd(ptr);
	}
	return (0);
}