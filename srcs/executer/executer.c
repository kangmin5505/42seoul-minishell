/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:29:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/22 22:43:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **strs, char *envp[])
{
	int		cmd_len;
	char	*cmd;

	cmd = strs[0];
	cmd_len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "echo", cmd_len) == 0)
		printf("echo\n");
	else if (ft_strncmp(cmd, "cd", cmd_len) == 0)
		printf("cd\n");
	else if (ft_strncmp(cmd, "pwd", cmd_len) == 0)
		pwd();
	else if (ft_strncmp(cmd, "export", cmd_len) == 0)
		printf("export\n");
	else if (ft_strncmp(cmd, "unset", cmd_len) == 0)
		printf("unset\n");
	else if (ft_strncmp(cmd, "env", cmd_len) == 0)
		env(envp);
	else if (ft_strncmp(cmd, "exit", cmd_len) == 0)
		exit_shell(EXIT_SUCCESS);
}
