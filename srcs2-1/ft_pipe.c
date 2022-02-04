/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:38:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 18:51:08 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_processpipe(t_interpret *in, t_interpret **r)
{
	int			fd[2];
	t_interpret	*root;
	t_interpret	*tmp;
	int			pid;
	int			ret;

	pid = 0;
	ret = 0;
	root = in;
	while (root)
	{
		ft_putstr_fd("flag : ", STDERR_FILENO);
		ft_putendl_fd(ft_itoa(root->flag), STDERR_FILENO);
		while (root->son)
			ret = ft_processpipe(root->son, &tmp);
		if (root->flag == PIPE)
		{
			pipe(fd);
			ft_putstr_fd("num : ", STDERR_FILENO);
			ft_putendl_fd("1", STDERR_FILENO);
			pid = fork();
			if (pid)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				if (root->son == 0)
				{
					ft_putstr_fd("num : ", STDERR_FILENO);
					ft_putendl_fd("3", STDERR_FILENO);
					ft_run(root);
				}
				else
				{
					ft_putstr_fd("num : ", STDERR_FILENO);
					ft_putendl_fd("4", STDERR_FILENO);
					ft_run(tmp);
				}
				close(STDOUT_FILENO);
				ret += get_exit_status();
			}
			else
			{
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
			}
		}
		else if (root->flag == AND || root->flag == OR)
		{
			if (root->son == 0)
				ft_run(root);
			else
				ft_run(tmp);
			if (root->flag == AND)
				ret += get_exit_status();
			else if (root->flag == OR)
				ret = get_exit_status();
			if (ret != 0 && root->flag == AND)
				return (0);
			else if (ret == 0 && root->flag == OR)
				return (0);
		}
		else if (root->parent)
		{
			*r = root;
			return (ret);
		}
		else
		{
			ft_putstr_fd("num : ", STDERR_FILENO);
			ft_putendl_fd("2", STDERR_FILENO);
			ft_run(root);
			ret += get_exit_status();
			return (ret);
		}
		root = root->next;
	}
	return (ret);
}
