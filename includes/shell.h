/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/28 18:28:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "structure.h"

/* set_shell.c */
void	set_shell(t_envs *envs);
void	register_signal(void);
void	sig_handler(int signo);
void	set_tcattr(t_envs *envs);
void	exit_shell(t_envs *envs, int status);

/* read_shell.c */
void	get_shell_name(char *shell_name);
char	*readline_shell(void);
void	add_history_shell(const char *line);

/* check_line */
int		check_line(char *line);

#endif
