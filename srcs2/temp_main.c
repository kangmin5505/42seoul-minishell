/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:01:07 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/26 11:31:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	temp_main(char *line)
{
	t_interpret	*in;
	int	errc;

	in = ft_initinlist();
	errc = ft_interpret(&in, line);
	if (errc != -1)
		ft_printcmds(in, 0);
	else
		printf("parsing error\n");
}
