/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:14:12 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/25 03:57:21 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

t_clist	*ft_initclist(char *data, t_clist *next, int type, int on)
{
	t_clist	*rs;

	rs = (t_clist *)malloc(sizeof(t_clist));
	rs->data = data;
	rs->next = next;
	rs->type = type;
	rs->on = on;
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
	rs->num = 0;
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

void	ft_printcmds(t_interpret *in)
{
	int	i;
	int	j;

	i = 0;
	while (in)
	{
		if (in->son)
			ft_printcmds(in->son);
		if (in->son == 0)
		{
			printf("\n<--- %dth cmd start --->\n", i);
			j = -1;
			while (++j < 5)
				ft_printdatas(in->list[j], i, j);
			printf("\n<--- %dth cmd end --->\n", i);
		}
		in = in->next;
		++i;
	}
}

void	ft_printdatas(t_clist *root, int nthcmd, int type)
{
	int	i;

	i = -1;
	printf("\n<--- this is %dth cmd %s start ---> \n", nthcmd, (type == DATA) ? "DATA" : (type == I) ? "SINGLEIN" : (type == DI) ? "DOUBLEIN" : (type == O) ? "SINGLEOUT" : "DOUBLEOUT");
	while (root)
	{
		printf("%dth data-> %s\n", ++i, root->data);
		printf("%dth join-> %s\n", i, (root->on) ? "CONTINUED" : "NOT CONTINUED");
		printf("%dth type-> %s\n", i, (root->type == SPACE) ? "SPACE" : (root->type == DQUOTE) ? "DQUOTE" : "QUOTE");
		root = root->next;
	}
	printf("\n<--- this is %dth cmd %s end ---> \n", nthcmd, (type == DATA) ? "DATA" : (type == I) ? "SINGLEIN" : (type == DI) ? "DOUBLEIN" : (type == O) ? "SINGLEOUT" : "DOUBLEOUT");
}

/*int		clean_list(c_list *list)
{
}*/
