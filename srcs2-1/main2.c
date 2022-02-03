/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/03 10:19:05 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_interpret.h"

int	main(int n, char **args)
{
	char	*a = "echo <<hello && hw good 'bye'\"sh\" | wow";
	char	*b = "eaf$s1$a2&&agshSRHr\"agag\" aaaf'asf'\"sgdshsb\" ss << '$af&&fs'\"asgag\" >> out'a'";
	char	*c = "<<'affs'\"asgag\"  ";
	char	*d = "$a1$a2$ax&&list";
	char	*e;
	t_interpret	*in;
	int	errc;

	e = b;
	in = ft_initinlist();
	errc = ft_interpret(&in, (n >= 2) ? args + 1 : &b);
	ft_valpret_all(in);
	ft_merge(in);
	printf("original->%s\n", e);
	if (errc >= 0)
		ft_printcmds(in, 0);
	else
		printf("parsing error\n");
	ft_freeinlist(in);
}
