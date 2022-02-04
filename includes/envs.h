/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:55:53 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 11:45:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVS_H
# define ENVS_H

/* envs.c */
void	fill_envs_contents(char **envp);
void	init_envs(char **envp);
void	destroy_envs(void);

/* envs_func.c */
void	env(void);
char	*get_env(const char *name);
void	set_env(char *name, char *value);
void	unset_env(char *name);
int		get_exit_status(void);

/* envs_utils.c */
char	*join_name_value(t_dict *dict);
char	**get_envp(void);
char	**get_paths(void);

/* envs_utils2.c */
void	unset_env_detail(t_dict *curr, t_dict *prev, char *name);
void	set_env_change(t_dict *curr, char *value);
void	set_env_new(t_dict *curr, t_dict *prev, char *name, char *value);

#endif
