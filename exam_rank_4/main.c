#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define WRITEFD 1
#define READFD 0

void err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int cd(char **av, int i)
{
	if (i != 2)
		return err("error: cd: bad arguments\n"), 1;
	if (chdir(av[i]) == -1)
		return err("error: cd: cannot change directory to "), err(av[i]), err("\n"), 1;
	return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe == TRUE && (dup2(fd[end], end) == -1 || close(fd[WRITEFD]) == -1 || close(fd[READFD]) == -1))
		err("error: fatal\n"), exit(1);
}

int execute(char **av, int i, char **envp)
{
	int has_pipe, fd[2], pid, status;

	if (av[i] != NULL && !strcmp(av[i], "|"))
		has_pipe = TRUE;
	else
		has_pipe = FALSE;
	if (has_pipe == FALSE && !strcmp(av[0], "cd"))
		return (cd(av, i));
	if (has_pipe == TRUE && pipe(fd) == -1)
		err("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1)
		err("error: fatal\n"), exit(1);
	if (pid == 0)
	{
		av[i] = 0;
		set_pipe(has_pipe, fd, WRITEFD);
		if (!strcmp(av[0], "cd"))
			exit(cd(av, i));
		execve(av[0], av, envp);
		err("error: cannot execute "), err(av[0]), err("\n"), exit(1);
	}
	waitpid(pid,&status, 0);
	set_pipe(has_pipe,fd, READFD);
	if (status >= 0 && status <= 255)
		return status;
	else
		return 1;
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	int i, status;
	i = 0;
	status = 0;
	while (av[i])
	{
		av = av + i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if ( i != 0)
			status = execute(av, i, envp);
	}
	return status;
}