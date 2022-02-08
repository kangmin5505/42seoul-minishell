/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/08 00:06:23 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(t_interpret *in, char **line, int type, int i)
{
	char	c;
	int		cond;
	int		rs;

	rs = SUCCESS_A;
	c = **line;
	if (i == 2)
	{
		*line += 1;
		rs = ft_savestr(in, line, c, type);
	}
	else if (i == 3)
	{
		cond = c != SPACE && c != DQUOTE && c != QUOTE;
		*line += !cond;
		if (cond)
			rs = ft_savestr(in, line, SPACE, type);
		else
			rs = ft_savestr(in, line, c, type);
	}
	return (rs);
}

int	ft_savestr(t_interpret *in, char **line, int i, int type)
{
	int			data[3];
	char		*rs;
	static int	n;

	data[0] = ft_fsel0(i);
	if (data[0] == SPACE)
		data[2] = ft_while2(*line);
	else
		data[2] = ft_while(*line, data[0], OFF, END);
	if (data[2] < 0)
		return (PARSE_ERR_UNFIN_Q);
	rs = ft_strcpy(*line, 0, data[2], 0);
	*line += data[2];
	data[1] = (((data[0] == SPACE) && (**line == DQUOTE || **line == QUOTE)))
		* 2 + (((data[0] == DQUOTE || data[0] == QUOTE))
			&& (*(*line + 1) == DQUOTE || *(*line + 1)
				== QUOTE || ((*(*line + 1) != SPACE)
					&& *(*line + 1) != 0))) * 3;
	if (data[0] == DQUOTE || data[0] == QUOTE)
		*line += 1;
	ft_linklist(in->list[ft_fsel1(type)], rs, data[0], data[1]);
	ft_last(in->list[ft_fsel1(type)])->order = n++;
	if (data[1])
		return (ft_execute(in, line, type, data[1]));
	return (SUCCESS_A);
}

int	ft_select(t_interpret **in, char **line, int *val)
{
	int	sign;
	int	i;

	i = *val;
	if (i == AND || i == OR || i == PIPE)
		sign = ft_next(in, i);
	else
	{
		if ((*in)->son)
			sign = PARSE_ERR_EMPTYNEXT;
		if (i == Q || i == DQ)
			sign = ft_savestr(*in, line, i, DATA);
		else if (i == OPAR)
			sign = ft_parentis(*in, line);
		else if (i == CPAR && (*in)->parent)
			sign = ft_inerror(*in, 0);
		else if (i == CPAR && (*in)->parent == 0)
			sign = PARSE_ERR_CPAR;
		else if (i == DOUT || i == IN || i == OUT || i == DIN)
			sign = ft_redirect(*in, line, i);
	}
	*val = sign;
	return (sign);
}

int	ft_interpret(t_interpret **in, char **line)
{
	int			c;
	t_interpret	*root;

	root = *in;
	while (**line)
	{
		*line += ft_while(*line, SPACE, ON, NOTEND);
		if (!**line)
			break ;
		c = ft_spc(*line);
		if (c)
		{
			*line += c / 8 + 1;
			if (ft_select(&root, line, &c) <= 0)
				return (c);
		}
		else
		{
			if (root->son)
				return (PARSE_ERR_EMPTYNEXT);
			if (ft_savestr(root, line, SPACE, DATA) < 0)
				return (PARSE_ERR_UNFIN_Q);
		}
	}
	return (ft_inerror(root, ATEXIT));
}
