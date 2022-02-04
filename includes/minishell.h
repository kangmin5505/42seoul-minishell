/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:40 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 23:24:59 by kangkim          ###   ########.fr       */
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
# include <errno.h>

# include "readline/readline.h"
# include "readline/history.h"
# include "libft.h"
# include "shell.h"
# include "executer.h"
# include "envs.h"
# include "structure.h"
# include "utils.h"
# include "commands.h"

/* sakim's header file */
# include "ft_interpret.h"

extern t_envs	*g_envs;
# define TRUE	0
# define FALSE	-1
# define SUCCESS 0
# define FAILURE 1

#endif
