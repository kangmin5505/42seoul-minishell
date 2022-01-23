/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:51:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/23 15:57:58 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUTILS_H

# define FT_STRUTILS_H

# define Q 1
# define DQ 2
# define OP 3
# define CP 4
# define PIPE 5
# define IN 6
# define OUT 7
# define OR 8
# define AND 9
# define DIN 10
# define DOUT 11
# define SPACE 32
# define DQUOTE 34
# define QUOTE 39
# define ON 0
# define OFF 1
# define END 1
# define NOTEND 0

int			ft_spc(char *line);
int			ft_match(char *str, char *tof);
int			ft_while(char *str, char del, int not, int end);
char		*ft_strcpy(char *str, int off, int size, int fit);
int			ft_strlen(char *str);
t_clist		*ft_initclist(char *data, t_clist *next, int type);
t_interpret	*ft_initinlist(void);
void		ft_linklist(t_clist **data, char *str, int type);
#endif
