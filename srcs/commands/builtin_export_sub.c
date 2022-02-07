/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:55:13 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 10:58:37 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_error(char	*arg)
{
	ft_putstr_fd("minishell: export: \'", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
}

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
