/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:26:49 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 11:24:21 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_dict	t_dict;
typedef struct s_envs	t_envs;

struct s_dict
{
	char	*name;
	char	*value;
	char	*name_value;
	t_dict	*next;
};

struct s_envs
{
	t_dict			*head;
	int				size;
	char			**envp;
	char			**paths;
	struct termios	origin_tcattr;
};

typedef struct s_clist
{
	char			*data;
	int				on;
	int				type;
	struct s_clist	*next;
}				t_clist;

typedef struct s_interpret
{
	int					flag;
	int					num;
	struct s_clist		*list[5];
	struct s_interpret	*next;
	struct s_interpret	*son ;
	struct s_interpret	*parent;
}				t_interpret;

#endif