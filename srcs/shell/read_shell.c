/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:08:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/10 12:09:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*readline_shell(void)
{
	char	*line;
	char	shell_name[NAME_MAX + PATH_MAX + 2];

	set_tcattr();
	register_signal();
	get_shell_name(shell_name);
	line = readline(shell_name);
	unset_tcattr();
	un_register_signal();
	return (line);
}

void	get_shell_name(char *shell_name)
{
	char	*logname;
	char	buf[PATH_MAX];
	char	*cwd;
	int		len_logname;
	int		len_cwd;

	logname = getenv("LOGNAME");
	cwd = getcwd(buf, PATH_MAX);
	len_logname = ft_strlen(logname);
	len_cwd = ft_strlen(cwd);
	ft_strlcpy(shell_name, logname, len_logname + 1);
	shell_name[len_logname] = ' ';
	ft_strlcpy(shell_name + len_logname + 1, cwd, len_cwd + 1);
	shell_name[len_logname + len_cwd + 1] = '$';
	shell_name[len_logname + len_cwd + 2] = ' ';
	shell_name[len_logname + len_cwd + 3] = '\0';
}

void	add_history_shell(const char *line)
{
	if (line != NULL)
		add_history(line);
}
