/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:14:12 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/08 15:00:56 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_clist	*ft_initclist(char *data, t_clist *next, int type, int on)
{
	t_clist	*rs;

	rs = (t_clist *)malloc(sizeof(t_clist));
	rs->data = data;
	rs->next = next;
	rs->type = type;
	rs->on = on;
	rs->order = 0;
	return (rs);
}

t_interpret	*ft_initinlist(void)
{
	t_interpret	*rs;

	rs = (t_interpret *)malloc(sizeof(t_interpret));
	rs->list[DATA] = ft_initclist(0, 0, 0, 0);
	rs->list[I] = ft_initclist(0, 0, 0, 0);
	rs->list[DI] = ft_initclist(0, 0, 0, 0);
	rs->list[O] = ft_initclist(0, 0, 0, 0);
	rs->list[DO] = ft_initclist(0, 0, 0, 0);
	rs->parent = 0;
	rs->son = 0;
	rs->next = 0;
	rs->flag = 0;
	rs->visit = 0;
	rs->stype = 0;
	return (rs);
}

void	ft_linklist(t_clist *root, char *str, int type, int on)
{
	if (root->data == 0)
	{
		root->data = str;
		root->type = type;
		root->next = 0;
		root->on = on;
		return ;
	}
	while (root->next != 0)
		root = root->next;
	root->next = ft_initclist(str, 0, type, on);
}
