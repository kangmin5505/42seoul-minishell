/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/25 05:18:58 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"
#include <stdio.h>

int	ft_savestr(t_interpret *in, char **line, int i, int type)
{
	int	size;
	int	flag;
	int	cond1;
	int	cond2;
	char	*rs;
	int	ret;

	ret = 2;
	if (i == 0 || i == SPACE)
		flag = SPACE;
	else if (i == Q || i == QUOTE)
		flag = QUOTE;
	else if (i == DQ || i == DQUOTE)
		flag = DQUOTE;
	if (flag == SPACE)
		size = ft_while3(*line);
	else
		size = ft_while(*line, flag, OFF, END);
	if (size < 0)
		return (-1);
	rs = ft_strcpy(*line, 0, size, 0);
	*line += size;
	cond1 = ((flag == SPACE) && (**line == DQUOTE || **line == QUOTE));
	cond2 = ((flag == DQUOTE || flag == QUOTE)) && (*(*(line) + 1) == DQUOTE || *(*(line) + 1) == QUOTE || *(*(line) + 1) != SPACE);
	if (type == DATA)
		ft_linklist(in->list[DATA], rs, flag, cond1 || cond2);
	else if (type == IN)
		ft_linklist(in->list[I], rs, flag, cond1 || cond2);
	else if (type == DIN) 
		ft_linklist(in->list[DI], rs, flag, cond1 || cond2);
	else if (type == OUT) 
		ft_linklist(in->list[O], rs, flag, cond1 || cond2);
	else if (type == DOUT) 
		ft_linklist(in->list[DO], rs, flag, cond1 || cond2);
	if (flag != SPACE)
		*line += 1;
	if (cond1)
	{
		*line += 1;
		ret = ft_savestr(in, line, *(*line - 1), type);
		if (ret == -1)
			return (ret);
	}
	else if (cond2)
	{
		*line += 1;
		if (*(*line - 1) != SPACE && *(*line - 1) != DQUOTE && *(*line - 1)!= QUOTE)
			ret = ft_savestr(in, line, (--*line - *line), type);
		else
			ret = ft_savestr(in, line, *(*line - 1), type);
		if (ret == -1)
			return (ret);
	}
	return (ret);
}

int	ft_redirect(t_interpret *in, char **line, int i)
{
	int	size;

	size = ft_while(*line, SPACE, ON, END);
	if (size == -1)
		return (-1);
	*line += size;
	if (**line == QUOTE || **line == DQUOTE)
	{
		*line += 1;
		if (**line == QUOTE)
			return (ft_savestr(in, line, Q, i));
		else
			return (ft_savestr(in, line, DQ, i));
	}
	else if (ft_spc(*line))
		return (-1);
	return (ft_savestr(in, line, SPACE, i));
}

int	ft_next(t_interpret **in, char **line, int i)
{
	printf("next\n");
	(*in)->flag = i;
	(*in)->next = ft_initinlist();
	*in = (*in)->next;
	return (2);
}

int	ft_select(t_interpret **in, char **line, int i)
{
	int	sign;

	if (i == Q || i == DQ)
		sign = ft_savestr(*in, line, i, DATA);
	else if (i == OPAR)
		sign= ft_parentis(*in, line, i);
	else if (i == CPAR && (*in)->parent)
		return (0);
	else if (i == AND || i == OR || i == PIPE)
		sign = ft_next(in, line, i);
	else if (i == DOUT || i == IN || i == OUT || i == DIN)
		sign = ft_redirect(*in, line, i);
	return (sign);
}


int	ft_interpret(t_interpret **in, char *line)
{
	int			i;
	int			c;
	t_interpret	*root;
	
	if (!line || !*line)
		return (0);
	root = *in;
	while (*line)
	{
		line += ft_while(line, SPACE, ON, NOTEND);
		if (!*line)
			break ;
		if ((i = ft_spc(line)))
		{
			line += i / 8 + 1;
			c = ft_select(&root, &line, i);
			if (c == -1 || c == 0)
				return (c);
		}
		else
		{
			if (ft_savestr(root, &line, SPACE, DATA) == -1)
				return (-1);
		}
	}
	if (ft_inerror(root, ATEXIT))
		return (-1);
	return (0);
}

int ft_inerror(t_interpret *in, int flag)
{
	if (in->parent)
		printf("errorforsure\n");
	if (in->parent && (ATEXIT & flag))
		return (-1);
	return (0);
}

int	ft_parentis(t_interpret *in, char **list, int i)
{
	int	x;

	in->son = ft_initinlist();
	in->son->parent = in;
	x = ft_interpret(&(in->son), *list);
	if (x == 0)
		x = 2;
	return (x);
}
