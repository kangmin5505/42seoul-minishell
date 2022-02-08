/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:38:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/08 14:48:23 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipeline(t_interpret *in)
{
	int	i;
	int	stat;

	i = ft_pipelen(in);
	while (--i)
	{
		if (ft_forkpipeline())
		{
			wait(&stat);
			break ;
		}
	}
	in = ft_innext(in, i);
	if (in->stype == SUBSHELL)
		exit(ft_sub(in->son));
	else
		ft_run(in);
	exit(get_exit_status());
}

int	ft_flagandor(t_interpret *in, int *ret)
{
	int	cond1;

	if (in->son == 0)
	{
		ft_run(in);
		*ret = get_exit_status();
	}
	else if (in->stype == SUBSHELL)
		*ret = ft_sub(in->son);
	cond1 = *ret && (in->flag == AND);
	cond1 = cond1 || (!*ret && (in->flag == OR));
	if (cond1)
		return (1);
	return (0);
}

int	ft_forkpipe(t_interpret *in)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == 0)
		exit(ft_pipeline(in));
	else
		wait(&ret);
	return (ft_getsign(ret));
}

int	ft_none(t_interpret *root, int ret)
{
	if (root->son == 0)
	{
		ft_run(root);
		return (get_exit_status());
	}
	else if (root->stype == SUBSHELL)
		return (ft_sub(root->son));
	return (ret);
}

int	ft_processpipe(t_interpret *in)
{
	t_interpret	*root;
	int			ret;

	root = in;
	ret = 0;
	while (root)
	{
		if (root->stype == PIPELINE)
			ret = ft_forkpipe(root->son);
		if (root->flag == AND || root->flag == OR)
		{
			if (ft_flagandor(root, &ret))
				return (ret);
		}
		else
			ret = ft_none(root, ret);
		root = root->next;
	}
	return (ret);
}
