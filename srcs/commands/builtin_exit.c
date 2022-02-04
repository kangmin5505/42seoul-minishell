/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:10:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:31:40 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_argc(t_interpret *in)
{
	t_clist	*curr;
	int		argc;

	curr = in->list[0]->next;
	argc = 0;
	while (curr)
	{
		argc++;
		curr = curr->next;
	}
	return (argc);
}

void	print_exit_error_1(void)
{
	ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
}

void	print_exit_error_255(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
}

int	is_numeric_arg(char *arg)
{
	while (*arg != '\0')
	{
		if (ft_isdigit(*arg) == 0)
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

void	builtin_exit(t_interpret *in)
{
	int		argc;
	char	*arg;

	argc = get_argc(in);
	if (argc > 1)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		g_envs->exit_status = 1;
		print_exit_error_1();
	}
	else
	{
		if (argc == 1)
		{
			arg = in->list[0]->next->data;
			if (is_numeric_arg(arg) == FALSE)
			{
				g_envs->exit_status = 255;
				print_exit_error_255(arg);
			}
		}
		else
			g_envs->exit_status = SUCCESS;
		exit_shell(g_envs->exit_status);
	}
}
