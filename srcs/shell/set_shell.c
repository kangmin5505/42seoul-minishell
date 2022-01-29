/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:12:35 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 11:11:38 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_shell(t_envs *envs)
{
	register_signal();
	set_tcattr(envs);
}

void	register_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int	signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_tcattr(t_envs *envs)
{
	struct termios	new_tcattr;

	tcgetattr(STDIN_FILENO, &(envs->origin_tcattr));
	tcgetattr(STDIN_FILENO, &new_tcattr);
	new_tcattr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_tcattr);
}

void	exit_shell(t_envs *envs, int status)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(envs->origin_tcattr));
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit(status);
}
