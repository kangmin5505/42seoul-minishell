/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:23:14 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/30 00:44:57 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"


void	*ft_iteration(void *p)
{
	t_interpret	*in;

	in = p;
	if (in->son)
	{
		while (in->son)
			in = in->son;
		return (in);
	}
	if (in->next)
		return (in->next);
	if (in->parent)
		return (in->parent);
	return (0);
}

void	ft_freeclist(t_clist *t)
{
	t_clist	*tmp;

	while (t)
	{
		tmp = t;
		if (t->data)
			free(t->data);
		t = t->next;
		free(tmp);
	}
}

void	ft_freeinlist(t_interpret *in)
{
	t_interpret	*tmp;
	int			i;

	while (in)
	{
		i = -1;
		in = (t_interpret *)ft_iteration(in);
		while (++i < 5)
			ft_freeclist(in->list[i]);
		tmp = in;
		free(tmp);
	}
}
