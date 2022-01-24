/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/24 21:35:07 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"
#include <stdio.h>

int	ft_savestr(t_interpret *in, char **line, int i)
{
	int	size;
	int	flag;
	int	cond1;
	int	cond2;
	char	*rs;

	if (i == 0)
		flag = SPACE;
	else if (i == Q || i == QUOTE)
		flag = QUOTE;
	else if (i == DQ || i == DQUOTE)
		flag = DQUOTE;
	if (flag == SPACE)
		size = ft_while3(*line);
	else
		size = ft_while(*line, flag, OFF, flag - SPACE);
	if (size < 0)
		return (-1);
	rs = ft_strcpy(*line, 0, size, 0);
	*line += size;
	cond1 = ((flag == SPACE) && (**line == DQUOTE || **line == QUOTE));
	cond2 = ((flag == DQUOTE || flag == QUOTE)) && (*(*(line) + 1) == DQUOTE || *(*(line) + 1) == QUOTE || *(*(line) + 1) != SPACE);
	ft_linklist(in->data, rs, flag, cond1 || cond2);
	if (cond1)
	{
		*line += 1;
		ft_savestr(in, line, *(*line - 1));
	}
	else if (cond2)
	{
		*line += 2;
		if (*(*line - 1) != SPACE && *(*line - 1) != DQUOTE && *(*line - 1)!= QUOTE)
			ft_savestr(in, line, 0);
		else
			ft_savestr(in, line, *(*line - 1));
	}
	return (size);
}

/*int	ft_redirection(t_interpret *in, char **line, int i)
{
	int	size;

	size = ft_while(*line, SPACE, ON, END);
	if (size == -1)
		return (-1);
	*line += size;
	size = ft_wh
}*/

/*int	ft_select(t_interpret *in, char *line, int i)
{
	int	sign;

	if (i == Q || i == DQ)
		sign = ft_savestr(in, &line, i);
	//else if (i == OPAR)
		//sign= ft_parentis(in, line, i);
	//else if (i == CPAR && in->mom)
		//return (0);
	//else if (i == AND || i == OR || i == PIPE)
		//sign = ft_next(in, line, i);
	//else if (i == DOUT || i == IN || i == OUT || i == DIN)
		//sign = ft_redirection(in, line, i);
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
}*/
