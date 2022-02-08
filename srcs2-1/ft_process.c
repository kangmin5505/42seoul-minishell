/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:59 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/08 00:27:52 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_processline(char *line)
{
	t_interpret	*in;
	t_interpret	root;
	int			i;

	in = ft_initinlist();
	i = ft_interpret(&in, &line);
	if (i < 0)
	{
		ft_error(i, in);
		return ;
	}
	ft_valpret_all(in);
	ft_merge(in);
	root.next = in;
	ft_prepipeall(&root);
	in = root.next;
	ft_processpipe(in);
	ft_freeinlist(in);
}
