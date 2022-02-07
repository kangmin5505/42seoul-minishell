/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:10:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 17:12:21 by kangkim          ###   ########.fr       */
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
	ft_putendl_fd("exit", STDOUT_FILENO);
	g_envs->exit_status = 1;
	ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
}

void	print_exit_error_255(char *arg)
{
	g_envs->exit_status = 255;
	ft_putendl_fd("exit", STDOUT_FILENO);
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
}

t_clist	*get_not_numeric_arg(t_interpret *in)
{
	t_clist	*curr;
	int		idx;

	curr = in->list[0]->next;
	while (curr != NULL)
	{
		idx = 0;
		while (curr->data[idx] != '\0')
		{
			if (ft_isdigit(curr->data[idx]) == 0)
				return (curr);
			idx++;
		}
		curr = curr->next;
	}
	return (NULL);
}

void	builtin_exit(t_interpret *in)
{
	int		argc;
	t_clist	*not_numeric_arg;

	argc = get_argc(in);
	if (argc > 1)
	{
		not_numeric_arg = get_not_numeric_arg(in);
		if (not_numeric_arg != NULL)
			print_exit_error_255(not_numeric_arg->data);
		else
			print_exit_error_1();
	}
	else
	{
		if (argc == 1)
		{
			not_numeric_arg = get_not_numeric_arg(in);
			if (not_numeric_arg != NULL)
				print_exit_error_255(in->list[0]->next->data);
			else
				g_envs->exit_status = ft_atoi(in->list[0]->next->data);
		}
		exit_shell(g_envs->exit_status);
	}
}
