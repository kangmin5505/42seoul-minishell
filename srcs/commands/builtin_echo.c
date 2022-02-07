/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:31:31 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 14:40:24 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_option_n(char *str)
{
	int	idx;

	if (str[0] != '-')
		return (FALSE);
	idx = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] != 'n')
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

void	print_echo(t_clist *arg)
{
	while (arg != NULL)
	{
		ft_putstr_fd(arg->data, STDOUT_FILENO);
		if (arg->data != NULL && arg->next != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
		arg = arg->next;
	}
}

void	builtin_echo(t_interpret *in)
{
	t_clist	*arg;
	char	*option_n;

	arg = in->list[0]->next;
	if (arg == NULL || arg->data == NULL)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return ;
	}
	option_n = arg->data;
	if (check_option_n(option_n) == TRUE)
	{
		arg = arg->next;
		print_echo(arg);
	}
	else
	{
		print_echo(arg);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	g_envs->exit_status = SUCCESS;
}
