/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:14:15 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 12:38:07 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_envs *envs)
{
	t_dict *curr;

	curr = envs->head;
	while (curr != NULL)
	{
		ft_putendl_fd(curr->name_value, STDOUT_FILENO);
		curr = curr->next;
	}
}

char	*get_env(t_envs *envs, const char *name)
{
	char	*ret;
	t_dict	*curr;

	curr = envs->head;
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

void	set_env(t_envs *envs, char *name, char *value)
{
	t_dict	*curr;
	t_dict	*prev;

	curr = envs->head;
	prev = curr;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			free(curr->value);
			free(curr->name_value);
			free_args(envs->envp);
			curr->value = ft_strdup(value);
			curr->name_value = join_name_value(curr);
			envs->envp = get_envp(envs);
			envs->size++;
			if (ft_strcmp(curr->name, "PATH") == 0)
			{
				free_args(envs->paths);
				envs->paths = get_paths(envs);
			}
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
	prev->next = (t_dict *)malloc(sizeof(t_dict));
	prev->next->name = ft_strdup(name);
	prev->next->value = ft_strdup(value);
	curr->name_value = join_name_value(curr);
	free_args(envs->envp);
	envs->size++;
	envs->envp = get_envp(envs);
	prev->next->next = NULL;
}

void	unset_env(t_envs *envs, char *name)
{
	t_dict	*prev;
	t_dict	*curr;

	curr = envs->head;
	prev = curr;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			free(curr->name);
			free(curr->value);
			free(curr->name_value);
			free_args(envs->envp);
			prev->next = curr->next;
			envs->size--;
			envs->envp = get_envp(envs);
			free(curr);
			if (ft_strcmp(name, "PATH") == 0)
			{
				free_args(envs->paths);
				envs->paths = get_paths(envs);
			}
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
