/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:24:16 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 07:50:25 by gimsang-w        ###   ########.fr       */
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

void	ft_error(int i, t_interpret *in)
{
	ft_freeinlist(in);
	if (i == PARSE_ERR_NODEL)
		write(1, NODEL, ft_strlen(NODEL));
	if (i == PARSE_ERR_CPAR)
		write(1, CPAR, ft_strlen(CPAR));
	if (i == PARSE_ERR_UNFIN_PAR)
		write(1, UNFINPAR, ft_strlen(UNFINPAR));
	if (i == PARSE_ERR_UNFIN_Q)
		write(1, UNFINQ, ft_strlen(UNFINQ));
	if (i == PARSE_ERR_EMPTYNEXT)
		write(1, EMPTY, ft_strlen(EMPTY));
	if (i == PARSE_ERR_UNFIN_CPAR)
		write(1, UNFIN_CPAR, ft_strlen(UNFIN_CPAR));
	exit();
}
