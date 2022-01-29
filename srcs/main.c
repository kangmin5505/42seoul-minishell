/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 11:12:22 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;
	t_envs		envs;
	t_interpret	*in;
	int			errc;

	argc = 0;
	argv = 0;

	create_envs(&envs, envp);
	set_shell(&envs);
	while (1)
	{
		line = readline_shell();
		if (line == NULL)
			exit_shell(&envs, EXIT_SUCCESS);
		add_history_shell(line);
		if (check_line(line) == FALSE)
		{
			printf("check_line error\n");
			free(line);
			continue ;
		}
		// parse
		if (*line != '\0')
		{
			in = ft_initinlist();
			errc = ft_interpret(&in, line);
			if (errc == -1)
			{
				free(line);
				exit_shell(&envs, EXIT_FAILURE);
			}
			// execute
			execute(in, &envs);
		}
		free(line);
	}
	return (0);
}
