/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 16:49:38 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envs	*g_envs;

void	print_line_error(void)
{
	ft_putendl_fd("line error", STDERR_FILENO);
	g_envs->exit_status = FAILURE;
}

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;

	argc = 0;
	argv = 0;
	init_envs(envp);
	set_shell();
	while (1)
	{
		line = readline_shell();
		if (line == NULL)
			exit_shell(EXIT_SUCCESS);
		add_history_shell(line);
		if (check_line(line) == FALSE)
			print_line_error();
		else if (*line != '\0')
			ft_processline(line);
		free(line);
	}
	return (0);
}
