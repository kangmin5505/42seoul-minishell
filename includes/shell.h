/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/21 18:28:48 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/* set_shell.c */
void	set_shell(void);
void	register_signal(void);
void	sig_handler(int signo);
void	set_tcattr(void);
void	exit_shell(int status);

/* read_shell.c */
void	get_shell_name(char *shell_name);
char	*readline_shell(void);
void	add_history_shell(const char *line);

#endif
