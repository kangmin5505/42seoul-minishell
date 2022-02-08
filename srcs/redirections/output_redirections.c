/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:06 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/08 21:49:53 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_output_redirection(t_clist *file, int type)
{
	char	*file_name;
	int		fd;

	file_name = file->data;
	if (type == O)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	trunc_file(char *file_name)
{
	int	fd;

	if (file_name != NULL)
	{
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
		close(fd);
	}
}

t_clist	*get_last_output(t_interpret *in, int type)
{
	t_clist	*last_output;

	last_output = in->list[type];
	while (last_output->next != NULL)
	{
		trunc_file(last_output->data);
		last_output = last_output->next;
	}
	return (last_output);
}
