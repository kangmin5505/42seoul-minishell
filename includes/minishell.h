/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:40 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/08 22:29:51 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <sys/wait.h>

# include "readline.h"
# include "history.h"
# include "libft.h"
# include "shell.h"
# include "executer.h"
# include "envs.h"
# include "structure.h"
# include "utils.h"
# include "ft_interpret.h"
# include "ft_errcode.h"
# include "redirections.h"

extern t_envs	*g_envs;

# define TRUE	0
# define FALSE	-1
# define SUCCESS 0
# define FAILURE 1
# define BUFFER_SIZE 1024
# define SHELL_NAME "minishell"

#endif
