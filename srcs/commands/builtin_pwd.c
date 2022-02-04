/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:44:03 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:32:04 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(void)
{
	char	*pwd;
	char	buf[PATH_MAX];

	pwd = getcwd(buf, PATH_MAX);
	ft_putendl_fd(pwd, STDOUT_FILENO);
	g_envs->exit_status = SUCCESS;
}
