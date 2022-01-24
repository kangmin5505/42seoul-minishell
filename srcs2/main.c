/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/25 03:51:19 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_interpret.h"

int	main(int n, char **args)
{
	char	*a = "echo <<hello && hw good 'bye'\"sh\" | wow";
	char	*b;
	t_interpret	*in;

	in = ft_initinlist();
	ft_interpret(&in, (n >= 2) ? args[1] : a);
	ft_printcmds(in);
}
