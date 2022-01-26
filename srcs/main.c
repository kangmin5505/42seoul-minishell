/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/26 11:14:10 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios	g_origin_tcattr;

void	free_strs(char **strs)
{
	char	**temp;

	temp = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(temp);
}

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
		if (check_line(line) == FALSE)
		{
			printf("check_line error\n");
			continue ;
		}
		// parse
		temp_main(line);
		// execute
		free(line);
	}
	return (0);
}
