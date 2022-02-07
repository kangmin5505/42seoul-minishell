/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:24:59 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/07 17:01:08 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

/* builtin_env.c */
void	builtin_env(void);

/* builtin_exit.c */
void	builtin_exit(t_interpret *in);
void	print_exit_error_1(void);
void	print_exit_error_255(char *arg);
t_clist	*get_not_numeric_arg(t_interpret *in);
int		get_argc(t_interpret *in);

/* builtin_echo.c */
int		check_option_n(char *str);
void	print_echo(t_clist *arg);
void	builtin_echo(t_interpret *in);

/* builtin_cd.c */
void	builtin_cd(t_interpret *in);
void	execute_cd(char *path);

/* builtin_pwd.c */
void	builtin_pwd(void);

/* builtin_unset.c */
void	builtin_unset(t_interpret *in);

/* builtin_export.c */
void	set_export_var(char *arg);
void	execute_export(t_interpret *in);
void	builtin_export(t_interpret *in);

/* builtin_export_sub.c */
void	print_export_error(char *arg);
void	print_all_declares(void);
int		is_valid_var_name(char *arg);
int		get_equal_idx(char *arg);

#endif
