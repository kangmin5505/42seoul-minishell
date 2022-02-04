/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:38:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/05 03:43:26 by gimsang-w        ###   ########.fr       */
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
	int			stat;

	pid = 0;
	ret = 0;
	root = in;
	while (root)
	{
		if (root->son)
			ret = ft_processpipe(root->son, &tmp);
		if (root->flag == PIPE)
		{
			pipe(fd);
			pid = fork();
			if (pid)
			{
				close(fd[0]);
				close(STDOUT_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				if (root->son == 0)
					ft_run(root);
				else
					if (tmp)
						ft_run(tmp);
				close(STDOUT_FILENO);
				ret += get_exit_status();
			}
			else
			{
				close(fd[1]);
				close(STDIN_FILENO);
				dup2(fd[0], STDIN_FILENO);
			}
		}
		else if (root->flag == AND || root->flag == OR)
		{
			if (root->son == 0)
			{
				ft_run(root);
				if (root->flag == AND)
					ret += get_exit_status();
				else
					ret = get_exit_status();
			}
			else
			{
				if (tmp)
				{
					ft_run(tmp);
					ret += get_exit_status();
				}
			}
			if (ret != 0 && root->flag == AND)
			{
				if (r)
					*r = 0;
				return (0);
			}
			else if (ret == 0 && root->flag == OR)
			{
				if (r)
					*r = 0;
				return (0);
			}
		}
		else if (root->parent)
		{
			*r = root;
			return (ret);
		}
		else
		{
			if (root->son == 0)
			{
				ft_run(root);
				ret += get_exit_status();
			}
			return (ret);
		}
		if (pid)
		{
			wait(&stat);
			return (stat);
		}
		else
			root = root->next;
	}
	return (ret);
}
