/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:14:15 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 00:16:00 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	t_dict	*curr;

	curr = g_envs->head;
	while (curr != NULL)
	{
		ft_putendl_fd(curr->name_value, STDOUT_FILENO);
		curr = curr->next;
	}
}

char	*get_env(const char *name)
{
	char	*ret;
	t_dict	*curr;

	curr = g_envs->head;
	while (curr != NULL)
	{
		if (ft_strncmp(curr->name, name, ft_strlen(name)) == 0)
		{
			ret = curr->value;
			return (ret);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	set_env(char *name, char *value)
{
	t_dict	*curr;
	t_dict	*prev;

	curr = g_envs->head;
	prev = curr;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			set_env_change(curr, value);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	set_env_new(curr, prev, name, value);
}

void	unset_env(char *name)
{
	t_dict	*curr;
	t_dict	*prev;

	curr = g_envs->head;
	prev = curr;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			unset_env_detail(curr, prev, name);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	get_exit_status(void)
{
	return (g_envs->exit_status);
}
