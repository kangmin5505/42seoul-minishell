/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:12:35 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/05 11:43:50 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_shell(void)
{
	register_signal();
	set_tcattr();
}

void	register_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int	signo)
{
	if (signo)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_tcattr(void)
{
	struct termios	new_tcattr;

	tcgetattr(STDIN_FILENO, &(g_envs->origin_tcattr));
	tcgetattr(STDIN_FILENO, &new_tcattr);
	new_tcattr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_tcattr);
}

void	exit_shell(int status)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(g_envs->origin_tcattr));
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit(status);
}
