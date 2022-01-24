/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/24 21:35:54 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_interpret.h"

int	main(void)
{
	char	*a = "daa' 'afa\"fag\"'afgghello'   ";
	char	*b;
	t_interpret	*in;

	in = ft_initinlist();
	ft_savestr(in, &a, 0);
	ft_printdatas(in->data);
}
