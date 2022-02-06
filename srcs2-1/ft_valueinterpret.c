/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valueinterpret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:41:15 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 05:43:57 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substitute(char *str)
{
	char	*rs;
	int		code;
	char	*tmp;

	rs = 0;
	code = NOVAR;
	while (*str)
	{
		tmp = ft_val(&str, code);
		rs = ft_strjoin(rs, tmp);
		free(tmp);
		if (*str == '$')
		{
			code = VAR;
			str += 1;
		}
		else
			code = NOVAR;
	}
	return (rs);
}

char	*ft_val(char **t, int type)
{
	int		s;
	char	*rs;
	char	*n;
	char	*tmp;

	rs = 0;
	s = 0;
	if (type == VAR)
	{
		while (t[0][s] && !(ft_spc(t[0] + s))
				&& t[0][s] != '$' && t[0][s] != '?')
			++s;
		if (t[0][s] == '?' && s == 0)
		{
			t[0] += s;
			t[0] += 1;
			return (ft_itoa(get_exit_status()));
		}
		else if (t[0][s] == 0)
			return (ft_strcpy("$", 0, 1, 0));
		n = ft_strcpy(t[0], 0, s, 0);
		tmp = get_env(n);
		rs = ft_strcpy(tmp, 0, ft_strlen(tmp), 0);
		free(n);
	}
	else
	{
		s = ft_while(t[0], '$', OFF, NOTEND);
		rs = ft_strcpy(t[0], 0, s, 0);
	}
	t[0] += s;
	return (rs);
}

void	ft_valpret_all(t_interpret *in)
{
	t_interpret	*root;
	int			i;
	t_clist		*t;

	root = in;
	while (root)
	{
		if (root->son == 0)
		{
			i = -1;
			while (++i < 5)
			{
				t = root->list[i];
				ft_valpret(t, i);
			}
		}
		root = ft_iterator(root);
	}
}

void	ft_valpret(t_clist *t, int flag)
{
	char	*data;
	char	*tmp;
	int		type;

	tmp = 0;
	while (t)
	{
		data = t->data;
		type = t->type;
		if (t->data)
		{
			if (type == SPACE)
				tmp = ft_substitute(data);
			else if (type == DQUOTE || type == QUOTE)
			{
				if (flag == DIN || type == QUOTE)
					tmp = t->data;
				else
					tmp = ft_substitute(data);
			}
		}
		t->data = tmp;
		t = t->next;
	}
}
