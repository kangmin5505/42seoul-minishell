/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procedure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:15:36 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/06 20:21:41 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect(t_interpret *in, char **line, int i)
{
	int	size;

	size = ft_while(*line, SPACE, ON, END);
	if (size == -1)
		return (PARSE_ERR_NODEL);
	*line += size;
	if (**line == QUOTE)
	{
		*line += 1;
		return (ft_savestr(in, line, Q, i));
	}
	if (**line == DQUOTE)
	{
		*line += 1;
		return (ft_savestr(in, line, DQ, i));
	}
	else if (ft_spc(*line))
		return (PARSE_ERR_NODEL);
	return (ft_savestr(in, line, SPACE, i));
}

int	ft_next(t_interpret **in, int i)
{
	(*in)->flag = i;
	(*in)->next = ft_initinlist();
	(*in)->next->parent = (*in)->parent;
	*in = (*in)->next;
	return (SUCCESS_A);
}

int	ft_parentis(t_interpret *in, char **list)
{
	int	rs;

	in->stype = SUBSHELL;
	in->son = ft_initinlist();
	in->son->parent = in;
	rs = ft_interpret(&(in->son), list);
	if (rs == RET_TO_PAR)
		rs = SUCCESS_A;
	return (rs);
}
