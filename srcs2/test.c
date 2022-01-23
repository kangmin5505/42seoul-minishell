#include <stdio.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "readline/readline.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	buf[1024];
	char	*line;
	pid_t	pid;
	int		wstatus;

	printf("%s\n", getcwd(buf, PATH_MAX));
	while (1)
	{
		line = readline("minishell % ");
		if (line && strcmp(line, "cd ..") == 0)
		{
			chdir("..");
			printf("%s\n", getcwd(buf, PATH_MAX));
		}
		else if (line && strcmp(line, "ls") == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve("/bin/ls", argv, envp);
			}
			else
			{
				waitpid(pid, &wstatus, WUNTRACED);
			}
		}
	}
}
