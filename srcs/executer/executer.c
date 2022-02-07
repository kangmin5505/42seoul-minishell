/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:29:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 12:03:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	external_cmd(char *cmd, char **argv)
{
	pid_t	pid;
	char	*path;
	int		wstatus;

	pid = fork();
	if (pid == 0)
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
		waitpid(pid, &wstatus, 0);
		g_envs->exit_status = WEXITSTATUS(wstatus);
	}
}

void	execute_cmd(t_interpret *in)
{
	char	**argv;
	char	*cmd;

	argv = get_argv(in);
	cmd = in->list[DATA]->data;
	if (cmd == NULL)
		;
	else if (ft_strcmp("echo", cmd) == 0)
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
	free_args(argv);
}

void	ft_run(t_interpret *in)
{
	if (in->list[I]->data != NULL || in->list[DI]->data != NULL \
		|| in->list[O]->data != NULL || in->list[DO]->data != NULL)
		redirections_cmd(in);
	else
		execute_cmd(in);
}
