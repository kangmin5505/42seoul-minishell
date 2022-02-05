/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:25:05 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/06 00:45:05 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

/* redirections_cmd.c */
char	*input_redirections(t_interpret *in);
void	output_redirections(t_interpret *in);
void	redirections_cmd(t_interpret *in);

/* output_redirections.c */
void	open_output_redirection(t_clist *file, int type);
void	trunc_file(char *file_name);
t_clist	*get_last_output(t_interpret *in, int type);

/* input_redirections.c */
void	create_temp_file(t_clist *file);
t_clist	*get_last_input(t_interpret *in, int type);
void	open_input_redirection(t_clist *file);

#endif
