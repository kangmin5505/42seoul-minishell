/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell_tcattr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:35:04 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/10 11:35:31 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_tcattr(void)
{
	struct termios	new_tcattr;

	tcgetattr(STDIN_FILENO, &(g_envs->origin_tcattr));
	tcgetattr(STDIN_FILENO, &new_tcattr);
	new_tcattr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_tcattr);
}

void	unset_tcattr(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(g_envs->origin_tcattr));
}

