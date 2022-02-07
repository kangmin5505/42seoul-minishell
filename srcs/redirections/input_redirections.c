/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:44:04 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 11:02:31 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_temp_file(t_clist *file)
{
	char	*file_name;
	int		fd;
	int		bytes;
	char	buf[BUFFER_SIZE];

	file_name = file->data;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		bytes = read(STDIN_FILENO, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		if (ft_strncmp(file_name, buf, ft_strlen(file_name) - 1) == 0)
			break ;
		write(fd, buf, bytes);
	}
	if (file->next != NULL)
		unlink(file_name);
}

t_clist	*get_last_input(t_interpret *in, int type)
{
	t_clist	*last_input;

	last_input = in->list[type];
	while (last_input->data != NULL)
	{
		if (type == DI)
			create_temp_file(last_input);
		if (last_input->next == NULL)
			break ;
		last_input = last_input->next;
	}
	return (last_input);
}

void	open_input_redirection(t_clist *file)
{
	char	*file_name;
	int		fd;

	file_name = file->data;
	fd = open(file_name, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
}
