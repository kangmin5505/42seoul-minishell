/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:40 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/26 10:15:40 by kangkim          ###   ########.fr       */
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

# include "readline/readline.h"
# include "readline/history.h"
# include "libft.h"
# include "shell.h"
# include "executer.h"

/* sakim's header file */
# include "ft_interpret.h"

# define TRUE	0
# define FALSE	-1


#endif
