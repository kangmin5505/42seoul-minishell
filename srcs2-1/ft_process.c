/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:59 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/05 02:58:39 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_processline(char *line)
{
	t_interpret	*in;
	int	i;

	in = ft_initinlist();
	i = ft_interpret(&in, &line);
	if (i < 0)
		ft_error(i, in);
	ft_valpret_all(in);
	ft_merge(in);
	ft_printcmds(in, 0);
	//ft_delimeters(in); 시험이필요한부분
	ft_processpipe(in, 0);
}
