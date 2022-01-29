/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:29:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 14:03:18 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char	**args)
{
	char	**temp;

	temp = args;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}

char	**get_argv(t_interpret *in)
{
	char	**argv;
	t_clist	*curr;
	int		size;
	int		idx;

	curr = in->list[0];
	size = 0;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	argv = (char **)malloc(sizeof(char *) * (size + 1));
	idx = 0;
	curr = in->list[0];
	while (idx < size)
	{
		argv[idx] = strdup(curr->data);
		idx++;
		curr = curr->next;
	}
	argv[idx] = NULL;
	return (argv);
}

char	*find_path(t_envs *envs, char *cmd)
{
	char		**paths;
	char		*path;
	struct stat	buf;

	if (stat(cmd, &buf) == 0)
		return (cmd);
	paths = envs->paths;
	while (*paths)
	{
		path = ft_strjoin2(*paths, cmd, "/");
		if (stat(path, &buf) == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

void	external_cmd(char *cmd, char **argv, t_envs *envs)
{
	 pid_t	pid;
	 char	*path;

	 pid = fork();
	 if (pid == 0)
	 {
		 path = find_path(envs, cmd);
		 if (path == NULL)
			 perror("minishell: command not found:");
		 execve(path, argv, envs->envp);
		 exit(1);
	 }
	 else
	 {
		 wait(0);
	 }
}

void	execute(t_interpret *in, t_envs *envs)
{
	char	**argv;
	char	*cmd;

	argv = get_argv(in);
	cmd = in->list[0]->data;
	if (ft_strcmp("echo", cmd) == 0)
		printf("echo\n");
	else if (ft_strcmp("cd", cmd) == 0)
		printf("cd\n");
	else if (ft_strcmp("pwd", cmd) == 0)
		printf("pwd\n");
	else if (ft_strcmp("export", cmd) == 0)
		printf("export\n");
	else if (ft_strcmp("unset", cmd) == 0)
		unset_env(envs, "PATH");
	else if (ft_strcmp("env", cmd) == 0)
		env(envs);
	else if (ft_strcmp("exit", cmd) == 0)
		printf("exit\n");
	else
		external_cmd(cmd, argv, envs);
	free_args(argv);
}
