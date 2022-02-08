/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:56:42 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/08 22:34:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_perror(char *cmd, char *error_str)
{
	ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(error_str, STDERR_FILENO);
}

void	print_external_cmd_error(char *cmd)
{
	ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
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
	idx = -1;
	curr = in->list[0];
	while (++idx < size)
	{
		if (curr->data != NULL)
			argv[idx] = ft_strdup(curr->data);
		else
			argv[idx] = ft_strdup("");
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
