/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:55:53 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 11:19:50 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVS_H
# define ENVS_H

/* envs.c */
void	create_envs(t_envs *envs, char **envp);
void	destroy_envs(t_envs *envs);

/* envs_func.c */
void	env(t_envs *envs);
char	*get_env(t_envs *envs, const char *name);
void	set_env(t_envs *envs, char *name, char *value);
void	unset_env(t_envs *envs, char *name);

/* envs_utils.c */
char	*join_name_value(t_dict *dict);
char	**get_envp(t_envs *envs);
char	**get_paths(t_envs *envs);

#endif
