/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:52:01 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 00:15:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_detail(t_dict *curr, t_dict *prev, char *name)
{
	free(curr->name);
	free(curr->value);
	free(curr->name_value);
	free_args(g_envs->envp);
	prev->next = curr->next;
	g_envs->size--;
	g_envs->envp = get_envp();
	free(curr);
	if (ft_strcmp(name, "PATH") == 0)
	{
		free_args(g_envs->paths);
		g_envs->paths = get_paths();
	}
}

void	set_env_change(t_dict *curr, char *value)
{
	free(curr->value);
	free(curr->name_value);
	free_args(g_envs->envp);
	curr->value = ft_strdup(value);
	curr->name_value = join_name_value(curr);
	g_envs->envp = get_envp();
	if (ft_strcmp(curr->name, "PATH") == 0)
	{
		free_args(g_envs->paths);
		g_envs->paths = get_paths();
	}
}

void	set_env_new(t_dict *curr, t_dict *prev, char *name, char *value)
{
	prev->next = (t_dict *)malloc(sizeof(t_dict));
	curr = prev->next;
	curr->name = ft_strdup(name);
	curr->value = ft_strdup(value);
	curr->name_value = join_name_value(curr);
	free_args(g_envs->envp);
	g_envs->size++;
	g_envs->envp = get_envp();
	curr->next = NULL;
}
