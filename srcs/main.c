/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/10 11:51:31 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envs	*g_envs;

void	execute_argv_processline(char *argv[])
{
	int	idx;

	idx = 1;
	while (argv[idx] != NULL)
	{
		ft_processline(argv[idx]);
		idx++;
	}
	exit_shell(g_envs->exit_status);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	init_envs(envp);
	register_signal();
	while (1)
	{
		if (argc > 1)
			execute_argv_processline(argv);
		else
		{
			line = readline_shell();
			if (line == NULL)
				exit_shell(EXIT_SUCCESS);
			add_history_shell(line);
			if (*line != '\0')
				ft_processline(line);
			free(line);
		}
	}
	return (0);
}
