/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:16:23 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/27 16:28:53 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

int	ft_strlen(char *str)
{
	register int	i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

char	*ft_strcpy(char *str, int off, int size, int fit)
{
	char	*rs;
	int		i;

	if (!str || !*str || size <= 0)
		return (0);
	i = ft_strlen(str);
	if (i <= off)
		return (0);
	if (fit && (off + size - 1 > i))
		rs = malloc(sizeof(char) * (i - off + 1));
	else
		rs = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (*(str + off + ++i) && (--size + 1))
		*(rs + i) = *(str + off + i);
	*(rs + i) = 0;
	return (rs);
}

int	ft_exclusive(char c, char *ex)
{
	int	exsize;
	int	i;

	i = -1;
	exsize = ft_strlen(ex);
	while (++i < exsize)
		if (c == *(ex + i))
			return (0);
	return (1);
}

int	ft_strexlen(char *str, char *ex, int size)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (*(str + ++i) && i < size)
		if (ft_exclusive(*(str + i), ex))
			++n;
	return (n);
}

char	*ft_strexcpy(char *str, int size, char *ex)
{
	char	*rs;
	int		real;
	int		i;
	int		j;

	j = -1;
	i = -1;
	real = ft_strexlen(str, ex, size);
	rs = malloc(sizeof(char) * (real + 1));
	while (*(str + ++i) && i < size)
		if (ft_exclusive(*(str + i), ex))
			rs[++j] = str[i];
	rs[j + 1] = 0;
	return (rs);
}

/*int	ft_alotsize(char *str)
{
	
}*/