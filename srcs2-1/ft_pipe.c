/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:38:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 10:30:58 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

int	ft_processpipe(t_interpret *in, t_interpret *r)
{
	int			fd[2];
	t_interpret	*root;
	t_interpret	*tmp;
	int			pid;
	int			ret;
	int			stat;

	pid = 0;
	ret = 1;
	root = in;
	(((a1 && a2 && a3) && a4))
	while (root)
	{
		while (root->son)
			ret = ft_process(root->son, &tmp);
		if (root->flag == PIPE)
		{
			pipe(fd);
			pid = fork();
			if (pid)
			{
				close(fd[0]);
				close(STDOUT_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				if (root->son == 0)
					ft_run(root);
				else
					ft_run(tmp);
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
				ft_run(root);
			else
				ft_run(tmp);
			ret += get_exit_status();
			if (ret == 0 && root->flag == AND)
				return (0);
			else if (ret != 0 && root->flag == OR)
				return (0);
		}
		else if (root->parent)
			return (ret);
		else
			ret &= ft_run(root);
		root = root->next;
	}
	return (ret);
}
