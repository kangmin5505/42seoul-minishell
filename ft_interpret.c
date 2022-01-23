/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/23 18:32:57 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

int	ft_savestr(t_interpret *in, char **line, int i)
{
	int	size;
	int	flag;

	if (i == 0)
		flag = SPACE;
	else if (i == Q)
		flag = QUOTE;
	else if (i == DQ)
		flag = DQUOTE;
	size = ft_while(*line, flag, OFF, flag - SPACE);
	if (size < 0)
		return (-1);
	ft_linklist(&in->data, ft_strcpy(*line, 0, size, 0));
	*line += size + (flag - 10) / 23;
	return (size);
}

int	ft_redirection(t_interpret *in, char **line, int i)
{
	int	size;

	size = ft_while(*line, SPACE, ON, END);
	if (size == -1)
		return (-1);
	*line += size;
	size = ft_wh
}

int	ft_select(t_interpret *in, char *line, int i)
{
	int	sign;

	if (i == Q || i == DQ)
		sign = ft_savestr(in, line, i);
	else if (i == OPAR)
		sign= ft_parentis(in, line, i);
	else if (i == CPAR && in->mom)
		return (0);
	else if (i == AND || i == OR || i == PIPE)
		sign = ft_next(in, line, i);
	else if (i == DOUT || i == IN || i == OUT || i == DIN)
		sign = ft_redirection(in, line, i);
	return (sign);
}

int	ft_interpret(t_interpret *in, char *line)
{
	int			i;
	int			c;

	if (!line || !*line)
		return (0);
	while (*line)
	{
		line += ft_while(line, SPACE, ON, NOTEND);
		if ((i = ft_spc(line)))
		{
			line += i / 8 + 1;
			ft_select(in, line, i);
		}
		else
			ft_savestr(in, line, 0);
	}
	if (ft_inerror(in))
		return (-1);
	return (0);
}

int ft_inerror(t_interpret *in, int flag)
{
	if (in->mom && ATEXIT)
		return (-1);
}

int	ft_parentis(t_interpret *in, char **list, const char *i)
{
	*list += strlen(i);
	in->son = ft_newinlist();
	return (ft_interpret(in->son, list));
}
