/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:12:35 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/10 12:15:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	register_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	child_sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3", STDERR_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
	}
}

void	un_register_signal(void)
{
	signal(SIGINT, child_sig_handler);
	signal(SIGQUIT, child_sig_handler);
}

void	sig_handler(int signo)
{
	if (signo)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	exit_shell(int status)
{
	unset_tcattr();
	destroy_envs();
	ft_putstr_fd("good bye\n", STDOUT_FILENO);
	exit(status);
}
