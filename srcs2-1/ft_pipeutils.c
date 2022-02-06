/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:31:18 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 06:09:27 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getsign(int i)
{
	if (WIFEXITED(i))
		return (WEXITSTATUS(i));
	if (WIFSIGNALED(i))
		return (WTERMSIG(i));
	return (127);
}

void	ft_rtow(int a, int b)
{
	char	str[100];
	int		r;

	r = read(a, str, 100);
	while (r > 0)
	{
		write(b, str, r);
		r = read(a, str, 100);
	}
}

int	ft_sub(t_interpret *in)
{
	int		pid;
	int		stat;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		exit(ft_processpipe(in));
	}
	else
	{
		close(fd[1]);
		wait(&stat);
		ft_rtow(fd[0], 1);
	}
	return (ft_getsign(stat));
}

t_interpret	*ft_innext(t_interpret *in, int i)
{
	int	x;

	x = -1;
	while (++x < i && in)
		in = in->next;
	return (in);
}

int	ft_forkpipeline(void)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		exit(-1);
	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
	return (pid);
}
