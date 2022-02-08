/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:10:00 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/08 00:26:51 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getonsize(t_clist *c)
{
	int	i;

	i = 0;
	while (c->on)
	{
		c = c->next;
		++i;
	}
	return (i);
}

t_clist	*ft_gettotal(t_clist *c)
{
	int		n;
	char	*rs;
	t_clist	*r;
	int		len;

	n = -1;
	len = 0;
	while (c->on)
	{
		len += ft_strlen(c->data);
		c = c->next;
	}
	len += ft_strlen(c->data);
	if (len)
	{
		rs = (char *)malloc(sizeof(char) * (len + 1));
		rs[len] = 0;
	}
	else
		rs = 0;
	r = ft_initclist(rs, c->next, 0, 0);
	return (r);
}

t_clist	*ft_mergestr(t_clist *c)
{
	int			n[4];
	int			len;
	t_clist		*r[3];

	r[0] = c;
	n[0] = -1;
	n[2] = -1;
	len = 0;
	r[1] = ft_gettotal(c);
	n[3] = ft_getonsize(c);
	while (++n[0] <= n[3])
	{
		n[1] = -1;
		len = ft_strlen(r[0]->data);
		while (++n[1] < len)
			r[1]->data[++n[2]] = r[0]->data[n[1]];
		r[2] = r[0];
		if (r[2]->data)
			free(r[2]->data);
		r[0] = r[0]->next;
		free(r[2]);
	}
	return (r[1]);
}

t_clist	*ft_merge_list(t_clist *s)
{
	t_clist	*root;
	t_clist	*prev;

	prev = s;
	root = s->next;
	while (root)
	{
		if (root->on)
			root = ft_mergestr(root);
		prev->next = root;
		prev = root;
		root = root->next;
	}
	return (s->next);
}

void	ft_merge(t_interpret *in)
{
	t_clist	t;
	int		i;

	while (in)
	{
		if (in->son)
			ft_merge(in->son);
		i = -1;
		while (++i < 5)
		{
			if (in->list[i])
			{
				t.next = in->list[i];
				in->list[i] = ft_merge_list(&t);
			}
		}
		in = in->next;
	}
}
