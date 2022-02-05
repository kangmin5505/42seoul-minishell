/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:36:25 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/05 14:19:51 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "commands.h"
# include "structure.h"

/* executer.c */
void	external_cmd(char *cmd, char **argv);
void	execute_cmd(t_interpret *in);
void	ft_run(t_interpret *in);

/* executer_utils.c */
void	print_external_cmd_error(char *cmd);
char	**get_argv(t_interpret *in);
char	*find_path(char *cmd);

#endif
