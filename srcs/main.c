/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/21 17:52:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios	g_origin_tcattr;

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	argc = 0;
	argv = 0;
	envp = 0;

	set_shell();
	while (1)
	{
		line = readline_shell();
		add_history_shell(line);
		// parse
		// execute
		free(line);
	}
	return (0);
}
