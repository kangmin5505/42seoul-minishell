/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:04 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/05 21:15:36 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*a;

	if (s == NULL)
		return (0);
	a = s;
	while (*a)
		a++;
	return ((size_t)(a - s));
}
