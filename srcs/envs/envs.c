/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:15:33 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 11:25:34 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_envs(t_envs *envs, char **envp)
{
	int		idx;
	t_dict	*curr;

	envs->head = NULL;
	envs->size = 0;
	while (*envp != NULL)
	{
		if (envs->head == NULL)
		{
			envs->head = (t_dict *)malloc(sizeof(t_dict));
			curr = envs->head;
		}
		else
		{
			curr->next = (t_dict *)malloc(sizeof(t_dict));
			curr = curr->next;
		}
		idx = 0;
		while ((*envp)[idx] != '=')
			idx++;
		curr->name = ft_strndup(*envp, idx);
		curr->value = ft_strdup(*envp + idx + 1);
		curr->name_value = ft_strdup(*envp);
		curr->next = NULL;
		envs->size++;
		envp++;
	}
	envs->envp = get_envp(envs);
	envs->paths = get_paths(envs);
}

void	destroy_envs(t_envs *envs)
{
	t_dict	*curr;
	t_dict	*next;

	curr = envs->head;
	while (curr != NULL)
	{
		free(curr->name);
		free(curr->value);
		free(curr->name_value);
		next = curr->next;
		free(curr);
		curr = next;
	}
	free_args(envs->envp);
}
