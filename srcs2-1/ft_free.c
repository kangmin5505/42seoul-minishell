/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:23:14 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 22:19:58 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_clist	*ft_last(t_clist *t)
{
	while (t->next)
		t = t->next;
	return (t);
}

void	*ft_iterator(void *p)
{
	t_interpret	*in;

	in = p;
	if (in->son && in->visit == 0)
	{
		while (in->son)
			in = in->son;
		return (in);
	}
	if (in->next)
	{
		if (in->son)
			in->visit = 0;
		return (in->next);
	}
	if (in->parent)
	{
		in->parent->visit = 1;
		if (in->son)
			in->visit = 0;
		return (in->parent);
	}
	if (in->son)
		in->visit = 0;
	return (in->next);
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
		if (in->son)
			ft_freeinlist(in->son);
		while (++i < 5)
		{
			if (in->list[i])
				ft_freeclist(in->list[i]);
		}
		tmp = in;
		in = in->next;
		free(tmp);
	}
}
