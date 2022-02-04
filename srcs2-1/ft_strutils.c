/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:55:14 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 11:20:45 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_while(char *str, char del, int not, int end)
{
	int	i;

	i = 0;
	if (not)
		not = -1;
	while (((*(str + i) == del) + not) && *(str + i))
		++i;
	if (end && !*(str + i))
		return (-1);
	return (i);
}

int	ft_while2(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (ft_spc(str + i) || ft_match(str + i, " "))
			return (i);
		++i;
	}
	return (i);
}

int	ft_while3(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (ft_match(str + i, " "))
			return (i);
		else if (ft_match(str + i, "'"))
			return (i);
		else if (ft_match(str + i, "\""))
			return (i);
		++i;
	}
	return (i);
}

int	ft_match(char *str, char *tof)
{
	int	i;

	if (!str || !*str || !tof || !*tof)
		return (0);
	i = 0;
	while (*(tof + i) && *(str + i) == *(tof + i))
	{
		++i;
		if (!*(tof + i))
			return (1);
	}
	return (0);
}

int	ft_spc(char *line)
{
	if (ft_match(line, "\""))
		return (DQ);
	else if (ft_match(line, "'"))
		return (Q);
	else if (ft_match(line, "&&"))
		return (AND);
	else if (ft_match(line, "||"))
		return (OR);
	else if (ft_match(line, "("))
		return (OPAR);
	else if (ft_match(line, ")"))
		return (CPAR);
	else if (ft_match(line, "|"))
		return (PIPE);
	else if (ft_match(line, "<<"))
		return (DIN);
	else if (ft_match(line, "<"))
		return (IN);
	else if (ft_match(line, ">>"))
		return (DOUT);
	else if (ft_match(line, ">"))
		return (OUT);
	return (0);
}
