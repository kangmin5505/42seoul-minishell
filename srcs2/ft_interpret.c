/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/29 19:09:25 by gimsang-w        ###   ########.fr       */
=======
/*   Updated: 2022/01/26 11:33:14 by kangkim          ###   ########.fr       */
>>>>>>> 368222a710288de8621bed9e47e5a56353969caf
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_savestr(t_interpret *in, char **line, int i, int type)
{
	int	size;
	int	flag;
	int	cond1;
	int	cond2;
	char	*rs;
	int	ret;

	ret = 2;
	/* ADD flag = 0 */
	flag = 0;
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
<<<<<<< HEAD
=======
	/* ADD line = NULL */
	line = NULL;
	printf("next\n");
>>>>>>> 368222a710288de8621bed9e47e5a56353969caf
	(*in)->flag = i;
	(*in)->next = ft_initinlist();
	(*in)->next->parent = (*in)->parent;
	*in = (*in)->next;
	return (2);
}

int	ft_select(t_interpret **in, char **line, int i)
{
	int	sign;

<<<<<<< HEAD
	sign = 0;
	if (i == AND || i == OR || i == PIPE)
=======
	/* ADD sign = 0 */
	sign = 0;
	if (i == Q || i == DQ)
		sign = ft_savestr(*in, line, i, DATA);
	else if (i == OPAR)
		sign= ft_parentis(*in, line, i);
	else if (i == CPAR && (*in)->parent)
		return (0);
	else if (i == AND || i == OR || i == PIPE)
>>>>>>> 368222a710288de8621bed9e47e5a56353969caf
		sign = ft_next(in, line, i);
	else
	{
		if ((*in)->son)
			sign = -1;
		if (i == Q || i == DQ)
			sign = ft_savestr(*in, line, i, DATA);
		else if (i == OPAR)
			sign = ft_parentis(*in, line, i);
		else if (i == CPAR && (*in)->parent)
			return (ft_inerror(*in));
		else if (i == CPAR && (*in)->parent == 0)
			return (-1);
		else if (i == DOUT || i == IN || i == OUT || i == DIN)
			sign = ft_redirect(*in, line, i);
	}
	return (sign);
}


int	ft_interpret(t_interpret **in, char **li)
{
	int			i;
	int			c;
	t_interpret	*root;
<<<<<<< HEAD
	char		*line;

	line = *li;
=======

	/* ADD i = 0 */
	i = 0;
>>>>>>> 368222a710288de8621bed9e47e5a56353969caf
	if (!line || !*line)
		return (0);
	root = *in;
	while (**li)
	{
		*li += ft_while(*li, SPACE, ON, NOTEND);
		if (!**li)
			break ;
		if ((i = ft_spc(*li)))
		{
			*li += i / 8 + 1;
			c = ft_select(&root, li, i);
			if (c == -1 || c == 0)
				return (c);
		}
		else
		{
			if ((root)->son)
				return (-1);
			if (ft_savestr(root, li, SPACE, DATA) == -1)
				return (-1);
		}
	}
	if (root->parent)
		return (-1);
	if (ft_inerror(root))
		return (-1);
	return (0);
}

int ft_inerror(t_interpret *in)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (++i < 5)
		if (in->list[i]->data)
			++j;
	if (j || in->son)
		return (0);
	else
		return (-1);
	return (0);
}

int	ft_parentis(t_interpret *in, char **list, int i)
{
	int	x;

	/* ADD i = 0 */
	i = 0;
	in->son = ft_initinlist();
	in->son->parent = in;
	x = ft_interpret(&(in->son), list);
	if (x == 0)
		x = 2;
	return (x);
}
