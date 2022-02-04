/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:29:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:35:24 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*find_path(char *cmd)
{
	char		**paths;
	char		*path;
	struct stat	buf;

	if (stat(cmd, &buf) == 0)
		return (cmd);
	paths = g_envs->paths;
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

void	external_cmd(char *cmd, char **argv)
{
	pid_t	pid;
	char	*path;
	int		wstatus;

	pid = fork();
	if (pid == -1)
		perror(strerror(errno));
	else if (pid == 0)
	{
		path = find_path(cmd);
		if (path == NULL)
		{
			print_external_cmd_error(cmd);
			exit(127);
		}
		else
		{
			execve(path, argv, g_envs->envp);
			perror(strerror(errno));
		}
	}
	else
	{
		waitpid(pid, &wstatus, WUNTRACED);
		g_envs->exit_status = WEXITSTATUS(wstatus);
	}
}

void	execute(t_interpret *in)
{
	char	**argv;
	char	*cmd;

	argv = get_argv(in);
	cmd = in->list[0]->data;
	if (ft_strcmp("echo", cmd) == 0)
		builtin_echo(in);
	else if (ft_strcmp("cd", cmd) == 0)
		builtin_cd(in);
	else if (ft_strcmp("pwd", cmd) == 0)
		builtin_pwd();
	else if (ft_strcmp("export", cmd) == 0)
		builtin_export(in);
	else if (ft_strcmp("unset", cmd) == 0)
		builtin_unset(in);
	else if (ft_strcmp("env", cmd) == 0)
		builtin_env();
	else if (ft_strcmp("exit", cmd) == 0)
		builtin_exit(in);
	else
		external_cmd(cmd, argv);
	printf("exit_status : %d\n", get_exit_status());
	free_args(argv);
}
