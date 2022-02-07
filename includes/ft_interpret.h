/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:14:23 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 22:20:34 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERPRET_H

# define FT_INTERPRET_H

# define PIPELINE 1
# define SUBSHELL 2

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

# define VAR 1
# define NOVAR 2

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
int			ft_interpret(t_interpret **in, char **line);
void		ft_printdatas(t_clist *root, int nthcmd, int type);
void		ft_printcmds(t_interpret *in, int depth);
int			ft_redirect(t_interpret *in, char **line, int i);
int			ft_next(t_interpret **in, int i);
int			ft_parentis(t_interpret *in, char **list);
int			ft_fsel1(int type);
int			ft_fsel0(int i);
void		ft_freeclist(t_clist *c);
void		ft_freeinlist(t_interpret *in);
void		*ft_iterator(void *p);
t_clist		*ft_merge_list(t_clist *t);
void		ft_merge(t_interpret *in);
char		*ft_substitute(char *str);
char		*ft_val(char **t, int type);
void		ft_delimeters(t_interpret *in);
void		ft_deltotmp(char *del);
void		ft_valpret_all(t_interpret *in);
void		ft_valpret(t_clist *t, int flag);
int			ft_processpipe(t_interpret *in);
void		ft_processline(char *line);
t_interpret	*ft_prepipeall(t_interpret *in);
void		ft_error(int i, t_interpret *in);
int			ft_pipelen(t_interpret *in);
int			ft_getsign(int i);
void		ft_rtow(int a, int b);
int			ft_sub(t_interpret *in);
t_interpret	*ft_innext(t_interpret *in, int i);
char		*ft_substitute(char *str);
char		*ft_val(char **t, int type);
void		ft_valpret_all(t_interpret *in);
void		ft_valpret(t_clist *t, int flag);
int			ft_forkpipeline(void);
t_clist		*ft_last(t_clist *t);
#endif
