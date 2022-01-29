/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:24:16 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/29 23:24:57 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

int	ft_inerror(t_interpret *in, int flag)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	if (in->parent && (flag & ATEXIT))
		return (PARSE_ERR_UNFIN_CPAR);
	while (++i < 5)
		if (in->list[i]->data)
			++j;
	if (j || in->son)
		return (0);
	else
		return (-1);
	return (0);
}
