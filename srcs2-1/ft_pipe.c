/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:38:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 04:38:54 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getsign(int *i)
{
	if (WIFEXITED(*i))
		return (WEXITSTATUS(*i));
	if (WIFSIGNALED(*i))
		return (WTERMSIG(*i));
	return (127);
}

int	ft_sub(t_interpret *in)
{
	int	pid;
	int	stat;
	int	ret;
	int	fd[2];
	char	str[100];
	int	r;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		ret = ft_processpipe(in);
		exit(ret);
	}
	else
	{
		close(fd[1]);
		wait(&stat);
		while ((r = read(fd[0], str, 100)) > 0)
			write(1, str, r);
	}
	return (ft_getsign(&stat));
}

t_interpret	*ft_innext(t_interpret *in, int i)
{
	int	x;

	x = -1;
	while (++x < i && in)
		in = in->next;
	return (in);
}

int	ft_pipeline(t_interpret *in)
{
	int	i;
	int	fd[2];
	int	pid;
	int	stat;

	i = ft_pipelen(in);
	while (--i)
	{
		if (pipe(fd) < 0)
			exit(-1);
		pid = fork();
		if (pid < 0)
			exit(-1);
		if (pid)
		{
			in = ft_innext(in, i);
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			wait(&stat);
			if (in->stype == SUBSHELL)
				exit(ft_sub(in->son));
			else
				ft_run(in);
			stat = get_exit_status();
			exit(stat);
		}
		else
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
	}
	in = ft_innext(in, i);
	if (in->stype == SUBSHELL)
		exit(ft_sub(in->son));
	else
		ft_run(in);
	exit(get_exit_status());
	//run pipeline
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

int	ft_processpipe(t_interpret *in)
{
	t_interpret	*root;
	int			pid;
	int			ret;

	root = in;
	ret = 0;
	while (root)
	{
		if (root->stype == PIPELINE)
		{
			pid = fork();
			if (pid == 0)
			{
				ret = ft_pipeline(root->son);
				exit(ret);
			}
			else
				wait(&ret);
			ret = ft_getsign(&ret);
		}
		if (root->flag == AND || root->flag == OR)
		{
			if (ft_flagandor(root, &ret))
				return (ret);
		}
		else
		{
			if (root->son == 0)
			{
				ft_run(root);
				ret = get_exit_status();
			}
			else if (root->stype == SUBSHELL)
				ft_sub(root->son);
		}
		root = root->next;
	}
	return (ret);
}
