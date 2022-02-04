/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 02:27:01 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/03 05:11:04 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*rs;
	int		size1;
	int		size2;
	int		i;

	i = -1;
	if (!str1 && !str2)
		return (0);
	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	rs = malloc(sizeof(char) * (size1 + size2 + 1));
	while (++i < size1 + size2)
	{
		if (i < size1)
			rs[i] = str1[i];
		else
			rs[i] = str2[i - size1];
	}
	rs[i] = 0;
	return (rs);
}
