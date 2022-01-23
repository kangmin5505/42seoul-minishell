/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/23 18:54:54 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_interpret.h"

int	ft_savestr(t_interpret *in, char **line, int i)
{
	int	size;
	int	flag;

	if (i == 0)
		flag = SPACE;
	else if (i == Q)
		flag = QUOTE;
	else if (i == DQ)
		flag = DQUOTE;
	size = ft_while(*line, flag, OFF, !(flag - SPACE));
	if (size < 0)
		return (-1);
	ft_linklist(&(in->data), ft_strcpy(*line, 0, size, 0), flag);
	*line += size + (flag - 10) / 23;
	return (size);
}

#include <stdio.h>

int	main(void)
{
	char	*a = "da&aafafag\"";
	char	*b;

	b = ft_strexcpy(a, 10, "ax");
	printf("%s\n", b);
	free(b);
}
