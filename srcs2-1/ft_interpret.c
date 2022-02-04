/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 12:48:43 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(t_interpret *in, char **line, int type, int i)
{
	char	c;
	int		cond;
	int		rs;

	rs = SUCCESS;
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
	int			size;
	int			flag;
	int			cond;
	char		*rs;
	static int	n;

	flag = ft_fsel0(i);
	if (flag == SPACE)
		size = ft_while2(*line);
	else
		size = ft_while(*line, flag, OFF, END);
	if (size < 0)
		return (PARSE_ERR_UNFIN_Q);
	rs = ft_strcpy(*line, 0, size, 0);
	*line += size;
	cond = (((flag == SPACE) && (**line == DQUOTE || **line == QUOTE))) * 2
		+ (((flag == DQUOTE || flag == QUOTE))
			&& (*(*line + 1) == DQUOTE || *(*line + 1)
				== QUOTE || ((*(*line + 1) != SPACE) && *(*line + 1) != 0))) * 3;
	if (flag == DQUOTE || flag == QUOTE)
		*line += 1;
	ft_linklist(in->list[ft_fsel1(type)], rs, flag, cond);
	in->list[ft_fsel1(type)]->order = n++;
	if (cond)
		return (ft_execute(in, line, type, cond));
	return (SUCCESS);
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
