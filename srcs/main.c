/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 16:37:16 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envs	*g_envs;

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;
	int			idx;

	init_envs(envp);
	set_shell();
	while (1)
	{
		if (argc > 1)
		{
			idx = 1;
			while (argv[idx] != NULL)
			{
				ft_processline(argv[idx]);
				idx++;
			}
			exit_shell(g_envs->exit_status);
		}
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
		//system("leaks minishell");
	}
	return (0);
}
