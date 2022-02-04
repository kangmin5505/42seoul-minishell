/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:21:21 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 11:20:01 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fsel0(int i)
{
	int	flag;

	flag = SPACE;
	if (i == 0 || i == SPACE)
		flag = SPACE;
	else if (i == Q || i == QUOTE)
		flag = QUOTE;
	else if (i == DQ || i == DQUOTE)
		flag = DQUOTE;
	return (flag);
}

int	ft_fsel1(int type)
{
	int	i;

	i = 0;
	if (type == DATA)
		i = DATA;
	else if (type == IN)
		i = I;
	else if (type == DIN)
		i = DI;
	else if (type == OUT)
		i = O;
	else if (type == DOUT)
		i = DO;
	return (i);
}
