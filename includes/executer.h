/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:36:25 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/29 01:11:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "structure.h"

void	free_args(char **args);
char	**get_argv(t_interpret *in);
void	execute(t_interpret *in, t_envs *envs);


void	pwd(void);
#endif
