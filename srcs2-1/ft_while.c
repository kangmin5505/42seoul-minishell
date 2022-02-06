/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:10:00 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 05:42:57 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_clist	*ft_merge_list(t_clist *s)
{
	t_clist	*t[2];
	char	*data[2];
	int		order;

	data[0] = 0;
	order = 0;
	t[0] = s;
	while (t[0])
	{
		t[1] = t[0];
		if (t[0]->on)
		{
			data[1] = data[0];
			if (!data[0])
			{
				data[0] = ft_strjoin(t[0]->data, t[0]->next->data);
				order = t[0]->order;
				if (t[0]->data)
					free(t[0]->data);
			}
			else
				data[0] = ft_strjoin(data[0], t[0]->next->data);
			if (t[0]->next->data)
				free(t[0]->next->data);
			if (data[1])
				free(data[1]);
		}
		else
			break ;
		t[0] = t[0]->next;
		free(t[1]);
	}
	t[1] = t[0];
	if (t[0] == s)
		return (s);
	t[0] = ft_initclist(data[0], 0, 0, 0);
	t[0]->order = order;
	if (t[1])
		t[0]->next = t[1]->next;
	else
		t[0]->next = 0;
	if (t[1])
		free(t[1]);
	return (t[0]);
}

void	ft_merge(t_interpret *in)
{
	t_interpret	*root;
	t_clist		*a[3];
	int			i;

	root = in;
	while (root)
	{
		i = -1;
		while (++i < 5)
		{
			a[0] = 0;
			a[1] = root->list[i];
			while (a[1])
			{
				if (a[0])
				{
					a[0]->next = ft_merge_list(a[1]);
					a[0] = a[0]->next;
				}
				else
				{
					a[0] = ft_merge_list(a[1]);
					a[2] = a[0];
				}
				if (a[0])
					a[1] = a[0]->next;
				else
					a[1] = 0;
			}
			root->list[i] = a[2];
		}
		root = ft_iterator(root);
	}
}
