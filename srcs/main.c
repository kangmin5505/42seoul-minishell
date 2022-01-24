/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:11 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/22 22:47:46 by kangkim          ###   ########.fr       */
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
	char	**strs;

	argc = 0;
	argv = 0;

	set_shell();
	while (1)
	{
		line = readline_shell();
		add_history_shell(line);
		// parse
		if (*line != '\0')
		{
			strs = ft_split(line, ' ');
			execute(strs, envp);
			free_strs(strs);
		}
		free(line);
	}
	return (0);
}
