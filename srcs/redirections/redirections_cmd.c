/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:27:41 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 18:18:37 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*input_redirections(t_interpret *in)
{
	t_clist	*single_in;
	t_clist	*double_in;
	int		single_in_order;
	int		double_in_order;

	single_in = get_last_input(in, I);
	single_in_order = single_in->order;
	double_in = get_last_input(in, DI);
	double_in_order = double_in->order;
	if (single_in_order > double_in_order)
	{
		open_input_redirection(single_in);
		return (NULL);
	}
	else
	{
		open_input_redirection(double_in);
		return (double_in->data);
	}
}

void	output_redirections(t_interpret *in)
{
	t_clist	*single_out;
	t_clist	*double_out;
	int		single_out_order;
	int		double_out_order;

	single_out = get_last_output(in, O);
	single_out_order = single_out->order;
	double_out = get_last_output(in, DO);
	double_out_order = double_out->order;
	if (single_out_order > double_out_order)
	{
		trunc_file(double_out->data);
		open_output_redirection(single_out, O);
	}
	else
	{
		trunc_file(single_out->data);
		open_output_redirection(double_out, DO);
	}
}

void	redirections_cmd(t_interpret *in)
{
	int		input_backup_fd;
	int		output_backup_fd;
	char	*last_doublein_file;

	input_backup_fd = dup(STDIN_FILENO);
	output_backup_fd = dup(STDOUT_FILENO);
	last_doublein_file = NULL;
	if (in->list[I]->data != NULL || in->list[DI]->data != NULL)
		last_doublein_file = input_redirections(in);
	if (in->list[O]->data != NULL || in->list[DO]->data != NULL)
		output_redirections(in);
	execute_cmd(in);
	dup2(input_backup_fd, STDIN_FILENO);
	close(input_backup_fd);
	dup2(output_backup_fd, STDOUT_FILENO);
	close(output_backup_fd);
	if (last_doublein_file != NULL)
		unlink(last_doublein_file);
}
