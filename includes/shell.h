/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 11:25:36 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "structure.h"

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
