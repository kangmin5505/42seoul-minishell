/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:58:34 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:29:08 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_all_declares(void)
{
	t_dict	*curr;
	char	*name;
	char	*value;

	curr = g_envs->head;
	while (curr != NULL)
	{
		name = curr->name;
		value = curr->value;
		printf("declare -x %s=\"%s\"\n", name, value);
		curr = curr->next;
	}
}

int	is_valid_var_name(char	*arg)
{
	if (ft_isalpha(*arg) != 1 && *arg != '_')
		return (FALSE);
	arg++;
	while (*arg != '\0' && *arg != '=')
	{
		if (ft_isalnum(*arg) != 1 && *arg != '_')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

int	get_equal_idx(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] != '\0' && arg[idx] != '=')
		idx++;
	if (arg[idx] == '\0')
		return (-1);
	return (idx);
}

void	print_export_error(char	*arg)
{
	ft_putstr_fd("minishell: export: \'", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
}

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
