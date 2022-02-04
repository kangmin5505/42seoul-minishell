/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:51:02 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 16:09:24 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_args(char **args);
char	*ft_strjoin2(const char *s1, const char *s2, const char *substr);
char	*ft_strndup(const char *s1, int n);
int		ft_strcmp(const char *s1, const char *s2);

#endif
