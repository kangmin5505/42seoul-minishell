/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:08:59 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 17:28:45 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_int_len(long long nbr, int base)
{
	long long	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_lltoa_base(long long n, int base)
{
	long long		nbr;
	long long		len;
	char			*str;

	nbr = n;
	if (n < 0)
		nbr *= -1;
	len = ft_int_len(nbr, base);
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
