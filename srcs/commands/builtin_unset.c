/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:50:59 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:29:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_interpret *in)
{
	t_clist	*curr;
	char	*name;

	curr = in->list[0]->next;
	if (curr != NULL)
	{
		name = curr->data;
		unset_env(name);
	}
	g_envs->exit_status = SUCCESS;
}
