/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/29 21:58:15 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_interpret.h"

int	main(int n, char **args)
{
	char	*a = "echo <<hello && hw good 'bye'\"sh\" | wow";
	char	*b = "eafagshSRHr\n";
	t_interpret	*in;
	int	errc;

	in = ft_initinlist();
	errc = ft_interpret(&in, (n >= 2) ? args + 1 : &b);
	if (errc >= 0)
		ft_printcmds(in, 0);
	else
		printf("parsing error\n");
}
