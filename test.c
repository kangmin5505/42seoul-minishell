#include <stdio.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "readline/readline.h"

int	main(int argc, char *argv[], char *envp[])
{
	for (int i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "LOGNAME", 7) == 0)
		{
			envp[i] = "";
		}
		if (strlen(envp[i]) != 0)
			printf("%s\n", envp[i]);
	}
}
