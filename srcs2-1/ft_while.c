/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:10:00 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/29 23:49:55 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_process(t_interpret *in)
{

}

void	ft_merge(t_interpret *in)
{
	t_interpret	*root;
	t_clist		*t;
	t_clist		*o;
	int			i;

	root = in;
	while (root)
	{
		root = ft_iterator(in);
		i = -1;
		while (++i < 5)
		{
			o = 0;
			t = root->list[i];
			while (t)
			{
				if (o)
					o->next =  ft_merge_list(t);
				else
					o = ft_merge_list(t);
				t = o->next;
			}
		}
	}
}

char	*ft_substitute(const char *str)
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

	rs = 0;
	s = 0;
	if (type == VAR)
	{
		while (t[0][s] && !(ft_spc(t[0] + s)) && t[0][s] != '$' && t[0][s] != '?')
			++s;
		if (t[0][s] == '?' && s == 0)
			return (ft_getenv(RETURNCODE));
		n = ft_strcpy(t[0], s);
		rs = ft_getenv(n); //cpy real env p
		free(n);
	}
	else
	{
		s = ft_while(t[0], '$', OFF, NOTEND);
		rs = ft_strcpy(t[0], s):
	}
	t[0] += s;
	return (rs);
}

char	*ft_valpret(t_clist *t, int flag)
{
	char	*data;
	char	*tmp;
	char	*rs;
	int		type;

	rs = 0;
	while (t)
	{
		data = t->data;
		type = t->type;
		if (type == SPACE)
			tmp = ft_substitute(data);
		else if (type == DQUOTE || type == QUOTE)
		{
			if (flag == DIN || type == QUOTE)
				tmp = ft_strcpy(data, ft_strlen(data));
			else
				tmp = ft_substitue(data);
		}
		rs = ft_strjoin(rs, tmp);
		free(tmp);
	}
	return (rs);
}

void	ft_delimeters(t_interpret *in)
{
	t_clist		*root;
	t_interpret	*rootx;

	rootx = in;
	while (rootx)
	{
		root = rootx->list[DIN];
		while (root && root->data)
		{
			ft_deltotmp((const char *)root->data);
			root = root->next;
		}
		if (rootx->son)
			ft_delimeters(rootx->son);
		rootx = rootx->next;
	}
}

void	ft_deltotmp(const char *del)
{
	t_clist	*c;
	char	*tmp;
	int		fd;
	int		size;

	tmp = ft_strjoin("tmp/", del);
	fd = open(tmp, O_CREAT | O_WRONLY);
	free(tmp);
	tmp = readline();
	size = ft_strlen(tmp);
	while(ft_strcmp(tmp, del))
	{
		write(fd, tmp, size);
		write(fd, "\n", 1);
		tmp = read_line();
	}
	close(fd);
}
