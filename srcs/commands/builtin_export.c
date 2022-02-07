/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:58:34 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 10:58:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_export_var(char *arg)
{
	int		equal_idx;
	char	*name;
	char	*value;

	equal_idx = get_equal_idx(arg);
	if (equal_idx != -1)
	{
		name = ft_strndup(arg, equal_idx);
		value = ft_strdup(arg + equal_idx + 1);
		set_env(name, value);
		free(name);
		free(value);
	}
}

void	execute_export(t_interpret *in)
{
	t_clist	*curr;
	char	*arg;
	int		failure_flag;

	failure_flag = -1;
	curr = in->list[0]->next;
	while (curr != NULL)
	{
		arg = curr->data;
		if (is_valid_var_name(arg) == TRUE)
			set_export_var(arg);
		else
		{
			print_export_error(arg);
			failure_flag = 1;
		}
		curr = curr->next;
	}
	if (failure_flag == 1)
		g_envs->exit_status = FAILURE;
	else
		g_envs->exit_status = SUCCESS;
}

void	builtin_export(t_interpret *in)
{
	t_clist	*curr;

	curr = in->list[0]->next;
	if (curr == NULL)
	{
		print_all_declares();
		g_envs->exit_status = SUCCESS;
	}
	else
		execute_export(in);
}
