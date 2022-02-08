/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:05:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/08 10:59:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cd(char *path)
{
	char	*oldpwd;
	char	buf[PATH_MAX];

	oldpwd = getcwd(buf, PATH_MAX);
	if (chdir(path) == -1)
	{
		g_envs->exit_status = 1;
		perror(strerror(errno));
	}
	else
	{
		set_env("OLDPWD", oldpwd);
		set_env("PWD", getcwd(buf, PATH_MAX));
	}
}

void	builtin_cd(t_interpret *in)
{
	t_clist	*path;
	char	*home;

	path = in->list[0]->next;
	if (path == NULL)
	{
		home = get_env("HOME");
		execute_cd(home);
	}
	else
		execute_cd(path->data);
}
