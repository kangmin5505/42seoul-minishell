/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:10:10 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 05:38:56 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipelen(t_interpret *in)
{
	int	i;

	if (!in)
		return (0);
	i = 0;
	while (in->flag == PIPE)
	{
		in = in->next;
		++i;
	}
	if (i == 0)
		return (0);
	++i;
	return (i);
}

t_interpret	*ft_linkpipe(t_interpret *new, t_interpret *root)
{
	t_interpret	tmp;
	t_interpret	*bf;

	if (root->son)
	{
		tmp.next = root->son;
		root->son = ft_prepipeall(&tmp);
	}
	new->son = root;
	root->parent = new;
	while (root->flag == PIPE)
	{
		bf = root;
		root = root->next;
		if (root->son)
		{
			tmp.next = root->son;
			root->son = ft_prepipeall(&tmp);
		}
		root->parent = new;
		bf->next = root;
	}
	return (root);
}

t_interpret	*ft_prepipe(t_interpret *in)
{
	t_interpret	*root;
	t_interpret	*new;

	root = in;
	new = ft_initinlist();
	new->stype = PIPELINE;
	root = ft_linkpipe(new, root);
	new->next = root->next;
	root->next = 0;
	new->flag = root->flag;
	root->flag = 0;
	return (new);
}

t_interpret	*ft_prepipeall(t_interpret *in)
{
	t_interpret	*root;
	t_interpret	*bef;
	t_interpret	tmp;

	bef = in;
	root = in->next;
	while (root)
	{
		if (root->flag == PIPE)
			root = ft_prepipe(root);
		else if (root->son)
		{
			tmp.next = root->son;
			root->son = ft_prepipeall(&tmp);
		}
		bef->next = root;
		bef = bef->next;
		root = root->next;
	}
	return (in->next);
}
