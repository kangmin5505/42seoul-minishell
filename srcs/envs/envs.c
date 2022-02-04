/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:15:33 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 09:21:56 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_envs_contents(char **envp)
{
	t_dict	*curr;
	int		idx;

	while (*envp != NULL)
	{
		if (g_envs->head == NULL)
		{
			g_envs->head = (t_dict *)malloc(sizeof(t_dict));
			curr = g_envs->head;
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
		g_envs->size++;
		envp++;
	}
}

void	init_envs(char **envp)
{
	g_envs = (t_envs *)malloc(sizeof(t_envs));
	g_envs->head = NULL;
	g_envs->size = 0;
	fill_envs_contents(envp);
	g_envs->envp = get_envp();
	g_envs->paths = get_paths();
	g_envs->exit_status = SUCCESS;
}

void	destroy_envs(void)
{
	t_dict	*curr;
	t_dict	*next;

	curr = g_envs->head;
	while (curr != NULL)
	{
		free(curr->name);
		free(curr->value);
		free(curr->name_value);
		next = curr->next;
		free(curr);
		curr = next;
	}
	free_args(g_envs->envp);
}
