/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:23:37 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 09:22:11 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_name_value(t_dict *dict)
{
	int		name_len;
	int		value_len;
	char	*name_value;

	name_len = ft_strlen(dict->name);
	value_len = ft_strlen(dict->value);
	name_value = (char *)malloc(name_len + value_len + 1);
	ft_strlcpy(name_value, dict->name, name_len + 1);
	name_value[name_len] = '=';
	ft_strlcpy(name_value + name_len + 1, dict->value, value_len + 1);
	return (name_value);
}

char	**get_envp(void)
{
	char	**envp;
	int		size;
	int		idx;
	t_dict	*curr;

	size = g_envs->size;
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	idx = 0;
	curr = g_envs->head;
	while (idx < size)
	{
		envp[idx] = ft_strdup(curr->name_value);
		idx++;
		curr = curr->next;
	}
	envp[idx] = NULL;
	return (envp);
}

char	**get_paths(void)
{
	t_dict	*curr;
	char	**paths;

	curr = g_envs->head;
	while (curr)
	{
		if (ft_strcmp(curr->name, "PATH") == 0)
		{
			paths = ft_split(curr->value, ':');
			return (paths);
		}
		curr = curr->next;
	}
	paths = (char **)malloc(sizeof(char *));
	paths[0] = NULL;
	return (paths);
}
