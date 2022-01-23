/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:14:12 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/23 15:48:59 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

t_clist	*ft_initclist(char *data, t_clist *next, int type)
{
	t_clist	*rs;

	rs = (t_clist *)malloc(sizeof(t_clist));
	rs->data = data;
	rs->next = next;
	rs->type = type;
	return (rs);
}

t_interpret	*ft_initinlist(void)
{
	t_interpret	*rs;

	rs = (t_interpret *)malloc(sizeof(t_interpret));
	rs->data = ft_initclist(0, 0, 0);
	rs->parent = 0;
	rs->son = 0;
	rs->next = 0;
	rs->flag = 0;
	rs->num = 0;
	return (rs);
}

void	ft_linklist(t_clist **data, char *str, int type)
{
	if ((*data)->data == 0)
	{
		(*data)->data = str;
		(*data)->type = type;
		return ;
	}
	(*data)->next = ft_initclist(str, 0, type);
	(*data) = (*data)->next;
}

/*int		clean_list(c_list *list)
{
}*/
