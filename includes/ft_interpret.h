/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:14:23 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/28 23:12:21 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERPRET_H

# define FT_INTERPRET_H

# define Q 1
# define DQ 2
# define OPAR 3
# define CPAR 4
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
# define ATEXIT 1
# define DATA 0
# define I 1
# define DI 2
# define O 3
# define DO 4

void		temp_main(char *line);

int			ft_spc(char *line);
int			ft_match(char *str, char *tof);
int			ft_while(char *str, char del, int not, int end);
char		*ft_strcpy(char *str, int off, int size, int fit);
t_clist		*ft_initclist(char *data, t_clist *next, int type, int on);
t_interpret	*ft_initinlist(void);
void		ft_linklist(t_clist *root, char *str, int type, int on);
int			ft_savestr(t_interpret *in, char **line, int i, int type);
int			ft_while2(char *str);
int			ft_strexlen(char *str, char *ex, int size);
char		*ft_strexcpy(char *str, int size, char *ex);
int			ft_while3(char *str);
int			ft_inerror(t_interpret *in, int flag);
int			ft_parentis(t_interpret *in, char **list, int i);
int			ft_interpret(t_interpret **in, char *line);
void		ft_printdatas(t_clist *root, int nthcmd, int type);
void		ft_printcmds(t_interpret *in, int depth);

#endif
